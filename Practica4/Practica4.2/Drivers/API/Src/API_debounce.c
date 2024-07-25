/**
  ******************************************************************************
  * @file    UART/UART_Printf/Src/main.c
  * @author  MCD Application Team
  * @brief   This example shows how to retarget the C library printf function
  *          to the UART.
  */

/* Includes ------------------------------------------------------------------*/
#include "API_debounce.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static bool_t keyPressed = false;

/* Private function prototypes -----------------------------------------------*/
static void Error_Handler(void);

/* Private functions ---------------------------------------------------------*/
/* Inicializa la máquina de estados debounce */
debounceFSM_init(debounceState_t *current, debounceState_t initial)
{
    *current = initial;
    keyPressed = false; // Inicializamos la variable global keyPressed en falso
}

/* Actualiza la máquina de estados debounce */
debounceFSM_update(debounceState_t *current, delay_t *delay)
{
    switch (*current)
    {
    case BUTTON_UP:
        if (BSP_PB_GetState(BUTTON_USER)==1)
        {
            *current = BUTTON_FALLING;
        }
        break;

    case BUTTON_FALLING:
        if (BSP_PB_GetState(BUTTON_USER)==1 && delayRead(delay))
        {
            *current = BUTTON_DOWN;
            keyPressed = true; // Se activó un flanco descendente, establecemos keyPressed en true
        }
        else
        {
            *current = BUTTON_UP;
        }
        break;

    case BUTTON_DOWN:
        if (BSP_PB_GetState(BUTTON_USER)==0)
        {
            *current = BUTTON_RAISING;
        }
        break;

    case BUTTON_RAISING:
        if (BSP_PB_GetState(BUTTON_USER)==0 && delayRead(delay))
        {
            *current = BUTTON_UP;
            keyPressed = false; // Se activó un flanco ascendente, establecemos keyPressed en false
        }
        else
        {
            *current = BUTTON_DOWN;
        }
        break;

    default:
        /* Handle unexpected state */
        Error_Handler();
        break;
    }
}

bool_t readKey(void) {
    bool_t keyStatus = keyPressed; // Leemos el estado de la tecla almacenado en keyPressed
    keyPressed = false; // Reseteamos el estado de keyPressed para la siguiente lectura
    return keyStatus; // Devolvemos el estado de la tecla
}

static void Error_Handler(void)
{
  /* Turn LED2 on */
  BSP_LED_On(LED2);
  while (1)
  {
  }
}
