################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/synergy_gen/blinky_thread.c \
../src/synergy_gen/common_data.c \
../src/synergy_gen/hal_data.c \
../src/synergy_gen/main.c \
../src/synergy_gen/pin_data.c \
../src/synergy_gen/thread_0_entry.c \
../src/synergy_gen/thread_1_entry.c \
../src/synergy_gen/thread_2_entry.c \
../src/synergy_gen/thread_3_entry.c \
../src/synergy_gen/thread_4_entry.c \
../src/synergy_gen/thread_5_entry.c \
../src/synergy_gen/thread_6_entry.c \
../src/synergy_gen/thread_7_entry.c 

OBJS += \
./src/synergy_gen/blinky_thread.o \
./src/synergy_gen/common_data.o \
./src/synergy_gen/hal_data.o \
./src/synergy_gen/main.o \
./src/synergy_gen/pin_data.o \
./src/synergy_gen/thread_0_entry.o \
./src/synergy_gen/thread_1_entry.o \
./src/synergy_gen/thread_2_entry.o \
./src/synergy_gen/thread_3_entry.o \
./src/synergy_gen/thread_4_entry.o \
./src/synergy_gen/thread_5_entry.o \
./src/synergy_gen/thread_6_entry.o \
./src/synergy_gen/thread_7_entry.o 

C_DEPS += \
./src/synergy_gen/blinky_thread.d \
./src/synergy_gen/common_data.d \
./src/synergy_gen/hal_data.d \
./src/synergy_gen/main.d \
./src/synergy_gen/pin_data.d \
./src/synergy_gen/thread_0_entry.d \
./src/synergy_gen/thread_1_entry.d \
./src/synergy_gen/thread_2_entry.d \
./src/synergy_gen/thread_3_entry.d \
./src/synergy_gen/thread_4_entry.d \
./src/synergy_gen/thread_5_entry.d \
./src/synergy_gen/thread_6_entry.d \
./src/synergy_gen/thread_7_entry.d 


# Each subdirectory must supply rules for building sources it contributes
src/synergy_gen/%.o: ../src/synergy_gen/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	C:\Renesas\Synergy\e2studio_v7.5.1_ssp_v1.7.8\Utilities\\/isdebuild arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g3 -D_RENESAS_SYNERGY_ -I"C:\Users\gabri\Documentos\e2_studio\workplace\lab7b\src" -I"C:\Users\gabri\Documentos\e2_studio\workplace\lab7b\src\synergy_gen" -I"C:\Users\gabri\Documentos\e2_studio\workplace\lab7b\synergy_cfg\ssp_cfg\bsp" -I"C:\Users\gabri\Documentos\e2_studio\workplace\lab7b\synergy_cfg\ssp_cfg\driver" -I"C:\Users\gabri\Documentos\e2_studio\workplace\lab7b\synergy\ssp\inc" -I"C:\Users\gabri\Documentos\e2_studio\workplace\lab7b\synergy\ssp\inc\bsp" -I"C:\Users\gabri\Documentos\e2_studio\workplace\lab7b\synergy\ssp\inc\bsp\cmsis\Include" -I"C:\Users\gabri\Documentos\e2_studio\workplace\lab7b\synergy\ssp\inc\driver\api" -I"C:\Users\gabri\Documentos\e2_studio\workplace\lab7b\synergy\ssp\inc\driver\instances" -I"C:\Users\gabri\Documentos\e2_studio\workplace\lab7b\synergy_cfg\ssp_cfg\framework\el" -I"C:\Users\gabri\Documentos\e2_studio\workplace\lab7b\synergy\ssp\inc\framework\el" -I"C:\Users\gabri\Documentos\e2_studio\workplace\lab7b\synergy\ssp\src\framework\el\tx" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


