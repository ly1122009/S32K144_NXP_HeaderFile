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
#ifndef LPUART_H_  /* Check if memory map has not been already included */
#define LPUART_H_ 

/* ----------------------------------------------------------------------------
   -- Peripheral Access Layer
   ---------------------------------------------------------------------------- */



typedef struct {
  volatile const unsigned int       VERID;
  volatile const unsigned int       PARAM;
  volatile unsigned int       GLOBAL;
  volatile unsigned int       PINCFG;
  volatile unsigned int       BAUD;
  volatile unsigned int       STAT;
  volatile unsigned int       CTRL;
  volatile unsigned int       DATA;
  volatile unsigned int       MATCH;
  volatile unsigned int       MODIR;
  volatile unsigned int       FIFO;
  volatile unsigned int       WATER;
  
} LPUART_Type;

/* LPUART0 */

#define LPUART0_BASE_ADDRS (0X4006A000) /* Base Address */
#define LPUART0 ((LPUART_Type*)LPUART0_BASE_ADDRS)


/* LPUART1 */

#define LPUART1_BASE_ADDRS (0X4006B000) /* Base Address */
#define LPUART1 ((LPUART_Type*)LPUART1_BASE_ADDRS)


/* LPUART2 */


#define LPUART2_BASE_ADDRS (0X4006C000) /* Base Address */
#define LPUART2 ((LPUART_Type*)LPUART2_BASE_ADDRS)




#endif  /* #if !defined(LPUART_H_ ) */


