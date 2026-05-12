/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_1_Pin|LED_2_Pin|LED_3_Pin|LED_4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : IN_3_Pin IN_2_Pin */
  GPIO_InitStruct.Pin = IN_3_Pin|IN_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : IN_4_Pin IN_5_Pin */
  GPIO_InitStruct.Pin = IN_4_Pin|IN_5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : IN_1_Pin */
  GPIO_InitStruct.Pin = IN_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(IN_1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_1_Pin LED_2_Pin LED_3_Pin LED_4_Pin */
  GPIO_InitStruct.Pin = LED_1_Pin|LED_2_Pin|LED_3_Pin|LED_4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : LED_5_Pin */
  GPIO_InitStruct.Pin = LED_5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_5_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : IN_6_Pin IN_7_Pin IN_8_Pin IN_9_Pin */
  GPIO_InitStruct.Pin = IN_6_Pin|IN_7_Pin|IN_8_Pin|IN_9_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */
void GPIO_Poll (uint16_t * p_button_state)
{
	*p_button_state = 0;
	*p_button_state |= HAL_GPIO_ReadPin(BTN1_GPIO_Port, BTN1_Pin);
	*p_button_state |= HAL_GPIO_ReadPin(BTN2_GPIO_Port, BTN2_Pin) << 1;
	*p_button_state |= HAL_GPIO_ReadPin(BTN3_GPIO_Port, BTN3_Pin) << 2;
	*p_button_state |= HAL_GPIO_ReadPin(BTN4_GPIO_Port, BTN4_Pin) << 3;
	*p_button_state |= HAL_GPIO_ReadPin(BTN5_GPIO_Port, BTN5_Pin) << 4;
	*p_button_state |= HAL_GPIO_ReadPin(BTN6_GPIO_Port, BTN6_Pin) << 5;
	*p_button_state |= HAL_GPIO_ReadPin(BTN7_GPIO_Port, BTN7_Pin) << 6;
	*p_button_state |= HAL_GPIO_ReadPin(BTN8_GPIO_Port, BTN8_Pin) << 7;
	*p_button_state |= HAL_GPIO_ReadPin(BTN9_GPIO_Port, BTN9_Pin) << 8;
	*p_button_state ^= 0x0FFF;
}

/* USER CODE END 2 */
