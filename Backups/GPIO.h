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
#ifndef GPIO_H_ /* Check if memory map has not been already included */
#define GPIO_H_  




/* ----------------------------------------------------------------------------
   -- Peripheral Access Layer
   ---------------------------------------------------------------------------- */
/* <GPIOA>  */
typedef struct {
 	 volatile unsigned int GPIO_PDOR;
   volatile unsigned int GPIO_PSOR;
	 volatile unsigned int GPIO_PCOR;
 	 volatile unsigned int GPIO_PTOR;
	 volatile const unsigned int GPIO_PDIR;
	 volatile unsigned int GPIO_PDDR;
	 volatile unsigned int GPIO_PIDR;
        
} GPIO_Type;

#define GPIOA_BASE_ADDRESS 0x400FF000
#define GPIO_A ((GPIO_Type*)GPIOA_BASE_ADDRESS)

/* <GPIOB>  */

#define GPIOB_BASE_ADDRESS 0x400FF040
#define GPIO_B ((GPIO_Type*)GPIOB_BASE_ADDRESS)

/* <GPIOC>  */
        
#define GPIOC_BASE_ADDRESS 0x400FF080
#define GPIO_C ((GPIO_Type*)GPIOC_BASE_ADDRESS)

/* <GPIOD>  */

#define GPIOD_BASE_ADDRESS 0x400FF0C0
#define GPIO_D ((GPIO_Type*)GPIOD_BASE_ADDRESS)

/* <GPIOE>  */

#define GPIOE_BASE_ADDRESS 0x400FF100
#define GPIO_E ((GPIO_Type*)GPIOE_BASE_ADDRESS)




#endif  /* #if !defined(GPIO_H_) */



