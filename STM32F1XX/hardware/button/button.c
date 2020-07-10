#include "button.h"
#include "stm32f103xb.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_rcc.h"

void button_init(void)
{
	GPIO_InitTypeDef GPIO_Initure;

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();

	GPIO_Initure.Pin = GPIO_PIN_0;
	GPIO_Initure.Mode = GPIO_MODE_INPUT;
	GPIO_Initure.Pull = GPIO_PULLDOWN;
	GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA, &GPIO_Initure);

	GPIO_Initure.Pin = GPIO_PIN_1 | GPIO_PIN_13;
	GPIO_Initure.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOC, &GPIO_Initure);
}
