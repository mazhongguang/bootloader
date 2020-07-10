#ifndef __IAP_H
#define __IAP_H

#include <stdint.h>
typedef void (*iapfun)(void);

#define FLASH_APP1_ADDR 0x08003000

void iap_load_app(uint32_t appxaddr);	/* jump to APP program execution */
void iap_write_appbin(uint32_t appxaddr, uint8_t *appbuff, uint32_t applen);	/* Start at the specified address and write */

#endif
