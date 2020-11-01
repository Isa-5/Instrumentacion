################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/ADC0_driver.c" \
"../Sources/LPTMR_driver.c" \
"../Sources/UART_driverU.c" \
"../Sources/conversion_ADC.c" \
"../Sources/main.c" \
"../Sources/sa_mtb.c" \

C_SRCS += \
../Sources/ADC0_driver.c \
../Sources/LPTMR_driver.c \
../Sources/UART_driverU.c \
../Sources/conversion_ADC.c \
../Sources/main.c \
../Sources/sa_mtb.c \

OBJS += \
./Sources/ADC0_driver.o \
./Sources/LPTMR_driver.o \
./Sources/UART_driverU.o \
./Sources/conversion_ADC.o \
./Sources/main.o \
./Sources/sa_mtb.o \

C_DEPS += \
./Sources/ADC0_driver.d \
./Sources/LPTMR_driver.d \
./Sources/UART_driverU.d \
./Sources/conversion_ADC.d \
./Sources/main.d \
./Sources/sa_mtb.d \

OBJS_QUOTED += \
"./Sources/ADC0_driver.o" \
"./Sources/LPTMR_driver.o" \
"./Sources/UART_driverU.o" \
"./Sources/conversion_ADC.o" \
"./Sources/main.o" \
"./Sources/sa_mtb.o" \

C_DEPS_QUOTED += \
"./Sources/ADC0_driver.d" \
"./Sources/LPTMR_driver.d" \
"./Sources/UART_driverU.d" \
"./Sources/conversion_ADC.d" \
"./Sources/main.d" \
"./Sources/sa_mtb.d" \

OBJS_OS_FORMAT += \
./Sources/ADC0_driver.o \
./Sources/LPTMR_driver.o \
./Sources/UART_driverU.o \
./Sources/conversion_ADC.o \
./Sources/main.o \
./Sources/sa_mtb.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/ADC0_driver.o: ../Sources/ADC0_driver.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/ADC0_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/ADC0_driver.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/LPTMR_driver.o: ../Sources/LPTMR_driver.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/LPTMR_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/LPTMR_driver.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/UART_driverU.o: ../Sources/UART_driverU.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/UART_driverU.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/UART_driverU.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/conversion_ADC.o: ../Sources/conversion_ADC.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/conversion_ADC.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/conversion_ADC.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/sa_mtb.o: ../Sources/sa_mtb.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/sa_mtb.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/sa_mtb.o"
	@echo 'Finished building: $<'
	@echo ' '


