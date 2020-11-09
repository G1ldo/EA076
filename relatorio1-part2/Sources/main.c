/* ###################################################################
**     Filename    : main.c
**     Project     : relatorio1
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2020-10-17, 13:35, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "ESP.h"
#include "ASerialLdd2.h"
#include "PC.h"
#include "ASerialLdd1.h"
#include "MCUC1.h"
#include "RED.h"
#include "LEDpin1.h"
#include "BitIoLdd1.h"
#include "GREEN.h"
#include "LEDpin2.h"
#include "BitIoLdd2.h"
#include "BLUE.h"
#include "LEDpin3.h"
#include "BitIoLdd3.h"
#include "UTIL.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include <stdio.h>
#include <string.h>

/* User includes (#include below this line is not maintained by Processor Expert) */
uint8_t cmd[100] = {};//buffer para montar comando a ser enviado
volatile uint8_t rcv[100] = {};//buffer de mensagem recebida
volatile uint8_t pos = 0;//posicao dentro do buffer de mensagem recebida
volatile char msg = 0;//flag de mensagem recebida

uint8_t top[50] = {};//string de topico
uint8_t par[10] = {};//string de parametro
uint8_t scan = 0;//posicao de varredura da string de origem
uint8_t scan2 = 0;//posicao de varredura na string de destino

uint8_t macAddres[20] = {};

//Funcao para enviar comando ao ESP
void SendCmd(uint8_t *s){
	while(*s){
		while(ESP_SendChar(*s));
		s++;
	}
}

//Funcao para enviar mensagem ao PC
void SendPC(uint8_t *s){
	while(*s){
		while(PC_SendChar(*s));
		s++;
	}
}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  /*Util_strcpy(cmd, "GETMAC");//solicita o MAC Address
  SendCmd(cmd);
  while(msg == 0);
  msg = 0;
  Util_strcpy(macAddress, rcv);//copia o MAC Address para a variavel macAddress
  */
  strcpy(cmd, "CONNWIFI \"Gildo\",\"asdf9876\"\r\n");
  SendCmd(cmd);
  while(msg == 0);
  msg = 0;
  if(UTIL_strcmp(rcv, "CONNECT WIFI\r\n")){
	  SendPC("WIFI NAO CONECTA\r\n");
  }
  else{
	  strcpy(cmd, "CONNMQTT \"137.135.83.217\",1883,\"Quevedo\"\r\n");
	  SendCmd(cmd);
	  while(msg == 0);
	  msg = 0;
	  if(UTIL_strcmp(rcv, "CONNECT MQTT\r\n")){
		  SendPC("MQTT NAO CONECTA\r\n");
	  }
	  else{
		  strcpy(cmd, "SUBSCRIBE \"EA076/155544/LEDR\"\r\n");
		  SendCmd(cmd);
		  while(msg == 0);
		  msg = 0;
		  strcpy(cmd, "SUBSCRIBE \"EA076/155544/LEDG\"\r\n");
		  SendCmd(cmd);
		  while(msg == 0);
		  msg = 0;
		  strcpy(cmd, "SUBSCRIBE \"EA076/155544/LEDR\"\r\n");
		  SendCmd(cmd);
		  while(msg == 0);
		  msg = 0;
		  SendPC("TUDO PRONTO\r\n");
	  }
  }
  for(;;){
	 if(msg){
		 msg = 0;
		 if(UTIL_strFind(rcv, "MESSAGE") == -1){
			 SendPC(rcv);
		 }
		 else{
			 scan = 0;
			 while(rcv[scan] != '['){
				 scan++;
			 }
			 scan++;
			 scan2 = 0;
			 while(rcv[scan] != ']'){
				 top[scan2] = rcv[scan];
				 scan++;
				 scan2++;
			 }
			 top[scan2] = 0;
			 while(rcv[scan] != '['){
				 scan++;
			 }
			 scan++;
			 scan2 = 0;
			 while(rcv[scan] != ']'){
				 par[scan2] = rcv[scan];
				 scan++;
				 scan2++;
			 }
			 par[scan2] = 0;
			 
			 if(UTIL_strcmp(top, "EA076/155544/LEDR") == 0){
				 if(UTIL_strcmp(par, "ON") == 0){
					 RED_On();
						 strcpy(cmd, "PUBLISH \"EA076/155544/reply\",\"LEDR ON\"\r\n");
						 SendCmd(cmd);
						 while(msg == 0);
						 msg = 0;
				 }
				 else if(UTIL_strcmp(par, "OFF") == 0){
					 RED_Off();
					 strcpy(cmd, "PUBLISH \"EA076/155544/reply\",\"LEDR OFF\"\r\n");
					 SendCmd(cmd);
					 while(msg == 0);
					 msg = 0;
				 }
			 }
			 
			 if(UTIL_strcmp(top, "EA076/155544/LEDG") == 0){
				 if(UTIL_strcmp(par, "ON") == 0){
					 GREEN_On();
						 strcpy(cmd, "PUBLISH \"EA076/155544/reply\",\"LEDG ON\"\r\n");
						 SendCmd(cmd);
						 while(msg == 0);
						 msg = 0;
				 }
				 else if(UTIL_strcmp(par, "OFF") == 0){
					 GREEN_Off();
					 strcpy(cmd, "PUBLISH \"EA076/155544/reply\",\"LEDG OFF\"\r\n");
					 SendCmd(cmd);
					 while(msg == 0);
					 msg = 0;
				 }
			 }
			 
			 if(UTIL_strcmp(top, "EA076/155544/LEDG") == 0){
				 if(UTIL_strcmp(par, "ON") == 0){
					 GREEN_On();
						 strcpy(cmd, "PUBLISH \"EA076/155544/reply\",\"LEDG ON\"\r\n");
						 SendCmd(cmd);
						 while(msg == 0);
						 msg = 0;
				 }
				 else if(UTIL_strcmp(par, "OFF") == 0){
					 GREEN_Off();
					 strcpy(cmd, "PUBLISH \"EA076/155544/reply\",\"LEDG OFF\"\r\n");
					 SendCmd(cmd);
					 while(msg == 0);
					 msg = 0;
				 }
			 }
		 }
	 }
  }
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
