/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f4xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Stop_Start_Pin GPIO_PIN_13
#define Stop_Start_GPIO_Port GPIOC
#define Stop_Start_EXTI_IRQn EXTI15_10_IRQn
#define Current_W_Pin GPIO_PIN_0
#define Current_W_GPIO_Port GPIOC
#define Current_V_Pin GPIO_PIN_1
#define Current_V_GPIO_Port GPIOC
#define NTC_Pin GPIO_PIN_2
#define NTC_GPIO_Port GPIOC
#define U_volt_Pin GPIO_PIN_3
#define U_volt_GPIO_Port GPIOC
#define Current_U_Pin GPIO_PIN_0
#define Current_U_GPIO_Port GPIOA
#define Bus_Volt_Pin GPIO_PIN_1
#define Bus_Volt_GPIO_Port GPIOA
#define UART_TX_Pin GPIO_PIN_2
#define UART_TX_GPIO_Port GPIOA
#define UART_RX_Pin GPIO_PIN_3
#define UART_RX_GPIO_Port GPIOA
#define Speed_Pin GPIO_PIN_4
#define Speed_GPIO_Port GPIOA
#define OCP_Pin GPIO_PIN_6
#define OCP_GPIO_Port GPIOA
#define UL_Pin GPIO_PIN_7
#define UL_GPIO_Port GPIOA
#define V_volt_Pin GPIO_PIN_4
#define V_volt_GPIO_Port GPIOC
#define W_volt_Pin GPIO_PIN_5
#define W_volt_GPIO_Port GPIOC
#define VL_Pin GPIO_PIN_0
#define VL_GPIO_Port GPIOB
#define WL_Pin GPIO_PIN_1
#define WL_GPIO_Port GPIOB
#define Hall_C_Pin GPIO_PIN_10
#define Hall_C_GPIO_Port GPIOB
#define UH_Pin GPIO_PIN_8
#define UH_GPIO_Port GPIOA
#define VH_Pin GPIO_PIN_9
#define VH_GPIO_Port GPIOA
#define WH_Pin GPIO_PIN_10
#define WH_GPIO_Port GPIOA
#define Hall_A_Pin GPIO_PIN_15
#define Hall_A_GPIO_Port GPIOA
#define Hall_B_Pin GPIO_PIN_3
#define Hall_B_GPIO_Port GPIOB
#define DAC1_Pin GPIO_PIN_4
#define DAC1_GPIO_Port GPIOB
#define DAC2_Pin GPIO_PIN_5
#define DAC2_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_6
#define LED1_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_7
#define LED2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
	
extern int16_t Task_10ms;
extern int16_t Task_100ms;
extern int16_t Task_2ms;
//Voltage
extern uint32_t ADC_Value[6];
extern float Bus_volt_V,Ia_A,Ib_A,Ic_A;
extern float Tempreture,U_voltage,V_voltage,W_voltage,Speed_In;
extern uint8_t EnDisable_flag;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
