C_INCLUDES = \
-Iapp \
-Icore \
-Icore/arm \
-Icore/gcc \
-Ihallib/Inc \
-Ihallib/Inc/Legacy \
-Ihardware/button \
-Ihardware/iap \
-Ihardware/led \
-Ihardware/stmflash \
-ISYSTEM/delay \
-ISYSTEM/sys \
-ISYSTEM/usart \


# C defines
C_DEFS =  \
-DUSE_HAL_DRIVER  \
-DUSE_FULL_LL_DRIVER\
-DSTM32F301x8 \


# AS incluedes
AS_INCLUDES =


#以下是YCM配置文件需要复制的FLAG内容
#'-I',
#'app',
#'-I',
#'core',
#'-I',
#'core/arm',
#'-I',
#'core/gcc',
#'-I',
#'hallib/Inc',
#'-I',
#'hallib/Inc/Legacy',
#'-I',
#'hardware/button',
#'-I',
#'hardware/iap',
#'-I',
#'hardware/led',
#'-I',
#'hardware/stmflash',
#'-I',
#'SYSTEM/delay',
#'-I',
#'SYSTEM/sys',
#'-I',
#'SYSTEM/usart',
