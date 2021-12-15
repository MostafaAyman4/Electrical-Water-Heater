/*
 * DOWN_BUTTON.c
 *
 *  Author: Mostafa Ayman
 */
#include "DOWN_BUTTON.h"
#define  F_CPU 16000000UL
#include "util/delay.h"
#include <avr/interrupt.h>
#include "EX_INT.h"

void   DOWN_BUTTON_INIT(void){
	EXTERNAL_INT_2_INIT();
}
