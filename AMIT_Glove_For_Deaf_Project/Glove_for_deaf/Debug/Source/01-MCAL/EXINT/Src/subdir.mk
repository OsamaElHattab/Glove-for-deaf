################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/01-MCAL/EXINT/Src/ExInt.c 

OBJS += \
./Source/01-MCAL/EXINT/Src/ExInt.o 

C_DEPS += \
./Source/01-MCAL/EXINT/Src/ExInt.d 


# Each subdirectory must supply rules for building sources it contributes
Source/01-MCAL/EXINT/Src/%.o: ../Source/01-MCAL/EXINT/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Eclipse projects\AMIT_Glove_For_Deaf_Project\Glove_for_deaf\Source\02-ECUA\potentiometer\Inc" -I"D:\Eclipse projects\AMIT_Glove_For_Deaf_Project\Glove_for_deaf\Source\01-MCAL\ADC\Inc" -I"D:\Eclipse projects\AMIT_Glove_For_Deaf_Project\Glove_for_deaf\Source\01-MCAL\EXINT\Inc" -I"D:\Eclipse projects\AMIT_Glove_For_Deaf_Project\Glove_for_deaf\Source\01-MCAL\GINT\Inc" -I"D:\Eclipse projects\AMIT_Glove_For_Deaf_Project\Glove_for_deaf\Source\02-ECUA\LCD\Inc" -I"D:\Eclipse projects\AMIT_Glove_For_Deaf_Project\Glove_for_deaf\Source\00-Lib" -I"D:\Eclipse projects\AMIT_Glove_For_Deaf_Project\Glove_for_deaf\Source\01-MCAL\Dio\Inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


