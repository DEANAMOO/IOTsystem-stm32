/*
 * queue.c
 *
 *  Created on: Nov 8, 2023
 *      Author: trgo1
 */
#include "queue.h"
#include "main.h"
#include "stdio.h"

int is_max(strQUEUE *strQUEUE) {
	return strQUEUE->tail == QUEUE_MAX;
}
;
int is_empty(strQUEUE *strQUEUE) {
	return strQUEUE->head == strQUEUE->tail;
}
;

void put(strQUEUE *strQUEUE, uint8_t data) {
	if (strQUEUE->tail == QUEUE_MAX) {
		strQUEUE->tail=0;
	}
	strQUEUE->Buffer[strQUEUE->tail++] = data;
}

int get(strQUEUE *strQUEUE) {
	if (is_empty(strQUEUE)) {
		printf("queue empty");
		return -1;
	}
	return strQUEUE->Buffer[strQUEUE->head++];
}

void resetQUEUE(strQUEUE *strQUEUE) {
	strQUEUE->data = strQUEUE->head = strQUEUE->tail = 0;
	memset(strQUEUE->Buffer,0,sizeof(strQUEUE->Buffer));
}

