#ifndef __STMFLASH_H
#define	__STMFLASH_H

#include "main.h"
#include "sys.h"
#include <stm32f3xx_hal_flash.h>
#include <stm32f3xx_hal_flash_ex.h>
/****************** FLASH 起始地址	********************************/
#define STM32_FLASH_BASE	0X08000000								//STM32 Flash的起始地址
#define STM32_FLASH_SIZE 	64 	 		//所选STM32的FLASH容量大小(单位为K)
#define STM32_FLASH_WREN 	1              	//使能FLASH写入(0，不使能;1，使能)
#define FLASH_WAITETIME		50000									//FLASH等待超时时间

/*****************	FLASH扇区的起始地址	**************************
#define	ADDR_FLASH_SECTOR_0			((u32)0X08000000)					//扇区0起始地址16KB
#define ADDR_FLASH_SECTOR_1			((u32)0X08004000)					//扇区1起始地址16KB
#define	ADDR_FLASH_SECTOR_2			((u32)0X08008000)					//扇区2起始地址16KB
#define ADDR_FLASH_SECTOR_3			((u32)0X0800C000)					//扇区3起始地址16KB
#define	ADDR_FLASH_SECTOR_4			((u32)0X08010000)					//扇区4起始地址16KB
#define ADDR_FLASH_SECTOR_5			((u32)0X08020000)					//扇区5起始地址16KB
#define	ADDR_FLASH_SECTOR_6			((u32)0X08040000)					//扇区6起始地址16KB
#define ADDR_FLASH_SECTOR_7			((u32)0X08060000)					//扇区7起始地址16KB
#define	ADDR_FLASH_SECTOR_8			((u32)0X08080000)					//扇区8起始地址16KB
#define ADDR_FLASH_SECTOR_9			((u32)0X080A0000)					//扇区9起始地址16KB
#define	ADDR_FLASH_SECTOR_10		((u32)0X080C0000)					//扇区10起始地址16KB
#define ADDR_FLASH_SECTOR_11		((u32)0X080E0000)					//扇区11起始地址16KB

#define	ADDR_FLASH_SECTOR_12		((u32)0X08100000)					//扇区12起始地址16KB
#define ADDR_FLASH_SECTOR_13		((u32)0X08104000)					//扇区13起始地址16KB
#define	ADDR_FLASH_SECTOR_14		((u32)0X08108000)					//扇区14起始地址16KB
#define ADDR_FLASH_SECTOR_15		((u32)0X0810C000)					//扇区15起始地址16KB
#define	ADDR_FLASH_SECTOR_16		((u32)0X08110000)					//扇区16起始地址16KB
#define ADDR_FLASH_SECTOR_17		((u32)0X08120000)					//扇区17起始地址16KB
#define	ADDR_FLASH_SECTOR_18		((u32)0X08140000)					//扇区18起始地址16KB
#define ADDR_FLASH_SECTOR_19		((u32)0X08160000)					//扇区19起始地址16KB
#define	ADDR_FLASH_SECTOR_20		((u32)0X08180000)					//扇区20起始地址16KB
#define ADDR_FLASH_SECTOR_21		((u32)0X081A0000)					//扇区21起始地址16KB
#define	ADDR_FLASH_SECTOR_22		((u32)0X081C0000)					//扇区22起始地址16KB
#define ADDR_FLASH_SECTOR_23		((u32)0X081E0000)					//扇区23起始地址16KB

*/

extern void    FLASH_PageErase(uint32_t PageAddress);
u8 STMFLASH_GetStatus(void);				  //获得状态
u8 STMFLASH_WaitDone(u16 time);				  //等待操作结束
u8 STMFLASH_ErasePage(u32 paddr);			  //擦除页
u8 STMFLASH_WriteHalfWord(u32 faddr, u16 dat);//写入半字
u16 STMFLASH_ReadHalfWord(u32 faddr);		  //读出半字  
void STMFLASH_WriteLenByte(u32 WriteAddr,u32 DataToWrite,u16 Len);	//指定地址开始写入指定长度的数据
u32 STMFLASH_ReadLenByte(u32 ReadAddr,u16 Len);						//指定地址开始读取指定长度数据
void STMFLASH_Write(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite);		//从指定地址开始写入指定长度的数据
void STMFLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead);   		//从指定地址开始读出指定长度的数据
u32 STMFLASH_ReadWord(u32 faddr);											//读出字

//测试写入
void TEST_Write(u32 WriteAddr,u32 WriteData);

#endif
