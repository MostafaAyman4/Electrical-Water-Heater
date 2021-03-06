/*
 * COOLING_ELEMENT.c
 *
 *  Author: Mostafa Ayman
 */ 


#include "COOLING_ELEMENT.h"

#include "DIO.h"

void COOLING_ELEMENT_INIT(void){
	PIN_MODE(COOLING_ELEMENT_PIN,OUTPUT);
}
void COOLING_ELEMENT_ON(void){
	PIN_WRITE(COOLING_ELEMENT_PIN,HIGH);
}
void COOLING_ELEMENT_OFF(void){
	PIN_WRITE(COOLING_ELEMENT_PIN,LOW);
}