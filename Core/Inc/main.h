/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */


/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define IN_3_Pin GPIO_PIN_9
#define IN_3_GPIO_Port GPIOB
#define IN_4_Pin GPIO_PIN_14
#define IN_4_GPIO_Port GPIOC
#define IN_5_Pin GPIO_PIN_15
#define IN_5_GPIO_Port GPIOC
#define IN_1_Pin GPIO_PIN_1
#define IN_1_GPIO_Port GPIOA
#define LED_1_Pin GPIO_PIN_4
#define LED_1_GPIO_Port GPIOA
#define LED_2_Pin GPIO_PIN_5
#define LED_2_GPIO_Port GPIOA
#define LED_3_Pin GPIO_PIN_6
#define LED_3_GPIO_Port GPIOA
#define LED_4_Pin GPIO_PIN_7
#define LED_4_GPIO_Port GPIOA
#define LED_5_Pin GPIO_PIN_0
#define LED_5_GPIO_Port GPIOB
#define IN_2_Pin GPIO_PIN_1
#define IN_2_GPIO_Port GPIOB
#define IN_6_Pin GPIO_PIN_0
#define IN_6_GPIO_Port GPIOD
#define IN_7_Pin GPIO_PIN_1
#define IN_7_GPIO_Port GPIOD
#define IN_8_Pin GPIO_PIN_2
#define IN_8_GPIO_Port GPIOD
#define IN_9_Pin GPIO_PIN_3
#define IN_9_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */
#define THROTTLE_ENABLED				0					// 1 for enabled, 0 for disabled
#define RUDDER_ENABLED					0					// 1 for enabled, 0 for disabled
#define JOYSTICK_AXIS_NUM				0
#define SECONDARY_AXIS_NUM			0

#define BUTTONS_NUM							5
#define LEDS_NUM								0

/* END OF USER CODE AREA */


/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define IN_3_Pin GPIO_PIN_9
#define IN_3_GPIO_Port GPIOB
#define IN_4_Pin GPIO_PIN_14
#define IN_4_GPIO_Port GPIOC
#define IN_5_Pin GPIO_PIN_15
#define IN_5_GPIO_Port GPIOC
#define IN_1_Pin GPIO_PIN_1
#define IN_1_GPIO_Port GPIOA
#define LED_1_Pin GPIO_PIN_4
#define LED_1_GPIO_Port GPIOA
#define LED_2_Pin GPIO_PIN_5
#define LED_2_GPIO_Port GPIOA
#define LED_3_Pin GPIO_PIN_6
#define LED_3_GPIO_Port GPIOA
#define LED_4_Pin GPIO_PIN_7
#define LED_4_GPIO_Port GPIOA
#define LED_5_Pin GPIO_PIN_0
#define LED_5_GPIO_Port GPIOB
#define IN_2_Pin GPIO_PIN_1
#define IN_2_GPIO_Port GPIOB
#define IN_6_Pin GPIO_PIN_0
#define IN_6_GPIO_Port GPIOD
#define IN_7_Pin GPIO_PIN_1
#define IN_7_GPIO_Port GPIOD
#define IN_8_Pin GPIO_PIN_2
#define IN_8_GPIO_Port GPIOD
#define IN_9_Pin GPIO_PIN_3
#define IN_9_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */
#define LED1_Pin 					GPIO_PIN_0
#define LED1_GPIO_Port 		GPIOB
#define LED2_Pin 					GPIO_PIN_1
#define LED2_GPIO_Port 		GPIOB
#define LED3_Pin 					GPIO_PIN_10
#define LED3_GPIO_Port 		GPIOB
#define LED4_Pin 					GPIO_PIN_11
#define LED4_GPIO_Port 		GPIOB


#define BTN1_Pin 					IN_1_Pin
#define BTN1_GPIO_Port 		IN_1_GPIO_Port

#define BTN2_Pin 					IN_9_Pin
#define BTN2_GPIO_Port 		IN_9_GPIO_Port

#define BTN3_Pin 					IN_3_Pin
#define BTN3_GPIO_Port 		IN_3_GPIO_Port

#define BTN4_Pin 					IN_4_Pin
#define BTN4_GPIO_Port 		IN_4_GPIO_Port

#define BTN5_Pin				 	IN_5_Pin
#define BTN5_GPIO_Port 		IN_5_GPIO_Port

#define BTN6_Pin 					IN_6_Pin
#define BTN6_GPIO_Port 		IN_6_GPIO_Port

#define BTN7_Pin 					IN_7_Pin
#define BTN7_GPIO_Port 		IN_7_GPIO_Port

#define BTN8_Pin 					IN_8_Pin
#define BTN8_GPIO_Port 		IN_8_GPIO_Port

#define BTN9_Pin 					IN_2_Pin
#define BTN9_GPIO_Port 		IN_2_GPIO_Port




#define THROTTLE_ENABLED				0					// 1 for enabled, 0 for disabled
#define RUDDER_ENABLED					0					// 1 for enabled, 0 for disabled
#define JOYSTICK_AXIS_NUM				2
#define SECONDARY_AXIS_NUM			0

#define BUTTONS_NUM							2
#define LEDS_NUM								0




/* DO NOT CHANGE CODE BELOW IF NOT SURE WHAT ARE YOU DOING */

#define FILTER_WINDOW_SIZE			10

#define ADC_CHANNELS_NUM				8


#define AXIS_NUM								((THROTTLE_ENABLED) + (JOYSTICK_AXIS_NUM) \
																+ (SECONDARY_AXIS_NUM) + (RUDDER_ENABLED))

#if (JOYSTICK_AXIS_NUM > 0)
	#define JOYSTICK_AXIS_ENABLED  	1
#else
	#define JOYSTICK_AXIS_ENABLED  	0
#endif

#if (SECONDARY_AXIS_NUM > 0)
	#define SECONDARY_AXIS_ENABLED  	1
#else
	#define SECONDARY_AXIS_ENABLED  	0
#endif

#if (BUTTONS_NUM > 0)
	#define BUTTONS_ENABLED  	1
#else
	#define BUTTONS_ENABLED  	0
#endif

#define DEVICE_ID1					0x1FFFF7E8
#define DEVICE_ID2					0x1FFFF7EA
#define DEVICE_ID3					0x1FFFF7EC
#define DEVICE_ID4					0x1FFFF7F0

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
