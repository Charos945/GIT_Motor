/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Motor_Control.h"
#include "rtwtypes.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */
static void UploadData(void);	// upload paramters to simulink by uart2.
/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_adc1;
extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim5;
extern DMA_HandleTypeDef hdma_usart2_tx;
extern DMA_HandleTypeDef hdma_usart2_rx;
extern UART_HandleTypeDef huart2;
/* USER CODE BEGIN EV */
extern TIM_HandleTypeDef htim2;
float Ia_arr[2000];
uint8_t Hall_Arr[6],Hall_Sector,Hall_InterruptCnt,Hall_a,Hall_b,Hall_c;
uint16_t Hall_TimerCnt;
uint16_t arr_index,Sampling_cnt;
/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */
	

	
  {
    extern volatile uint32_t remainAutoReloadTimerLoopVal_S;

    /* Manage number of loop before interrupt has to be processed. */
    if (remainAutoReloadTimerLoopVal_S) {
      remainAutoReloadTimerLoopVal_S--;
    }
  }

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles DMA1 stream5 global interrupt.
  */
void DMA1_Stream5_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream5_IRQn 0 */

  /* USER CODE END DMA1_Stream5_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart2_rx);
  /* USER CODE BEGIN DMA1_Stream5_IRQn 1 */

  /* USER CODE END DMA1_Stream5_IRQn 1 */
}

/**
  * @brief This function handles DMA1 stream6 global interrupt.
  */
void DMA1_Stream6_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream6_IRQn 0 */

  /* USER CODE END DMA1_Stream6_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart2_tx);
  /* USER CODE BEGIN DMA1_Stream6_IRQn 1 */

  /* USER CODE END DMA1_Stream6_IRQn 1 */
}

/**
  * @brief This function handles ADC1 global interrupt.
  */

void ADC_IRQHandler(void)
{
  /* USER CODE BEGIN ADC_IRQn 0 */
	HAL_GPIO_WritePin(GPIOB,LED1_Pin,1);
	//HAL_ADCEx_InjectedStop_IT(&hadc1);
	// HAL_NVIC_DisableIRQ(ADC_IRQn);
	//HAL_ADCEx_InjectedStart(&hadc1);
		rtU.Timer_counter=__HAL_TIM_GET_COUNTER(&htim5);
               
	 //ADC_IRQ();
	  
	
	
	Ia_A=((float)HAL_ADCEx_InjectedGetValue(&hadc1,1)-2043.0f)*0.01611328125f;
	Ib_A=((float)HAL_ADCEx_InjectedGetValue(&hadc1,2)-2043.0f)*0.01611328125f;
	Ic_A=((float)HAL_ADCEx_InjectedGetValue(&hadc1,3)-2043.0f)*0.01611328125f;
	
	
	U_voltage=(float)ADC_Value[3]*0.017947f;
	V_voltage=(float)ADC_Value[4]*0.017947f;
	W_voltage=(float)ADC_Value[5]*0.017947f;
//	

  if(Debug_SetSpeed<100)
	{
	 rtU.Speed_target = Speed_In;
	}else if(Debug_SetSpeed>100)
	{
	  rtU.Speed_target = Debug_SetSpeed;
	}
	
	rtU.Phase_CurrentABC[0] = Ia_A;
	rtU.Phase_CurrentABC[1] = Ib_A;
	rtU.Phase_CurrentABC[2] = Ic_A;
	rtU.Bus_Voltage=Bus_volt_V;//24

	
	 //rtU.Angle_Theta =0;
	 
	
	if(EnDisable_flag==1)
	{
	rtU.Start_Stop=1;
	Motor_Control_step();
	}
		
Sampling_cnt++;
	if(Sampling_cnt>5)
	{
		UploadData();
		Sampling_cnt=0;
	Ia_arr[arr_index]=Hall_Angle;
	arr_index++;
	if(arr_index>=1999)
	{
		arr_index=0;
	}
}
	
////  rtY.Ta=0;
////	rtY.Tb=0;
////	rtY.Tc=0;
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,(uint16_t) rtY.Ta);
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,(uint16_t) rtY.Tb);
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,(uint16_t) rtY.Tc);
	//DAC
	//__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,(uint16_t)(rtY.Ubeta_Ealpha[0]*525));
	//__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,(uint16_t)(rtY.Ubeta_Ealpha[1]*525));
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,(uint16_t)(rtY.Ta*334));
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,(uint16_t)(rtY.Tb*334));
 // MotorControl_step();

  /* USER CODE END ADC_IRQn 0 */
  HAL_ADC_IRQHandler(&hadc1);
  /* USER CODE BEGIN ADC_IRQn 1 */
//	HAL_ADCEx_InjectedStart_IT(&hadc1);
 HAL_GPIO_WritePin(GPIOB,LED1_Pin,0);
  /* USER CODE END ADC_IRQn 1 */
}

/**
  * @brief This function handles TIM1 break interrupt and TIM9 global interrupt.
  */
void TIM1_BRK_TIM9_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_BRK_TIM9_IRQn 0 */
  
  /* USER CODE END TIM1_BRK_TIM9_IRQn 0 */
  HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_BRK_TIM9_IRQn 1 */
 
  /* USER CODE END TIM1_BRK_TIM9_IRQn 1 */
}

/**
  * @brief This function handles TIM1 update interrupt and TIM10 global interrupt.
  */
void TIM1_UP_TIM10_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_UP_TIM10_IRQn 0 */
	
//HAL_GPIO_WritePin(GPIOB,LED2_Pin,1);
//__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4, 2100);
  /* USER CODE END TIM1_UP_TIM10_IRQn 0 */
  HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_UP_TIM10_IRQn 1 */
 // HAL_GPIO_WritePin(GPIOB,LED2_Pin,0);
  /* USER CODE END TIM1_UP_TIM10_IRQn 1 */
}

/**
  * @brief This function handles TIM2 global interrupt.
  */
void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */

  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */
	//Hall_Sector
	//Hall_InterruptCn
  Hall_a=HAL_GPIO_ReadPin(Hall_A_GPIO_Port,Hall_A_Pin);
	Hall_b=HAL_GPIO_ReadPin(Hall_B_GPIO_Port,Hall_B_Pin);
	Hall_c=HAL_GPIO_ReadPin(Hall_C_GPIO_Port,Hall_C_Pin);
  Hall_Sector=Hall_a | Hall_b<<1 | Hall_c<<2;
	Hall_Arr[Hall_InterruptCnt]=Hall_Sector;
  Hall_InterruptCnt++;
	
	rtU.Hall[0]=Hall_a;
	rtU.Hall[1]=Hall_b;
	rtU.Hall[2]=Hall_c;
	rtU.Timer_counter=__HAL_TIM_GET_COUNTER(&htim5);
	//ACC_OMG();
	
	if(Hall_InterruptCnt>=6)
	{
	 Hall_InterruptCnt=0;
	}
	switch  (Hall_Sector)
	{
		case 5:
			break;
		case 1:
			break;
		case 3:
			break;
		case 2:
			break;
		case 6:
			break;
		case 4:
			break;
	}
	
  /* USER CODE END TIM2_IRQn 1 */
}

/**
  * @brief This function handles TIM3 global interrupt.
  */
void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM3_IRQn 0 */
	//HAL_GPIO_TogglePin(GPIOB,LED1_Pin);
	
	rtU.Torque_ref=3;
	Bus_volt_V=ADC_Value[0]*0.017947;
	Speed_In = (float)ADC_Value[1]*0.45945f+800;
	if(Speed_In<800)Speed_In=800;
	Task_100ms++;
	if(Task_100ms>8000)//100ms
	{
		
	 Task_100ms=0;
	}
	Task_10ms++;
	if(Task_10ms>800)//10ms
	{
		
	  Task_10ms=0;
	}
	Task_2ms++;
	if(Task_2ms>160)
	{
	Task_2ms=0;
	}

  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */

  /* USER CODE END TIM3_IRQn 1 */
}

/**
  * @brief This function handles USART2 global interrupt.
  */
void USART2_IRQHandler(void)
{
  /* USER CODE BEGIN USART2_IRQn 0 */
  extern uint8_t aRxBuffer[];
	extern float comm[6];
	extern CRC_HandleTypeDef hcrc;
	uint32_t crc_calc, crc_comm;
	
  /* USER CODE END USART2_IRQn 0 */
  HAL_UART_IRQHandler(&huart2);
  /* USER CODE BEGIN USART2_IRQn 1 */
if( __HAL_UART_GET_FLAG( &huart2, UART_FLAG_IDLE) != RESET)
	{
		crc_comm = (aRxBuffer[12]<<8) + aRxBuffer[13];
		crc_calc = HAL_CRC_Calculate( &hcrc, (uint32_t *)aRxBuffer, 12);
		if( crc_comm == crc_calc)
		{
			//memcpy(comm, aRxBuffer, 4*3);
		}

		HAL_UART_Receive_DMA( &huart2, aRxBuffer, 14);
		__HAL_UART_CLEAR_FLAG( &huart2, UART_FLAG_IDLE);
	}
  /* USER CODE END USART2_IRQn 1 */
}

/**
  * @brief This function handles EXTI line[15:10] interrupts.
  */
void EXTI15_10_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI15_10_IRQn 0 */
	EnDisable_flag=1;
      HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);

      /* Enable the complementary PWM output 1. */
      HAL_TIMEx_PWMN_Start(&htim1,TIM_CHANNEL_1);

      HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);

      /* Enable the complementary PWM output 2. */
      HAL_TIMEx_PWMN_Start(&htim1,TIM_CHANNEL_2);
			
      HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
			
      /* Enable the complementary PWM output 3. */
      HAL_TIMEx_PWMN_Start(&htim1,TIM_CHANNEL_3);

	
  /* USER CODE END EXTI15_10_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
  /* USER CODE BEGIN EXTI15_10_IRQn 1 */

  /* USER CODE END EXTI15_10_IRQn 1 */
}

/**
  * @brief This function handles TIM5 global interrupt.
  */
void TIM5_IRQHandler(void)
{
  /* USER CODE BEGIN TIM5_IRQn 0 */
//HAL_GPIO_WritePin(GPIOB,LED2_Pin,1);
	HAL_GPIO_TogglePin(GPIOB,LED2_Pin);
  /* USER CODE END TIM5_IRQn 0 */
  HAL_TIM_IRQHandler(&htim5);
  /* USER CODE BEGIN TIM5_IRQn 1 */

  /* USER CODE END TIM5_IRQn 1 */
}

/**
  * @brief This function handles DMA2 stream0 global interrupt.
  */
void DMA2_Stream0_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream0_IRQn 0 */

  /* USER CODE END DMA2_Stream0_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_adc1);
  /* USER CODE BEGIN DMA2_Stream0_IRQn 1 */

  /* USER CODE END DMA2_Stream0_IRQn 1 */
}

/* USER CODE BEGIN 1 */
void UploadData(void)
{
	extern UART_HandleTypeDef huart2;
	static int16_T temp[15];//float temp[15];
	static uint16_t time_count;
 
	if( time_count == 0)
	{
		time_count++;
		temp[0] = *(int16_T*)"AA";
		temp[1] =(int16_T)(Hall_Speed*10);
		temp[2] =(int16_T)(Obs_Speed*10);
		temp[3] =(int16_T)(Hall_Angle*1000);
		temp[4] =(int16_T)(Obs_Theta*1000);
		temp[5] =(int16_T)(Ia_A*100);
	
		__HAL_UNLOCK( huart2.hdmatx);
		huart2.gState = HAL_UART_STATE_READY;
		huart2.hdmatx->State = HAL_DMA_STATE_READY;
		HAL_UART_Transmit_DMA( &huart2, (uint8_t *)temp, 6*2);
	}
	else if( time_count == 999)
	{
		temp[0] = (int16_T)(Hall_Speed*10);
		temp[1] = (int16_T)(Obs_Speed*10);
		temp[2] = (int16_T)(Hall_Angle*1000);
		temp[3] = (int16_T)(Obs_Theta*1000);
		temp[4] = (int16_T)(Ia_A*100);
		
		temp[5] = *(int16_T*)"BB";
		__HAL_UNLOCK( huart2.hdmatx);
		huart2.gState = HAL_UART_STATE_READY;
		huart2.hdmatx->State = HAL_DMA_STATE_READY;
		HAL_UART_Transmit_DMA( &huart2, (uint8_t *)temp, 6*2);
		time_count = 0;
	}
	else
	{
		time_count++;
		temp[0] = (int16_T)(Hall_Speed*10);
		temp[1] = (int16_T)(Obs_Speed*10);
		temp[2] = (int16_T)(Hall_Angle*1000);
		temp[3] = (int16_T)(Obs_Theta*1000);
		temp[4] = (int16_T)(Ia_A*100);
		
		__HAL_UNLOCK( huart2.hdmatx);
		huart2.gState = HAL_UART_STATE_READY;
		huart2.hdmatx->State = HAL_DMA_STATE_READY;
		HAL_UART_Transmit_DMA( &huart2, (uint8_t *)temp, 5*2);
	}
}

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
