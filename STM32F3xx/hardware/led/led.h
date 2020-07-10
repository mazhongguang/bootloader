#ifndef __LED_H
#define __LED_H

#include "sys.h"

#define LED0_ON() HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
#define LED0_OFF() HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);

//#define LED1 PDout(2)

void led_init(void);

#endif
