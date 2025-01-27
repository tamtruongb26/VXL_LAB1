/*
 * ex1.c
 *
 *  Created on: Dec 16, 2024
 *      Author: THANH TAM
 */


#include "ex1.h"

int status = 0;

void ex1(){
	switch (status){
		case INIT:
			//TODO
			off();

			status = STATUS_1;
			setTimer(0, 500);
			break;
		case STATUS_1:
			//TODO
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			two();

			if (timer_flag[0] == 1) {
				status = STATUS_2;
				setTimer(0, 500);
			}
			break;
		case STATUS_2:
			//TODO
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			one();

			if (timer_flag[0] == 1) {
				status = STATUS_1;
				setTimer(0, 500);
			}
			break;
		default:
			break;
	}
}
