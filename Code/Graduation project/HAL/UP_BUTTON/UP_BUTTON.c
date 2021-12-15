/*
 * UP_BUTTON.c
 *
 *  Author: Mostafa Ayman
 */ 


#include "UP_BUTTON.h"
#include "DIO.h"
#define  F_CPU 16000000UL
#include "util/delay.h"
#include <avr/interrupt.h>
#include "EX_INT.h"


void   UP_BUTTON_INIT(void){
	EXTERNAL_INT_1_INIT();
}