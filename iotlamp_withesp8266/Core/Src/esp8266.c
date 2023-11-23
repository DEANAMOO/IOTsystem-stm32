/*
 * esp8266.c
 *
 *  Created on: Nov 22, 2023
 *      Author: trgo1
 */
#include "esp8266.h"
#include "main.h"
#include <string.h>
#include <stdio.h>

extern UART_HandleTypeDef huart1;
//AT명령어로 ESP8266 리셋
HAL_StatusTypeDef esp_reset() {
	uint8_t AT_CMD[] = "AT+RST\r\n";
	return HAL_UART_Transmit(&huart1, AT_CMD, strlen(AT_CMD), 10);
}
//ESP8266 다중연결 허용
HAL_StatusTypeDef esp_cipmux() {
	uint8_t AT_CMD[] = "AT+CIPMUX=1\r\n";
	return HAL_UART_Transmit(&huart1, AT_CMD, strlen(AT_CMD), 10);
}
//ESP8266 333번포트로 서버 생성
HAL_StatusTypeDef esp_server() {
	uint8_t AT_CMD[] = "AT+CIPSERVER=1,333\r\n";
	return HAL_UART_Transmit(&huart1, AT_CMD, strlen(AT_CMD), 10);
}

//펌웨어 시작시 ESP8266 TCP설정 초기화
void esp_init(){
	esp_reset();
	HAL_Delay(500);
	esp_cipmux();
	HAL_Delay(500);
	esp_server();
	HAL_Delay(500);
}
