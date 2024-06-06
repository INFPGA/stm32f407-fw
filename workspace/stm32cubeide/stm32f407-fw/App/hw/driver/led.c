#include "led.h"

#ifdef _USE_HW_LED
#include "cli.h"



typedef struct
{
  GPIO_TypeDef *port;
  uint16_t      pin;
  GPIO_PinState on_state;
  GPIO_PinState off_state;
  LedList_t     led;
  const char*   led_name;
} led_tbl_t;


static const led_tbl_t led_tbl[LED_MAX_CH] =
{
  { LED1_GPIO_Port, LED1_Pin,  GPIO_PIN_RESET, GPIO_PIN_SET, NAME_DEF(LED1) },
  { LED2_GPIO_Port, LED2_Pin,  GPIO_PIN_RESET, GPIO_PIN_SET, NAME_DEF(LED2) },
  { LED3_GPIO_Port, LED3_Pin,  GPIO_PIN_RESET, GPIO_PIN_SET, NAME_DEF(LED3) },
};

static void cliLed(cli_args_t *args);

bool ledInit(void)
{
  #ifdef _USE_HW_CLI
  cliAdd("led", cliLed);
  #endif

  return true;
}

void ledOn(uint8_t ch)
{
  if (ch >= LED_MAX_CH) return;

  HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pin, led_tbl[ch].on_state);
}

void ledOff(uint8_t ch)
{
  if (ch >= LED_MAX_CH) return;

  HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pin, led_tbl[ch].off_state);
}

void ledToggle(uint8_t ch)
{
  if (ch >= LED_MAX_CH) return;

  HAL_GPIO_TogglePin(led_tbl[ch].port, led_tbl[ch].pin);
}
#endif

#ifdef _USE_HW_CLI
void cliLed(cli_args_t *args)
{
  bool ret = false;

  if (args->argc == 1 && args->isStr(0, "info"))
  {
    for (int i=0; i<LED_MAX_CH; i++)
    {
      cliPrintf("%-12s \n", led_tbl[i].led_name);
    }
    ret = true;
  }

  if (args->argc == 3 && args->isStr(0, "toggle"))
  {
    uint8_t  ch;
    uint32_t toggle_time;
    uint32_t pre_time;

    ch = (uint8_t)args->getData(1);
    ch = constrain(ch, 0, LED_MAX_CH-1);
    toggle_time = (uint32_t)args->getData(2);

    pre_time = millis();
    while(cliKeepLoop())
    {
      if (millis()-pre_time >= toggle_time)
      {
        pre_time = millis();
        ledToggle(ch);
      }
    }
    ledOff(ch);
    ret = true;
  }

  if (ret == false)
  {
    cliPrintf("led info\n");
    cliPrintf("led toggle [ch : 0~%d] [ms] \n", LED_MAX_CH);
  }
}
#endif
