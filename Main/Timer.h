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
#ifndef TIMER_H_  /* Check if memory map has not been already included */
#define TIMER_H_ 

/* ----------------------------------------------------------------------------
   -- Peripheral Access Layer
   ---------------------------------------------------------------------------- */


/* LOW POWER TIMER (LPTMR)   */
typedef struct {
  volatile unsigned int       CSR;
  volatile unsigned int       PSR;
  volatile unsigned int       CMR;
  volatile unsigned int       CNR;

} LPTMR_Type;

#define TIMER_LPTMR_SET_BASE_ADDRS (0x40040000) /* Base Address */
#define LPTMR ((LPTMR_Type*)TIMER_LPTMR_SET_BASE_ADDRS)

/* FLEXIBLE TIMER MODUNE (FTM)*/
typedef struct {
  volatile unsigned int       SC;
  volatile unsigned int       CNT;
  volatile unsigned int       MOD;
  volatile unsigned int       C0SC;
  volatile unsigned int       C0V;
	volatile unsigned int       C1SC;
} FTM_Type;

#define TIMER_FTM0_SET_BASE_ADDRS (0x40038000) /* Base Address FTM0 */
#define FTM0 ((FTM_Type*)TIMER_FTM0_SET_BASE_ADDRS)

#define TIMER_FTM1_SET_BASE_ADDRS (0x40039000) /* Base Address FTM1 */
#define FTM1 ((FTM_Type*)TIMER_FTM1_SET_BASE_ADDRS)

#define TIMER_FTM2_SET_BASE_ADDRS (0x4003A000) /* Base Address FTM2 */
#define FTM2 ((FTM_Type*)TIMER_FTM2_SET_BASE_ADDRS)

#define TIMER_FTM3_SET_BASE_ADDRS (0x40026000h) /* Base Address FTM3 */
#define FTM3 ((FTM_Type*)TIMER_FTM3_SET_BASE_ADDRS)

#define TIMER_FTM4_SET_BASE_ADDRS (0x4006E000h) /* Base Address FTM4 */
#define FTM4 ((FTM_Type*)TIMER_FTM4_SET_BASE_ADDRS)

#define TIMER_FTM5_SET_BASE_ADDRS (0x4006F000h) /* Base Address FTM5 */
#define FTM5 ((FTM_Type*)TIMER_FTM5_SET_BASE_ADDRS)

#define TIMER_FTM6_SET_BASE_ADDRS (0x40070000h) /* Base Address FTM6 */
#define FTM6 ((FTM_Type*)TIMER_FTM6_SET_BASE_ADDRS)

#define TIMER_FTM7_SET_BASE_ADDRS (0x40071000h) /* Base Address FTM7 */
#define FTM7 ((FTM_Type*)TIMER_FTM7_SET_BASE_ADDRS)



/* LOW-POWER PERIODIC INTERRUPT TIMER (LPIT) */
/*LPIT*/
typedef struct 
{
	volatile unsigned int LPIT_VERID;
	volatile unsigned int LPIT_PARAM;
	volatile unsigned int LPIT_MCR;
	volatile unsigned int LPIT_MSR;
	volatile unsigned int LPIT_MIER;
	volatile unsigned int LPIT_SETTEN;
	volatile unsigned int LPIT_CLRTEN;
	volatile unsigned int dummy17;
	volatile unsigned int LPIT_TVAL0;
	volatile unsigned int LPIT_CVAL0;
	volatile unsigned int LPIT_TCTRL0;
	volatile unsigned int dummy18;
	volatile unsigned int LPIT_TVAL1;
	volatile unsigned int LPIT_CVAL1;
	volatile unsigned int LPIT_TCTRL1;
	volatile unsigned int dummy19;
	volatile unsigned int LPIT_TVAL2;
	volatile unsigned int LPIT_CVAL2;
	volatile unsigned int LPIT_TCTRL2;
	volatile unsigned int dummy20;
	volatile unsigned int LPIT_TVAL3;
	volatile unsigned int LPIT_CVAL3;
	volatile unsigned int LPIT_TCTRL3;
	
}LPIT_Type;

#define LPIT_BASE_ADDRS      0x40037000
#define LPIT								((LPIT_Type *) LPIT_BASE_ADDRS)

#endif  /* #if !defined(TIMER_H_) */






