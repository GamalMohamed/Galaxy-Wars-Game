################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/camera.cpp \
../src/enviroment.cpp \
../src/gamewindow.cpp \
../src/main.cpp \
../src/mesh.cpp \
../src/model.cpp \
../src/shader.cpp 

OBJS += \
./src/camera.o \
./src/enviroment.o \
./src/gamewindow.o \
./src/main.o \
./src/mesh.o \
./src/model.o \
./src/shader.o 

CPP_DEPS += \
./src/camera.d \
./src/enviroment.d \
./src/gamewindow.d \
./src/main.d \
./src/mesh.d \
./src/model.d \
./src/shader.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


