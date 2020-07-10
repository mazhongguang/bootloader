#include "led.h"
#include "sys.h"

void led_init(void)
{
	GPIO_InitTypeDef GPIO_Initure;

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();

	GPIO_Initure.Pin = GPIO_PIN_8;
	GPIO_Initure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Initure.Pull = GPIO_PULLUP;
	GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA, &GPIO_Initure);

	GPIO_Initure.Pin = GPIO_PIN_2;
	HAL_GPIO_Init(GPIOD, &GPIO_Initure);
	
	LED0 = 1;
	LED1 = 1;
}
