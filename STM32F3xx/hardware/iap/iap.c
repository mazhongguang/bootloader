#include "iap.h"
#include "delay.h"
#include "stm32f301x8.h"
#include "stm32f3xx_ll_usart.h"
#include "sys.h"
#include "stmflash.h"

iapfun jump2app;
uint16_t iapbuf[1024];

/* @bref 
 * @param appxaddr APP start address
 * @param appbuf APP code
 * @param applen APP size
 * @retval none
 */
void iap_write_appbin(uint32_t appxaddr, uint8_t *appbuf, uint32_t applen)
{
	uint8_t *dfu = appbuf;
	uint16_t t, temp;
	uint16_t i = 0;
	uint32_t fwaddr = appxaddr;

	for (t = 0; t < applen; t += 2)
	{
		temp = (uint16_t)dfu[1] << 8;
		temp |= (uint16_t)dfu[0];
		dfu += 2;
		iapbuf[i++] = temp;

		if (i == 1024)
		{
			i = 0;
			STMFLASH_Write(fwaddr, iapbuf, 1024);
			fwaddr += 2048;
		}
	}

	if (i)
	{
		STMFLASH_Write(fwaddr, iapbuf, i);
	}
}


/* @bref jump to user app program
 * @param appxaddr user's app start address
 * @retval none
 */
void iap_load_app(uint32_t appxaddr)
{
	if (((*(vu32 *)appxaddr) & 0x2FFE0000) == 0x20000000)	
	{
		jump2app = (iapfun)*(vu32 *)(appxaddr + 4);
		MSR_MSP(*(vu32 *)appxaddr);
		/* 关闭中断，防止进入APP后进入中断
			由于查找不到相应中断的服务函数
			而死机
		*/
		for (int i = 0; i < 8; i++)
		{
			NVIC->ICER[i] = 0xFFFFFFFF;
			NVIC->ICPR[i] = 0xFFFFFFFF;
		}
		HAL_RCC_DeInit();
		SysTick->CTRL = 0;
		SysTick->LOAD = 0;
		SysTick->VAL = 0;
		
		jump2app();
	}
}
