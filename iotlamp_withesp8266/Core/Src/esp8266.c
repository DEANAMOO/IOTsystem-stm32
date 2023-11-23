/*
 * esp8266.c
 *
 *  Created on: Nov 22, 2023
 *      Author: trgo1
 */
#include "esp8266.h"
#include "main.h"
#include <stdio.h>

extern UART_HandleTypeDef huart1;
HAL_StatusTypeDef esp_reset() {
	uint8_t AT_CMD[] = "AT+RST\r\n";
	return HAL_UART_Transmit(&huart1, AT_CMD, sizeof(AT_CMD), 10);
}

HAL_StatusTypeDef esp_cipmux() {
	uint8_t AT_CMD[] = "AT+CIPMUX=1\r\n";
	return HAL_UART_Transmit(&huart1, AT_CMD, sizeof(AT_CMD), 10);
}

HAL_StatusTypeDef esp_server() {
	uint8_t AT_CMD[] = "AT+CIPSERVER=1,333\r\n";
	return HAL_UART_Transmit(&huart1, AT_CMD, sizeof(AT_CMD), 10);
}

void esp_init(){
	esp_reset();
	HAL_Delay(500);
	esp_cipmux();
	HAL_Delay(500);
	esp_server();
	HAL_Delay(500);
}
