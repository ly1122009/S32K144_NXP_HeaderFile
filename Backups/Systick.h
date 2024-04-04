#ifndef SYSTICK_H_  /* Check if memory map has not been already included */
#define SYSTICK_H_ 


  /* SYSTEM TICK */
typedef struct {
  volatile unsigned int   SYST_CSR; /* SysTick Control and Status Register */
  volatile unsigned int   SYST_RVR; /* SysTick Reload Value Register */
	volatile unsigned int   SYST_CVR;  /* SysTick Current Value Register */
	volatile const unsigned int   SYST_CALIB;  /* SysTick Calibration Value Register */
	
} Systick_Type;

#define SYSTICK_BASE_ADDRS (0xE000E010) /* Base Address */
#define Systick ((Systick_Type*)SYSTICK_BASE_ADDRS)



	

  








#endif


