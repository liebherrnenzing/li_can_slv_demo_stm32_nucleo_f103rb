################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/li_can_slv/source/arch/canpie_adapter/io_can_async_hw.c \
../source/li_can_slv/source/arch/canpie_adapter/io_can_hw.c \
../source/li_can_slv/source/arch/canpie_adapter/io_can_main_hw.c \
../source/li_can_slv/source/arch/canpie_adapter/io_can_main_hw_handler.c 

OBJS += \
./source/li_can_slv/source/arch/canpie_adapter/io_can_async_hw.o \
./source/li_can_slv/source/arch/canpie_adapter/io_can_hw.o \
./source/li_can_slv/source/arch/canpie_adapter/io_can_main_hw.o \
./source/li_can_slv/source/arch/canpie_adapter/io_can_main_hw_handler.o 

C_DEPS += \
./source/li_can_slv/source/arch/canpie_adapter/io_can_async_hw.d \
./source/li_can_slv/source/arch/canpie_adapter/io_can_hw.d \
./source/li_can_slv/source/arch/canpie_adapter/io_can_main_hw.d \
./source/li_can_slv/source/arch/canpie_adapter/io_can_main_hw_handler.d 


# Each subdirectory must supply rules for building sources it contributes
source/li_can_slv/source/arch/canpie_adapter/io_can_async_hw.o: ../source/li_can_slv/source/arch/canpie_adapter/io_can_async_hw.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../source/io_app_ma_w -I../include/li_can_slv_hw -I../include -I../source/canpie-fd_device/stm32/f1/hal -I../source/li_can_slv/include/li_can_slv/arch/canpie_adapter -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../source/li_can_slv/include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../source/io_app_conv -I"../source/canpie/source/canpie-fd" -I../source/canpie/source/misc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"source/li_can_slv/source/arch/canpie_adapter/io_can_async_hw.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
source/li_can_slv/source/arch/canpie_adapter/io_can_hw.o: ../source/li_can_slv/source/arch/canpie_adapter/io_can_hw.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../source/io_app_ma_w -I../include/li_can_slv_hw -I../include -I../source/canpie-fd_device/stm32/f1/hal -I../source/li_can_slv/include/li_can_slv/arch/canpie_adapter -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../source/li_can_slv/include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../source/io_app_conv -I"../source/canpie/source/canpie-fd" -I../source/canpie/source/misc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"source/li_can_slv/source/arch/canpie_adapter/io_can_hw.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
source/li_can_slv/source/arch/canpie_adapter/io_can_main_hw.o: ../source/li_can_slv/source/arch/canpie_adapter/io_can_main_hw.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../source/io_app_ma_w -I../include/li_can_slv_hw -I../include -I../source/canpie-fd_device/stm32/f1/hal -I../source/li_can_slv/include/li_can_slv/arch/canpie_adapter -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../source/li_can_slv/include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../source/io_app_conv -I"../source/canpie/source/canpie-fd" -I../source/canpie/source/misc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"source/li_can_slv/source/arch/canpie_adapter/io_can_main_hw.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
source/li_can_slv/source/arch/canpie_adapter/io_can_main_hw_handler.o: ../source/li_can_slv/source/arch/canpie_adapter/io_can_main_hw_handler.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../source/io_app_ma_w -I../include/li_can_slv_hw -I../include -I../source/canpie-fd_device/stm32/f1/hal -I../source/li_can_slv/include/li_can_slv/arch/canpie_adapter -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../source/li_can_slv/include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../source/io_app_conv -I"../source/canpie/source/canpie-fd" -I../source/canpie/source/misc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"source/li_can_slv/source/arch/canpie_adapter/io_can_main_hw_handler.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

