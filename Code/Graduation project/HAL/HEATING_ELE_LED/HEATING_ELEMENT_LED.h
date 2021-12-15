/*
 * HEATING_ELEMENT_LED.h
 *
 *  Author: Mostafa Ayman
 */ 


#ifndef HEATING_ELEMENT_LED_H_
#define HEATING_ELEMENT_LED_H_

#include "HEATING_ELEMENT_LED_CONFIG.h"

#define BLINKING        2

void HEATING_ELEMENT_LED_INIT(void);
void HEATING_ELEMENT_LED_ON(void);
void HEATING_ELEMENT_LED_OFF(void);
void HEATING_ELEMENT_LED_TOGGLE(void);



#endif /* HEATING_ELEMENT_LED_H_ */