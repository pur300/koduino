/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Templates/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.8.0
  * @date    04-November-2016
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2016 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "timer.h"
#include "timebase.h"
#include "exti.h"
#include "variant.h"
#include "USARTClass.h"

/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}


/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */

// General purpose timers
void TIM1_CC_IRQHandler() {
  timerISR(TIMER1);
}
void TIM2_IRQHandler() {
  timerISR(TIMER2);
}
void TIM3_IRQHandler() {
  timerISR(TIMER3);
}
void TIM4_IRQHandler() {
  timerISR(TIMER4);
}
void TIM5_IRQHandler() {
  timerISR(TIMER5);
}
void TIM8_CC_IRQHandler() {
  timerISR(TIMER8);
}
void TIM1_BRK_TIM9_IRQHandler() {
  timerISR(TIMER9);
}
void TIM8_BRK_TIM12_IRQHandler() {
  timerISR(TIMER12);
}
void TIM1_UP_TIM10_IRQHandler() {
  timerISR(TIMER10);
}
void TIM1_TRG_COM_TIM11_IRQHandler() {
  timerISR(TIMER11);
}
void TIM8_UP_TIM13_IRQHandler() {
  timerISR(TIMER13);
}
void TIM8_TRG_COM_TIM14_IRQHandler() {
  timerISR(TIMER14);
}

// Timebase
void TIM6_DAC_IRQHandler() {
  timebaseISR(0, TIMER6);
}
void TIM7_IRQHandler() {
  timebaseISR(1, TIMER7);
}

// EXTI

// USART
void USART1_IRQHandler() {
  wirishUSARTInterruptHandler(&USART_MAP[0]);
}
void USART2_IRQHandler() {
  wirishUSARTInterruptHandler(&USART_MAP[1]);
}
void USART3_IRQHandler() {
  wirishUSARTInterruptHandler(&USART_MAP[2]);
}
void UART4_IRQHandler() {
  wirishUSARTInterruptHandler(&USART_MAP[3]);
}
void UART5_IRQHandler() {
  wirishUSARTInterruptHandler(&USART_MAP[4]);
}
void USART6_IRQHandler() {
  wirishUSARTInterruptHandler(&USART_MAP[5]);
}

/**
  * @}
  */ 


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
