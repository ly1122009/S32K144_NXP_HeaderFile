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
#ifndef LPSPI_H_  /* Check if memory map has not been already included */
#define LPSPI_H_ 

/* ----------------------------------------------------------------------------
   -- Peripheral Access Layer
   ---------------------------------------------------------------------------- */



typedef struct { 
  volatile const unsigned int VERID ;
  volatile const unsigned int PARAM ;
  unsigned char dummy0[8];
  volatile unsigned int CR ;
  volatile unsigned int SR ;
  volatile unsigned int IER ;
  volatile unsigned int DER ;
  volatile unsigned int CFGR0 ;
  volatile unsigned int CFGR1 ;
  unsigned char dummy1[8];
  volatile unsigned int DMR0 ;
  volatile unsigned int DMR1 ;
  unsigned char dummy2[8];
  volatile unsigned int CCR ;
  unsigned char dummy3[20];
  volatile unsigned int FCR ;
  volatile const unsigned int FSR ;
  volatile unsigned int TCR ;
  volatile unsigned int TDR ;
  unsigned char dummy4[8];
  volatile const unsigned int RSR ;
  volatile const unsigned int RDR ;
} LPSPI_Type; 

#define LPSPI0_BASE_ADDRS		 0x4002C000
#define LPSPI0				(( LPSPI_Type* ) LPSPI0_BASE_ADDRS) 

#define LPSPI1_BASE_ADDRS		 0x4002D000
#define LPSPI1				(( LPSPI_Type* ) LPSPI1_BASE_ADDRS) 

#define LPSPI2_BASE_ADDRS		 0x4002E000
#define LPSPI2				(( LPSPI_Type* ) LPSPI2_BASE_ADDRS)




#endif  /* #if !defined(LPSPI_H_ ) */


