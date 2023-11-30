/*
 * mpu6050.h
 *
 *  Created on: Nov 30, 2023
 *      Author: trgo1
 */
#include "mpu6050.h"

extern I2C_HandleTypeDef hi2c1;
extern DMA_HandleTypeDef hdma_i2c1_rx;
extern UART_HandleTypeDef huart2;
int16_t acc_x, acc_Y, acc_Z;
int16_t gyro_X, gyro_Y, gyro_Z;
uint8_t temp_reg0 = 0;
uint8_t temp_reg1 = 0;
uint8_t temp_reg2 = 0;
uint8_t temp_reg3 = 0;
uint8_t device_address_temp = 0;

