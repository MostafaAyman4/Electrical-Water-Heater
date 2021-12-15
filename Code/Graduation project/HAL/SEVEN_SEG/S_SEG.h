/*
 * S_SEG.h
 *
 *  Author: MOSTAFA AYMAN
 */ 


#ifndef S_SEG_H_
#define S_SEG_H_

#include "DIO.h"
#include "S_SEG_CONFI.h"
#define  F_CPU 16000000UL
#include "util/delay.h"

void S_SEG_INIT();
void S_SEG_ON(void);
void S_SEG_OFF(void);
void S_SEG_TOGGLE(void);
void S_SEG_DISPLAY(uint8);



#endif /* S_SEG_H_ */