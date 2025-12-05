/********************************************************************************************************
 * @file    rf_pa.c
 *
 * @brief   This is the source file for BLE SDK
 *
 * @author  BLE GROUP
 * @date    06,2022
 *
 * @par     Copyright (c) 2022, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
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
 *
 *******************************************************************************************************/
#include "compiler.h"
#include "rf_pa.h"
#include "../gpio.h"
#include "../../stack/2_4g/genfsk_ll/genfsk_ll.h"

_attribute_data_retention_	rf_pa_callback_t  blc_rf_pa_cb = 0;

#if(PA_ENABLE)
//_attribute_ram_code_
void app_rf_pa_handler(int type)
{

	if(type == PA_TYPE_TX_ON){
	    gpio_write(PA_RXEN_PIN, 0);
	    gpio_write(PA_TXEN_PIN, 1);
	}
	else if(type == PA_TYPE_RX_ON){
	    gpio_write(PA_TXEN_PIN, 0);
	    gpio_write(PA_RXEN_PIN, 1);
	}
	else{
	    gpio_write(PA_RXEN_PIN, 0);
	    gpio_write(PA_TXEN_PIN, 0);
	}
}

/**
 * @brief	RF software PA initialization
 * @param	none
 * @return	none
 */
void rf_pa_init(void)
{
    gpio_set_func(PA_TXEN_PIN, AS_GPIO);
    gpio_set_output_en(PA_TXEN_PIN, 1);
    gpio_write(PA_TXEN_PIN, 0);

    gpio_set_func(PA_RXEN_PIN, AS_GPIO);
    gpio_set_output_en(PA_RXEN_PIN, 1);
    gpio_write(PA_RXEN_PIN, 0);

    blc_rf_pa_cb = app_rf_pa_handler;
}

/**
 * @brief   rf pa handler
 * @param   rf irq event
 * @return  none
 */
_attribute_ram_code_sec_ void rf_pa_handler(rf_irq_e flag)
{

    if (!blc_rf_pa_cb)
        return;

    switch(flag){
    case FLD_RF_IRQ_TX:
                if (gen_fsk_current_mode == GEN_FSK_MD_STX || gen_fsk_current_mode == GEN_FSK_MD_SRX2TX)
                {
                    blc_rf_pa_cb(PA_TYPE_OFF);
                }
                else if (gen_fsk_current_mode == GEN_FSK_MD_STX2RX)
                {
                    blc_rf_pa_cb(PA_TYPE_RX_ON);
                }
                break;
    case FLD_RF_IRQ_RX:
                if(gen_fsk_current_mode == GEN_FSK_MD_SRX || gen_fsk_current_mode == GEN_FSK_MD_STX2RX)
                {
                    blc_rf_pa_cb(PA_TYPE_OFF);
                }
                if (gen_fsk_current_mode == GEN_FSK_MD_SRX2TX )
                {
                    blc_rf_pa_cb(PA_TYPE_TX_ON);
                }
                break;
    case FLD_RF_IRQ_FIRST_TIMEOUT:
                if (gen_fsk_current_mode == GEN_FSK_MD_SRX)
                {
                    blc_rf_pa_cb(PA_TYPE_OFF);
                }
                break;
    case FLD_RF_IRQ_RX_TIMEOUT:
                if (gen_fsk_current_mode == GEN_FSK_MD_STX2RX)
                {
                    blc_rf_pa_cb(PA_TYPE_OFF);
                }
                break;
    default:
        break;
}


}
#endif
