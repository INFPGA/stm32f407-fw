#include "hw.h"


bool hwInit(void)
{
  cliInit();
  logInit();
  ledInit();
  uartInit();
  
  for (int i=0; i<HW_UART_MAX_CH; i++)
  {
    uartOpen(i, 115200);
  }

  swtimerInit();
  buttonInit();
  return true;
}
