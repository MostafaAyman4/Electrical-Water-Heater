/*
 * EEPROM_24C16.h
 *
 *  Author: Mostafa Ayman
 */ 


#ifndef EEPROM_24C16_H_
#define EEPROM_24C16_H_

#include "STD_TYPES.h"

void EEPROM_24C16_INIT(void);
void EEPROM_24C16_WRITE(uint8,uint8);
uint8   EEPROM_24C16_READ(uint8);


#endif /* EEPROM_24C16_H_ */