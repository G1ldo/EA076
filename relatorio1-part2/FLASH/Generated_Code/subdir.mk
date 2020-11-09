################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/ASerialLdd1.c" \
"../Generated_Code/ASerialLdd2.c" \
"../Generated_Code/BLUE.c" \
"../Generated_Code/BitIoLdd1.c" \
"../Generated_Code/BitIoLdd2.c" \
"../Generated_Code/BitIoLdd3.c" \
"../Generated_Code/Cpu.c" \
"../Generated_Code/ESP.c" \
"../Generated_Code/GREEN.c" \
"../Generated_Code/LEDpin1.c" \
"../Generated_Code/LEDpin2.c" \
"../Generated_Code/LEDpin3.c" \
"../Generated_Code/MCUC1.c" \
"../Generated_Code/PC.c" \
"../Generated_Code/PE_LDD.c" \
"../Generated_Code/RED.c" \
"../Generated_Code/UTIL.c" \
"../Generated_Code/Vectors.c" \

C_SRCS += \
../Generated_Code/ASerialLdd1.c \
../Generated_Code/ASerialLdd2.c \
../Generated_Code/BLUE.c \
../Generated_Code/BitIoLdd1.c \
../Generated_Code/BitIoLdd2.c \
../Generated_Code/BitIoLdd3.c \
../Generated_Code/Cpu.c \
../Generated_Code/ESP.c \
../Generated_Code/GREEN.c \
../Generated_Code/LEDpin1.c \
../Generated_Code/LEDpin2.c \
../Generated_Code/LEDpin3.c \
../Generated_Code/MCUC1.c \
../Generated_Code/PC.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/RED.c \
../Generated_Code/UTIL.c \
../Generated_Code/Vectors.c \

OBJS += \
./Generated_Code/ASerialLdd1.o \
./Generated_Code/ASerialLdd2.o \
./Generated_Code/BLUE.o \
./Generated_Code/BitIoLdd1.o \
./Generated_Code/BitIoLdd2.o \
./Generated_Code/BitIoLdd3.o \
./Generated_Code/Cpu.o \
./Generated_Code/ESP.o \
./Generated_Code/GREEN.o \
./Generated_Code/LEDpin1.o \
./Generated_Code/LEDpin2.o \
./Generated_Code/LEDpin3.o \
./Generated_Code/MCUC1.o \
./Generated_Code/PC.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/RED.o \
./Generated_Code/UTIL.o \
./Generated_Code/Vectors.o \

C_DEPS += \
./Generated_Code/ASerialLdd1.d \
./Generated_Code/ASerialLdd2.d \
./Generated_Code/BLUE.d \
./Generated_Code/BitIoLdd1.d \
./Generated_Code/BitIoLdd2.d \
./Generated_Code/BitIoLdd3.d \
./Generated_Code/Cpu.d \
./Generated_Code/ESP.d \
./Generated_Code/GREEN.d \
./Generated_Code/LEDpin1.d \
./Generated_Code/LEDpin2.d \
./Generated_Code/LEDpin3.d \
./Generated_Code/MCUC1.d \
./Generated_Code/PC.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/RED.d \
./Generated_Code/UTIL.d \
./Generated_Code/Vectors.d \

OBJS_QUOTED += \
"./Generated_Code/ASerialLdd1.o" \
"./Generated_Code/ASerialLdd2.o" \
"./Generated_Code/BLUE.o" \
"./Generated_Code/BitIoLdd1.o" \
"./Generated_Code/BitIoLdd2.o" \
"./Generated_Code/BitIoLdd3.o" \
"./Generated_Code/Cpu.o" \
"./Generated_Code/ESP.o" \
"./Generated_Code/GREEN.o" \
"./Generated_Code/LEDpin1.o" \
"./Generated_Code/LEDpin2.o" \
"./Generated_Code/LEDpin3.o" \
"./Generated_Code/MCUC1.o" \
"./Generated_Code/PC.o" \
"./Generated_Code/PE_LDD.o" \
"./Generated_Code/RED.o" \
"./Generated_Code/UTIL.o" \
"./Generated_Code/Vectors.o" \

C_DEPS_QUOTED += \
"./Generated_Code/ASerialLdd1.d" \
"./Generated_Code/ASerialLdd2.d" \
"./Generated_Code/BLUE.d" \
"./Generated_Code/BitIoLdd1.d" \
"./Generated_Code/BitIoLdd2.d" \
"./Generated_Code/BitIoLdd3.d" \
"./Generated_Code/Cpu.d" \
"./Generated_Code/ESP.d" \
"./Generated_Code/GREEN.d" \
"./Generated_Code/LEDpin1.d" \
"./Generated_Code/LEDpin2.d" \
"./Generated_Code/LEDpin3.d" \
"./Generated_Code/MCUC1.d" \
"./Generated_Code/PC.d" \
"./Generated_Code/PE_LDD.d" \
"./Generated_Code/RED.d" \
"./Generated_Code/UTIL.d" \
"./Generated_Code/Vectors.d" \

OBJS_OS_FORMAT += \
./Generated_Code/ASerialLdd1.o \
./Generated_Code/ASerialLdd2.o \
./Generated_Code/BLUE.o \
./Generated_Code/BitIoLdd1.o \
./Generated_Code/BitIoLdd2.o \
./Generated_Code/BitIoLdd3.o \
./Generated_Code/Cpu.o \
./Generated_Code/ESP.o \
./Generated_Code/GREEN.o \
./Generated_Code/LEDpin1.o \
./Generated_Code/LEDpin2.o \
./Generated_Code/LEDpin3.o \
./Generated_Code/MCUC1.o \
./Generated_Code/PC.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/RED.o \
./Generated_Code/UTIL.o \
./Generated_Code/Vectors.o \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/ASerialLdd1.o: ../Generated_Code/ASerialLdd1.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/ASerialLdd1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/ASerialLdd1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/ASerialLdd2.o: ../Generated_Code/ASerialLdd2.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/ASerialLdd2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/ASerialLdd2.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/BLUE.o: ../Generated_Code/BLUE.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/BLUE.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/BLUE.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/BitIoLdd1.o: ../Generated_Code/BitIoLdd1.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/BitIoLdd1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/BitIoLdd1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/BitIoLdd2.o: ../Generated_Code/BitIoLdd2.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/BitIoLdd2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/BitIoLdd2.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/BitIoLdd3.o: ../Generated_Code/BitIoLdd3.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/BitIoLdd3.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/BitIoLdd3.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Cpu.o: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Cpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Cpu.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/ESP.o: ../Generated_Code/ESP.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/ESP.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/ESP.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/GREEN.o: ../Generated_Code/GREEN.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/GREEN.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/GREEN.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/LEDpin1.o: ../Generated_Code/LEDpin1.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/LEDpin1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/LEDpin1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/LEDpin2.o: ../Generated_Code/LEDpin2.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/LEDpin2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/LEDpin2.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/LEDpin3.o: ../Generated_Code/LEDpin3.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/LEDpin3.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/LEDpin3.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/MCUC1.o: ../Generated_Code/MCUC1.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/MCUC1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/MCUC1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PC.o: ../Generated_Code/PC.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PC.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PC.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_LDD.o: ../Generated_Code/PE_LDD.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PE_LDD.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PE_LDD.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/RED.o: ../Generated_Code/RED.c
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/RED.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/RED.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/UTIL.o: ../Generated_Code/UTIL.c
	@echo 'Building file: $<'
	@echo 'Executing target #22 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/UTIL.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/UTIL.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors.o: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #23 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Vectors.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Vectors.o"
	@echo 'Finished building: $<'
	@echo ' '


