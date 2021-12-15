/*
 * LM35_TEMP.c
 *
 *  Author: Mostafa Ayman
 */ 
#include "LM35_TEMP.h"
#include "ADC.h"

void TEMP_S_INIT(){
	ADC_INIT();
	}
uint8 TEMP_S_READ(){
	uint8 sensor_val=ADC_READ();
	return (5.0 * sensor_val * 100.0) / 1024;
}