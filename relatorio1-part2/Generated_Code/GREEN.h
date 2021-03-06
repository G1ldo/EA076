/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : GREEN.h
**     Project     : relatorio1-part2
**     Processor   : MKL25Z128VLK4
**     Component   : LED
**     Version     : Component 01.077, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2020-11-08, 22:08, # CodeGen: 0
**     Abstract    :
**          This component implements a universal driver for a single LED.
**     Settings    :
**          Component name                                 : GREEN
**          Turned On with initialization                  : no
**          HW Interface                                   : 
**            On/Off                                       : Enabled
**              Pin                                        : LEDpin
**            PWM                                          : Disabled
**            High Value means ON                          : no
**          Shell                                          : Disabled
**     Contents    :
**         On         - void GREEN_On(void);
**         Off        - void GREEN_Off(void);
**         Neg        - void GREEN_Neg(void);
**         Get        - uint8_t GREEN_Get(void);
**         Put        - void GREEN_Put(uint8_t val);
**         SetRatio16 - void GREEN_SetRatio16(uint16_t ratio);
**         Deinit     - void GREEN_Deinit(void);
**         Init       - void GREEN_Init(void);
**
**Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**All Rights Reserved.
**
**Redistribution and use in source and binary forms, with or without modification,
**are permitted provided that the following conditions are met:
**
**o Redistributions of source code must retain the above copyright notice, this list
**  of conditions and the following disclaimer.
**
**o Redistributions in binary form must reproduce the above copyright notice, this
**  list of conditions and the following disclaimer in the documentation and/or
**  other materials provided with the distribution.
**
**o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**  contributors may be used to endorse or promote products derived from this
**  software without specific prior written permission.
**
**THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**http: www.freescale.com
**mail: support@freescale.com
** ###################################################################*/
/*!
** @file GREEN.h
** @version 01.00
** @brief
**          This component implements a universal driver for a single LED.
*/         
/*!
**  @addtogroup GREEN_module GREEN module documentation
**  @{
*/         

#ifndef __GREEN_H
#define __GREEN_H

/* MODULE GREEN. */
#include "MCUC1.h" /* SDK and API used */
#include "GREENconfig.h" /* LED configuration */
#include "LEDpin2.h" /* interface to pin */

#define GREEN_ClrVal()    LEDpin2_ClrVal() /* put the pin on low level */
#define GREEN_SetVal()    LEDpin2_SetVal() /* put the pin on high level */
#define GREEN_SetInput()  LEDpin2_SetInput() /* use the pin as input pin */
#define GREEN_SetOutput() LEDpin2_SetOutput() /* use the pin as output pin */

#define GREEN_PARSE_COMMAND_ENABLED  0 /* set to 1 if method ParseCommand() is present, 0 otherwise */


#if GREEN_CONFIG_IS_LOW_ACTIVE
  #define GREEN_On() LEDpin2_ClrVal()
#else
  #define GREEN_On() LEDpin2_SetVal()
#endif
/*
** ===================================================================
**     Method      :  GREEN_On (component LED)
**     Description :
**         This turns the LED on.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#if GREEN_CONFIG_IS_LOW_ACTIVE
  #define GREEN_Off() LEDpin2_SetVal()
#else
  #define GREEN_Off() LEDpin2_ClrVal()
#endif
/*
** ===================================================================
**     Method      :  GREEN_Off (component LED)
**     Description :
**         This turns the LED off.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define GREEN_Neg() LEDpin2_NegVal()
/*
** ===================================================================
**     Method      :  GREEN_Neg (component LED)
**     Description :
**         This negates/toggles the LED
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#if GREEN_CONFIG_IS_LOW_ACTIVE
  #define GREEN_Get() (!(LEDpin2_GetVal()))
#else
  #define GREEN_Get() LEDpin2_GetVal()
#endif
/*
** ===================================================================
**     Method      :  GREEN_Get (component LED)
**     Description :
**         This returns logical 1 in case the LED is on, 0 otherwise.
**     Parameters  : None
**     Returns     :
**         ---             - Status of the LED (on or off)
** ===================================================================
*/

void GREEN_Init(void);
/*
** ===================================================================
**     Method      :  GREEN_Init (component LED)
**     Description :
**         Performs the LED driver initialization.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define GREEN_Put(val)  ((val) ? GREEN_On() : GREEN_Off())
/*
** ===================================================================
**     Method      :  GREEN_Put (component LED)
**     Description :
**         Turns the LED on or off.
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - value to define if the LED has to be on or
**                           off.
**     Returns     : Nothing
** ===================================================================
*/

void GREEN_Deinit(void);
/*
** ===================================================================
**     Method      :  GREEN_Deinit (component LED)
**     Description :
**         Deinitializes the driver
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void GREEN_SetRatio16(uint16_t ratio);
/*
** ===================================================================
**     Method      :  GREEN_SetRatio16 (component LED)
**     Description :
**         Method to specify the duty cycle. If using a PWM pin, this
**         means the duty cycle is set. For On/off pins, values smaller
**         0x7FFF means off, while values greater means on.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ratio           - Ratio value, where 0 means 'off' and
**                           0xffff means 'on'
**     Returns     : Nothing
** ===================================================================
*/

/* END GREEN. */

#endif
/* ifndef __GREEN_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
