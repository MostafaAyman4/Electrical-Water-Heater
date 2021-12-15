/*
 * HEATING_ELEMENT.c
 *
 *  Author: Mostafa Ayman
 */ 
#include "HEATING_ELEMENT.h"

void HEATING_ELEMENT_INIT(void){
	PIN_MODE(HEATING_ELEMENT_PIN,OUTPUT);
}
void HEATING_ELEMENT_ON(void){
	PIN_WRITE(HEATING_ELEMENT_PIN,HIGH);
}
void HEATING_ELEMENT_OFF(void){
	PIN_WRITE(HEATING_ELEMENT_PIN,LOW);
}