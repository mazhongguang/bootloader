C_SOURCES = \
app/main.c \
app/stm32f3xx_hal_msp.c \
app/stm32f3xx_it.c \
core/system_stm32f3xx.c \
hardware/button/button.c \
hardware/iap/iap.c \
hardware/led/led.c \
hardware/stmflash/stmflash.c \
SYSTEM/delay/delay.c \
SYSTEM/sys/sys.c \
SYSTEM/usart/usart.c \

C_SOURCES += 	 \
		hallib/Src/stm32f3xx_hal_rcc.c \
		hallib/Src/stm32f3xx_hal_rcc_ex.c \
		hallib/Src/stm32f3xx_hal_gpio.c \
		hallib/Src/stm32f3xx_hal_dma.c \
		hallib/Src/stm32f3xx_hal_pwr.c \
		hallib/Src/stm32f3xx_hal_cortex.c \
		hallib/Src/stm32f3xx_hal.c \
		hallib/Src/stm32f3xx_hal_tim.c \
		hallib/Src/stm32f3xx_hal_tim_ex.c \
		hallib/Src/stm32f3xx_hal_flash.c \
		hallib/Src/stm32f3xx_hal_flash_ex.c \
		hallib/Src/stm32f3xx_hal_uart.c \
		hallib/Src/stm32f3xx_hal_uart_ex.c \
		hallib/Src/stm32f3xx_ll_usart.c \
		hallib/Src/stm32f3xx_ll_rcc.c \

C_SOURCES += \




ASM_SOURCES =  \
core/gcc/startup_stm32f301x8.s


GCC_PATH = /opt/gcc-arm-none-eabi-6-2017-q2-update/bin


