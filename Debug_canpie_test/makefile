################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include source/li_can_slv/source/xload/subdir.mk
-include source/li_can_slv/source/util/subdir.mk
-include source/li_can_slv/source/sys/subdir.mk
-include source/li_can_slv/source/sync/subdir.mk
-include source/li_can_slv/source/error/subdir.mk
-include source/li_can_slv/source/core/subdir.mk
-include source/li_can_slv/source/config/subdir.mk
-include source/li_can_slv/source/arch/canpie_adapter/subdir.mk
-include source/li_can_slv/source/api/subdir.mk
-include source/io_app_ma_w/subdir.mk
-include source/io_app_conv/subdir.mk
-include source/canpie/source/canpie-fd/subdir.mk
-include source/canpie-fd_device/stm32/hal/subdir.mk
-include source/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

BUILD_ARTIFACT_NAME := li_can_slv_demo_stm32_nucleo_f103rb_canpie_test
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX := 
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME).$(BUILD_ARTIFACT_EXTENSION)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
li_can_slv_demo_stm32_nucleo_f103rb_canpie_test.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
li_can_slv_demo_stm32_nucleo_f103rb_canpie_test.list \

OBJCOPY_BIN += \
li_can_slv_demo_stm32_nucleo_f103rb_canpie_test.bin \


# All Target
all: main-build

# Main-build Target
main-build: li_can_slv_demo_stm32_nucleo_f103rb_canpie_test.elf secondary-outputs

# Tool invocations
li_can_slv_demo_stm32_nucleo_f103rb_canpie_test.elf: $(OBJS) $(USER_OBJS) C:\workdir\io8\li_can_slv_demo_stm32_nucleo_f103rb\STM32F103RBTX_FLASH.ld
	arm-none-eabi-gcc -o "li_can_slv_demo_stm32_nucleo_f103rb_canpie_test.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\workdir\io8\li_can_slv_demo_stm32_nucleo_f103rb\STM32F103RBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="li_can_slv_demo_stm32_nucleo_f103rb.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

li_can_slv_demo_stm32_nucleo_f103rb_canpie_test.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "li_can_slv_demo_stm32_nucleo_f103rb_canpie_test.list"
	@echo 'Finished building: $@'
	@echo ' '

li_can_slv_demo_stm32_nucleo_f103rb_canpie_test.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "li_can_slv_demo_stm32_nucleo_f103rb_canpie_test.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified
.SECONDARY:

-include ../makefile.targets
