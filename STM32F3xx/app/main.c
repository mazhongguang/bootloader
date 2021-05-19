#include "main.h"
#include "stm32f301x8.h"
#include "stm32f3xx_hal_gpio.h"
#include "stm32f3xx_ll_usart.h"
#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "button.h"
#include "iap.h"
#include <stdio.h>

int main(void)
{
	uint8_t t = 0, state = 0;
	uint16_t oldcnt = 0;
	uint16_t applenth = 0;
	/*SCB->VTOR = 0x4000;*/
	
	HAL_Init();
	Stm32_Clock_Init(RCC_PLL_MUL9);
	delay_init(72);
	uart_init(115200);
	led_init();
	button_init();
	#if 1
		while(1)
		{
			state = !state;
			if (state)
			{
				LED0_ON();
			}
			else
			{
				LED0_OFF();
			}
			printf("APP程序运行中。。。\r\n");
			delay_ms(1000);
		}
	#endif
		#if 0
	while (1)
	{
		if (USART_RX_CNT)
		{
			if (oldcnt == USART_RX_CNT)
			{
				applenth = USART_RX_CNT;
				oldcnt = 0;
				USART_RX_CNT = 0;
				printf("用户程序接收完成！\r\n");
				
				printf("代码长度： %d Bytes\r\n", applenth);
			}
			else
			{
				oldcnt = USART_RX_CNT;
			}
		}
		
		t++;
		delay_ms(10);
		if (t == 30)
		{
			state = !state;
			if (state)
			{
				LED0_ON();
			}
			else
			{
				LED0_OFF();
			}
			t = 0;
		}
		
		if (WKUP_PRESS)
		{
			if (applenth)
			{
				printf("开始更新固件...\r\n");
				if (((*(vu32 *)(0x20001000 + 4)) & 0xFF000000) == 0x08000000)
				{
					iap_write_appbin(FLASH_APP1_ADDR, USART_RX_BUF, applenth);
					printf("固件更新完成!\r\n");
				}
				else
				{
					printf("非FLASH应用程序！\r\n");
				}
			}
			else
			{
				printf("没有可以更新的固件！\r\n");
			}
		}
		else if(KEY0_PRESS)
		{
			printf("开始执行FLASH用户代码！\r\n");
			if (((*(vu32 *)(FLASH_APP1_ADDR + 4)) & 0xFF000000) == 0x08000000)
			{
				iap_load_app(FLASH_APP1_ADDR);
			}
			else
			{
				printf("非FLASH应用程序，无法执行！\r\n");
			}
		}
  }
	#endif
}
