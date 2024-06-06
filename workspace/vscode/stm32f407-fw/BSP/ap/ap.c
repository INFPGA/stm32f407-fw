#include "ap.h"


void apInit (void)
{
  cliOpen(_DEF_UART1, 115200);
  logBoot(1);
}

void apMain (void)
{
	while (1)
	{
		
		cliMain();
	}
}


