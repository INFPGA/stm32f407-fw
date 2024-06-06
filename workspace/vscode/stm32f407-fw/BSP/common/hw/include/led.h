#ifndef LED_H_
#define LED_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "hw_def.h"


#define LED_MAX_CH  HW_LED_MAX_CH

typedef enum
{
  LED1,
  LED2,
  LED3,
  LED_MAX
} LedList_t;

bool ledInit(void);
void ledOn(uint8_t ch);
void ledOff(uint8_t ch);
void ledToggle(uint8_t ch);

#ifdef __cplusplus
}
#endif

#endif
