/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : PC.h
**     Project     : relatorio1-part2
**     Processor   : MKL25Z128VLK4
**     Component   : AsynchroSerial
**     Version     : Component 02.611, Driver 01.01, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2020-11-08, 22:08, # CodeGen: 0
**     Abstract    :
**         This component "AsynchroSerial" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial channel.
**     Settings    :
**         Serial channel              : UART0
**
**         Protocol
**             Width                   : 8 bits
**             Stop bits               : 1
**             Parity                  : none
**             Breaks                  : Disabled
**             Input buffer size       : 0
**             Output buffer size      : 0
**
**         Registers
**             Input buffer            : UART0_D   [0x4006A007]
**             Output buffer           : UART0_D   [0x4006A007]
**
**         Input interrupt
**             Vector name             : INT_UART0
**             Priority                : 2
**
**         Output interrupt
**             Vector name             : INT_UART0
**             Priority                : 2
**
**         Used pins:
**         ----------------------------------------------------------
**           Function | On package           |    Name
**         ----------------------------------------------------------
**            Input   |     27               |  TSI0_CH2/PTA1/UART0_RX/TPM2_CH0
**            Output  |     28               |  TSI0_CH3/PTA2/UART0_TX/TPM2_CH1
**         ----------------------------------------------------------
**
**
**
**     Contents    :
**         RecvChar        - byte PC_RecvChar(PC_TComData *Chr);
**         SendChar        - byte PC_SendChar(PC_TComData Chr);
**         GetCharsInRxBuf - word PC_GetCharsInRxBuf(void);
**         GetCharsInTxBuf - word PC_GetCharsInTxBuf(void);
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
** @file PC.h
** @version 01.01
** @brief
**         This component "AsynchroSerial" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial channel.
*/         
/*!
**  @addtogroup PC_module PC module documentation
**  @{
*/         

#ifndef __PC
#define __PC

/* MODULE PC. */

/* Include inherited components */
#include "ASerialLdd1.h"
#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 



#ifndef __BWUserType_PC_TError
#define __BWUserType_PC_TError
  typedef union {
  byte err;
  struct {
    bool OverRun  : 1;                 /* Overrun error flag */
    bool Framing  : 1;                 /* Framing error flag */
    bool Parity   : 1;                 /* Parity error flag */
    bool RxBufOvf : 1;                 /* Rx buffer full error flag */
    bool Noise    : 1;                 /* Noise error flag */
    bool Break    : 1;                 /* Break detect */
    bool LINSync  : 1;                 /* LIN synchronization error */
    bool BitError  : 1;                /* Bit error flag - mismatch to the expected value happened. */
  } errName;
} PC_TError;                           /* Error flags. For languages which don't support bit access is byte access only to error flags possible. */
#endif

#ifndef __BWUserType_PC_TComData
#define __BWUserType_PC_TComData
  typedef byte PC_TComData;            /* User type for communication. Size of this type depends on the communication data witdh */
#endif

/*
** ===================================================================
**     Method      :  PC_RecvChar (component AsynchroSerial)
**     Description :
**         If any data is received, this method returns one character,
**         otherwise it returns an error code (it does not wait for
**         data). This method is enabled only if the receiver property
**         is enabled.
**         [Note:] Because the preferred method to handle error and
**         break exception in the interrupt mode is to use events
**         <OnError> and <OnBreak> the return value ERR_RXEMPTY has
**         higher priority than other error codes. As a consequence the
**         information about an exception in interrupt mode is returned
**         only if there is a valid character ready to be read.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Chr             - Pointer to a received character
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RXEMPTY - No data in receiver
**                           ERR_BREAK - Break character is detected
**                           (only when the <Interrupt service> property
**                           is disabled and the <Break signal> property
**                           is enabled)
**                           ERR_COMMON - common error occurred (the
**                           <GetError> method can be used for error
**                           specification)
** ===================================================================
*/
byte PC_RecvChar(PC_TComData *Chr);

/*
** ===================================================================
**     Method      :  PC_SendChar (component AsynchroSerial)
**     Description :
**         Sends one character to the channel. If the component is
**         temporarily disabled (Disable method) SendChar method only
**         stores data into an output buffer. In case of a zero output
**         buffer size, only one character can be stored. Enabling the
**         component (Enable method) starts the transmission of the
**         stored data. This method is available only if the
**         transmitter property is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Chr             - Character to send
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_TXFULL - Transmitter is full
** ===================================================================
*/
byte PC_SendChar(PC_TComData Chr);

/*
** ===================================================================
**     Method      :  PC_GetCharsInRxBuf (component AsynchroSerial)
**     Description :
**         Returns the number of characters in the input buffer. This
**         method is available only if the receiver property is enabled.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the input
**                           buffer.
** ===================================================================
*/
word PC_GetCharsInRxBuf(void);

/*
** ===================================================================
**     Method      :  PC_GetCharsInTxBuf (component AsynchroSerial)
**     Description :
**         Returns the number of characters in the output buffer. This
**         method is available only if the transmitter property is
**         enabled.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the output
**                           buffer.
** ===================================================================
*/
word PC_GetCharsInTxBuf(void);

/*
** ===================================================================
**     Method      :  PC_Init (component AsynchroSerial)
**
**     Description :
**         Initializes the associated peripheral(s) and the bean internal 
**         variables. The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PC_Init(void);

/*
** ===================================================================
**     Method      :  PC_ASerialLdd1_OnBlockReceived (component AsynchroSerial)
**
**     Description :
**         This event is called when the requested number of data is 
**         moved to the input buffer.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void ASerialLdd1_OnBlockReceived(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  PC_ASerialLdd1_OnBlockSent (component AsynchroSerial)
**
**     Description :
**         This event is called after the last character from the output 
**         buffer is moved to the transmitter.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void ASerialLdd1_OnBlockSent(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  PC_ASerialLdd1_OnError (component AsynchroSerial)
**
**     Description :
**         This event is called when a channel error (not the error 
**         returned by a given method) occurs.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void ASerialLdd1_OnError(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  PC_ASerialLdd1_OnBreak (component AsynchroSerial)
**
**     Description :
**         This event is called when a break occurs on the input channel.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void ASerialLdd1_OnBreak(LDD_TUserData *UserDataPtr);


/* END PC. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif /* ifndef __PC */
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
