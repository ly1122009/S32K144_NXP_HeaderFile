/*
** ###################################################################
**     Processor:           S32K144
**     Compiler:            Keil ARM C/C++ Compiler
**     Version:             rev. 1.0, 23/09/16 - 19:58:27
**
**     Abstract:
**         Peripheral Access Layer for S32K144
**
** ###################################################################
*/

/* Prevention from multiple including the same memory map */
#ifndef MAX7219_H_  /* Check if memory map has not been already included */
#define MAX7219_H_ 

/* ----------------------------------------------------------------------------
   -- Peripheral Access Layer
   ---------------------------------------------------------------------------- */
#include "LPSPI.h"


/* Define Register */

#define No_Op 0xF000
#define Digit0 0xF100
#define Digit1 0xF200
#define Digit2 0xF300
#define Digit3 0xF400
#define Digit4 0xF500
#define Digit5 0xF600
#define Digit6 0xF700
#define Digit7 0xF800
#define Decode_Mode 0xF900
#define Intensity 0xFA00
#define Scan_Limit 0xFB00
#define Shutdown 0xFC00
#define Display_Test 0xFD00




/* MACRO */
/* void MAX7219_Shutdown(ShutDown_Mode) */
#define Shutdown_ShutDownMode 1
#define Shutdown_NormalOperation 2

/* void MAX7219_DecodeMode(DecodeMode) */
#define DecodeMode_NoDecodeB_0to7 0
#define DecodeMode_DecodeB_ForDigit0 1
#define DecodeMode_DecodeB_ForDigit0to3 2
#define DecodeMode_DecodeB_ForDigit0to7 3

/* void MAX7219_DisplayTest(Display_Test_Mode) */
#define DisplayTestMode_NormalOperation 0
#define DisplayTestMode_DisplayTestMode 1

/* void MAX7219_ScanLimit(ScanLimit_NumberOfDigits) */
#define ScanLimit_NumberOfDigits_0 0
#define ScanLimit_NumberOfDigits_0to1 1
#define ScanLimit_NumberOfDigits_0to2 2
#define ScanLimit_NumberOfDigits_0to3 3
#define ScanLimit_NumberOfDigits_0to4 4
#define ScanLimit_NumberOfDigits_0to5 5
#define ScanLimit_NumberOfDigits_0to6 6
#define ScanLimit_NumberOfDigits_0to7 7

/* void MAX7219_SetValueForDigits( NumberOfDigit,  ValueOfDigits, UsingDP);*/
#define NumberOfDigit_0 0
#define NumberOfDigit_1 1
#define NumberOfDigit_2 2
#define NumberOfDigit_3 3
#define NumberOfDigit_4 4
#define NumberOfDigit_5 5
#define NumberOfDigit_6 6
#define NumberOfDigit_7 7
#define ValueOfDigits_0 0
#define ValueOfDigits_1 1
#define ValueOfDigits_2 2
#define ValueOfDigits_3 3
#define ValueOfDigits_4 4
#define ValueOfDigits_5 5
#define ValueOfDigits_6 6
#define ValueOfDigits_7 7
#define ValueOfDigits_8 8
#define ValueOfDigits_9 9
#define ValueOfDigits_Subtraction 10
#define ValueOfDigits_E 11
#define ValueOfDigits_H 12
#define ValueOfDigits_L 13
#define ValueOfDigits_P 14
#define ValueOfDigits_blank 15

#define NoUsingDP 0
#define UsingDP 128
/* void MAX7219_SetIntensity(Intensity_Brightness)*/
#define Intensity_Brightness_Min 0
#define Intensity_Brightness_1 5
#define Intensity_Brightness_2 10
#define Intensity_Brightness_Max 15

/* void MAX7219_SetValue_DP(DPOfDigits) */


/* MAX7219 Functions */

void MAX7219_Shutdown(volatile unsigned int ShutDown_Mode);
void MAX7219_DecodeMode(volatile unsigned int DecodeMode);
void MAX7219_DisplayTest(volatile unsigned int DisplayTestMode);
void MAX7219_ScanLimit(volatile unsigned int ScanLimit_NumberOfDigits);
void MAX7219_SetValueForDigits(volatile unsigned int NumberOfDigit, volatile unsigned int ValueOfDigits, volatile unsigned int UsingDP_p);
void MAX7219_SetIntensity(volatile unsigned int Intensity_Brightness);
void MAX7219_SetValue_DP(volatile unsigned int DPOfDigits);  /* DPOfDigit is register digits (digit0 - digit7) */





void MAX7219_Shutdown(volatile unsigned int ShutDown_Mode)
{
	/* Nomrmal Operation */
	volatile unsigned int Reg_Temp = 0;
	if(ShutDown_Mode == Shutdown_ShutDownMode)
	{
		while( (LPSPI0 -> SR & (1u<<0)) == 0);  /* wait for Transmit data is requested */
		LPSPI0 -> TDR = (unsigned short) Shutdown ;  /* Shutdown mode : Shut down mode */
	}
	else if( ShutDown_Mode == Shutdown_NormalOperation)
	{
		while( (LPSPI0 -> SR & (1u<<0)) == 0);  /* wait for Transmit data is requested */
		Reg_Temp = Shutdown + 1u;
		LPSPI0 -> TDR = Reg_Temp;  /* Shutdown mode : Normal Operation */		
	}
	else
	{
		return;
	}
}


void MAX7219_DecodeMode(volatile unsigned int DecodeMode)
{
	if(DecodeMode == DecodeMode_NoDecodeB_0to7)
	{
	while( (LPSPI0 -> SR & (1u<<0)) == 0);  /* wait for Transmit data is requested */
	LPSPI0 -> TDR = Decode_Mode ;  /* Decode mode : No using decode B */				
	}
	else if ( DecodeMode == DecodeMode_DecodeB_ForDigit0 )
	{
	while( (LPSPI0 -> SR & (1u<<0)) == 0);  /* wait for Transmit data is requested */
	LPSPI0 -> TDR = (Decode_Mode + 1);  /* Decode mode : Using decode B for digit 0 */						
	}
	else if ( DecodeMode == DecodeMode_DecodeB_ForDigit0to3 )
	{
	while( (LPSPI0 -> SR & (1u<<0)) == 0);  /* wait for Transmit data is requested */
	LPSPI0 -> TDR = (Decode_Mode + 15);  /* Decode mode : Using decode B for digit 0 - 3 */						
	}
	else if ( DecodeMode == DecodeMode_DecodeB_ForDigit0to7 )
	{
	while( (LPSPI0 -> SR & (1u<<0)) == 0);  /* wait for Transmit data is requested */
	LPSPI0 -> TDR = (Decode_Mode + 255 );  /* Decode mode : Using decode B for digit 0 - 7 */		
	}	
	else
	{
		return;
	}
}




void MAX7219_DisplayTest(volatile unsigned int DisplayTestMode)
{
	if( DisplayTestMode == DisplayTestMode_NormalOperation )
	{
	while( (LPSPI0 -> SR & (1u<<0)) == 0);  /* wait for Transmit data is requested */
	LPSPI0 -> TDR = Display_Test;  /* Display test : Normal Operation */
	}
	else if( DisplayTestMode == DisplayTestMode_DisplayTestMode )
	{
	while( (LPSPI0 -> SR & (1u<<0)) == 0);  /* wait for Transmit data is requested */
	LPSPI0 -> TDR = (Display_Test + 1);  /* Display test : Display test mode */		
	}
	else
	{
		return;
	}
}



void MAX7219_ScanLimit(volatile unsigned int ScanLimit_NumberOfDigits)
{
	if( ScanLimit_NumberOfDigits == ScanLimit_NumberOfDigits_0)
	{
	while( (LPSPI0 -> SR & (1u<<0)) == 0);  /* wait for Transmit data is requested */
	LPSPI0 -> TDR = Scan_Limit ;  /* Scan limit : Display digit 0 */		
	}
	else 
	{
	while( (LPSPI0 -> SR & (1u<<0)) == 0);  /* wait for Transmit data is requested */
	LPSPI0 -> TDR =  (Scan_Limit + ScanLimit_NumberOfDigits) ;  /* Scan limit : Display digit (ScanLimit_NumberOfDigits) */		
	}
}
void MAX7219_SetValueForDigits(volatile unsigned int NumberOfDigit, volatile unsigned int ValueOfDigits, volatile unsigned int UsingDP_p)
{
	if( NumberOfDigit == NumberOfDigit_0)
	{
	while( (LPSPI0 -> SR & (1u<<0)) == 0);  /* wait for Transmit data is requested */
	LPSPI0 -> TDR =  (Digit0 + ValueOfDigits + UsingDP_p) ;  /* Digit 0 : Set value Digit 0 is (ValueOfDigits) */		
	}
	else if( NumberOfDigit == NumberOfDigit_1 )
	{
	while( (LPSPI0 -> SR & (1u<<0)) == 0);  /* wait for Transmit data is requested */
	LPSPI0 -> TDR = (Digit1 + ValueOfDigits + UsingDP_p);  /* Digit 1 : Set value Digit 0 is (ValueOfDigits) */		
	}
	else if( NumberOfDigit == NumberOfDigit_2 )
	{
	while( (LPSPI0 -> SR & (1u<<0)) == 0);  /* wait for Transmit data is requested */
	LPSPI0 -> TDR = (Digit2 + ValueOfDigits + UsingDP_p);  /* Digit 2 : Set value Digit 0 is (ValueOfDigits) */		
	}
	else if( NumberOfDigit == NumberOfDigit_3 )
	{
	while( (LPSPI0 -> SR & (1u<<0)) == 0);  /* wait for Transmit data is requested */
	LPSPI0 -> TDR = (Digit3 + ValueOfDigits + UsingDP_p);  /* Digit 3 : Set value Digit 0 is (ValueOfDigits) */		
	}
	else if( NumberOfDigit == NumberOfDigit_4 )
	{
	while( (LPSPI0 -> SR & (1u<<0)) == 0);  /* wait for Transmit data is requested */
	LPSPI0 -> TDR = (Digit4 + ValueOfDigits + UsingDP_p);  /* Digit 4 : Set value Digit 0 is (ValueOfDigits) */		
	}
	else if( NumberOfDigit == NumberOfDigit_5 )
	{
	while( (LPSPI0 -> SR & (1u<<0)) == 0);  /* wait for Transmit data is requested */
	LPSPI0 -> TDR = (Digit5 + ValueOfDigits + UsingDP_p);  /* Digit 5 : Set value Digit 0 is (ValueOfDigits) */		
	}
	else if( NumberOfDigit == NumberOfDigit_6 )
	{
	while( (LPSPI0 -> SR & (1u<<0)) == 0);  /* wait for Transmit data is requested */
	LPSPI0 -> TDR = (Digit6 + ValueOfDigits + UsingDP_p);  /* Digit 6 : Set value Digit 0 is (ValueOfDigits) */		
	}
	else if( NumberOfDigit == NumberOfDigit_7 )
	{
	while( (LPSPI0 -> SR & (1u<<0)) == 0);  /* wait for Transmit data is requested */
	LPSPI0 -> TDR = (Digit7 + ValueOfDigits + UsingDP_p);  /* Digit 7 : Set value Digit 0 is (ValueOfDigits) */		
	}
	else
	{
		return;
	}	
}
void MAX7219_SetIntensity(volatile unsigned int Intensity_Brightness)
{
	while( (LPSPI0 -> SR & (1u<<0)) == 0);  /* wait for Transmit data is requested */
	LPSPI0 -> TDR =  (Intensity + Intensity_Brightness) ;  /* Intensity : Set Brightness of Led is (Intensity_Brightness) */		
}






#endif  /* #if !defined(MAX7219_H_ ) */


