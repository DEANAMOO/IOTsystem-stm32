/*
 * esp8266.h
 *
 *  Created on: Nov 22, 2023
 *      Author: trgo1
 */

#ifndef INC_ESP8266_H_
#define INC_ESP8266_H_
#include "main.h"

HAL_StatusTypeDef esp_reset();
HAL_StatusTypeDef esp_cipmux();
HAL_StatusTypeDef esp_server();
void esp_init();
#endif /* INC_ESP8266_H_ */
