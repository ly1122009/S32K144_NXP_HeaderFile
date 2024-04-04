/* Function S32K144 */

#ifndef PROTOTYPE_H_ /* Check if memory map has not been already included */
#define PROTOTYPE_H_ 

/* Marco */
  /* Interrupt */
/* void NVIC_Interrupt_Init (Mode_interrupt) */
#define Falling 2
#define Rising 3
#define Either 4


/* void NVIC_Interrupt_Timer(LPIT_Channel) */
#define Channel0 48
#define Channel1 49
#define Channel2 50
#define Channel3 51




  /* SCG */
	
/* void SCG_Switch_RunMode_SystemClockSource (UsingClock)*/
#define OSC 1  
#define SIRC 2
#define FIRC 3
#define PLL 6
/* DIV_SLOW = (1 -> 8)*/
/* DIV_BUS = (1 -> 16)*/
/* DIV_CORE = (1 -> 16)*/
/* void SCG_Switch_RunMode_SystemClockSource (DIV1, DIV2) -> Using PCC  */
#define DIV_0 0
#define DIV_1 1
#define DIV_2 2
#define DIV_4 3
#define DIV_8 4
#define DIV_16 5
#define DIV_32 6
#define DIV_64 7

/* void SCG_Enable_SourceCLock( ClockSource ) */
#define OSC 1  
#define SIRC 2
#define FIRC 3
#define PLL 6

/* void SCG_EnableAndCongfig_PLL( PRE_DIV,  MULT, DIV1, DIV2)*/
/* PRE_DIV = ( 1 - 8 ) */
/* MULT  = ( 16 - 47 ) */
#define DIV_0 0
#define DIV_1 1
#define DIV_2 2
#define DIV_4 3
#define DIV_8 4
#define DIV_16 5
#define DIV_32 6
#define DIV_64 7



 /* PCC */
/* void PCC_Congfig_LPIT(SelectSource_LPIT)*/
#define SOSCDIV2 1
#define SIRCDIV2 2
#define FIRCDIV2 3
#define SPLLDIV2 6

/* void PCC_EnableClock_LPUART(SelectSource);*/

#define SOSCDIV2 1
#define SIRCDIV2 2
#define FIRCDIV2 3
#define SPLLDIV2 6


/* void PCC_EnableClock_LPSPI(SelectSource) */
#define SOSCDIV2 1
#define SIRCDIV2 2
#define FIRCDIV2 3
#define SPLLDIV2 6

/* LPUART */
/* void LPUART_InitTransmitter(Modeparity)*/
#define Disable_Parity 0
#define Even_Parity    1    /* Chan */
#define Odd_Parity		 2		/* Le*/


/* void LPUART_EnableInterrupt(ReceiverOrTransmitter)*/
#define LPUART_EnableInterrupt_Receiver 1 
#define LPUART_EnableInterrupt_Transmitter 2 


/* Code rules */

typedef unsigned int uint32;
typedef unsigned char uint8;
	

/* Library */

#include "GPIO.h"
#include "PCC.h"
#include "PORT.h"
#include "NVIC.h"
#include "Systick.h"
#include "SCG.h"
#include "Timer.h"
#include "LPUART.h"
#include "LPSPI.h"
/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/
											/* Content */



/* GPIO */

void GPIO_Input_Init(GPIO_Type*GPIOx, volatile uint32 pin);
void GPIO_Output_Init(GPIO_Type*GPIOx, volatile uint32 pin);
void GPIO_TogglePIN(GPIO_Type*GPIOx, volatile uint32 pin);
void GPIO_SetHighPIN(GPIO_Type*GPIOx, volatile uint32 pin);
void GPIO_SetLowPIN(GPIO_Type*GPIOx, volatile uint32 pin);


/* Interrupt */
void NVIC_Interrupt_Init(GPIO_Type*GPIOx, volatile uint32 pin, volatile uint32 Mode_interrupt);  
void NVIC_Interrupt_Timer(volatile uint32 LPIT_Channel_ID);




/* Systick */
void NVIC_Systick_Enable(void);
void NVIC_Systick_Init(volatile uint32 Reload_Value);

/* SCG */
void SCG_Enable_SourceCLock(volatile uint32 ClockSource, volatile uint32 Tanso_SIRC); /* Loi FIRC */
void SCG_EnableAndCongfig_PLL(volatile uint32 PRE_DIV, volatile uint32 MULT);  
void SCG_Switch_RunMode_SystemClockSource(volatile uint32 UsingClock, volatile uint32 DIV_CORE, volatile uint32 DIV_BUS, volatile uint32 DIV_SLOW); 
void SCG_CongfigDIV_PCC(volatile uint32 ClockSource, volatile uint32 DIV1, volatile uint32 DIV2);


/* PCC */
void PCC_SelectSource_LPIT(volatile uint32 SelectSource_LPIT);
void PCC_EnableClock_Port(PORT_Type*PORT_x);
void PCC_EnableClock_LPUART(LPUART_Type*LPUART_x , volatile uint32 SelectSource);
void PCC_EnableClock_LPSPI(LPSPI_Type*LPSPT_x, volatile uint32 SelectSource);


/* TIMER - (LPIT) */
void LPIT_InitPCCToTimer(void);
void LPIT_EnableChannelInterrupt(volatile uint32 Channelx);
void LPIT_CongfigTimer32bit(volatile uint32 TimerChannelx, volatile uint32 ValueTimer);  /* dung trong mode 32 bit */
void LPIT_CongfigTimer16bit(volatile uint32 TimerChannelx, volatile uint32 ValueTimer16bit_big, volatile uint32 ValueTimer16bit_small);  /* dung trong mode 16 bit*/
void LPIT_EnableOrDisableTimerChannel(volatile uint32 Channelx, volatile uint32 Status);


void LPIT_ClearFlagInterruptChannel(volatile uint32 Channalx);  /* using clear flag channel x for interrupt timer LPIT */
void LPIT_ChainModeChannel(volatile uint32 Channelx);  /* using chain mode 32 bit channel timer */  /*TVALn * (TVALn-1 + 1) = TVALcanchay */  /* Cannot use this function in channel 0*/  
     


/* LPUART */
/* Need to Enable PCC source clock for Port (void PCC_EnableClock_Port) and Enable PCC source clock for LPUART (void PCC_EnableClock_LPUART) before using LPUART_InitTransmitter function  */
void LPUART_Init(LPUART_Type*LPUART_x , PORT_Type*PORT_x ,volatile uint32 Pin_Tx, volatile uint32 Pin_Rx, volatile uint32 BaudRate, volatile uint32 PCC_ClockValue, volatile uint32 ModeBitData, volatile uint32 ModeParity);
void LPUART_InitTransmitter(LPUART_Type*LPUART_x , PORT_Type*PORT_x ,volatile uint32 Pin_Tx, volatile uint32 Pin_Rx, volatile uint32 BaudRate, volatile uint32 PCC_ClockValue, volatile uint32 ModeParity);

/* 	UART0: (Rx : PTA2,PTB0) (Tx : PTA3,PTB1)
UART1: (Rx : PTC6,PTC8) (Tx : PTC7,PTC9)
UART2: (Rx : PTD6,PTD17) (Tx : PTD7,PTE12)
UART3: (Rx : PTA8,PTD13) (Tx : PTA9, PTD14)*/
void LPUART_EnableTransmitter(LPUART_Type*LPUART_x);
void LPUART_EnableReceiver(LPUART_Type*LPUART_x);
void LPUART_DisableTransmitter(LPUART_Type*LPUART_x);
void LPUART_DisableReceiver(LPUART_Type*LPUART_x);

	/* Receive Data */
void LPUART_Receiver_Char(LPUART_Type*LPUART_x, volatile uint8 *Char_result);
void LPUART_Receiver_String(LPUART_Type*LPUART_x, volatile uint8 String_result[], volatile uint8 Char_End); /* Dung lai khi gap ky tu '=' */  /* Chua dung duoc */

	/* Transmitte Data */
void LPUART_SendString(volatile uint8 String[], LPUART_Type*LPUART_x);
void LPUART_SendChar(volatile uint8 Char_Send, LPUART_Type*LPUART_x);

	
	/* Interrupt for LPUART */
	void LPUART_EnableInterrupt(LPUART_Type*LPUART_x, volatile uint32 ReceiverORTransmitter);  
	uint32 LPUART_CheckFlagReceiver(LPUART_Type*LPUART_x);
	uint32 LPUART_CheckFlagTransmitter(LPUART_Type*LPUART_x);
	void LPUART_ClearFlagReceiver(LPUART_Type*LPUART_x);
	void LPUART_ClearFlagTransmitter(LPUART_Type*LPUART_x);
	
	
#endif


