#ifndef __BUTTON_H
#define __BUTTON_H

#include "main.h"

#define WKUP_PRESS HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)==1
#define KEY0_PRESS HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1)==0
#define KEY1_PRESS HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)==0


void button_init(void);

#endif

