/*
 * queue.h
 *
 *  Created on: Nov 8, 2023
 *      Author: trgo1
 */
#ifndef __QUEUE_H_
#define __QUEUE_H_
#include "stdio.h"
#include "main.h"
#define QUEUE_MAX 1024

typedef struct {
	uint8_t head, tail, data;
	uint8_t Buffer[QUEUE_MAX];
} strQUEUE;

void resetQUEUE(strQUEUE *strQUEUE);
int is_max(strQUEUE *strQUEUE);
int is_empty(strQUEUE *strQUEUE);
void put(strQUEUE *strQUEUE, uint8_t data);
int get(strQUEUE *strQUEUE);
#endif
