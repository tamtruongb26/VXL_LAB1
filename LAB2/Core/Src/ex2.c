/*
 * ex2.c
 *
 *  Created on: Dec 16, 2024
 *      Author: THANH TAM
 */

#include "ex2.h"

int status0 = INIT;

void numtoled(int ledbuffer){
	switch (ledbuffer){
		case 0:
			zero();
			break;
		case 1:
			one();
			break;
		case 2:
			two();
			break;
		case 3:
			three();
			break;
		case 4:
			four();
			break;
		case 5:
			five();
			break;
		case 6:
			six();
			break;
		case 7:
			seven();
			break;
		case 8:
			eight();
			break;
		case 9:
			nine();
			break;
		default:
			break;
		}
}

void ex2(){
	switch (status0){
		case INIT:
			//TODO

			status0 = STATUS_1;
			setTimer(0, 500);
			break;
		case STATUS_1:
			//TODO
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			numtoled(1);

			if (timer_flag[0] == 1) {
				status0 = STATUS_2;
				setTimer(0, 500);
			}
			break;
		case STATUS_2:
			//TODO
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			two();

			if (timer_flag[0] == 1) {
				status0 = STATUS_3;
				setTimer(0, 500);
			}
			break;
		case STATUS_3:
			//TODO
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			three();

			if (timer_flag[0] == 1) {
				status0 = STATUS_4;
				setTimer(0, 500);
			}
			break;
		case STATUS_4:
			//TODO
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			zero();

			if (timer_flag[0] == 1) {
				status0 = STATUS_1;
				setTimer(0, 500);
			}
			break;
		default:
			break;
	}

	if (timer_flag[1] == 1){
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		setTimer(1, 500);
	}
}
