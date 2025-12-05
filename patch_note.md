## V3.4.2.2_Patch_0001
### Features

* **Flash**
  - (B80/B80B) Optimized flash_page_program() interface: previously only supported buffers located in RAM space; the current version now also supports buffers located in flash space.

### Bug Fixes

* **Link**
  * For B80/B80B
    - Fixed the misalignment of the data_reload section start address to a 4-byte boundary
      - Detailed Description: The starting address of the data_reload section is not forced to be aligned to 4 bytes. When the starting address of the data_reload section is not aligned to 4 bytes, it may cause abnormal data transfer in this section, potentially leading to issues such as ADC module initialization failure and abnormal initialization of printf PIN.
      - After Fix:  Optimized the data_reload section configuration to enforce a 4-byte aligned start address.
      - Update Recommendation: Mandatory update.

* **PLL**
  - For B80/B80B
    - Fixed the issue where under specific environmental conditions, a very small number of external crystals could cause the system to crash with an extremely low probability.
      - Detailed Description: In certain working environments, the stability of a very small number of external crystals may vary. The original PLL stability judgment mechanism could incorrectly determine that the crystal had reached full stability when it had not. If selected as the system clock source at that moment, there was an extremely low probability of causing system operation anomalies.
      - After Fix: Stricter stability criteria for the PLL have been implemented, enhancing system robustness.
      - Update Recommendation: Mandatory update.
* **OTA**
  - For B80/B80B
    - Fix the issue where the MCU fails to reboot normally when OTA times out.
      - Detailed Description: When the OTA update fails due to timeout, the MCU does not reboot automatically.
      - After Fix: The MCU will reboot normally after the OTA update fails due to timeout.
      - Update Recommendation: Recommended update.
* **PM**
  - For B80/B80B
    - Fixed the issue where pmParam.wakeup_src was not updated after waking from suspend, preventing the correct wake-up source from being retrieved.
      - Detailed Description: When the MCU was in suspend state, pmParam.wakeup_src was not updated after the MCU was woken up.
      - After Fix: After the MCU wakes from suspend, pmParam.wakeup_src is now correctly updated with the wake-up source information.
      - Update Recommendation: Evaluate if needed.
* **ATT**
  - For B80/B80B
    - Fix the issue where ATT_ERROR_RSP is not responded normally due to incorrect permission judgment during the ATT service process.
      - Detailed Description: When the ATT client sends an ATT request packet to the ATT server, if there is insufficient permission at this time, the ATT server should respond with an ATT_ERROR_RSP. However, due to an underlying logic error, the ATT_ERROR_RSP fails to be sent normally, resulting in an abnormality in the ATT process.
      - After Fix: ATT_ERROR_RSP is now sent correctly in such scenarios.
      - Update Recommendation: Evaluate if needed.
* **USB**
  - For B80/B80B
    - Fix the issue where USB failed to detect the sleep state of the USB Host.
      - Detailed Description: When PM was enabled and BLE remained in a connected state, the USB module could not detect if the USB Host (e.g., a PC) entered sleep mode.
      - After Fix: The USB will detect the PC's sleep state if the PC enters sleep mode.
      - Update Recommendation: Evaluate if needed.
* **SCAN IN ADV**
  - For B80/B80B
    - Fixed the issue where the RF state machine did not terminate the scanning process as expected after disabling advertising with the Scan in ADV feature enabled.
      - Detailed Description: When advertising was disabled while the Scan in ADV feature was active, the RF state machine incorrectly remained in the Scanning state.
      - After Fix: After disabling advertising will correctly transition the RF state machine back to the IDLE state.
      - Update Recommendation: Evaluate if needed.
* **ADV**
  - For B80/B80B
    - Fixed the issue where the BLE slave 2.4G dual-mode reference design could not properly transmit BLE advertisements when using a special custom_made library.
      - Detailed Description: When using a special custom_made library and the ble_slave_2_4g dual-mode reference design, BLE advertisements cannot be transmitted normally when the 2.4G mode is enabled.
      - After Fix: BLE advertisements are now correctly transmitted in the same scenario.
      - Update Recommendation: Evaluate if needed.

### Build Fixes and Improvements

* **PA**
  - (B80/B80B) Merged rf_pa.c and rf_private_pa.c source files, resolving function redefinition errors that occurred when the PA_ENABLE macro was enabled.
* **UART**
  - (B80B) Resolved compilation issues caused by UART initialization in the ble_module when the PM_DEEPSLEEP_RETENTION_ENABLE feature was enabled.

### Refactor

* **APP**
  - (B80/B80B) In the ble_slave_2_4g reference design, 2.4GHz communication is temporarily suspended during BLE OTA firmware upgrades to reduce the upgrade time.

### BREAKING CHANGES
* **PLL**
   - (B80/B80B) Customers cannot use the bit that uses the DEEP_ANA_REG0[bit2] (0x3a[2]) flag to indicate whether a restart caused by a PLL exception occurred.



### Features

* **Flash**
  - （B80/B80B）优化flash_page_program()接口之前只支持传入的buff指向ram空间，目前的版本也支持指向flash空间。

### Bug Fixes

* **Link**
  - For B80/B80B
    - 修复data_reload段首地址有概率没有4字节对齐的问题。
      - 详细描述：data_reload段首地址没有强制4字节对齐，当 data_reload 段首地址未满足 4 字节对齐时，会导致该段数据搬移异常，进而可能引发 ADC 模块初始化失败、printf PIN无法正常初始化的问题。
      - 修复效果：优化 data_reload 段配置，确保其首地址强制满足 4 字节对齐要求。
      - 更新建议：必须更新。

* **PLL**
  - For B80/B80B
    - 修复极少数外部晶振在特定环境条件下，可能导致系统极低概率死机的问题。
      - 详细描述：在特定工作环境下，极少数外部晶振的稳定性可能存在差异，原PLL稳定性判断机制可能在晶振尚未达到完全稳态时判定为稳态，若此时将其选为系统时钟源，将存在极低概率引发系统运行异常。
      - 修复效果：提高PLL的稳定性的判断标准，提升系统鲁棒性。
      - 更新建议：必须更新。
* **OTA**
  - For B80/B80B
    - 修复 OTA 超时情况下 MCU 无法正常重启的问题。
      - 详细描述：当 OTA 更新因超时导致失败时，MCU 不会自动重启。
      - 修复效果：OTA 更新因超时导致失败后，MCU 将正常重启。
      - 更新建议：建议更新。
* **PM**
  - For B80/B80B
    - 修复pmParam.wakeup_src在suspend被唤醒后未被更新，导致无法获取唤醒源的问题。
      - 详细描述：MCU处于suspend状态时，pmParam.wakeup_src未在MCU被唤醒后更新。
      - 修复效果：MCU从suspend状态唤醒后，pmParam.wakeup_src能正确更新唤醒源信息。
      - 更新建议：自行评估。
* **ATT**
  - For B80/B80B
    - 修复 ATT 服务过程中的权限判断错误时未正常回复 ATT_ERROR_RSP。
      - 详细描述：当 ATT client 端对 ATT server 端发送 ATT request 包时，如果此时权限不足，ATT server 端应该回复ATT_ERROR_RSP，但由于底层逻辑错误，会导致 ATT_ERROR_RSP 无法正常发出，ATT流程异常。
      - 修复效果：可正常回复 ATT_ERROR_RSP。
      - 更新建议：自行评估。
* **USB**
  - For B80/B80B
    - 修复 USB 无法检测 USB Host 睡眠状态的问题。
      - 详细描述：当开启 PM 且 BLE 处于连接状态时，若 USB Host(如PC) 进入睡眠模式，USB 将无法检测到 USB Host 的睡眠状态。
      - 修复效果：当 PC 进入睡眠模式时，USB 将能检测到 USB Host 的睡眠状态。
      - 更新建议：自行评估。
* **SCAN IN ADV**
  - For B80/B80B
    - 修复开启 Scan in ADV 功能后，关闭广播时 RF 状态机未按预期终止scan流程。
      - 详细描述：在Scan in ADV状态下，关闭广播后，RF 状态机错误地维持在 Scanning 状态。
      - 修复效果：修复后，关闭广播时 RF 状态机将正确返回 IDLE 状态。
      - 更新建议：自行评估。
* **ADV**
  - For B80/B80B
    - 修复了使用特殊的custom_made的库时，ble_slave_2_4g双模参考设计无法正常发出BLE广播的问题。
      - 详细说明：使用特殊的custom_made的库，且使用ble_slave_2_4g双模参考设计时，在使能2.4G模式时，BLE广播无法正常发出。
      - 修复后：在相同场景下，BLE 广播可正常发出。
      - 修复建议：自行评估。

### Build Fixes and Improvements

* **PA**
  - （B80/B80B）合并 rf_pa.c 与 rf_private_pa.c 源文件，解决了在启用 PA_ENABLE 宏时出现的函数重复定义问题。
* **UART**
  - （B80B）解决了启用 PM_DEEPSLEEP_RETENTION_ENABLE 功能后，ble_module 中 UART 初始化引起的编译问题。

### Refactor

* **APP**
  - （B80/B80B）在 ble_slave_2_4g 参考设计中，使用BLE进行OTA期间将暂停2.4GHz通信，缩短固件升级时间。

### BREAKING CHANGES
* **PLL**
   - （B80/B80B）占用DEEP_ANA_REG0[bit2]（0x3a[2]）标志是否发生过PLL异常导致的重启，客户不能使用这个bit。
