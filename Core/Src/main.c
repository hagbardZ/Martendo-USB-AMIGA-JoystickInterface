/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include <usbd_hid_joystick.h>
#include "main.h"
#include "usb_device.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
volatile uint8_t data_ready = 0;

#if (AXIS_NUM > 0)
uint32_t filter_buf[AXIS_NUM][FILTER_WINDOW_SIZE];
#endif
uint16_t report_data[AXIS_NUM + BUTTONS_ENABLED];

uint16_t buttons_state;
uint16_t ADC_data[ADC_CHANNELS_NUM];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
uint16_t FilterWindow (uint32_t * p_buf, uint16_t new_val);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USB_Device_Init();
  /* USER CODE BEGIN 2 */

uint32_t ledFlash=0;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  //HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, 1);
if (ledFlash<20000) ledFlash++;
else ledFlash=0;

if (ledFlash>18000) HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, 1);
else HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, 0);


HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, 0);

	if (1)// (data_ready != 0)
		{
			GPIO_Poll(&buttons_state);
/*
#if (AXIS_NUM > 0)
				for (uint8_t i=0; i<AXIS_NUM; i++)
					report_data[i] = FilterWindow(filter_buf[i], ADC_data[i]);
#endif



*/
			report_data[0]=0;		 //x axis
			report_data[1]=0;		//y axis

//
// ----------------------------------------------------------------------------------------------
// ---- IN3=PB9=TP2=North,  IN4=PC14=TP1=South,   IN5=PC15=TP4=East,    IN6=PD0=TP7=West     ----
// ----------------------------------------------------------------------------------------------
//

			if (HAL_GPIO_ReadPin(IN_3_GPIO_Port, IN_3_Pin)==0)
					{
						report_data[0]=0;			//x Axis (North)
						report_data[1]=-32767;		//y Axis
						HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, 1);
					}
			if (HAL_GPIO_ReadPin(IN_4_GPIO_Port, IN_4_Pin)==0)
					{
						report_data[0]=0;			//x
						report_data[1]=32767;		//y (South)
						HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, 1);
					}
			if (HAL_GPIO_ReadPin(IN_5_GPIO_Port, IN_5_Pin)==0)
					{
						report_data[0]=-32767;	//X (east)
						report_data[1]=0;
						HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, 1);
					}
			if (HAL_GPIO_ReadPin(IN_6_GPIO_Port, IN_6_Pin)==0)
					{
						report_data[0]=32767;		//x (west)
						report_data[1]=0;
						HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, 1);
					}



			if ((HAL_GPIO_ReadPin(IN_3_GPIO_Port, IN_3_Pin)==0)&&(HAL_GPIO_ReadPin(IN_5_GPIO_Port, IN_5_Pin)==0))	// NorthEast
					{
						report_data[0]=32767;		// NE
						report_data[1]=-32767;
						HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, 1);
					}
			if ((HAL_GPIO_ReadPin(IN_4_GPIO_Port, IN_4_Pin)==0)&&(HAL_GPIO_ReadPin(IN_5_GPIO_Port, IN_5_Pin)==0))	// SouthEast
					{
						report_data[0]=32767;		// SE
						report_data[1]=32767;
						HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, 1);
					}
			if ((HAL_GPIO_ReadPin(IN_3_GPIO_Port, IN_3_Pin)==0)&&(HAL_GPIO_ReadPin(IN_6_GPIO_Port, IN_6_Pin)==0))	// SouthWest
					{
						report_data[0]=-32767;		// SW
						report_data[1]=32767;
						HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, 1);
					}
			if ((HAL_GPIO_ReadPin(IN_3_GPIO_Port, IN_3_Pin)==0)&&(HAL_GPIO_ReadPin(IN_6_GPIO_Port, IN_6_Pin)==0))	// NorthWest
					{
						report_data[0]=-32767;		// NW
						report_data[1]=-32767;
						HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, 1);
					}


			if (HAL_GPIO_ReadPin(IN_9_GPIO_Port, IN_9_Pin)==0) HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, 1);
			if (HAL_GPIO_ReadPin(IN_1_GPIO_Port, IN_1_Pin)==0) HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, 1);

#if (BUTTONS_ENABLED == 1)
			report_data[2] = buttons_state;
#endif

			USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*) &report_data, (AXIS_NUM + BUTTONS_ENABLED)*sizeof(uint16_t));
			data_ready = 0;
		}




//HAL_Delay(20);







  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSI48;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
