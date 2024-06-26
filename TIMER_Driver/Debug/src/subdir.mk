################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/App_7.c \
../src/DIO_Program.c \
../src/EXTI_Program.c \
../src/GI_Program.c \
../src/LCD_Program.c \
../src/LED_Program.c \
../src/TIMERS_Program.c \
../src/WDT_Program.c 

OBJS += \
./src/App_7.o \
./src/DIO_Program.o \
./src/EXTI_Program.o \
./src/GI_Program.o \
./src/LCD_Program.o \
./src/LED_Program.o \
./src/TIMERS_Program.o \
./src/WDT_Program.o 

C_DEPS += \
./src/App_7.d \
./src/DIO_Program.d \
./src/EXTI_Program.d \
./src/GI_Program.d \
./src/LCD_Program.d \
./src/LED_Program.d \
./src/TIMERS_Program.d \
./src/WDT_Program.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


