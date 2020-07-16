#ifndef __LED_H
#define __LED_H

#include "sys.h"

#define LED0_ON() HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
#define LED0_OFF() HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);


void led_init(void);

#endif
