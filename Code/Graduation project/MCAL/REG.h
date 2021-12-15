/*
 * REG.h
 *  Author: Mostafa Ayman
 */ 


#ifndef REG_H_
#define REG_H_

#include "STD_TYPES.h"

/*************** DIO_REGISTERS *************/

#define PORTA      (*((volatile uint8*)0x3B))
#define DDRA       (*((volatile uint8*)0x3A))
#define PINA       (*((volatile uint8*)0x39))

#define PORTB      (*((volatile uint8*)0x38))
#define DDRB       (*((volatile uint8*)0x37))
#define PINB       (*((volatile uint8*)0x36))

#define PORTC      (*((volatile uint8*)0x35))
#define DDRC       (*((volatile uint8*)0x34))
#define PINC       (*((volatile uint8*)0x33))

#define PORTD      (*((volatile uint8*)0x32))
#define DDRD       (*((volatile uint8*)0x31))
#define PIND       (*((volatile uint8*)0x30))

/**************_EX_INT_REGISTERS_************/

#define SREG   (*(volatile uint8*)(0x5F))
#define GICR   (*(volatile uint8*)(0x5B))
#define GIFR   (*(volatile uint8*)(0x5A))
#define MCUCR  (*(volatile uint8*)(0x55))
#define MCUCSR (*(volatile uint8*)(0x54))

/***************_ADC_REGISTERS_**************/

#define ADMUX           (*(volatile uint8*)(0x27))
#define ADCSRA          (*(volatile uint8*)(0x26))
#define ADCH            (*(volatile uint8*)(0x25))
#define ADCL            (*(volatile uint8*)(0x24))
#define ADC_VALUE       (*(volatile uint16*)(0x24))

/**************_TIMER_0_REGISTERS_************/

#define TCNT0  (*(volatile uint8*)(0x52))
#define TCCR0  (*(volatile uint8*)(0x53))
#define TIMSK  (*(volatile uint8*)(0x59))
#define OCR0   (*(volatile uint8*)(0x5C))

/****************_TWI_REGISTERS_**************/

#define TWAR     (*((volatile uint8*)0x22))
#define TWBR     (*((volatile uint8*)0x20))
#define TWCR     (*((volatile uint8*)0x56))
#define TWDR     (*((volatile uint8*)0x23))
#define TWSR     (*((volatile uint8*)0x21))

#endif /* REG_H_ */