/*
 * ON_OFF_SWITCH.c
 *
 *  Author: Mostafa Ayman
 */ 
#include "ON_OFF_SWITCH.h"
#define  F_CPU 16000000UL
#include "util/delay.h"
#include <avr/interrupt.h>
#include "EX_INT.h"

void ON_OFF_SWITCH_INIT(void){
	EXTERNAL_INT_0_INIT();
}