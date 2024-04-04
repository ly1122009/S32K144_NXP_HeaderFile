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
#ifndef PORT_H_  /* Check if memory map has not been already included */
#define PORT_H_ 

/* ----------------------------------------------------------------------------
   -- Peripheral Access Layer
   ---------------------------------------------------------------------------- */


/* PORTA  */
typedef struct {
  volatile unsigned int       PORT_PCR0;
  volatile unsigned int       PORT_PCR1;
  volatile unsigned int       PORT_PCR2;
  volatile unsigned int       PORT_PCR3;
  volatile unsigned int       PORT_PCR4;
  volatile unsigned int       PORTAPCR5;
  volatile unsigned int       PORT_PCR6;
  volatile unsigned int       PORT_PCR7;
  volatile unsigned int       PORT_PCR8;
  volatile unsigned int       PORT_PCR9;
  volatile unsigned int       PORT_PCR10;
  volatile unsigned int       PORT_PCR11;
  volatile unsigned int       PORT_PCR12;
  volatile unsigned int       PORT_PCR13;
  volatile unsigned int       PORT_PCR14;
  volatile unsigned int       PORT_PCR15;
  volatile unsigned int       PORT_PCR16;
  volatile unsigned int       PORT_PCR17;
  unsigned int                dummy_00[14];
  volatile unsigned int       PORT_GPCLR;
  volatile unsigned int       PORT_GPCHR;
  volatile unsigned int       PORT_GICLR;
  volatile unsigned int       PORT_GICHR;
  unsigned int                dummy_01[4];
  volatile unsigned int       PORT_ISFR;
  unsigned int                dummy_02[7];
  volatile unsigned int       PORT_DFER;
  volatile unsigned int       PORT_DFCR;
  volatile unsigned int       PORT_DFWR;
} PORT_Type;

#define PORTA_BASE_ADDRS (0x40049000) /* Base Address */
#define PORT_A ((PORT_Type*)PORTA_BASE_ADDRS)


/* PORTB  */

#define PORTB_BASE_ADDRS (0x4004A000) /* Base Address */
#define PORT_B ((PORT_Type*)PORTB_BASE_ADDRS)


/* PORTC  */


#define PORTC_BASE_ADDRS (0x4004B000) /* Base Address */
#define PORT_C ((PORT_Type*)PORTC_BASE_ADDRS)


/* PORTD  */


#define PORTD_BASE_ADDRS (0x4004C000) /* Base Address */
#define PORT_D ((PORT_Type*)PORTD_BASE_ADDRS)


/* PORTE  */


#define PORTE_BASE_ADDRS (0x4004D000) /* Base Address */
#define PORT_E ((PORT_Type*)PORTE_BASE_ADDRS)

#endif  /* #if !defined(PORT_H_ ) */


