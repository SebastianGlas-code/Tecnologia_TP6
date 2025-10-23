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

#include "board.h"

//*****************************************************************************
//
// Board Configurations
// Initializes the rest of the modules.
// Call this function in your application if you wish to do all module
// initialization.
// If you wish to not use some of the initializations, instead of the
// Board_init use the individual Module_inits
//
//*****************************************************************************
void Board_init()
{
	PinMux_init();
	PERCONFIG_init();
	INPUTXBAR_init();
	AIO_init();
	GPIO_init();
	CMPSS_init();
	RTDMA1_init();
	RTDMA2_init();
	CPUTIMER_init();
	EPWM_init();
	UART_init();
	INTERRUPT_init();
}

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void PinMux_init()
{
	//
	// PinMux for modules assigned to CPU1
	//

	//
	// EPWM1 -> ePWM_MOTOR Pinmux
	//
	GPIO_setPinConfig(ePWM_MOTOR_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(ePWM_MOTOR_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(ePWM_MOTOR_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(ePWM_MOTOR_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(ePWM_MOTOR_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(ePWM_MOTOR_EPWMB_GPIO, GPIO_QUAL_SYNC);


	// GPIO2 -> GPIO_Sensor0 Pinmux
	GPIO_setPinConfig(GPIO_2_GPIO2);

	// GPIO3 -> GPIO_Sensor1 Pinmux
	GPIO_setPinConfig(GPIO_3_GPIO3);

	// GPIO4 -> GPIO_Sensor2 Pinmux
	GPIO_setPinConfig(GPIO_4_GPIO4);

	// GPIO5 -> GPIO_Sensor3 Pinmux
	GPIO_setPinConfig(GPIO_5_GPIO5);

	// GPIO19 -> myBoardLED1_GPIO Pinmux
	GPIO_setPinConfig(GPIO_19_GPIO19);

	// GPIO62 -> myBoardLED2_GPIO Pinmux
	GPIO_setPinConfig(GPIO_62_GPIO62);
	//
	// UARTA -> UI_UART Pinmux
	//
	GPIO_setPinConfig(UI_UART_UARTTX_PIN_CONFIG);
	GPIO_setPadConfig(UI_UART_UARTTX_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(UI_UART_UARTTX_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(UI_UART_UARTRX_PIN_CONFIG);
	GPIO_setPadConfig(UI_UART_UARTRX_GPIO, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(UI_UART_UARTRX_GPIO, GPIO_QUAL_ASYNC);


}

//*****************************************************************************
//
// Peripheral Configurations
//
//*****************************************************************************
void PERCONFIG_init()
{
	//
	// Configuration for modules assigned to CPU1
	//
    SysCtl_selectCPUForPeripheral(SYSCTL_PERIPH_CONFIG_EPWM1, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectFrameForPeripheral(SYSCTL_PERIPH_CONFIG_EPWM1, SYSCTL_FRAMESEL_0);
    SysCtl_selectCPUForPeripheral(SYSCTL_PERIPH_CONFIG_UARTA, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectFrameForPeripheral(SYSCTL_PERIPH_CONFIG_UARTA, SYSCTL_FRAMESEL_0);

	//
	// Inserting some delay for frame updates to take effect
	//
    SysCtl_delay(100);
}


//*****************************************************************************
//
// INPUTXBAR Configurations
//
//*****************************************************************************
void INPUTXBAR_init(){
}



//*****************************************************************************
//
// RTDMA1 MPU Configurations
//
//*****************************************************************************
void RTDMA1_MPU_init(){
}

//*****************************************************************************
//
// RTDMA2 MPU Configurations
//
//*****************************************************************************
void RTDMA2_MPU_init(){
}

//*****************************************************************************
//
// CMPSS Configurations
//
//*****************************************************************************
void CMPSS_init(){
    CMPSS_MUX_config();
}

void CMPSS_MUX_config(){
}


//*****************************************************************************
//
// RTDMA1 Configurations
//
//*****************************************************************************
void RTDMA1_init(){
    RTDMA1_global_init();
    RTDMA1_MPU_init();
}

void RTDMA1_global_init(){
}


//*****************************************************************************
//
// RTDMA2 Configurations
//
//*****************************************************************************
void RTDMA2_init(){
    RTDMA2_global_init();
    RTDMA2_MPU_init();
}

void RTDMA2_global_init(){
}

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void GPIO_init(){
	GPIO_Sensor0_init();
	GPIO_Sensor1_init();
	GPIO_Sensor2_init();
	GPIO_Sensor3_init();
	myBoardLED1_GPIO_init();
	myBoardLED2_GPIO_init();
}

void GPIO_Sensor0_init(){
	GPIO_setPadConfig(GPIO_Sensor0, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(GPIO_Sensor0, GPIO_QUAL_SYNC);
	GPIO_setControllerCore(GPIO_Sensor0, GPIO_CORE_CPU1);
	GPIO_setDirectionMode(GPIO_Sensor0, GPIO_DIR_MODE_IN);
}

void GPIO_Sensor1_init(){
	GPIO_setPadConfig(GPIO_Sensor1, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(GPIO_Sensor1, GPIO_QUAL_SYNC);
	GPIO_setControllerCore(GPIO_Sensor1, GPIO_CORE_CPU1);
	GPIO_setDirectionMode(GPIO_Sensor1, GPIO_DIR_MODE_IN);
}

void GPIO_Sensor2_init(){
	GPIO_setPadConfig(GPIO_Sensor2, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(GPIO_Sensor2, GPIO_QUAL_SYNC);
	GPIO_setControllerCore(GPIO_Sensor2, GPIO_CORE_CPU1);
	GPIO_setDirectionMode(GPIO_Sensor2, GPIO_DIR_MODE_IN);
}

void GPIO_Sensor3_init(){
	GPIO_setPadConfig(GPIO_Sensor3, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(GPIO_Sensor3, GPIO_QUAL_SYNC);
	GPIO_setControllerCore(GPIO_Sensor3, GPIO_CORE_CPU1);
	GPIO_setDirectionMode(GPIO_Sensor3, GPIO_DIR_MODE_IN);
}

void myBoardLED1_GPIO_init(){
	GPIO_setPadConfig(myBoardLED1_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(myBoardLED1_GPIO, GPIO_QUAL_SYNC);
	GPIO_setControllerCore(myBoardLED1_GPIO, GPIO_CORE_CPU1);
	GPIO_setDirectionMode(myBoardLED1_GPIO, GPIO_DIR_MODE_OUT);
}

void myBoardLED2_GPIO_init(){
	GPIO_setPadConfig(myBoardLED2_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(myBoardLED2_GPIO, GPIO_QUAL_SYNC);
	GPIO_setControllerCore(myBoardLED2_GPIO, GPIO_CORE_CPU1);
	GPIO_setDirectionMode(myBoardLED2_GPIO, GPIO_DIR_MODE_OUT);
}

//*****************************************************************************
//
// AIO Configurations
//
//*****************************************************************************
void AIO_init(){
}


//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************
void CPUTIMER_init(){
	Timer_1ms_init();
}

void Timer_1ms_init(){
	CPUTimer_setEmulationMode(Timer_1ms_BASE, CPUTIMER_EMULATIONMODE_RUNFREE);
	CPUTimer_setPreScaler(Timer_1ms_BASE, 0U);
	CPUTimer_setPeriod(Timer_1ms_BASE, 200000U);
	CPUTimer_enableInterrupt(Timer_1ms_BASE);
	CPUTimer_stopTimer(Timer_1ms_BASE);

	CPUTimer_reloadTimerCounter(Timer_1ms_BASE);
	CPUTimer_startTimer(Timer_1ms_BASE);
}

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
void EPWM_init(){
    EPWM_setClockPrescaler(ePWM_MOTOR_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBaseCounterMode(ePWM_MOTOR_BASE, EPWM_COUNTER_MODE_UP);	
    EPWM_setTimeBasePeriod(ePWM_MOTOR_BASE, 9999);	
    EPWM_setTimeBaseCounter(ePWM_MOTOR_BASE, 0);	
    EPWM_disablePhaseShiftLoad(ePWM_MOTOR_BASE);	
    EPWM_setPhaseShift(ePWM_MOTOR_BASE, 0);	
    EPWM_setCounterCompareValue(ePWM_MOTOR_BASE, EPWM_COUNTER_COMPARE_A, 5000);	
    EPWM_disableCounterCompareShadowLoadMode(ePWM_MOTOR_BASE, EPWM_COUNTER_COMPARE_A);	
    EPWM_setCounterCompareShadowLoadMode(ePWM_MOTOR_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(ePWM_MOTOR_BASE, EPWM_COUNTER_COMPARE_B, 0);	
    EPWM_disableCounterCompareShadowLoadMode(ePWM_MOTOR_BASE, EPWM_COUNTER_COMPARE_B);	
    EPWM_setCounterCompareShadowLoadMode(ePWM_MOTOR_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(ePWM_MOTOR_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(ePWM_MOTOR_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(ePWM_MOTOR_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(ePWM_MOTOR_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(ePWM_MOTOR_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(ePWM_MOTOR_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(ePWM_MOTOR_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(ePWM_MOTOR_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(ePWM_MOTOR_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(ePWM_MOTOR_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(ePWM_MOTOR_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(ePWM_MOTOR_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setDeadBandDelayPolarity(ePWM_MOTOR_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    EPWM_setDeadBandDelayMode(ePWM_MOTOR_BASE, EPWM_DB_RED, true);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(ePWM_MOTOR_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(ePWM_MOTOR_BASE);	
    EPWM_setRisingEdgeDelayCount(ePWM_MOTOR_BASE, 10);	
    EPWM_setDeadBandDelayMode(ePWM_MOTOR_BASE, EPWM_DB_FED, true);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(ePWM_MOTOR_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(ePWM_MOTOR_BASE);	
    EPWM_setFallingEdgeDelayCount(ePWM_MOTOR_BASE, 10);	
    EPWM_enableInterrupt(ePWM_MOTOR_BASE);	
    EPWM_setInterruptSource(ePWM_MOTOR_BASE, EPWM_INT_TBCTR_PERIOD);	
    EPWM_setInterruptEventCount(ePWM_MOTOR_BASE, 1);	
}

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************
void INTERRUPT_init(){
	Interrupt_setThreshold(0);
    Interrupt_setGroupMask(0xFF);
    Interrupt_setRTINTSPWarning(15, 0);

	// Interrupt Settings for Timer_1ms_INT -> INT_TIMER0
	Interrupt_register(Timer_1ms_INT, &INT_Timer_1ms_ISR);
	Interrupt_enable(Timer_1ms_INT);
	Interrupt_setPriority(Timer_1ms_INT, 255);
	Interrupt_setContextID(Timer_1ms_INT, INTERRUPT_CONTEXTID_0);

	// Interrupt Settings for ePWM_MOTOR_ET_INT -> INT_EPWM1
	Interrupt_register(ePWM_MOTOR_ET_INT, &INT_ePWM_MOTOR_ISR);
	Interrupt_enable(ePWM_MOTOR_ET_INT);
	Interrupt_setPriority(ePWM_MOTOR_ET_INT, 255);
	Interrupt_setContextID(ePWM_MOTOR_ET_INT, INTERRUPT_CONTEXTID_0);

	// Interrupt Settings for UI_UART_UART_INT -> INT_UARTA
	Interrupt_register(UI_UART_UART_INT, &INT_UI_UART_ISR);
	Interrupt_enable(UI_UART_UART_INT);
	Interrupt_setPriority(UI_UART_UART_INT, 255);
	Interrupt_setContextID(UI_UART_UART_INT, INTERRUPT_CONTEXTID_0);
}

//*****************************************************************************
//
// UART Configurations
//
//*****************************************************************************
void UART_init(){
    UI_UART_init();
}

void UI_UART_init(){
        //
        // Set UI_UART baud rate and configuration
        //
        UART_setConfig(
            UI_UART_BASE, // base address
            DEVICE_SYSCLK_FREQ, // UART source clock
            15000000, // baud rate
            (UART_CONFIG_WLEN_8 | // word length
             UART_CONFIG_STOP_ONE) // stop bits
        );
        
        //
        // FIFO enable
        //
        UART_enableFIFO(UI_UART_BASE);

        //
        // FIFO trigger levels
        //
        UART_setFIFOLevel(UI_UART_BASE, UART_FIFO_TX4_8, UART_FIFO_RX7_8);
        
        //
        // Configure interrupts
        //
        UART_clearInterruptStatus(UI_UART_BASE, 0xFFFF);
        UART_enableInterrupt(UI_UART_BASE,
            (UART_INT_RX)
        );
            
        UART_disableLoopback(UI_UART_BASE);
        
        //
        // Enable RX, TX, and the UART.
        //
        UART_enableModuleNonFIFO(UI_UART_BASE);
}

