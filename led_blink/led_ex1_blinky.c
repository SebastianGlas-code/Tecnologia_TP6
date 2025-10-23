//#############################################################################
//
// FILE:    led_ex1_blinky.c
//
// TITLE:   LED Blinky example
//
//! \addtogroup driver_example_list
//! <h1> LED Blinky example </h1>
//!
//! This example demonstrates how to blink an LED. The device GPIO is
//! configured through the sysconfig file. The GPIO pin is toggled in an
//! infinite loop.
//
//#############################################################################
//
//
// //
//	Copyright: Copyright (C) Texas Instruments Incorporated
//	All rights reserved not granted herein.
//
//  Redistribution and use in source and binary forms, with or without 
//  modification, are permitted provided that the following conditions 
//  are met:
//
//  Redistributions of source code must retain the above copyright 
//  notice, this list of conditions and the following disclaimer.
//
//  Redistributions in binary form must reproduce the above copyright
//  notice, this list of conditions and the following disclaimer in the 
//  documentation and/or other materials provided with the   
//  distribution.
//
//  Neither the name of Texas Instruments Incorporated nor the names of
//  its contributors may be used to endorse or promote products derived
//  from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

//#############################################################################

//
// Included Files
//
#include "board.h"
#include "Link.h"
#include "Link_Func.h"
#include "math.h"

//
// Macros
//
#define MOTOR_FREQ 50.0f
#define MOTOR_N_INV 0.00005f



//
// Globals
//
volatile unsigned int led_status = 0;
volatile unsigned long cpuTimer0IntCount = 0;
volatile unsigned long ePMW_isr_count = 0;


//
// Prototypes
//
__attribute__((interrupt("INT"))) void INT_Timer_1ms_ISR(void);

__attribute__((interrupt("INT")))void INT_ePWM_MOTOR_ISR(void);


//
// Main
//
int main(void)
{
    //
    // Initialize device clock, peripheral clocks and interrupts
    //
    Device_init();

    //
    // Board Initialization
    //
    Board_init();

    //
    // Enable PIPE Global Interrupt (for INTs and RTINTs) and INT enable in CPU.
    //
    ENINT;
    Interrupt_enableGlobal();



    //
    // Loop.
    //
    for(;;)
    {
        //
        // Delay for a bit.
        //
        DEVICE_DELAY_US(10);
    }
}

void INT_Timer_1ms_ISR(void)
{
    cpuTimer0IntCount++;

    if(!(cpuTimer0IntCount % 1000))
    {
        cpuTimer0IntCount = 0;
        // led_status ^= 0x0001;
        led_status = (led_status+1) % 2;
        GPIO_writePin(myBoardLED1_GPIO, led_status);
    }

}


void INT_ePWM_MOTOR_ISR(void)
{
    ePMW_isr_count ++;
    
    
    const uint32_t tbprd = EPWM_getTimeBasePeriod(ePWM_MOTOR_BASE);
    // uint32_t compa = EPWM_getCounterCompareValue(ePWM_MOTOR_BASE, EPWM_COUNTER_COMPARE_A);

    if (ePMW_isr_count == tbprd) ePMW_isr_count=0;
    const float raw_out = 0.5f *sinf(2*M_PI* MOTOR_FREQ * (float)ePMW_isr_count * MOTOR_N_INV );
    const float scaled_output = 0.5f + (motor_status * motor_speed *raw_out);
    const uint16_t cmpa = (uint16_t)(scaled_output * (float)tbprd);

    EPWM_setCounterCompareValue(ePWM_MOTOR_BASE, EPWM_COUNTER_COMPARE_A, cmpa);

    EPWM_clearEventTriggerInterruptFlag(ePWM_MOTOR_BASE);
}

//
// End of File
//

