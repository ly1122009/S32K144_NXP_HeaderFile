/*
** ###################################################################
**     Processor:           S32K144
**     Compiler:            Keil ARM C/C++ Compiler
**     Version:             rev. 1.0, Tue Sep 12 15:05:04 2023
  
**
**     Abstract:
**         Peripheral Access Layer for S32K144
**
** ###################################################################
*/

/* Prevention from multiple including the same memory map */
#ifndef SCG_H_  /* Check if memory map has not been already included */
#define SCG_H_

/* ----------------------------------------------------------------------------
   -- Peripheral Access Layer
   ---------------------------------------------------------------------------- */
/* SCG*/ 
typedef struct { 
  volatile const unsigned int SCG_VERID ;
  volatile const unsigned int SCG_PARAM ;
  unsigned char dummy22[8];
  volatile const unsigned int SCG_CSR ;
  volatile unsigned int SCG_RCCR ;
  volatile unsigned int SCG_VCCR ;
  volatile unsigned int SCG_HCCR ;
  volatile unsigned int SCG_CLKOUTCNFG ;
  unsigned char dummy23[220];
  volatile unsigned int SCG_SOSCCSR ;
  volatile unsigned int SCG_SOSCDIV ;
  volatile unsigned int SCG_SOSCCFG ;
  unsigned char dummy24[244];
  volatile unsigned int SCG_SIRCCSR ;
  volatile unsigned int SCG_SIRCDIV ;
  volatile unsigned int SCG_SIRCCFG ;
  unsigned char dummy25[244];
  volatile unsigned int SCG_FIRCCSR ;
  volatile unsigned int SCG_FIRCDIV ;
  volatile unsigned int SCG_FIRCCFG ;
  unsigned char dummy26[756];
  volatile unsigned int SCG_SPLLCSR ;
  volatile unsigned int SCG_SPLLDIV ;
  volatile unsigned int SCG_SPLLCFG ;

} SCG_Type; 

#define SCG_BASE_ADDRS		 0x40064000
#define SCG				(( SCG_Type* ) SCG_BASE_ADDRS)



#endif  /* #if !defined(SCG_H_) */

