/***********************************************************************************************************************
 * Copyright [2015-2017] Renesas Electronics Corporation and/or its licensors. All Rights Reserved.
 * 
 * This file is part of Renesas SynergyTM Software Package (SSP)
 *
 * The contents of this file (the "contents") are proprietary and confidential to Renesas Electronics Corporation
 * and/or its licensors ("Renesas") and subject to statutory and contractual protections.
 *
 * This file is subject to a Renesas SSP license agreement. Unless otherwise agreed in an SSP license agreement with
 * Renesas: 1) you may not use, copy, modify, distribute, display, or perform the contents; 2) you may not use any name
 * or mark of Renesas for advertising or publicity purposes or in connection with your use of the contents; 3) RENESAS
 * MAKES NO WARRANTY OR REPRESENTATIONS ABOUT THE SUITABILITY OF THE CONTENTS FOR ANY PURPOSE; THE CONTENTS ARE PROVIDED
 * "AS IS" WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, AND NON-INFRINGEMENT; AND 4) RENESAS SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, OR
 * CONSEQUENTIAL DAMAGES, INCLUDING DAMAGES RESULTING FROM LOSS OF USE, DATA, OR PROJECTS, WHETHER IN AN ACTION OF
 * CONTRACT OR TORT, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THE CONTENTS. Third-party contents
 * included in this file may be subject to different terms.
 **********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : hal_entry.c
* Description  : This is a very simple example application that blinks all LEDs on a board.
***********************************************************************************************************************/

#include "hal_data.h"
#include <stdio.h>
volatile uint32_t timerFlag;
timer_size_t recebidos;


/* Callback function */
void cb0(timer_callback_args_t *p_args)
{
    /* TODO: add your own code here */
    if(timerFlag)
    {
        g_timer0.p_api->reset(g_timer0.p_ctrl);
        g_timer0.p_api->periodSet(g_timer0.p_ctrl, 3, TIMER_UNIT_PERIOD_SEC);
        g_timer0.p_api->start(g_timer0.p_ctrl);
        g_external_irq0.p_api->enable(g_external_irq0.p_ctrl);
        timerFlag=0;
    }
    else
    {
        g_timer0.p_api->reset(g_timer0.p_ctrl);
        g_timer0.p_api->periodSet(g_timer0.p_ctrl, 1, TIMER_UNIT_PERIOD_SEC);
        g_timer0.p_api->start(g_timer0.p_ctrl);
        g_external_irq0.p_api->disable(g_external_irq0.p_ctrl);
        timerFlag = 1;

    }
}
/* Callback function */
void switch_callback(external_irq_callback_args_t *p_args)
{
    /* TODO: add your own code here */
    timer_size_t cronometro = 0;
    g_timer0.p_api->counterGet(g_timer0.p_ctrl, &cronometro);
    recebidos = cronometro;
    timerFlag = 0;
}

/*******************************************************************************************************************//**
 * @brief  Blinky example application
 *
 * Blinks all leds at a rate of 1 second using the software delay function provided by the BSP.
 * Only references two other modules including the BSP, IOPORT.
 *
 **********************************************************************************************************************/
void hal_entry(void) {

	/* Define the units to be used with the software delay function */
	const bsp_delay_units_t bsp_delay_units = BSP_DELAY_UNITS_MILLISECONDS;
	/* Set the blink frequency (must be <= bsp_delay_units */
    const uint32_t freq_in_hz = 2;
	/* Calculate the delay in terms of bsp_delay_units */
    const uint32_t delay = bsp_delay_units/freq_in_hz;
	/* LED type structure */
    bsp_leds_t leds;
	/* LED state variable */
    ioport_level_t level = IOPORT_LEVEL_HIGH;

    /* Get LED information for this board */
    R_BSP_LedsGet(&leds);

    /* If this board has no LEDs then trap here */
    if (0 == leds.led_count)
    {
        while(1);   // There are no LEDs on this board
    }
    g_timer0.p_api->open(g_timer0.p_ctrl, g_timer0.p_cfg);
    g_external_irq0.p_api->open(g_external_irq0.p_ctrl, g_external_irq0.p_cfg);
    g_external_irq0.p_api->disable(g_external_irq0.p_ctrl);

    timerFlag = 0;

    while(1)
    {
        /* Determine the next state of the LEDs */
        //level = IOPORT_LEVEL_HIGH;
        //level = IOPORT_LEVEL_LOW;

        /* Update all board LEDs */
        for(uint32_t i = 0; i < leds.led_count; i++)
        {
            g_ioport.p_api->pinWrite(leds.p_leds[i], level);
        }
        if(timerFlag)
            level = IOPORT_LEVEL_HIGH;
        else
            level = IOPORT_LEVEL_LOW;

        /* Delay */
        R_BSP_SoftwareDelay(delay, bsp_delay_units);
    }
}
