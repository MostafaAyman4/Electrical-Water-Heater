/*
 **************************************** Electrical_Water_Heater**********************************************
 *******************************NOTE:***************************************************************************
 ************************************This project works on ATMEGA32 MICROCONTROLLER With 16 MHZ Crystal********
 **************************************************************************************************************
 * Author :Mostafa Ayman
 */ 

#define  F_CPU 16000000UL
#include "util/delay.h"
#include "REG.h"
#include "S_SEG.h"
#include "HEATING_ELEMENT.h"
#include "COOLING_ELEMENT.h"
#include "HEATING_ELEMENT_LED.h"
#include "DOWN_BUTTON.h"
#include "UP_BUTTON.h"
#include "ON_OFF_SWITCH.h"
#include "LM35_TEMP.h"
#include "LM35_TEMP.h"
#include "EEPROM_24C16.h"
#include "EX_INT.h"
#include "TIMER.h"

#include <avr/interrupt.h>

extern uint32 num_of_ov;
extern uint32 initial_value;

uint8  TEMP=initial_temp;
uint8  DEVICE_STATE;
uint8  SETTING_MODE_STATE;
uint8  HEATING_ELE_LED_STATE;
uint8  SEVEN_SEG_STATE=OFF;

uint8  SENSOR_TEMP_VALUE=0;
uint16 SENSOR_TEMP_SUM=0;
uint8  AVERAGE_SENSOR_TEMP_VALUE=0;

static  uint32 counter_3=0;

int main (void){

	HEATING_ELEMENT_INIT();
	HEATING_ELEMENT_LED_INIT();
	COOLING_ELEMENT_INIT();
	
	TEMP_S_INIT();
	
	S_SEG_INIT();
	
	EEPROM_24C16_INIT();
	
	TIMER_0_INIT();
	TIMER_0_SET_TIME(100);      
	TIMER_0_START();
	
	ON_OFF_SWITCH_INIT();
	DOWN_BUTTON_INIT();
	UP_BUTTON_INIT();
	
	
	DEVICE_STATE=0x00;
	SETTING_MODE_STATE=DISABLE;
	
	if(EEPROM_24C16_READ(0x00) != 0xFF)     // check if there are no data in EEPROM (first time to use it)
	{
		TEMP = EEPROM_24C16_READ(0x00);       // read data from byte number 0 in external EEPROM IC
	}
	
	while(1){
		if(DEVICE_STATE==OFF){
			COOLING_ELEMENT_OFF();
			HEATING_ELEMENT_LED_OFF();
			HEATING_ELEMENT_OFF();
			HEATING_ELE_LED_STATE=OFF;
		}
		else if(DEVICE_STATE==ON){
			if(AVERAGE_SENSOR_TEMP_VALUE<=(TEMP-5)){
				HEATING_ELEMENT_ON();
				COOLING_ELEMENT_OFF();
				HEATING_ELE_LED_STATE=BLINKING;
			}
			else if(AVERAGE_SENSOR_TEMP_VALUE>=(TEMP+5)){
				HEATING_ELEMENT_OFF();
				COOLING_ELEMENT_ON();
				HEATING_ELEMENT_LED_ON();
				HEATING_ELE_LED_STATE=ON;
			}
			
		}

		if(DEVICE_STATE==ON){
			if(SETTING_MODE_STATE==DISABLE){
				S_SEG_DISPLAY(SENSOR_TEMP_VALUE);
				SEVEN_SEG_STATE=ON;
				S_SEG_ON();
			}
			else if(SETTING_MODE_STATE==ENABLE){
				SEVEN_SEG_STATE=BLINKING;
				S_SEG_DISPLAY(TEMP);
			}
			if(DEVICE_STATE==OFF){
				SEVEN_SEG_STATE=OFF;
				S_SEG_OFF();
			}
		}
	}
}

	
ISR(INT0_vect)   //ON_OFF_BUTTON_ACTIVATE_IN FALLING_EDGE_"RELEASED"
{
	DEVICE_STATE ^=0X01;   //Toggle the device state
}

ISR(INT1_vect)   //UP_BUTTON
{
	if(SETTING_MODE_STATE==DISABLE){
		SETTING_MODE_STATE=ENABLE;
	}
	else if(SETTING_MODE_STATE==ENABLE){
		counter_3=0;
		TEMP+=5;
		if(TEMP>75){
			TEMP=75;
		}
		EEPROM_24C16_WRITE(0x00,TEMP);  //save the set temp in EEPROM 
	}
}

ISR(INT2_vect)   //DOWN_BUTTON
{
	if(SETTING_MODE_STATE==DISABLE){
		SETTING_MODE_STATE=ENABLE;
	}
	else if(SETTING_MODE_STATE==ENABLE){
		counter_3=0;
		TEMP-=5;
		if(TEMP<35){
			TEMP=35;
		}
		EEPROM_24C16_WRITE(0x00,TEMP);  //save the set temp in EEPROM 
	}
}

ISR(TIMER0_OVF_vect)
{
	static uint32 counter_1;
	static uint32 counter_2;
	static  uint32 counter_4;
	static  uint32 counter_5;
	counter_1++;
	counter_2++;
	if (counter_1 == num_of_ov)    //what to do every 100 ms
	{
		SENSOR_TEMP_VALUE=TEMP_S_READ();
		SENSOR_TEMP_SUM+=SENSOR_TEMP_VALUE;
		counter_1 = 0;
		if(SETTING_MODE_STATE==ENABLE){
			counter_3++;
		}
		if(SEVEN_SEG_STATE==BLINKING){
			counter_4++;
		}
		if(HEATING_ELE_LED_STATE==BLINKING){
			counter_5++;
		}
		TCNT0 = initial_value;
	}
	if(counter_4==10){     //what to do every 1000ms in condition of seven segment toggle is enabled
		S_SEG_TOGGLE();
		counter_4=0;
	}
	if(counter_5==10){    //what to do every 1000ms in condition of heating element led toggle is enabled
		HEATING_ELEMENT_LED_TOGGLE();
		counter_5=0;
	}
	if(counter_2 == (num_of_ov*10)) //what to do every 1000ms
	{
		AVERAGE_SENSOR_TEMP_VALUE=SENSOR_TEMP_SUM/10;
		SENSOR_TEMP_SUM=0;
		counter_2 = 0;
	}
	if(counter_3 == 50 && SETTING_MODE_STATE==1){   //what to do every 5000ms if you entered the setting temp mode
		SETTING_MODE_STATE=DISABLE;
		counter_3=0;
	}
}
