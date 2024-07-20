/**
  ******************************************************************************
  * @file    UART/UART_Printf/Src/main.c
  * @author  MCD Application Team
  * @brief   This example shows how to retarget the C library printf function
  *          to the UART.
  */

/* Includes ------------------------------------------------------------------*/
#include "API_delay.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define LOWERlIMIT 0
#define UPPERlIMIT 2000

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void Error_Handler(void);

/* Private functions ---------------------------------------------------------*/
/*This function starts the structure Init. It receives as parameters the name of the structure*/
void delayInit(delay_t *delay, tick_t duration) {

	if (delay == NULL || durationOutOfRange(duration))
		Error_Handler();

	delay->startTime = 0;
 	delay->duration = duration;
	delay->running = false;
}

/*This function constantly validates if the indicated delay has elapsed.
  It receives the name of the structure as its only parameter*/
bool_t delayRead(delay_t *delay){

	bool_t rtnValue = false;

	if (delay == NULL)
		Error_Handler();

	if (delay->running == false){
		delay->running = true;
		delay->startTime = HAL_GetTick();

	} else {
		if ((HAL_GetTick() - delay->startTime) >= delay->duration) {
			rtnValue = true;
			delay->running = false;
		}
	}
	return rtnValue;
}

/*Receives the name of the structure and the new delay as parameters*/
void delayWrite(delay_t *delay, tick_t duration) {

	if (delay == NULL || durationOutOfRange(duration))
		Error_Handler();

	delay->duration = duration;
}

bool_t durationOutOfRange(tick_t duration) {

	bool_t rtnValue = false;

	if (duration < LOWERlIMIT || duration > UPPERlIMIT)
		rtnValue = true;

	return rtnValue;
}

bool_t delayIsRunning(delay_t * delay) {

	if (delay == NULL){
		Error_Handler();
	}
	return delay->running;
}

static void Error_Handler(void)
{
  /* Turn LED2 on */
  BSP_LED_On(LED2);
  while (1)
  {
  }
}
