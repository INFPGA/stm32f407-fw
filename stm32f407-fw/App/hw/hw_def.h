#ifndef HW_DEF_H_
#define HW_DEF_H_

#include "bsp.h"


#define _DEF_FIRMWATRE_VERSION    "V240604"
#define _DEF_BOARD_NAME           "STM32F407VET6-BSP"


#define _USE_HW_LED
#define      HW_LED_MAX_CH          3

#define _USE_HW_UART
#define      HW_UART_MAX_CH         1
#define      HW_UART_CH_DEBUG       _DEF_UART1

#define _USE_HW_CLI
#define      HW_CLI_CMD_LIST_MAX    32
#define      HW_CLI_CMD_NAME_MAX    16
#define      HW_CLI_LINE_HIS_MAX    8
#define      HW_CLI_LINE_BUF_MAX    64

#define _USE_HW_CLI_GUI
#define      HW_CLI_GUI_WIDTH       80
#define      HW_CLI_GUI_HEIGHT      24

#define _USE_HW_SWTIMER
#define      HW_SWTIMER_MAX_CH      1

#endif
