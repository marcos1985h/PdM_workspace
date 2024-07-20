################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c 

OBJS += \
./Src/main.o 

C_DEPS += \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"/home/marcos/Documentos/PdM/PdM_workspace/Practica3/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/marcos/Documentos/PdM/PdM_workspace/Practica3/Drivers/CMSIS/Include" -I"/home/marcos/Documentos/PdM/PdM_workspace/Practica3/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/marcos/Documentos/PdM/PdM_workspace/Practica3/Drivers/BSP/STM32F4xx_Nucleo_144" -I"/home/marcos/Documentos/PdM/PdM_workspace/Practica3/Drivers/Core/Inc" -I"/home/marcos/Documentos/PdM/PdM_workspace/Practica3/Drivers/API/Inc" -I"/home/marcos/Documentos/PdM/PdM_workspace/Practica3/Drivers/API/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su

.PHONY: clean-Src

