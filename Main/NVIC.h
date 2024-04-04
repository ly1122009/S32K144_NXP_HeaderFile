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
#ifndef NVIC_H_  /* Check if memory map has not been already included */
#define NVIC_H_ 

/* ----------------------------------------------------------------------------
   -- Peripheral Access Layer
   ---------------------------------------------------------------------------- */


/* NVIC Set - enable  */
typedef struct {
  volatile unsigned int       NVIC_ISER0;
  volatile unsigned int       NVIC_ISER1;
  volatile unsigned int       NVIC_ISER2;
  volatile unsigned int       NVIC_ISER3;
  volatile unsigned int       NVIC_ISER4;
  volatile unsigned int       NVIC_ISER5;
  volatile unsigned int       NVIC_ISER6;
  volatile unsigned int       NVIC_ISER7;

} NVIC_Type;

#define NVIC_SET_BASE_ADDRS (0xE000E100) /* Base Address */
#define NVIC_SetEnable ((NVIC_Type*)NVIC_SET_BASE_ADDRS)


/* NVIC Clear - enable  */

#define NVIC_CLEAR_BASE_ADDRS (0XE000E180) /* Base Address */
#define NVIC_ClearEnable ((NVIC_Type*)NVIC_CLEAR_BASE_ADDRS)



/* NVIC Set - Pending  */

#define NVIC_SET_PENDING_BASE_ADDRS (0XE000E200) /* Base Address */
#define NVIC_SetPending ((NVIC_Type*)NVIC_SET_PENDING_BASE_ADDRS)




/* NVIC Clear - Pending  */


#define NVIC_CLEAR_PENDING_BASE_ADDRS (0XE000E280) /* Base Address */
#define NVIC_ClearPending ((NVIC_Type*)NVIC_CLEAR_PENDING_BASE_ADDRS)



/* NVIC Active Bit Register */


#define NVIC_ACTIVE_BIT_BASE_ADDRS (0xE000E300) /* Base Address */
#define NVIC_ActiveBit ((NVIC_Type*)NVIC_ACTIVE_BIT_BASE_ADDRS)


/* NVIC Priority Register - Muc do uu tien */
typedef struct {
  volatile unsigned int       NVIC_IPR0;
  volatile unsigned int       NVIC_IPR1;
  volatile unsigned int       NVIC_IPR2;
  volatile unsigned int       NVIC_IPR3;
  volatile unsigned int       NVIC_IPR4;
  volatile unsigned int       NVIC_IPR5;
  volatile unsigned int       NVIC_IPR6;
  volatile unsigned int       NVIC_IPR7; 
  volatile unsigned int       NVIC_IPR8;
  volatile unsigned int       NVIC_IPR9;
  volatile unsigned int       NVIC_IPR10;
  volatile unsigned int       NVIC_IPR11;
  volatile unsigned int       NVIC_IPR12;
  volatile unsigned int       NVIC_IPR13;
  volatile unsigned int       NVIC_IPR14;
  volatile unsigned int       NVIC_IPR15; 
  volatile unsigned int       NVIC_IPR16;
  volatile unsigned int       NVIC_IPR17;
  volatile unsigned int       NVIC_IPR18;
  volatile unsigned int       NVIC_IPR19;
  volatile unsigned int       NVIC_IPR20;
  volatile unsigned int       NVIC_IPR21;
  volatile unsigned int       NVIC_IPR22;
  volatile unsigned int       NVIC_IPR23;
  volatile unsigned int       NVIC_IPR24;
  volatile unsigned int       NVIC_IPR25;
  volatile unsigned int       NVIC_IPR26;
  volatile unsigned int       NVIC_IPR27;
  volatile unsigned int       NVIC_IPR28;
  volatile unsigned int       NVIC_IPR29;
  volatile unsigned int       NVIC_IPR30;
  volatile unsigned int       NVIC_IPR31; 
  volatile unsigned int       NVIC_IPR32;
  volatile unsigned int       NVIC_IPR33;
  volatile unsigned int       NVIC_IPR34;
  volatile unsigned int       NVIC_IPR35;
  volatile unsigned int       NVIC_IPR36;
  volatile unsigned int       NVIC_IPR37;
  volatile unsigned int       NVIC_IPR38;
  volatile unsigned int       NVIC_IPR39;
  volatile unsigned int       NVIC_IPR40;
  volatile unsigned int       NVIC_IPR41; 
  volatile unsigned int       NVIC_IPR42;
  volatile unsigned int       NVIC_IPR43;
  volatile unsigned int       NVIC_IPR44;
  volatile unsigned int       NVIC_IPR45;
  volatile unsigned int       NVIC_IPR46;
  volatile unsigned int       NVIC_IPR47;
  volatile unsigned int       NVIC_IPR48;
  volatile unsigned int       NVIC_IPR49;
  volatile unsigned int       NVIC_IPR50;
  volatile unsigned int       NVIC_IPR51; 
  volatile unsigned int       NVIC_IPR52;
  volatile unsigned int       NVIC_IPR53;
  volatile unsigned int       NVIC_IPR54;
  volatile unsigned int       NVIC_IPR55;
  volatile unsigned int       NVIC_IPR56;
  volatile unsigned int       NVIC_IPR57;
  volatile unsigned int       NVIC_IPR58;
  volatile unsigned int       NVIC_IPR59;

} NVIC_PriorityType;

#define NVIC_PRIORITY_BASE_ADDRS (0xE000E400) /* Base Address */
#define NVIC_Priority ((NVIC_PriorityType*)NVIC_PRIORITY_BASE_ADDRS)


/* Trigger Interrupt - Write Only */
typedef struct {
  volatile unsigned int       STIR;
} NVIC_TriggerType;

#define NVIC_TRIGGER_BASE_ADDRS (0xE000EF00) /* Base Address */
#define NVIC_Trigger ((NVIC_TriggerType*)NVIC_TRIGGER_BASE_ADDRS)




#endif  /* #if !defined(NVIC_H_) */

