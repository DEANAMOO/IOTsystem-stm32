/*
 * queue.c
 *
 *  Created on: Nov 8, 2023
 *      Author: trgo1
 */
#include "queue.h"
#include "main.h"
#include "stdio.h"

//버퍼용량 전부 사용하는지 확인하는 함수
int is_max(strQUEUE *strQUEUE) {
	return strQUEUE->tail == QUEUE_MAX;
}

//버펴 비어있는지 확인하는 함수
int is_empty(strQUEUE *strQUEUE) {
	return strQUEUE->head == strQUEUE->tail;
}

//큐의 버퍼에 데이터 입력후 tail 1증가
void put(strQUEUE *strQUEUE, uint8_t data) {
	if (is_max(strQUEUE)) {
		printf("queue max");
		return -1;
	}
	strQUEUE->Buffer[strQUEUE->tail++] = data;
}
//큐의 버퍼의 데이터 출력후 head 1감소
int get(strQUEUE *strQUEUE) {
	if (is_empty(strQUEUE)) {
		printf("queue empty");
		return -1;
	}
	return strQUEUE->Buffer[strQUEUE->head++];
}

//큐 초기화
void resetQUEUE(strQUEUE *strQUEUE) {
	strQUEUE->data = strQUEUE->head = strQUEUE->tail = 0;
	memset(strQUEUE->Buffer, 0, sizeof(strQUEUE->Buffer));
}

