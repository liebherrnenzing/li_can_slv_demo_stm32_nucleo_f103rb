################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/io_app_conv/io_app_convc.c 

OBJS += \
./source/io_app_conv/io_app_convc.o 

C_DEPS += \
./source/io_app_conv/io_app_convc.d 


# Each subdirectory must supply rules for building sources it contributes
source/io_app_conv/io_app_convc.o: ../source/io_app_conv/io_app_convc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../source/io_app_ma_w -I../include/li_can_slv_hw -I../include -I../source/canpie-fd_device/stm32/f1/hal -I../source/li_can_slv/include/li_can_slv/arch/canpie_adapter -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../source/li_can_slv/include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../source/io_app_conv -I"../source/canpie/source/canpie-fd" -I../source/canpie/source/misc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"source/io_app_conv/io_app_convc.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

