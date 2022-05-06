/********************************************************************************************************
 * @file     app_buffer.c
 *
 * @brief    This is the source file for BLE SDK
 *
 * @author	 BLE GROUP
 * @date         12,2021
 *
 * @par     Copyright (c) 2021, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
 *
 *          Licensed under the Apache License, Version 2.0 (the "License");
 *          you may not use this file except in compliance with the License.
 *          You may obtain a copy of the License at
 *
 *              http://www.apache.org/licenses/LICENSE-2.0
 *
 *          Unless required by applicable law or agreed to in writing, software
 *          distributed under the License is distributed on an "AS IS" BASIS,
 *          WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *          See the License for the specific language governing permissions and
 *          limitations under the License.
 *******************************************************************************************************/

#include "tl_common.h"
#include "drivers.h"
#include "stack/ble/ble.h"

#include "app_uart.h"
#include "app_config.h"

#if (FEATURE_TEST_MODE == TEST_FEATURE_DEBUG&&BLE_DEBUG_MODE==BLE_DEBUG_UART)

_attribute_data_retention_  u8 		 	uart_rx_fifo_b[UART_RXFIFO_SIZE * UART_RXFIFO_NUM] = {0};
_attribute_data_retention_	my_fifo_t	 uart_rx_fifo = {
												UART_RXFIFO_SIZE,
												UART_RXFIFO_NUM,
												0,
												0,
												uart_rx_fifo_b,};

_attribute_data_retention_  u8 		 	uart_tx_fifo_b[UART_TXFIFO_SIZE * UART_TXFIFO_NUM] = {0};
_attribute_data_retention_	my_fifo_t	 uart_tx_fifo = {
												UART_TXFIFO_SIZE,
												UART_TXFIFO_NUM,
												0,
												0,
												uart_tx_fifo_b,};

_attribute_data_retention_  volatile unsigned char uart_dma_send_flag;

uart_data_t txdata_buf;

void user_uart_init()
{
	u8 *uart_rx_addr = (uart_rx_fifo_b + (uart_rx_fifo.wptr & (uart_rx_fifo.num-1)) * uart_rx_fifo.size);
	uart_recbuff_init( (unsigned char *)uart_rx_addr, uart_rx_fifo.size);

	uart_gpio_set(UART_TX_PIN, UART_RX_PIN);// uart tx/rx pin set

	uart_reset();  //uart module power-on again

	//baud rate: 115200
	uart_init_baudrate(115200,CLOCK_SYS_CLOCK_HZ,PARITY_NONE, STOP_BIT_ONE);

	uart_dma_enable(1, 1); 	//uart data in hardware buffer moved by dma, so we need enable them first

	irq_enable_type(FLD_IRQ_DMA_EN);// uart_rx use dma_rx irq

	dma_chn_irq_enable(FLD_DMA_CHN_UART_RX, 1);   	//uart Rx dma irq enable

	uart_mask_tx_done_irq_enable();

	uart_mask_error_irq_enable();// open uart_error_mask,when stop bit error or parity error,it will enter error_interrupt.
	irq_enable_type(FLD_IRQ_UART_EN);// uart_tx use uart_txdone irq

	uart_dma_send_flag=1;
}

/**
 * @brief		this function is used to process tx uart data.
 * @param[in]	none
 * @return      0 is ok
 */
int user_uart_mainloop(void) {

	if(uart_tx_fifo.wptr == uart_tx_fifo.rptr){
		return 0;//have no data
	}
	if (!uart_dma_send_flag) {
		return 0;
	}
	u8 *p =  my_fifo_get(&uart_tx_fifo);
	memcpy(&txdata_buf.data, p + 4, ((u32 *)p)[0]);

	txdata_buf.len = ((u32 *)p)[0];

	uart_dma_send_flag=0;
	uart_send_dma((unsigned char*) (&txdata_buf));
	my_fifo_pop(&uart_tx_fifo);
	return 1;
}

s8 uart_printf(char *txdata,unsigned int len)
{
	u8 *p = my_fifo_wptr (&uart_tx_fifo);
	if (!p || (len+4) >= uart_tx_fifo.size)
	{
		return -1;
	}

	*p++ = len;
	*p++ = len >> 8;
	*p++ = len >> 16;
	*p++ = len >> 24;
	memcpy (p, (u8 *)txdata, len);

	my_fifo_next (&uart_tx_fifo);
	return 0;
}

#endif //end of (FEATURE_TEST_MODE == xxx)
