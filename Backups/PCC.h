/*
** ###################################################################
**     Processor:           S32K144
**     Compiler:            Keil ARM C/C++ Compiler
**     Version:             rev. 1.0, 5:00     
**
**     Abstract:
**         Peripheral Access Layer for S32K144
**
** ###################################################################
*/

/* Prevention from multiple including the same memory map */
#ifndef PCC_H_ /* Check if memory map has not been already included */
#define PCC_H_  


/* ----------------------------------------------------------------------------
   -- Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* PCC  */
/* PCC  */
typedef struct {
  unsigned int                dummy_00[32];
  volatile unsigned int       PCC_FTFC;
  volatile unsigned int       PCC_DMAMUX;
  unsigned int                dummy_01[2];
  volatile unsigned int       PCC_FlexCAN0;
  volatile unsigned int       PCC_FlexCAN1;
  volatile unsigned int       PCC_FTM3;
  volatile unsigned int       PCC_ADC1;
  unsigned int                dummy_02[3];
  volatile unsigned int       PCC_FlexCAN2;
  volatile unsigned int       PCC_LPSPI0;
  volatile unsigned int       PCC_LPSPI1;
  volatile unsigned int       PCC_LPSPI2;
  unsigned int                dummy_03[2];
  volatile unsigned int       PCC_PDB1;
  volatile unsigned int       PCC_CRC;
  unsigned int                dummy_04[3];
  volatile unsigned int       PCC_PDB0;
  volatile unsigned int       PCC_LPIT;
  volatile unsigned int       PCC_FTM0;
  volatile unsigned int       PCC_FTM1;
  volatile unsigned int       PCC_FTM2;
  volatile unsigned int       PCC_ADC0;
  unsigned int                dummy_05[1];
  volatile unsigned int       PCC_RTC;
  unsigned int                dummy_06[2];
  volatile unsigned int       PCC_LPTMR0;
  unsigned int                dummy_07[8];
  volatile unsigned int       PCC_PORTA;
  volatile unsigned int       PCC_PORTB;
  volatile unsigned int       PCC_PORTC;
  volatile unsigned int       PCC_PORTD;
  volatile unsigned int       PCC_PORTE;
  unsigned int                dummy_08[6];
  volatile unsigned int       PCC_SAI0;
  volatile unsigned int       PCC_SAI1;
  unsigned int                dummy_09[4];
  volatile unsigned int       PCC_FlexIO;
  unsigned int                dummy_10[6];
  volatile unsigned int       PCC_EWM;
  unsigned int                dummy_11[4];
  volatile unsigned int       PCC_LPI2C0;
  volatile unsigned int       PCC_LPI2C1;
  unsigned int                dummy_12[2];
  volatile unsigned int       PCC_LPUART0;
  volatile unsigned int       PCC_LPUART1;
  volatile unsigned int       PCC_LPUART2;
  unsigned int                dummy_13[1];
  volatile unsigned int       PCC_FTM4;
  volatile unsigned int       PCC_FTM5;
  volatile unsigned int       PCC_FTM6;
  volatile unsigned int       PCC_FTM7;
  unsigned int                dummy_14[1];
  volatile unsigned int       PCC_CMP0;
  unsigned int                dummy_15[2];
  volatile unsigned int       PCC_QSPI;
  unsigned int                dummy_16[2];
  volatile unsigned int       PCC_ENET;
} PCC_Type;

#define PCC_BASE_ADDRESS 0x40065000
#define PCC_reg ((PCC_Type*)PCC_BASE_ADDRESS) 

#endif  /* #if !defined(PCC_H_) */



