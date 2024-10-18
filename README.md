# V3.4.2.1 (PR)

### Version
* SDK version: tc_ble_simple_sdk V3.4.2.1
* Chip Version
  - TLSR8208 (B80) (A1/A4)
  - TLSR8208 B (B80B) (A0/A1)
* Hardware EVK Version
  - B80: C1T261A30_V1_1
  - B80B: C1T321A30_V1_0
* Platform Version
  - tc_platform_sdk V2.0.0
* Toolchain Version
  - TC32 ELF GCC4.3 ( IDE: [Telink IDE](https://wiki.telink-semi.cn/wiki/IDE-and-Tools/IDE-for-TLSR8-Chips/)/ [TelinkIoTStudio_V2024.8](https://wiki.telink-semi.cn/tools_and_sdk/Tools/IoTStudio/TelinkIoTStudio_V2024.8.zip) )

### Features
* N/A.

### Bug Fixes
* **PM**
   - Fixed: In the BLE connection state, when enabling the macro "SAVE_RAM_CODE_ENABLE", the local device may not trigger the system timer interrupt after waking up from SUSPEND sleep mode, leading to disconnection.

* **Controller**
   - Fixed: When the local device sets the ADV type as "ADV_TYPE_NONCONNECTABLE_UNDIRECTED", only the "ADV_NONCONN_IND" PDU at channel 37 can be sent successfully.
   - Fixed: In the BLE connection state, when the local device uses the Flash "GD25WD10EGIG", frequent write operations may cause the received packet MIC check failure, leading to disconnection.

* **ATT**
   - Fixed: ATT TX Buffer could overflow when the exchanged effective MTU size exceeds the default MTU size 23.

* **Link**
   - Fixed: The "data_reload" section is not aligned by 4 bytes, which may cause the data in the "data_reload" section to be accessed by mistake.

* **Others**
   - Fixed: (B80) When the external 24M crystal uses external capacitors, the MCU crashes.

### Refactoring
* **Link**
   - Clean the link warning "warning: dot moved backwards before '.text'".

* **Application**
   - Adjust the early wake-up tick for deepsleep retention mode.
   - Adjust the location of the definition of the structure "cur_conn_device".

* **Others**
   - Adjust the location of the following functions to save SRAM size.
      - otp_set_auto_mode_clk
      - otp_set_clk
      - otp_read_data

### BREAKING CHANGES
* N/A.

### Flash
* **8208**
   - GD25LD10C
   - GD25LD40C
   - ZG25WD40B
   - P25Q40SU
	- P25D09U
	- GD25WD10EGIG

* **8208B**
   - P25Q40SU
	- P25D09U
	- GD25WD10EGIG

### CodeSize
* **BLE Sample**
   * Flash
      - B80: 42.6k Byte
      - B80B: 41.6k Byte
   * RAM
      - B80: 13.9k Byte
      - B80B: 13.9k Byte
   * The values above are obtained using the default configuration.
   
   * Flash
      - B80: 41.7k Byte
      - B80B: 41.1k Byte
   * RAM
      - B80: 10.7k Byte
      - B80B: 10.7k Byte
   * The values above are obtained by calling APIs to save RAM and disabling deepsleep retention.

* **BLE Master**
   * Flash
      - B80: 30.7k Byte
      - B80B: 29.8k Byte
   * RAM
      - B80: 10.6k Byte
      - B80B: 10.7k Byte


### Version
* SDK 版本： tc_ble_simple_sdk V3.4.2.1
* Chip 版本
  - TLSR8208 (B80) (A1/A4)
  - TLSR8208 B (B80B) (A0/A1)
* Hardware EVK 版本
  - B80: C1T261A30_V1_1
  - B80B: C1T321A30_V1_0
* Platform 版本
  - tc_platform_sdk V2.0.0
* Toolchain 版本
  - TC32 ELF GCC4.3 ( IDE: [Telink IDE](https://wiki.telink-semi.cn/wiki/IDE-and-Tools/IDE-for-TLSR8-Chips/)/ [TelinkIoTStudio_V2024.8](https://wiki.telink-semi.cn/tools_and_sdk/Tools/IoTStudio/TelinkIoTStudio_V2024.8.zip) )

### Features
* N/A.

### Bug Fixes
* **PM**
   - 修复：BLE连接状态下，当使能宏“SAVE_RAM_CODE_ENABLE”时，本地设备从SUSPEND睡眠模式唤醒后可能不会触发system timer中断，导致连接断开。

* **Controller**
   - 修复：当本地设备设置广播类型为“ADV_TYPE_NONCONNECTABLE_UNDIRECTED”时，只有37通道的“ADV_NONCONN_IND”广播包可以成功发送。
   - 修复：BLE连接状态下，当本地设备使用Flash “GD25WD10EGIG”时，频繁的写操作可能会导致收到的包MIC校验错误而断开连接。

* **ATT**
   - 修复：当有效MTU值大于默认MTU值23时，ATT TX Buffer会溢出。

* **Link**
   - 修复：“data_reload”段没有4字节对齐，这可能导致“data_reload”段中的数据被误访问。

* **Others**
   - 修复：（B80）当外部24M晶振使用外部电容时，MCU会死机。

### Refactoring
* **Link**
   - 清理link警告“warning: dot moved backwards before '.text'”。

* **Application**
   - 调整从deepsleep retention模式的提前唤醒时间。
   - 调整结构体“cur_conn_device”定义的位置。

* **Others**
   - 调整以下函数的位置以节省SRAM空间。
      - otp_set_auto_mode_clk
      - otp_set_clk
      - otp_read_data

### BREAKING CHANGES
* N/A.

### Flash
* **8208**
   - GD25LD10C
   - GD25LD40C
   - ZG25WD40B
   - P25Q40SU
	- P25D09U
	- GD25WD10EGIG

* **8208B**
   - P25Q40SU
	- P25D09U
	- GD25WD10EGIG

### CodeSize
* **BLE Sample**
   * Flash
      - B80: 42.6k Byte
      - B80B: 41.6k Byte
   * RAM
      - B80: 13.9k Byte
      - B80B: 13.9k Byte
   * 以上大小使用默认配置得到
   
   * Flash
      - B80: 41.7k Byte
      - B80B: 41.1k Byte
   * RAM
      - B80: 10.7k Byte
      - B80B: 10.7k Byte
   * 以上大小是调用节省ram的API和关闭deepsleep retention后得到。

* **BLE Master**
   * Flash
      - B80: 30.7k Byte
      - B80: 29.8k Byte
   * RAM
      - B80: 10.6k Byte
      - B80B: 10.7k Byte



# V3.4.2.0 (PR)

### Version
* SDK version: tc_ble_simple_sdk V3.4.2.0
* Chip Version
  - TLSR8208 (B80) (A1/A4)
  - TLSR8208 B (B80B) (A0/A1)
* Hardware EVK Version
  - B80: C1T261A30_V1_1
  - B80B: C1T321A30_V1_0
* Platform Version
  - tc_platform_sdk V2.0.0
* Toolchain Version
  - TC32 ELF GCC4.3 ( IDE: [Telink IDE](https://wiki.telink-semi.cn/wiki/IDE-and-Tools/IDE-for-TLSR8-Chips/)/ [TelinkIoTStudio_V2024.6](https://wiki.telink-semi.cn/tools_and_sdk/Tools/IoTStudio/TelinkIoTStudio_V2024.6.zip) )

### Note
* Copyright update causes all files to change.

* Battery Voltage Check is a very important function for mass production. The user must check the battery voltage to prevent abnormal writing or erasing Flash at a low voltage.
	
* Flash protection is a critical function for mass production. 
	- Flash protection is enabled by default in SDK. User must enable this function on their final mass-production application.
	- Users should use the "Unlock" command in the Telink BDT tool for Flash access during the development and debugging phase.
	- Flash protection demonstration in SDK is a reference design based on sample code. Considering that the user's final application may be different from the sample code, for example, the user's final firmware size is bigger, or the user has a different OTA design, or the user needs to store more data in some other area of Flash, all these differences imply that Flash protection reference design in SDK can not be directly used on user's mass production application without any change. User should refer to sample code, understand the principles and methods, and then change and implement a more appropriate mechanism according to their application if needed.

* Correct some spelling errors
	- For example, change DT_INCOMPLT_LIST_16BIT_SERVICE_UUID to DT_INCOMPLETE_LIST_16BIT_SERVICE_UUID


### Bug Fixes
* **Controller**
   - Fixed: If the local device uses connectable directed advertising events with "TargetA" in "ADV_DIRECT_IND" packet set to an RPA(resolvable private address) that correctly matches the distributed IRK in the previous pairing stage, it can not be reconnected to the paired Central device which refreshes the RPA in "CONNECT_IND" packet. 

* **Application**
   - Fixed: If the peer device acting as the Central role uses a public address to pair with the local device acting as the Peripheral role, but uses an RPA(resolvable private address) that matches its distributed IRK to reconnect the local device, the local device can not correctly reconnect to the peer device.

* **SMP**
   - Fixed: Abnormal "PAIRING_FAIL_REASON_PAIRING_TIMEOUT" event may be reported to the application layer with a very low probability when reconnecting to the Central device. 

* **PM**
   - Fixed: When enabling the macro "SAVE_RAM_CODE_ENABLE", the MCU may not wake up properly with a very low probability at the end of sleep time.

* **Software Timer**
   - Fixed: Reorder the software timer under the condition that at least one timer exists after deleting one in the function "blt_soft_timer_delete".

* **Others**
   - Fixed: After the MCU wakes up from deep retention, the printing function is abnormal.
   - Fixed: The properties of the Device Name characteristic should not include "Notify".

### BREAKING CHANGES 
* **Boot & Link**	
	- Optimized and simplified the implementation of cstartup.S and boot. link.
		- Modify Cstartup_flash.S. This file is enough for all B80/B80B projects. The SRAM size is automatically set by judging MCU_STARTUP. 
        - Configure "SRAM_SIZE" for different ICs in the project setting.
          - B80 Uses the macro MCU_STARTUP_B80 to configure.
          - B80B Uses the macro MCU_STARTUP_B80B to configure.
   - Adjust some sections' positions.

* **Application**
	- BLE Flash information and Calibration
		- Rename blt_common.h/blt_common.c to ble_flash.h/ble_flash.c.
		- Split function "blc_app_loadCustomizedParameters" into two functions "blc_app_loadCustomizedParameters_normal"	and "blc_app_loadCustomizedParameters_deepRetn".
		The first one is used when the MCU is powered on or wakes up from deepsleep mode. The second one is used when MCU wakes up from deepsleep retention mode.
		- Add API "blc_flash_read_mid_get_vendor_set_capacity" in "blc_readFlashSize_autoConfigCustomFlashSector" to get Flash mid, vendor and capacity information.
   
* **Others** 
	- Correct some spelling errors.
	- Remove ext_pm.h and ext_rf.h, and the API open to users has been moved to ext_misc.h

### Features
* **Application**
	- Add Flash Protection module and sample 
		- Add flash_prot.h/flash_prot.c in vendor/common folder as a common module for all applications.
		- Add Flash protection sample code in project 8208_ble_sample. Users can refer to the sample code and make sure the Flash protection function is enabled on their application.
		- "app_flash_protection_operation" is a common entrance for all Flash operations (Flash write and erase), Flash locking and unlocking are processed in this function.
		- "blc_appRegisterStackFlashOperationCallback" and "flash_prot_op_cb" are used to process some stack internal Flash operation callback which may need Flash locking and unlocking.
		- The Telink OTA and SMP module already add callbacks related to blc_flashProt to inform the application layer that they need to write/erase Flash. Then, the application layer processes Flash lock and unlock.
		- If users do not use Telink OTAs, they need to refer to this design to add similar callback functions in their own OTA code for upper-layer use.
		- Now only firmware is protected in the sample code. System data and user data are not protected now.
		- The IRQ disabling time in the driver API "flash_write_status" is too long, and the BLE system interrupt will be delayed, causing RX data errors. Replace the driver API "flash_write_status" with "flash_write_status" in flash_prot.c, and call the LinkLayer API "blc_ll_write_flash_status" to solve this problem.
		- The Flash types supported are:
			- 8208:
      		- GD25LD10C
         	- GD25LD40C
         	- ZG25WD40B	(Not test)
         	- P25Q40SU
				- P25D09U
				- GD25WD10EGIG
			- 8208B:
         	- P25Q40SU
				- P25D09U
				- GD25WD10EGIG

	- Add stack initialization error check for all applications.
		- Add API "blc_contr_checkControllerInitialization" to check if any controller initialization fails.
		- Add API "blc_host_checkHostInitialization" to check if any host initialization fails.	
		- Add enumeration definition "init_err_t" in ble_common.h to distinguish error types. Users should add some UI alarm action to know whether an initialization error happens, and then check the reason according to the definition of enumeration "init_err_t".
		- Merge API "blc_controller_check_appBufferInitialization" to API "blc_contr_checkControllerInitialization", the users don't need to call "blc_controller_check_appBufferInitialization" again to check the parameters.

   - Add ble_master.

* **Feature Test**
   - Add the setting of MTU size in feature_gatt_security when enabling Secure Connection.
   - Add feature_md_master.
   - Add feature_DLE_master.

* **Controller**
	- Add macro "GET_RXADD_FROM_CONNECT_EVT_DATA" to get RX address type from the callback data of controller event "BLT_EV_FLAG_CONNECT".
	- Add API "blc_ll_scanReq_filter_en", which is used to set whether to filter the scanning device.
	- Add API “blc_ll_setAdvIntervalCheckEnable”, which is used to set whether to check the ADV interval setting.
	- Add API “bls_pm_getNexteventWakeupTick”, which is used to get the next wake-up tick。

* **GATT**
	- Add APIs:
		- blc_gatt_pushMultiHandleValueNotify is used to notify multiple characteristic values to the client.
		- blc_gatt_pushPrepareWriteRequest is used to send prepare write requests to the server.
		- blc_gatt_pushExecuteWriteRequest is used to send execute/cancel write requests to the server.
		- blc_gatt_pushConfirm is used to send confirm.
		- blc_gatt_pushReadMultiRequest is used to read multiple Characteristic Values from a server when the client knows the Characteristic Value Handles.
		- blc_gatt_pushReadMultiVariableRequest is used to read multiple variable lengths of Characteristic Values from a server when the client knows the Characteristic Value Handles.
		- blc_gatt_pushErrResponse is used to send ATT Error Response.

* **ATT**
	- Add API "blc_att_holdAttributeResponsePayloadDuringPairingPhase", which is used to set whether blocking ATT Response PDU in the pairing stage.
	- Add API "blc_att_enableReadReqReject", which is used to set whether the automatically sends the Error Response based on the returned value by the read callback.
	- Add API "blc_att_enableWriteReqReject", which is used to set the BLE stack whether the automatically sends the Error Response based on the returned value by the write callback.

* **SMP**
	- Add data structure definition "smp_param_master_t" corresponding to Central(Master) SMP pairing information Flash storage.   
	- Add API "blm_smp_getPairedDeviceNumber" only for the Central(Master) role to get the current paired device number.
	- Add API "blm_smp_loadParametersByIndex" only for the Central(Master) role to read pairing parameters by index.
	- Add API "blc_smp_enableSecureConnections” to enable Secure Connection.

* **OTA** 
	- Add API "blc_ota_getCurrentUsedMultipleBootAddress" to read the current used multiple boot addresses.

* **Privacy**	
	- Add API "blc_app_isIrkValid" to check if IRK(local IRK or peer IRK) stored in Flash is valid. 

* **Others**
	- Add mcu_config.h, including features supported by the MCU.
	- Add ext_calibration.c and ext_calibration.h to support ADC calibration, including VBAT calibration and GPIO calibration.

### Refactoring
* **Application**
	- Add app_common.h/app_common.c to process some common initialization or settings for all application projects.
		- Add API "blc_app_checkControllerHostInitialization" in app_common to check stack initialization error for the application project.
		- Add API "blc_app_isIrkValid" in app_common to check if local or peer IRK is valid, which can be used in the whitelist and resolving list of relevant applications.
	- Battery Check is moved to common, and the application only handles the relevant UI parts.
	- Add simple_sdp.h/simple_sdp.c to handle the common simple SDP of the central role.
	- Add custom_pair.h/custom_pair.c to handle the common custom pair of the central role.
   - Rename 8208_ble_sample to ble_sample.
   - Rename 8208_feature to feature_test.
   - Rename 8208_module to ble_module.

* **BLE General**
	- Add stack/ble/ble_comp.h for some API/macro/data structure names in the old SDK compatible with the new SDK.
	- Add stack initialization error check for all applications.

* **Feature Test**
	- Rename feature_slave_dle to feature_DLE_slave.
	- Rename feature_slave_md to feature_md_slave.
	- Remove feature_emi_test. If necessary, please refer to the platform SDK.

* **Controller**
	- Add stack/ble/ble_controller/controller.h. Put some controller-relevant enumeration and API declaration in this file.
	- Add callback data structure for some Telink-defined controller events.
		- "tlk_contr_evt_connect_t" is for "BLT_EV_FLAG_CONNECT".
		- "tlk_contr_evt_terminate_t" is for "BLT_EV_FLAG_TERMINATE".
		- "tlk_contr_evt_dataLenExg_t" is for "BLT_EV_FLAG_DATA_LENGTH_EXCHANGE".
		- "tlk_contr_evt_chnMapRequest_t" is for "BLT_EV_FLAG_CHN_MAP_REQ".
		- "tlk_contr_evt_chnMapUpdate_t" is for "BLT_EV_FLAG_CHN_MAP_UPDATE".
		- "tlk_contr_evt_connParaReq_t" is for "BLT_EV_FLAG_CONN_PARA_REQ".
		- "tlk_contr_evt_connParaUpdate_t" is for "BLT_EV_FLAG_CONN_PARA_UPDATE".
		- "tlk_contr_evt_versionIndRev_t" is for "BLT_EV_FLAG_VERSION_IND_REV".

* **SMP**
	- Add return value indicating initialization error for API "blc_smp_param_setBondingDeviceMaxNumber".
	- Move smp_alg.h to algorithm/crypto, and rename to crypto_alg.h.

* **ATT**
   - Add input parameter "connection handle" for API "blc_att_getEffectiveMtuSize".

* **Algorithm**
	- Adjust the file structure of the algorithm.

* **Others**
   - Rename drivers/ext_driver to drivers/driver_ext.
	- Adjust the file structure of the drivers/driver_ext.
   - Add the 4-byte alignment attribute for some structures.

### Performance Improvements
* **Application**
	- Move “blc_readFlashSize_autoConfigCustomFlashSector” and “blc_app_loadCustomizedParameters_normal” into “user_init_normal” to improve code efficiency.

### Known issues
* **Link**
	- The compile warning "warning: dot moved backwards before `.text'" is normal and unavoidable. This is caused by the order of defining the position of the sections in the .link file.

### Flash
* **8208**
   - GD25LD10C
   - GD25LD40C
   - ZG25WD40B	(Not test)
   - P25Q40SU
	- P25D09U
	- GD25WD10EGIG

* **8208B**
   - P25Q40SU
	- P25D09U
	- GD25WD10EGIG

### CodeSize
* **BLE Sample**
   * Flash
      - B80: 42.6k Byte
      - B80B: 41.6k Byte
   * RAM
      - B80: 13.8k Byte
      - B80B: 13.9k Byte
   * The values above are obtained using the default configuration.
   
   * Flash
      - B80: 41.5k Byte
      - B80B: 40.6k Byte
   * RAM
      - B80: 10.4k Byte
      - B80B: 10.5k Byte
   * The values above are obtained by calling APIs to save RAM and disabling deepsleep retention.

* **BLE Master**
   * Flash
      - B80: 30.7k Byte
      - B80B: 29.8k Byte
   * RAM
      - B80: 10.6k Byte
      - B80B: 10.7k Byte


### Version
* SDK 版本： tc_ble_simple_sdk V3.4.2.0
* Chip 版本
  - TLSR8208 (B80) (A1/A4)
  - TLSR8208 B (B80B) (A0/A1)
* Hardware EVK 版本
  - B80: C1T261A30_V1_1
  - B80B: C1T321A30_V1_0
* Platform 版本
  - tc_platform_sdk V2.0.0
* Toolchain 版本
  - TC32 ELF GCC4.3 ( IDE: [Telink IDE](https://wiki.telink-semi.cn/wiki/IDE-and-Tools/IDE-for-TLSR8-Chips/)/ [TelinkIoTStudio_V2024.6](https://wiki.telink-semi.cn/tools_and_sdk/Tools/IoTStudio/TelinkIoTStudio_V2024.6.zip) )

### Note
* Copyright更新，引起所有文件发生变化。

* 电池电压检测是量产的重要功能。
	- 用户必须检查电池电压，以防止在低电压下Flash写入或擦除异常。
	
* Flash保护是量产的必要功能。
	- SDK中默认开启Flash保护。用户必须在最终的量产应用中启用此功能。
	- 在开发和调试阶段，用户可以使用Telink BDT工具中的“Unlock”命令进行Flash解锁。
	- SDK中的Flash保护是基于示例代码的参考设计。考虑到用户的最终应用可能与示例代码不同，如用户的最终固件尺寸更大，或者用户有不同的OTA设计，或者用户需要在Flash的其他区域存储更多的数据，这些差异都意味着SDK中的Flash保护参考设计不可能在不做任何更改的情况下直接用于用户的量产应用。用户应参考示例代码，了解原理和方法，然后根据自己的应用更改和实现更适合的机制。

* 纠正一些拼写错误
	- 如修改DT_INCOMPLT_LIST_16BIT_SERVICE_UUID为DT_INCOMPLETE_LIST_16BIT_SERVICE_UUID。

### Bug Fixes
* **Controller**
   - 修复: 如果本端设备使用可连接的定向广播“ADV_DIRECT_IND”，其中的“TargetA”设置为与配对阶段IRK匹配的RPA（可解析私有地址），且已配对的对端设备更新了“CONNECT_IND”数据包中的RPA，可能会无法正常回连。

* **Application**
   - 修复:如果Central角色的对端设备使用Public地址与作为Peripheral角色的本端设备配对，但回连时其使用IRK生成的RPA重新连接本端设备，则本端设备会无法正确重新连接到对端设备。

* **SMP**
   - 修复：在回连时，极低概率下会有异常的“PAIRING_FAIL_REASON_PAIRING_TIMEOUT”事件上报。

* **PM**
   - 修复：当使能宏“SAVE_RAM_CODE_ENABLE”时，在睡眠时间结束时，极低概率下MCU可能不能正常唤醒。

* **Software Timer**
   - 修复：调用API "blt_soft_timer_delete"删除一个software timer任务后，在至少存在一个software timer任务的情况下，才对software timer任务重新排序。

* **Others**
   - 修复：当MCU从deep retention模式唤醒后，打印功能异常。
   - 修复：Device Name的属性中不应该包含“Notify”。

### BREAKING CHANGES 
* **Boot & Link**	
	- 优化cstartup. S和boot.link的实现。
      - 修改Cstartup_flash.S，这个文件适用于所有B80/B80B工程，SRAM大小通过判断MCU_STARTUP自动设置。
         - 根据不同芯片，在project setting中配置"SRAM_SIZE"
            - B80使用宏 MCU_STARTUP_B80 来配置芯片。
            - B80B使用宏 MCU_STARTUP_B80B 来配置芯片。
	- 调整一些段的位置。

* **Application**
	- 调整BLE Flash配置和校准
		- 将blt_common.h/blt_common.c重命名为ble_flash.h/ble_flash.c。
		- 将函数"blc_app_loadCustomizedParameters"拆分为两个函数"blc_app_loadCustomizedParameters_normal"和"blc_app_loadCustomizedParameters_deepRetn"。第一个是在MCU上电或从deepsleep模式唤醒时使用，第二个是当MCU从deepsleep retention模式唤醒时使用的。
		- 添加API “blc_flash_read_mid_get_vendor_set_capacity”以获取Flash mid、供应商和容量信息。

* **Others** 
	- 修复拼写错误
	- 移除ext_pm.h和ext_rf.h，对用户开放的API已移动到ext_misc.h

### Features
* **Application**
	- 新增Flash Protection模块和示例
		- 在vendor/common文件夹中添加flash_prot.h/flash_prot.c作为所有应用程序的通用模块。
		- 在8208_ble_sample中增加Flash保护示例代码，用户可以参考示例代码，并必须确保Flash保护功能在应用程序上启用。
		- “app_flash_protection_operation”是所有Flash操作(Flash写、擦除)的通用入口，Flash加锁和解锁都在这个函数中进行。
		- “blc_appRegisterStackFlashOperationCallback”和“flash_prot_op_cb”用于处理一些协议栈内部Flash操作的回调，这些回调可能需要Flash加锁和解锁。
			- 协议栈OTA模块已经正确增加blc_flashProt相关回调，告知应用层SMP需要write/erase Flash的操作。应用层需要对应处理Flash lock/unlock。
			- 如果客户不使用Telink OTA，需参考此设计在OTA代码中添加类似的回调函数供上层使用。
		- 现在只有固件在示例代码中受到保护，系统数据和用户数据现在不受保护。
		- 驱动API “flash_write_status”中中断禁用时间过长，BLE系统中断会延迟，导致接收数据错误。将驱动API “flash_write_status”替换为flash_prot.c中的“flash_write_status”，通过调用LinkLayer API “blc_ll_write_flash_status”来解决此问题。
      - 目前所支持的Flash型号为：
			- 8208:
      		- GD25LD10C
         	- GD25LD40C
         	- ZG25WD40B	(未测试)
         	- P25Q40SU
				- P25D09U
				- GD25WD10EGIG
			- 8208B:
         	- P25Q40SU
				- P25D09U
				- GD25WD10EGIG
	- 新增协议栈初始化错误检查
		- 新增API “blc_contr_checkControllerInitialization”检查是否有Controller初始化失败。
		- 新增API "blc_host_checkHostInitialization"检查是否有Host初始化失败。
		- 在ble_common.h中增加枚举定义“init_err_t”，区分错误类型。用户应添加UI报警动作来确认是否发生初始化错误，并根据“init_err_t”中的定义确定原因。
      - 将API “blc_controller_check_appBufferInitialization”合并到API “blc_contr_checkControllerInitialization”中，用户不需要再调用“blc_controller_check_appBufferInitialization”做参数检查。
	- 新增ble_master。

* **Feature Test**
   - 在feature_gatt_security中，当使能Secure Connection时，添加MTU size的设置。
   - 增加feature_md_master。
   - 增加feature_DLE_master。

* **Controller**
	- 新增宏“GET_RXADD_FROM_CONNECT_EVT_DATA”，从Controller事件“BLT_EV_FLAG_CONNECT”的回调数据中获取RX地址类型。	
	- 新增API “blc_ll_scanReq_filter_en”，用于设置发送Scan Request是否进行过滤。
	- 新增API “blc_ll_setAdvIntervalCheckEnable”，用于设置是否检查广播interval参数。
	- 新增API “bls_pm_getNexteventWakeupTick”，用于获取下次唤醒时间。

* **GATT**
	- 新增如下API：
		- blc_gatt_pushMultiHandleValueNotify用于支持向client端通知多个特征值。
		- blc_gatt_pushPrepareWriteRequest用于向server端发送Prepare Write命令。
		- blc_gatt_pushExecuteWriteRequest用于向server端发送执行/取消写操作的命令。
		- blc_gatt_pushConfirm用于发送Confirm。
		- blc_gatt_pushReadMultiRequest用于当client端知道特征值handle时，从server端读取多个特征值。
		- blc_gatt_pushReadMultiVariableRequest用于当client端知道特征值handle时，从server端读取多个可变长度的特征值。
		- blc_gatt_pushErrResponse用于发送Error Response。

* **ATT**
	- 新增API “blc_att_holdAttributeResponsePayloadDuringPairingPhase”用于设置在配对阶段是否阻塞ATT Response PDU。
	- 新增API “blc_att_enableReadReqReject”用于设置是否协议栈根据读回调返回值自动发送Error Response。
	- 新增API “blc_att_enableWriteReqReject”用于设置是否协议栈根据写回调返回值自动发送Error Response。

* **SMP**
	- 增加Central(master) SMP配对信息对应的结构体定义“smp_param_master_t”。
	- 新增API "blm_smp_getPairedDeviceNumber"用于Central(Master)设备获取当前配对的设备编号。
	- 新增API "blm_smp_loadParametersByIndex"用于Central(Master)设备读取配对参数的索引。
	- 新增API "blc_smp_enableSecureConnections”用于使能Secure Connection。

* **OTA** 
	- 添加API“blc_ota_getCurrentUsedMultipleBootAddress”读取当前使用的boot地址。

* **Privacy**	
	- 新增API "blc_app_isIrkValid"检查存在在Flash中的IRK（Local IRK或Peer IRK）是否可用。

* **Others**
	- 新增mcu_config.h，包含MCU对应的功能支持。
	- 新增ext_calibration.c和ext_calibration.h，支持ADC校准，包括VBAT校准和GPIO校准。

### Refactoring
* **Application**
	- 添加app_common.h/app_common.c，用于处理所有应用项目的一些通用功能。
		- 在app_common中增加API "blc_app_checkControllerHostInitialization"，用于检查应用项目的协议栈初始化错误。
		- 在app_common中增加API "blc_app_isIrkValid"来检查本地或对端IRK是否有效，可用于白名单和地址解析相关的应用。
	- Battery Check移动到common下，应用只处理UI相关的部分。
	- 添加simple_sdp.h/simple_sdp.c处理central端通用的simple sdp流程。
	- 添加custom_pair.h/custom_pair.c处理central端通用的custom pair流程。
   - 8208_ble_sample重命名为ble_sample。
   - 8208_feature重命名为feature_test。
   - 8208_module重命名为ble_module。

* **BLE General**
	- 新增stack/ble/ble_comp.h，用于新版本SDK兼容旧版本SDK中一些API/宏/结构体。
	- 为所有应用程序添加协议栈初始化错误检查。

* **Feature Test**
	- feature_slave_dle重命名为feature_DLE_slave
	- feature_slave_md重命名为feature_md_slave
	- 删除feature_emi_test。如果需要，请参考platform SDK。

* **Controller**
	- 新增stack/ble/ble_controller/controller.h。在这个文件中放入一些Controller相关的枚举和API声明。
	- 为一些Telink定义的Controller事件添加回调数据结构体：
		- "tlk_contr_evt_connect_t"对应"BLT_EV_FLAG_CONNECT"
		- "tlk_contr_evt_terminate_t"对应"BLT_EV_FLAG_TERMINATE"
		- "tlk_contr_evt_dataLenExg_t"对应"BLT_EV_FLAG_DATA_LENGTH_EXCHANGE"
		- "tlk_contr_evt_chnMapRequest_t"对应"BLT_EV_FLAG_CHN_MAP_REQ"
		- "tlk_contr_evt_chnMapUpdate_t"对应"BLT_EV_FLAG_CHN_MAP_UPDATE"
		- "tlk_contr_evt_connParaReq_t"对应"BLT_EV_FLAG_CONN_PARA_REQ"
		- "tlk_contr_evt_connParaUpdate_t"对应"BLT_EV_FLAG_CONN_PARA_UPDATE"
		- "tlk_contr_evt_versionIndRev_t"对应"BLT_EV_FLAG_VERSION_IND_REV"

* **SMP**
	- API “blc_smp_param_setBondingDeviceMaxNumber”新增初始化错误返回值。
   - 将smp_alg.h移动到algorithm/crypto中，并重命名为crypto_alg.h。

* **ATT**
   - 为API“blc_att_getEffectiveMtuSize”新增一个输入参数connection handle。

* **Algorithm**
	- 调整algorithm文件结构。

* **Others**
	- 将drivers/ext_driver重命名为drivers/driver_ext。
   - 调整drivers/driver_ext文件结构。
   - 在一些结构体中添加4字节对齐。

### Performance Improvements
* **Application**
   - “blc_readFlashSize_autoConfigCustomFlashSector”和“blc_app_loadCustomizedParameters_normal”移动到函数“user_init_normal”中调用，以提高代码效率。

### Known issues
* **Link**
   - 编译警告“warning: dot moved backwards before `.text'”是正常且无法避免的，这是由于在link文件中定义各个段的顺序导致的。

### Flash
* **8208**
   - GD25LD10C
   - GD25LD40C
   - ZG25WD40B	(Not test)
   - P25Q40SU
	- P25D09U
	- GD25WD10EGIG

* **8208B**
   - P25Q40SU
	- P25D09U
	- GD25WD10EGIG

### CodeSize
* **BLE Sample**
   * Flash
      - B80: 42.6k Byte
      - B80B: 41.6k Byte
   * RAM
      - B80: 13.8k Byte
      - B80B: 13.9k Byte
   * 以上大小使用默认配置得到
   
   * Flash
      - B80: 41.5k Byte
      - B80B: 40.6k Byte
   * RAM
      - B80: 10.4k Byte
      - B80B: 10.5k Byte
   * 以上大小时是调用节省ram的API和关闭deepsleep retention后得到。

* **BLE Master**
   * Flash
      - B80: 30.7k Byte
      - B80: 29.8k Byte
   * RAM
      - B80: 10.6k Byte
      - B80B: 10.7k Byte



## V3.4.1.2_Patch_0002

### Features
* N/A.

### Bug Fixes
* Fix an issue: ATT TX Buffer could overflow when the exchanged effective MTU size is greater than default MTU size 23.

### BREAKING CHANGES
* N/A.


### Features
* N/A.

### Bug Fixes
* 修复: 当有效MTU值大于默认MTU值23时，ATT TX Buffer会溢出。

### BREAKING CHANGES
* N/A.


## V3.4.1.2_Patch_0001

### Features
* SDK version：telink_b80_ble_single_connection_sdk_v3.4.1.2_patch_0001.
* Add a new API "blc_contr_setBluetoothVersion" for changing the default Bluetooth version to meet some customers' special requirements.
* Add a new API "blc_att_holdAttributeResponsePayloadDuringPairingPhase" for setting whether to hold the ATT Response PDU during the pairing phase 3 to meet some customer's special requirement.

### Bug Fixes
* Fix an issue: For 4 kinds of ATT client commands below, the ATT server responds with data split by default MTU size 23 rather than the exchanged effective MTU size:
   - "ATT_OP_READ_BY_GROUP_TYPE_REQ"
   - "ATT_OP_FIND_BY_TYPE_VALUE_REQ"
   - "ATT_OP_READ_BY_TYPE_REQ"
   - "ATT_OP_FIND_INFO_REQ"
* Fix an issue: Some special Central devices send the "LL_PAUSE_ENC_REQ" request at encryption procedure, and may trigger peripheral devices working at error flow with very low probability, leading to disconnection.
* Fix an issue: Add 24M RC oscillator calibration with periodic time to enhance the oscillation starting ability of 24M crystal waking up from sleep, improving the situation that some poorly performing crystals may encounter insufficient oscillation with low probability.

### BREAKING CHANGES
* N/A.


### Features
* SDK 版本: telink_b80_ble_single_connection_sdk_v3.4.1.2_patch_0001.
* 增加API blc_contr_setBluetoothVersion，用于更改默认蓝牙版本，以满足一些客户的特殊要求。
* 增加API blc_att_holdAttributeResponsePayloadDuringPairingPhase，用于设置是否在配对阶段暂停ATT的交互，以满足一些客户的特殊要求。

### Bug Fixes
* 修复: 对于以下4种ATT客户端命令，ATT服务器响应数据按默认MTU大小23来分割，而不是按交换的有效MTU大小分割：
   - “ATT_OP_READ_BY_GROUP_TYPE_REQ”
   - “ATT_OP_FIND_BY_TYPE_VALUE_REQ”
   - “ATT_OP_READ_BY_TYPE_REQ”
   - “ATT_OP_FIND_INFO_REQ”
* 修复: 一些特殊的Central设备在加密过程中发送“LL_PAUSE_ENC_REQ”请求，极低的概率可能会触发Peripheral设备工作错误，导致断开连接。
* 修复: 增加24M RC定时校准，提高睡眠唤醒后的晶体起振能力，改善一些较差性能晶体可能存在的低概率起振不充分问题。

### BREAKING CHANGES
* N/A.


# V3.4.1.2

### Features
   * Normalizes the naming of content related to private schemas
   
### BREAKING CHANGES
   * N/A

### CodeSize
   * Flash:
      - Disable deepsleep retention: 39.7k Byte
      - Enable deepsleep retention: 40.5k Byte
   * RAM:
      - Disable deepsleep retention: 12.5k Byte
      - Enable deepsleep retention: 13.7k Byte
   * The values above are obtained by compiling 8208_ble_sample with default configuration. 

   * Flash:
      - Disable deepsleep retention: 39.6k Byte
      - Enable deepsleep retention: 40.0k Byte
   * RAM:
      - Disable deepsleep retention: 10.5k Byte
      - Enable deepsleep retention: 11.2k Byte
   * The values above are obtained by compiling 8208_ble_sample with calling APIs of saving RAM
   
### Features
   * 规范化与私有模式相关内容的命名
   
### BREAKING CHANGES
   * N/A

### CodeSize
   * Flash:
      - 关闭deepsleep retention: 39.7k Byte
      - 打开deepsleep retention: 40.5k Byte
   * RAM:
      - 关闭deepsleep retention: 12.5k Byte
      - 打开deepsleep retention: 13.7k Byte
   * 以上大小使用默认配置编译8208_ble_sample得到

   * Flash:
      - 关闭deepsleep retention: 39.6k Byte
      - 打开deepsleep retention: 40.0k Byte
   * RAM:
      - 关闭deepsleep retention: 10.5k Byte
      - 打开deepsleep retention: 11.2k Byte
   * 以上大小时是调用节省ram的API后得到

## V3.4.1.1_Patch_0002

### Features
   * N/A

### BREAKING CHANGES
   * N/A
   
### Bug Fixes
   * Fix the bug that the value of T_IFS is inaccurate when 48M is used.
	
### CodeSize
   * Flash:
      - Disable deepsleep retention: 39.7k Byte
      - Enable deepsleep retention: 40.6k Byte
   * RAM:
      - Disable deepsleep retention: 12.4k Byte
      - Enable deepsleep retention: 13.7k Byte
   * The values above are obtained by compiling 8208_ble_sample with default configuration
   
   * Flash:
      - Disable deepsleep retention: 39.7k Byte
      - Enable deepsleep retention: 40.0k Byte
   * RAM:
      - Disable deepsleep retention: 10.4k Byte
      - Enable deepsleep retention: 11.2k Byte
   * The values above are obtained by compiling 8208_ble_sample with calling APIs of saving RAM
   
   
   
### Features
   * N/A

### BREAKING CHANGES
   * N/A
   
### Bug Fixes
   * 修复使用48M时T_IFS值不准确的问题。
	
### CodeSize
   * Flash:
      - 关闭deepsleep retention: 39.7k Byte
      - 打开deepsleep retention: 40.6k Byte
   * RAM:
      - 关闭deepsleep retention: 12.4k Byte
      - 打开deepsleep retention: 13.7k Byte
   * 以上大小使用默认配置编译8208_ble_sample得到

   * Flash:
      - 关闭deepsleep retention: 39.7k Byte
      - 打开deepsleep retention: 40.0k Byte
   * RAM:
      - 关闭deepsleep retention: 10.4k Byte
      - 打开deepsleep retention: 11.2k Byte
    * 以上大小使用调用节省RAM的API编译8208_ble_sample得到

## V3.4.1.1_Patch_0001

### Features
   * SDK version：telink_b80_ble_single_connection_sdk_v3.4.1.1_patch_0001
   * Add API which is used to set whether to continue current ADV_event when recieveing SACN_REQ
   * Add long sleep function

### BREAKING CHANGES
   * N/A
   
### Bug Fixes
   * Solve the problem of crystal oscillator stability flag failure
	
### CodeSize
   * Flash:
      - Disable deepsleep retention: 39.6k Byte
      - Enable deepsleep retention: 40.5k Byte
   * RAM:
      - Disable deepsleep retention: 12.4k Byte
      - Enable deepsleep retention: 13.7k Byte
   * The values above are obtained by compiling 8208_ble_sample with default configuration
   
   * Flash:
      - Disable deepsleep retention: 39.6k Byte
      - Enable deepsleep retention: 39.9k Byte
   * RAM:
      - Disable deepsleep retention: 10.4k Byte
      - Enable deepsleep retention: 11.2k Byte
   * The values above are obtained by compiling 8208_ble_sample with calling APIs of saving RAM
   
   
   
### Features
   * SDK 版本：telink_b80_ble_single_connection_sdk_v3.4.1.1_patch_0001
   * 增加API,当在广播事件里收到SCAN_REQ时，可以选择是否继续当前广播事件
   * 增加长睡眠函数

### BREAKING CHANGES
   * N/A
   
### Bug Fixes
   * 解决晶振起振失败的问题。
	
### CodeSize
   * Flash:
      - 关闭deepsleep retention: 39.6k Byte
      - 打开deepsleep retention: 40.5k Byte
   * RAM:
      - 关闭deepsleep retention: 12.4k Byte
      - 打开deepsleep retention: 13.7k Byte
   * 以上大小使用默认配置编译8208_ble_sample得到

   * Flash:
      - 关闭deepsleep retention: 39.6k Byte
      - 打开deepsleep retention: 39.9k Byte
   * RAM:
      - 关闭deepsleep retention: 10.4k Byte
      - 打开deepsleep retention: 11.2k Byte
    * 以上大小使用调用节省RAM的API编译8208_ble_sample得到
	

## V3.4.1.1

### Dependency Updates
   * telink_b85m_driver_sdk_V1.5.0
### Features
   * Support passive scanning in slave connection
   * Support passive scanning in advertising
   * Add APIs of saving RAM, but these APIs increase power consumption when called
   * Fix the issue that the pointer to packet is null when callback of BLT_EV_FLAG_CONNECT is triggered
   * Add Puya Flash
   * Add version information at the end of bin file.
   
### BREAKING CHANGES
   * N/A

### CodeSize
   * Flash:
      - Disable deepsleep retention: 39.4k Byte
      - Enable deepsleep retention: 40.3k Byte
   * RAM:
      - Disable deepsleep retention: 12.4k Byte
      - Enable deepsleep retention: 13.6k Byte
   * The values above are obtained by compiling 8208_ble_sample with default configuration. 

   * Flash:
      - Disable deepsleep retention: 39.3k Byte
      - Enable deepsleep retention: 39.7k Byte
   * RAM:
      - Disable deepsleep retention: 10.4k Byte
      - Enable deepsleep retention: 11.2k Byte
   * The values above are obtained by compiling 8208_ble_sample with calling APIs of saving RAM
### Dependency Updates
   * telink_b85m_driver_sdk_V1.5.0
### Features
   * 支持在连接中被动扫描
   * 支持在广播中被动扫描
   * 增加api来节省RAM，在调用时会增加平均功耗
   * 修复了触发BLT_EV_FLAG_CONNECT事件回调时指向数据包的指针为空的问题
   * 适配Puya Flash
   * bin文件末尾增加版本信息
   
### BREAKING CHANGES
   * N/A

### CodeSize
   * Flash:
      - 关闭deepsleep retention: 39.4k Byte
      - 打开deepsleep retention: 40.3k Byte
   * RAM:
      - 关闭deepsleep retention: 12.4k Byte
      - 打开deepsleep retention: 13.6k Byte
   * 以上大小使用默认配置编译8208_ble_sample得到

   * Flash:
      - 关闭deepsleep retention: 39.3k Byte
      - 打开deepsleep retention: 39.7k Byte
   * RAM:
      - 关闭deepsleep retention: 10.4k Byte
      - 打开deepsleep retention: 11.2k Byte
   * 以上大小时是调用节省ram的API后得到