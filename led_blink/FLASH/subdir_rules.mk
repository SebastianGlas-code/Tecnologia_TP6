################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-c29_2.0.0.STS/bin/c29clang.exe" -c -O1 -I"C:/ti/f29h85x-sdk_1_02_01_00/source" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/security" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/driverlib" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/calibration/hrpwm/include" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/bitfields" -I"C:/ti/f29h85x-sdk_1_02_01_00/examples/device_support/include" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/dcl" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/dcl/common" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/dcl/df" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/dcl/misc" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/dcl/pi" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/dcl/pid" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/dsp/fpu/fpu32/fft" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/dsp/fpu/fpu32/fir" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/dsp/fpu/fpu32/iir" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/fastmath/crc" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/fastmath/matrix" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/fastmath/binary_lut_search" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/iqmath" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/kernel/freertos/Source/include" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/kernel/freertos/Source/portable/CCS/C2000_C29x" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/flash_api/include/FlashAPI" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/kernel/dpl" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/pmic" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/sdl" -I"C:/Users/Silicium Lab/workspace_ccstheia/led_blink" -I"C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-c29_2.0.0.STS/include" -DDEBUG -D_FLASH -g -Qunused-arguments -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)" -I"C:/Users/Silicium Lab/workspace_ccstheia/led_blink/FLASH/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-958135361: ../led_ex1_blinky.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs2020/ccs/utils/sysconfig_1.25.0/sysconfig_cli.bat" --script "C:/Users/Silicium Lab/workspace_ccstheia/led_blink/led_ex1_blinky.syscfg" -o "syscfg" -s "C:/ti/f29h85x-sdk_1_02_01_00/.metadata/sdk.json" -b "/boards/LAUNCHXL_F29H85X" --context "CPU1" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-958135361 ../led_ex1_blinky.syscfg
syscfg/board.h: build-958135361
syscfg/board.cmd.genlibs: build-958135361
syscfg/peripheral_frame_mapping.h: build-958135361
syscfg/interrupt_list.txt: build-958135361
syscfg/errorevent_list.txt: build-958135361
syscfg/pinmux.csv: build-958135361
syscfg/device.c: build-958135361
syscfg/device.h: build-958135361
syscfg/ti_drivers_config.c: build-958135361
syscfg/ti_drivers_config.h: build-958135361
syscfg/clocktree.h: build-958135361
syscfg/ti_dpl_config.c: build-958135361
syscfg/ti_dpl_config.h: build-958135361
syscfg: build-958135361

syscfg/%.o: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-c29_2.0.0.STS/bin/c29clang.exe" -c -O1 -I"C:/ti/f29h85x-sdk_1_02_01_00/source" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/security" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/driverlib" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/calibration/hrpwm/include" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/bitfields" -I"C:/ti/f29h85x-sdk_1_02_01_00/examples/device_support/include" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/dcl" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/dcl/common" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/dcl/df" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/dcl/misc" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/dcl/pi" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/dcl/pid" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/dsp/fpu/fpu32/fft" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/dsp/fpu/fpu32/fir" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/dsp/fpu/fpu32/iir" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/fastmath/crc" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/fastmath/matrix" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/fastmath/binary_lut_search" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/rtlibs/iqmath" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/kernel/freertos/Source/include" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/kernel/freertos/Source/portable/CCS/C2000_C29x" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/flash_api/include/FlashAPI" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/kernel/dpl" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/pmic" -I"C:/ti/f29h85x-sdk_1_02_01_00/source/sdl" -I"C:/Users/Silicium Lab/workspace_ccstheia/led_blink" -I"C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-c29_2.0.0.STS/include" -DDEBUG -D_FLASH -g -Qunused-arguments -MMD -MP -MF"syscfg/$(basename $(<F)).d_raw" -MT"$(@)" -I"C:/Users/Silicium Lab/workspace_ccstheia/led_blink/FLASH/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


