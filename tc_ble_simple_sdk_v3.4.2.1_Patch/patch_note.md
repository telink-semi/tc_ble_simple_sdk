## V3.4.2.1_Patch_0001
### Features
* N/A.

### Bug Fixes
* **PM**
  - For B80/B80B
    - Fix the issue where pmParam.wakeup_src was not updated after the suspend was wakeuped.
      - Detailed Description: When the MCU is in the suspend state, the pmParam.wakeup_src is not updated after the MCU is wakeuped.
      - After Fix: The pmParam.wakeup_src is updated after the MCU is wakeuped from suspend state.
      - Update Recommendation: Evaluate if needed.

* **ATT**
  - For B80/B80B
    - Fix handling of invalid ATT_FIND_INFORMATION_REQ parameter. When the peripheral device receives ATT_FIND_INFORMATION_REQ that the start handle is zero or the start handle exceeds the end handle, the ATT server needs to send ATT_ERROR_RSP, rather than sending an invalid ATT_FIND_INFORMATION_RSP packet.
      - Detailed Description: when receive ATT_FIND_INFORMATION_REQ that start handle is zero or start handle exceeds to end handle, the ATT server will send an invaluable packet that the opcode is error.
      - After Fix: when receive ATT_FIND_INFORMATION_REQ that start handle is zero or start handle exceeds to end handle, the ATT server will send ATT_ERROR_RSP.
      - Update Recommendation: Evaluate if needed.

    - Fix the issue where ATT_ERROR_RSP is not responded normally due to incorrect permission judgment during the ATT service process.
      - Detailed Description: When the ATT Central sends an ATT request packet to the ATT peripheral, if there is insufficient permission at this time, the ATT peripheral should respond with an ATT_ERROR_RSP. However, due to an underlying logic error, the ATT_ERROR_RSP fails to be sent normally, resulting in an abnormality in the ATT process.
      - After Fix: ATT_ERROR_RSP can be responded normally.
      - Update Recommendation: Evaluate if needed.

* **OTA**
  - For B80/B80B
    - Fix the issue where the MCU fails to reboot normally when OTA times out.
      - Detailed Description: When the OTA update fails due to timeout, the MCU does not reboot automatically.
      - After Fix: The MCU will reboot normally after the OTA update fails due to timeout.
      - Update Recommendation: Evaluate if needed.

* **USB**
  - For B80/B80B
    - Fix the issue where USB fails to detect the PC's sleep state.
      - Detailed Description: When PM is enabled and the BLE is in the connection state, the USB will fail to detect the PC's sleep state if the PC enters sleep mode.
      - After Fix: The USB will detect the PC's sleep state if the PC enters sleep mode.
      - Update Recommendation: Evaluate if needed.

### BREAKING CHANGES
* **PLL**
   - (B80/B80B) Customers cannot use the bit that uses the DEEP_ANA_REG0[bit2] (0x3a[2]) flag to indicate whether a restart caused by a PLL exception occurred.
   - (B80/B80B) The criteria for determining the stability of the PLL have become more stringent. Previously, it was considered passed if detected once; now, it is only considered passed if it is detected three times consecutively.

* **flash** 
   - (B80/B80B) Fix data access error in flash write API when passed in a const buffer pointer.

### Features
* N/A.

### Bug Fixes
* **PM**
  - For B80/B80B
    - 修复pmParam.wakeup_src在suspend被唤醒后未被更新的问题。
      - 详细描述：MCU处于suspend状态时，pmParam.wakeup_src未在MCU被唤醒后更新。
      - 修复效果：MCU从suspend状态唤醒后，pmParam.wakeup_src将被更新。
      - 更新建议：自行评估。

* **ATT**
  - For B80/B80B
    - 修复对无效 ATT_FIND_INFORMATION_REQ 请求参数的处理，当peripheral设备接收到的 ATT_FIND_INFORMATION_REQ 的开始句柄为零或开始句柄超过结束句柄时，应当回复 ATT_ERROR_RSP，而不是发送一个无效的ATT_FIND_INFORMATION_RSP 报文。
      - 详细描述：当接收到 ATT_FIND_INFORMATION_REQ 且起始句柄为零或起始句柄超出结束句柄范围时，ATT 服务器将发送一个opcode错误的数据包。
      - 修复效果：当接收到 ATT_FIND_INFORMATION_REQ 且起始句柄为零或起始句柄超出结束句柄范围时，ATT 服务器将发送“ATT_ERROR_RSP”。
      - 更新建议：自行评估。

    - 修复 ATT 服务过程中的权限判断错误时未正常回复 ATT_ERROR_RSP。
      - 详细描述：当ATT Central端对ATT peripheral 端发送ATT request包时，如果此时权限不足，ATT peripheral 端应该回复ATT_ERROR_RSP，但由于底层逻辑错误，会导致 ATT_ERROR_RSP 无法正常发出，ATT流程异常。
      - 修复效果：可正常回复 ATT_ERROR_RSP。
      - 更新建议：自行评估。

* **OTA**
  - For B80/B80B
    - 修复 OTA 超时情况下 MCU 无法正常重启的问题。
      - 详细描述：当 OTA 更新因超时导致失败时，MCU 不会自动重启。
      - 修复效果：OTA 更新因超时导致失败后，MCU 将正常重启。
      - 更新建议：自行评估。

* **USB**
  - For B80/B80B
    - 修复 USB 无法检测 PC 睡眠状态的问题。
      - 详细描述：当开启 PM 且 BLE 处于连接状态时，若 PC 进入睡眠模式，USB 将无法检测到 PC 的睡眠状态。
      - 修复效果：当 PC 进入睡眠模式时，USB 将能检测到 PC 的睡眠状态。
      - 更新建议：自行评估。

### BREAKING CHANGES
* **PLL**
   - （B80/B80B）占用DEEP_ANA_REG0[bit2]（0x3a[2]）标志是否发生过PLL异常导致的重启，客户不能使用这个bit。
   - （B80/B80B）判断PLL稳定的标志位的标准更加严格，以前检测到一次就通过，改为连续三次检测到才算通过。

* **flash** 
   - （B80/B80B）解决了写flash API在传入常量buffer指针时的数据访问出错的问题。
