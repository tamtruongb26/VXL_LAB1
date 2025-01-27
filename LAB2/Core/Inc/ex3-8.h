/*
 * ex3.h
 *
 *  Created on: Dec 16, 2024
 *      Author: THANH TAM
 */

#ifndef INC_EX3_5_H_
#define INC_EX3_5_H_

#include "main.h"
#include "led7_segment.h"
#include "software_timer.h"


// define status
#define INIT 1
#define STATUS_1 2
#define STATUS_2 3
#define STATUS_3 4
#define STATUS_4 5

// status
extern int status1;
extern int led_buffer[4];
extern int minute, hour, second;

void ex3_7();

#endif /* INC_EX3_5_H_ */
