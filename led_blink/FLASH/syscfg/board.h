/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BOARD_H
#define BOARD_H

#ifndef USE_PERIPHERAL_FRAMES
#define USE_PERIPHERAL_FRAMES
#endif

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//

#include "driverlib.h"
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************

//
// EPWM1 -> ePWM_MOTOR Pinmux
//
//
// EPWM1_A - GPIO Settings
//
#define GPIO_PIN_EPWM1_A 0
#define ePWM_MOTOR_EPWMA_GPIO 0
#define ePWM_MOTOR_EPWMA_PIN_CONFIG GPIO_0_EPWM1_A
//
// EPWM1_B - GPIO Settings
//
#define GPIO_PIN_EPWM1_B 1
#define ePWM_MOTOR_EPWMB_GPIO 1
#define ePWM_MOTOR_EPWMB_PIN_CONFIG GPIO_1_EPWM1_B
//
// GPIO2 - GPIO Settings
//
#define GPIO_Sensor0_GPIO_PIN_CONFIG GPIO_2_GPIO2
//
// GPIO3 - GPIO Settings
//
#define GPIO_Sensor1_GPIO_PIN_CONFIG GPIO_3_GPIO3
//
// GPIO4 - GPIO Settings
//
#define GPIO_Sensor2_GPIO_PIN_CONFIG GPIO_4_GPIO4
//
// GPIO5 - GPIO Settings
//
#define GPIO_Sensor3_GPIO_PIN_CONFIG GPIO_5_GPIO5
//
// GPIO19 - GPIO Settings
//
#define myBoardLED1_GPIO_GPIO_PIN_CONFIG GPIO_19_GPIO19
//
// GPIO62 - GPIO Settings
//
#define myBoardLED2_GPIO_GPIO_PIN_CONFIG GPIO_62_GPIO62

//
// UARTA -> UI_UART Pinmux
//
//
// UARTA_TX - GPIO Settings
//
#define GPIO_PIN_UARTA_TX 42
#define UI_UART_UARTTX_GPIO 42
#define UI_UART_UARTTX_PIN_CONFIG GPIO_42_UARTA_TX
//
// UARTA_RX - GPIO Settings
//
#define GPIO_PIN_UARTA_RX 43
#define UI_UART_UARTRX_GPIO 43
#define UI_UART_UARTRX_PIN_CONFIG GPIO_43_UARTA_RX

//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************
#define Timer_1ms_BASE CPUTIMER0_BASE
void Timer_1ms_init();

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
#define ePWM_MOTOR_BASE EPWM1_BASE
#define ePWM_MOTOR_TBPRD 9999
#define ePWM_MOTOR_COUNTER_MODE EPWM_COUNTER_MODE_UP
#define ePWM_MOTOR_TBPHS 0
#define ePWM_MOTOR_CMPA 5000
#define ePWM_MOTOR_CMPB 0
#define ePWM_MOTOR_CMPC 0
#define ePWM_MOTOR_CMPD 0
#define ePWM_MOTOR_DBRED 10
#define ePWM_MOTOR_DBFED 10
#define ePWM_MOTOR_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define ePWM_MOTOR_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define ePWM_MOTOR_INTERRUPT_SOURCE EPWM_INT_TBCTR_PERIOD

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************

// Interrupt Settings for Timer_1ms_INT -> INT_TIMER0
#define Timer_1ms_INT INT_TIMER0
__attribute__((interrupt("INT"))) extern void INT_Timer_1ms_ISR(void);

// Interrupt Settings for ePWM_MOTOR_ET_INT -> INT_EPWM1
#define ePWM_MOTOR_ET_INT INT_EPWM1
__attribute__((interrupt("INT"))) extern void INT_ePWM_MOTOR_ISR(void);

// Interrupt Settings for UI_UART_UART_INT -> INT_UARTA
#define UI_UART_UART_INT INT_UARTA
__attribute__((interrupt("INT"))) extern void INT_UI_UART_ISR(void);

//*****************************************************************************
//
// UART Configurations
//
//*****************************************************************************
//
// UI_UART Configuration
//
#define UI_UART_BASE UARTA_BASE
#define UI_UART_BAUDRATE 15000000
#define UI_UART_CONFIG_WLEN UART_CONFIG_WLEN_8
#define UI_UART_CONFIG_STP2 UART_CONFIG_STOP_ONE
#define UI_UART_CONFIG_EPS UART_CONFIG_PAR_ODD
#define UI_UART_CONFIG_SPS 0
#define UI_UART_FIFO_TXIFLSEL UART_FIFO_TX4_8
#define UI_UART_FIFO_RXIFLSEL UART_FIFO_RX7_8
void    UI_UART_init();




//*****************************************************************************
//
// RTDMA1 MPU Configurations
//
//*****************************************************************************


//*****************************************************************************
//
// RTDMA2 MPU Configurations
//
//*****************************************************************************


//*****************************************************************************
//
// CMPSS Configurations
//
//*****************************************************************************
void CMPSS_MUX_config();

//*****************************************************************************
//
// RTDMA1 Configurations
//
//*****************************************************************************
void RTDMA1_global_init();

//*****************************************************************************
//
// RTDMA2 Configurations
//
//*****************************************************************************
void RTDMA2_global_init();

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define GPIO_Sensor0 2
void GPIO_Sensor0_init();
#define GPIO_Sensor1 3
void GPIO_Sensor1_init();
#define GPIO_Sensor2 4
void GPIO_Sensor2_init();
#define GPIO_Sensor3 5
void GPIO_Sensor3_init();
#define myBoardLED1_GPIO 19
void myBoardLED1_GPIO_init();
#define myBoardLED2_GPIO 62
void myBoardLED2_GPIO_init();


//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	CPUTIMER_init();
void	EPWM_init();
void	INTERRUPT_init();
void	UART_init();
void	PinMux_init();
void	PERCONFIG_init();
void	RTDMA1_MPU_init();
void	RTDMA2_MPU_init();
void    INPUTXBAR_init();
void	GPIO_init();
void	AIO_init();
void    CMPSS_init();
void	RTDMA1_init();
void	RTDMA2_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition
