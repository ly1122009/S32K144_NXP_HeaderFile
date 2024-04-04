
#include "Prototype.h"
#include "GPIO.h"
#include "PCC.h"
#include "PORT.h"
#include "NVIC.h"
#include "Systick.h"
#include "SCG.h"
#include "Timer.h"
#include "LPSPI.h"

void GPIO_Input_Init(GPIO_Type*GPIOx , volatile uint32 pin)
{
	/* declare 3 register to configure GPIO */
	volatile uint32 * GPIOx_PDDR;
	volatile uint32 * PORTx_PCRn;
	volatile uint32 * PCC_PORTx;
	
	/* Init GPIO_PDDR */
	GPIOx_PDDR = &GPIOx -> GPIO_PDDR;
	
	/* Init PORTx_PCRn */
	if (GPIOx == GPIO_A)
	{
		PORTx_PCRn = (volatile uint32 *)PORT_A ;
		PORTx_PCRn += pin;
		PCC_PORTx = &PCC_reg -> PCC_PORTA;
	}
	else if (GPIOx == GPIO_B)
	{
		PORTx_PCRn = (volatile uint32 *)PORT_B ;
		PORTx_PCRn += pin;
		PCC_PORTx = &PCC_reg -> PCC_PORTB;
	}
	 
	else if (GPIOx == GPIO_C)
	{
		PORTx_PCRn = (volatile uint32 *)PORT_C ;
		PORTx_PCRn += pin;
		PCC_PORTx = &PCC_reg -> PCC_PORTC;
	}
	
	else if (GPIOx == GPIO_D)
	{
			PORTx_PCRn = (volatile uint32 *)PORT_D;
		PORTx_PCRn += pin;
		PCC_PORTx = &PCC_reg -> PCC_PORTD;
	}
	
	else if (GPIOx == GPIO_E)
	{
		PORTx_PCRn = (volatile uint32 *)PORT_E ;
		PORTx_PCRn += pin;
		PCC_PORTx = &PCC_reg -> PCC_PORTE;
	}
	else
	{
		return;
	}
	
	/* Enable Clock for Port */
	*PCC_PORTx |= (1u<<30);
	
	/*Set pin as GPIO <MUX> */
	*PORTx_PCRn &= ~(0x700u); /* Clear MUX */
	*PORTx_PCRn |= (1u <<8); /* Set MUX GPIO */
	
	/* Disable pull up/ down */
	*PORTx_PCRn &= ~(1u<<1); 
	
	/* Select input MODE */
  *GPIOx_PDDR &= ~(1u<<pin);
	
}

void GPIO_Output_Init(GPIO_Type*GPIOx , volatile uint32 pin)
{


	/* declare 3 register to configure GPIO */
	volatile uint32 * GPIOx_PDDR;
	volatile uint32 * PORTx_PCRn;
	volatile uint32 * PCC_PORTx;
	
	/* Init GPIO_PDDR */
	GPIOx_PDDR = &GPIOx -> GPIO_PDDR;
	
	/* Init PORTx_PCRn */
	if (GPIOx == GPIO_A)
	{
		PORTx_PCRn = (volatile uint32 *)PORT_A ;
		PORTx_PCRn += pin;
		PCC_PORTx = &PCC_reg -> PCC_PORTA;
	}
	else if (GPIOx == GPIO_B)
	{
		PORTx_PCRn = (volatile uint32 *)PORT_B ;
		PORTx_PCRn += pin;
		PCC_PORTx = &PCC_reg -> PCC_PORTB;
	}
	 
	else if (GPIOx == GPIO_C)
	{
		PORTx_PCRn = (volatile uint32 *)PORT_C ;
		PORTx_PCRn += pin;
		PCC_PORTx = &PCC_reg -> PCC_PORTC;
	}
	
	else if (GPIOx == GPIO_D)
	{
			PORTx_PCRn = (volatile uint32 *)PORT_D;
		PORTx_PCRn += pin;
		PCC_PORTx = &PCC_reg -> PCC_PORTD;
	}
	
	else if (GPIOx == GPIO_E)
	{
		PORTx_PCRn = (volatile uint32 *)PORT_E ;
		PORTx_PCRn += pin;
		PCC_PORTx = &PCC_reg -> PCC_PORTE;
	}
	else
	{
		return;
	}
	
	/* Enable Clock for Port */
	*PCC_PORTx |= (1u<<30);
	
	/*Set pin as GPIO <MUX> */
	*PORTx_PCRn &= ~(0x700u); /* Clear MUX */
	*PORTx_PCRn |= (1u <<8); /* Set MUX GPIO */
	
	/* Disable pull up/ down */
	*PORTx_PCRn &= ~(1u<<1); 
	
	/* Select output MODE */
  *GPIOx_PDDR |= (1u<<pin);
}

void GPIO_TogglePIN(GPIO_Type*GPIOx, volatile uint32 pin){

	/* Declare register */
  volatile uint32 *GPIOx_PDOR;

	/* Init GPIOx_PDOR */
	GPIOx_PDOR = &GPIOx -> GPIO_PDOR;
  
	/* Toggle pin */
	*GPIOx_PDOR ^= ( 1u<< pin); 
	
}

void GPIO_SetHighPIN(GPIO_Type*GPIOx, volatile uint32 pin){
	
	/* Declare register */
  volatile uint32 *GPIOx_PDOR;
	
	/* Init GPIOx_PDOR */
	GPIOx_PDOR = &GPIOx -> GPIO_PDOR;
	
	/* Toggle pin */
	*GPIOx_PDOR |= ( 1u<< pin); 
	
}


void GPIO_SetLowPIN(GPIO_Type*GPIOx, volatile uint32 pin){
	
		/* Declare register */
  volatile uint32 *GPIOx_PDOR;
	
	/* Init GPIOx_PDOR */
	GPIOx_PDOR = &GPIOx -> GPIO_PDOR;
	
	/* Toggle pin */
	*GPIOx_PDOR &= ~( 1u<< pin); 
	
}


void NVIC_Interrupt_Init(GPIO_Type*GPIOx, volatile uint32 pin, volatile uint32 Mode_interrupt) 
{
	/* Init Input GPIOx */
	GPIO_Input_Init(GPIOx, pin);
	
	/* declare register to configure GPIO */
	volatile uint32 * PORTx_PCRn;
	volatile uint32 * NVIC_ISERx;
	
	/* declare variable */
	volatile uint32 ID;
	volatile uint32 Index;
	volatile uint32 Vitri;
	
	
	
	if (GPIOx == GPIO_A)
	{
		PORTx_PCRn = (volatile uint32*) PORT_A;
		PORTx_PCRn += pin;
		ID = 59;
	}
	
	else if (GPIOx == GPIO_B)
	{
		PORTx_PCRn = (volatile uint32*) PORT_B;
		PORTx_PCRn += pin;
		ID = 60;
	}
	
	else if (GPIOx == GPIO_C)
	{
		PORTx_PCRn = (volatile uint32*) PORT_C;
		PORTx_PCRn += pin;
		ID = 61;
	}
	
	else if (GPIOx == GPIO_D)
	{
		PORTx_PCRn = (volatile uint32*) PORT_D;
		PORTx_PCRn += pin;
		ID = 62;
	}
	
	else if (GPIOx == GPIO_E)
	{
		PORTx_PCRn = (volatile uint32*) PORT_E;
		PORTx_PCRn += pin;
		ID = 63;
	}
	
	else
	{
		return;
	}
	
	/* Set mode interrupt */
	if(Mode_interrupt == 0)  /* Logic 0 */
	{
		*PORTx_PCRn |= (8u<<16);
	}
	
	else if ( Mode_interrupt == 1 ) /* Logic 1 */
	{
	    *PORTx_PCRn |= (12u<<16);
	}
	
	else if ( Mode_interrupt == 2 ) /* Falling edge */
	{
		*PORTx_PCRn |= (10u<<16);
	}
	
	else if ( Mode_interrupt == 3 ) /* Rising edge */
	{
		*PORTx_PCRn |= (9u<<16);
	}
	
	else if ( Mode_interrupt == 4 ) /* Either edge */
	{
		*PORTx_PCRn |= (11u<<16);
	}
	
	
	
	/* Tim vi tri va index */
	Index = ID / (32u);
	Vitri = ID % (32u);
	
	if(Index == 1)
	/* Init GPIO_PDDR */
	{
	NVIC_ISERx = &NVIC_SetEnable -> NVIC_ISER1;  
	*NVIC_ISERx |= ( 1u << (Vitri)); /*Enable interrupt Port x */
	}
	
	
	
	
}

void NVIC_Interrupt_Timer(volatile uint32 LPIT_Channel_ID){
		
	/* declare register to configure GPIO */
	volatile uint32 *NVIC_ISERx;
	
	/* declare variable */
  volatile uint32 Index = 0;
  volatile uint32 Vitri = 0;

	/* Tim vi tri va index */
  Index = LPIT_Channel_ID / (32u);
	Vitri = LPIT_Channel_ID % (32u);	
	
	/* Init LPIT channel  */
	NVIC_ISERx = &NVIC_SetEnable -> NVIC_ISER1;  
	*NVIC_ISERx |= ( 1u << (Vitri)); /*Enable interrupt Port x */
	
}


void NVIC_Systick_Enable(void)
{
		Systick -> SYST_CSR |= (1u<<0); /* Enable Systick */
}

void NVIC_Systick_Init(volatile uint32 Reload_Value)
{
	
	  
	Systick -> SYST_CSR &= ~(1u<<0); /* Disable Systick */
	Systick -> SYST_CSR |= (1u << 1); /* Config Interrupt of Systick */
	Systick -> SYST_CSR |= (1u<< 2); /* Using Processor Clock */
	
	Systick -> SYST_RVR |= ((Reload_Value) << 0); /* Set Reload Value -> If using 48Mhz is (47999) = 1ms */
	
	Systick -> SYST_CVR |= (1u<<1); /* Reset current value */
	
}


void SCG_Switch_RunMode_SystemClockSource(volatile uint32 UsingClock, volatile uint32 DIV_CORE, volatile uint32 DIV_BUS, volatile uint32 DIV_SLOW)
{	
    volatile uint32 Reg_Temp = 0;
	  /* (SW), (DIVCORE), (DIVBUS), (DIVSLOW) -> using RUN mode */   /* Set SW -> PLL vs (Congfig DIV) */
	Reg_Temp |= ((DIV_SLOW - 1) << 0 );  /* DIVSLOW  */
	Reg_Temp |= ((DIV_BUS - 1) << 4); /* DIVBUS */
  Reg_Temp |= ((DIV_CORE - 1) << 16); /* DIVCORE */	
	Reg_Temp |= (UsingClock << 24); /* Select System  */
	SCG -> SCG_RCCR = Reg_Temp;  /* Gan vao thanh ghi */
	while ( !((SCG -> SCG_RCCR) == (SCG -> SCG_CSR)) );  /* wait for 2 register is square */
	
}

void SCG_Enable_SourceCLock(volatile uint32 ClockSource, volatile uint32 Tanso_SIRC)
{
	
	volatile uint32 Reg_Temp = 0;
	
	if(ClockSource == FIRC)
	{
			/* Clock source FIRC */
	Reg_Temp = 0;                                                  /* Disable FIRC */
	SCG -> SCG_FIRCCSR = Reg_Temp;  /* Unlock bit 23 (LK) */
	SCG -> SCG_FIRCCSR = Reg_Temp;  /* Disable System OSC clock	*/
	Reg_Temp = 0;  /* Clear Reg_temp */
	
	Reg_Temp = 0u; /* Setting FIRC 48Mhz */                         /* Congfig FIRC */
	SCG -> SCG_FIRCCFG = Reg_Temp;  /* Gan vao thanh ghi */
	Reg_Temp = 0;  /* Clear Reg_temp */
		
		
	Reg_Temp = 0;  /* Unlock bit 23 (LK) */                        /* Enable FIRC */
	SCG -> SCG_FIRCCSR = Reg_Temp;  /* Unlock bit 23 (LK) */
	Reg_Temp = 1u; /* Enable FIRC */
	SCG -> SCG_FIRCCSR = Reg_Temp;  /* Enable FIRC*/
	while ( ((SCG -> SCG_FIRCCSR & (1u<<24)) == 0 )); /* wait valid bit 24 */	
	}
	
	else if (ClockSource == SIRC)
	{
    /* Clock SIRC */                                                 /* Disable SIRC */
	Reg_Temp = 0u;
	SCG -> SCG_SIRCCSR = Reg_Temp;  /* unlock bit 23 (LK)*/
	SCG -> SCG_SIRCCSR = Reg_Temp;  /* Disable clock SIRC */
	Reg_Temp = 0u; /* Clear Reg_temp */
	                              
								                                                     /* Congfig SIRC */
	if(Tanso_SIRC == 2)
	{
	Reg_Temp &= ~(1u<<0); /*Select SIRC = 2Mhz */   	
	}
	else if ( Tanso_SIRC == 8)
	{
    Reg_Temp |= (1u<<0); /*Select SIRC = 8Mhz */ 
	}	                     
	SCG -> SCG_SIRCCFG = Reg_Temp;
	Reg_Temp = 0;  /* Clear Reg_temp */
	

	Reg_Temp = 0; 												                             /* Enable SIRC */
	SCG -> SCG_SIRCCSR = Reg_Temp;  /* unlock bit 23 (LK)*/       
	Reg_Temp = 1u;  /* Enable SIRC */
	SCG -> SCG_SIRCCSR = Reg_Temp; /* Enable SIRC */
	while ( ((SCG -> SCG_SIRCCSR & (1u<<24)) == 0 ) );  /* wait valid */ 
	Reg_Temp = 0; /* Clear Reg_temp */
	}
	
	else if ( ClockSource == OSC )
	{
	/* Clock source OSC */
	Reg_Temp = 0;                                                  /* Disable Crytal OSC */
	SCG -> SCG_SOSCCSR = Reg_Temp;  /* Unlock bit 23 (LK) */
	SCG -> SCG_SOSCCSR = Reg_Temp;  /* Disable System OSC clock	*/
	Reg_Temp = 0;  /* Clear Reg_temp */
	
	Reg_Temp |= (1u<<2); /* Setting Crystal OSC (EREFS) */         /* Congfig OSC */
	Reg_Temp |= (2u<<4); /* Setting range medium (RANGE) */
	SCG -> SCG_SOSCCFG = Reg_Temp;  /* Gan vao thanh ghi */
	Reg_Temp = 0;  /* Clear Reg_temp */
	
			
		
		
	Reg_Temp = 0;  /* Unlock bit 23 (LK) */                        /* Enable Crytal OSC */
	SCG -> SCG_SOSCCSR = Reg_Temp;  /* Unlock bit 23 (LK) */
	Reg_Temp = 1u; /* Enable Crytal OSC */
	SCG -> SCG_SOSCCSR = Reg_Temp;  /* Enable Crytal OSC */
	while ( ((SCG -> SCG_SOSCCSR & (1u<<24)) == 0 )); /* wait valid bit 24 */	
		
		
		
	}
	
	
}
void SCG_EnableAndCongfig_PLL(volatile uint32 PRE_DIV, volatile uint32 MULT)
{
	volatile uint32 Reg_Temp = 0;
	/* PLL */
	Reg_Temp = 0;                                                  /* Disable Clock PLL */
	SCG -> SCG_SPLLCSR = Reg_Temp; /* Unlock bit 23 (LK)*/
	SCG -> SCG_SPLLCSR = Reg_Temp; /* Disable clock PLL */
	Reg_Temp = 0; /* Clear Reg_temp */
	
	Reg_Temp = 0; /* Source system OSC */                          /* Congfig PLL */
	Reg_Temp |= ((PRE_DIV - 1) <<8); /* Select PREDIV = 2 */
	Reg_Temp |= ((MULT - 16) <<16);  /* Select MUL = 20 */
	SCG -> SCG_SPLLCFG = Reg_Temp; /* Gan vao thanh ghi */
	Reg_Temp = 0; /* Clear Reg_temp */
	
	Reg_Temp = 0;                                                  /* Enable PLL */
	SCG -> SCG_SPLLCSR = Reg_Temp; /* Unlock bit 23 (LK)*/
	Reg_Temp = 1u;  /* Enable PLL */
	SCG -> SCG_SPLLCSR = Reg_Temp; /* Enable clock PLL */
	while ( (SCG -> SCG_SPLLCSR & (1u << 24)) == 0  ); /* wait valid bit 24 */
	Reg_Temp = 0; /* Clear Reg_temp */
}

void SCG_CongfigDIV_PCC(volatile uint32 ClockSource, volatile uint32 DIV1, volatile uint32 DIV2)
{
/* #define SOSCDIV2 1
#define SIRCDIV2 2
#define FIRCDIV2 3
#define SPLLDIV2 6*/
	
	volatile uint32 Reg_Temp = 0;
	
	if(ClockSource == SOSCDIV2)
	{
			 /* Congfig PCC DIV1, DIV2 */                                /* Congfig PCC DIV1, DIV2 */
  Reg_Temp |= (DIV1 << 0);  /* Congfig DIV1 */
	Reg_Temp |= (DIV2 << 8);  /* Congfig DIV2 */
	SCG -> SCG_SOSCDIV = Reg_Temp;
	Reg_Temp = 0;	
	}
	else if ( ClockSource == SIRCDIV2 )
	{
					   /* Congfig PCC DIV1, DIV2 */                                /* Congfig PCC DIV1, DIV2 */
  Reg_Temp |= (DIV1 << 0);  /* Congfig DIV1 */
	Reg_Temp |= (DIV2 << 8);  /* Congfig DIV2 */
	SCG -> SCG_SIRCDIV = Reg_Temp;
	Reg_Temp = 0;	
	}
	else if ( ClockSource == FIRCDIV2)
	{
					                                                         /* Congfig PCC DIV1, DIV2 */
  Reg_Temp |= (DIV1 << 0);  /* Congfig DIV1 */
	Reg_Temp |= (DIV2 << 8);  /* Congfig DIV2 */
	SCG -> SCG_FIRCDIV = Reg_Temp;
	Reg_Temp = 0;		
	}
	else if ( ClockSource == SPLLDIV2)
	{
	Reg_Temp |= (DIV1 << 0);  /* Congfig DIV1 */
	Reg_Temp |= (DIV2 << 8);  /* Congfig DIV2 */
	SCG -> SCG_SPLLDIV = Reg_Temp;
	Reg_Temp = 0;		
	}
	else 
	{
		return;
	}
	
}

void PCC_SelectSource_LPIT(volatile uint32 SelectSource_LPIT){

																																					 /* Disable Clock PCC */
      /* Disable Clock PCC */ 
	  PCC_reg -> PCC_LPIT &= ~(1u<<30);                                      /* Disable PCC for LPIT */
    
	    /* Congfig source PCC */
	  PCC_reg -> PCC_LPIT |= ( SelectSource_LPIT <<24);                      /* Select source PLL */			
	
      /* Enable PCC for LPIT */	
  	PCC_reg -> PCC_LPIT |= (1u<<30);                                       /* Enable PCC for LPIT */
	  

		
	
}

void PCC_EnableClock_Port(PORT_Type*PORT_x){
	
	if( PORT_x == PORT_A)
	{
		PCC_reg -> PCC_PORTA |= (1u << 30);  /* Enable clock gate for PORT A */
	}
	else if (PORT_x == PORT_B )
	{
		PCC_reg -> PCC_PORTB |= (1u << 30);  /* Enable clock gate for PORT B */
	}

	else if (PORT_x == PORT_C )
	{
		PCC_reg -> PCC_PORTC |= (1u << 30);  /* Enable clock gate for PORT C */
	}
	else if (PORT_x == PORT_D )
	{
		PCC_reg -> PCC_PORTD |= (1u << 30);  /* Enable clock gate for PORT D */
	}
	else if (PORT_x == PORT_E )
	{
		PCC_reg -> PCC_PORTE |= (1u << 30);  /* Enable clock gate for PORT E */
	}
	else 
	{
		return;
	}
	
	
}


void PCC_EnableClock_LPUART(LPUART_Type*LPUART_x , volatile uint32 SelectSource){
	
	if ( LPUART_x == LPUART0 )
	{
		PCC_reg -> PCC_LPUART0 |= ( SelectSource << 24 );  /* Select Source */ 
		PCC_reg -> PCC_LPUART0 |= ( 1u << 30);	/* Enable Clock gate for LPUART0 */			
	}
	else if ( LPUART_x == LPUART1 )
	{
		PCC_reg -> PCC_LPUART1 |= ( SelectSource << 24 );  /* Select Source */ 
		PCC_reg -> PCC_LPUART1 |= ( 1u << 30);	/* Enable Clock gate for LPUART1 */	
	}
	else if ( LPUART_x == LPUART2 )
	{
		PCC_reg -> PCC_LPUART2 |= ( SelectSource << 24 );  /* Select Source */ 
		PCC_reg -> PCC_LPUART2 |= ( 1u << 30);	/* Enable Clock gate for LPUART2 */	
	}
	else 
	{
		return;
	}
	
	
}

void PCC_EnableClock_LPSPI(LPSPI_Type*LPSPI_x , volatile uint32 SelectSource){
	
	if ( LPSPI_x == LPSPI0 )
	{
		PCC_reg -> PCC_LPSPI0 |= ( SelectSource << 24 );  /* Select Source */ 
		PCC_reg -> PCC_LPSPI0 |= ( 1u << 30);	/* Enable Clock gate for LPSPI0 */			
	}
	else if ( LPSPI_x == LPSPI1 )
	{
		PCC_reg -> PCC_LPSPI1 |= ( SelectSource << 24 );  /* Select Source */ 
		PCC_reg -> PCC_LPSPI1 |= ( 1u << 30);	/* Enable Clock gate for LPSPI1 */	
	}
	else if ( LPSPI_x == LPSPI2 )
	{
		PCC_reg -> PCC_LPSPI2 |= ( SelectSource << 24 );  /* Select Source */ 
		PCC_reg -> PCC_LPSPI2 |= ( 1u << 30);	/* Enable Clock gate for LPSPI2 */	
	}
	else 
	{
		return;
	}
	
	
}

void LPIT_InitPCCToTimer(void){

	/* Enable clock modune */
	LPIT -> LPIT_MCR |= (1u << 0); /* enable periphenal clock to timers */
	LPIT -> LPIT_MCR |= (1U << 3); /* enable debug bit */
	
}

void LPIT_EnableChannelInterrupt(volatile uint32 Channelx){
	
	/* Enable Channel interrupt for timer */
	LPIT -> LPIT_MIER |= (1u << Channelx);  /* Enable interrupt timer channel 1 */  
	    /* Channelx = 0 -> channel 0 */
	    /* Channelx = 1 -> channel 1 */
	    /* Channelx = 2 -> channel 2 */
	    /* Channelx = 3 -> channel 3 */
}

void LPIT_CongfigTimer32bit(volatile uint32 TimerChannelx, volatile uint32 ValueTimer){
	
	
		/* Declare Register for virtual register */
	volatile uint32 *LPIT_TVALx;
	volatile uint32 *LPIT_TCTRLx;
	
	if( TimerChannelx == 0)
	{
		LPIT_TVALx = &LPIT -> LPIT_TVAL0; 
	  LPIT_TCTRLx = &LPIT -> LPIT_TCTRL0;
	}
	else if( TimerChannelx == 1)
	{
		LPIT_TVALx = &LPIT -> LPIT_TVAL1; 
	  LPIT_TCTRLx = &LPIT -> LPIT_TCTRL1;
	}
	else if ( TimerChannelx == 2)
	{
		LPIT_TVALx = &LPIT -> LPIT_TVAL2; 
	  LPIT_TCTRLx = &LPIT -> LPIT_TCTRL2;
	}
	else if ( TimerChannelx == 3)
	{
		LPIT_TVALx = &LPIT -> LPIT_TVAL3; 
	  LPIT_TCTRLx = &LPIT -> LPIT_TCTRL3;
	}
	else
	{
		return;
	}
	
	/* step5: Set timer value start */
	*LPIT_TVALx = ValueTimer;  /* Busclock is 40MHz */
	
	/* step6: Congfig for channel timer */
	*LPIT_TCTRLx &= ~(1u<<0);  /* Disable timer LPIT channel 1 */
	*LPIT_TCTRLx &= ~(3u<<2); /* Mode 0: 32 bits */																														    
																																																	
}

void LPIT_CongfigTimer16bit(volatile uint32 TimerChannelx, volatile uint32 ValueTimer16bit_big, volatile uint32 ValueTimer16bit_small)
{
   		/* Declare Register for virtual register */
	volatile uint32 *LPIT_TVALx;
	volatile uint32 *LPIT_TCTRLx;
	
	if( TimerChannelx == 0)
	{
		LPIT_TVALx = &LPIT -> LPIT_TVAL0; 
	  LPIT_TCTRLx = &LPIT -> LPIT_TCTRL0;
	}
	else if( TimerChannelx == 1)
	{
		LPIT_TVALx = &LPIT -> LPIT_TVAL1; 
	  LPIT_TCTRLx = &LPIT -> LPIT_TCTRL1;
	}
	else if ( TimerChannelx == 2)
	{
		LPIT_TVALx = &LPIT -> LPIT_TVAL2; 
	  LPIT_TCTRLx = &LPIT -> LPIT_TCTRL2;
	}
	else if ( TimerChannelx == 3)
	{
		LPIT_TVALx = &LPIT -> LPIT_TVAL3; 
	  LPIT_TCTRLx = &LPIT -> LPIT_TCTRL3;
	}
	else
	{
		return;
	}
	
	/* step5: Set timer value start */
	*LPIT_TVALx |= ( ValueTimer16bit_big << 16 );  /* Busclock is 40MHz */
	*LPIT_TVALx |= ( ValueTimer16bit_small << 0 );
	
	/* step6: Congfig for channel timer */
	*LPIT_TCTRLx &= ~(1u<<0);  /* Disable timer LPIT channel 1 */
	*LPIT_TCTRLx |= (1u<<2); /* Mode 1: 16 bits */			

}

void LPIT_EnableOrDisableTimerChannel(volatile uint32 Channelx, volatile uint32 Status){
	
	  /* Declare register virtual for register */
		volatile uint32 *LPIT_TCTRLx;  
	  
	  if ( Channelx == 0 )
		{
		LPIT_TCTRLx = &LPIT -> LPIT_TCTRL0;
		}
	  else if ( Channelx == 1 )
		{
		LPIT_TCTRLx = &LPIT -> LPIT_TCTRL1;
		}
	  else if (Channelx == 2)
		{
		LPIT_TCTRLx = &LPIT -> LPIT_TCTRL2;
		}
    else if ( Channelx == 3)
    {
			LPIT_TCTRLx = &LPIT -> LPIT_TCTRL3;
		}
    else 
	 	{
			return; 
		}			
		
		if ( Status == 1 )
		{
			*LPIT_TCTRLx |= (1u<<0);  /* Enable Timer channelx */
		}
    else if (Status == 0)
		{
			*LPIT_TCTRLx &= ~(1u<<0); /* Disable Timer channelx */
		}
		else{
			return; 
		}
}   


void LPIT_ClearFlagInterruptChannel(volatile uint32 Channalx){
	
	
	LPIT -> LPIT_MSR |= (1u<< Channalx );  /* Clear flag */
	
}

void LPIT_ChainModeChannel(volatile uint32 Channelx){
	
	/* Declare register virtual for register */
		volatile uint32 *LPIT_TCTRLx;  
	
	if ( Channelx == 0 )
		{
		LPIT_TCTRLx = &LPIT -> LPIT_TCTRL0;
		}
	  else if ( Channelx == 1 )
		{
		LPIT_TCTRLx = &LPIT -> LPIT_TCTRL1;
		}
	  else if (Channelx == 2)
		{
		LPIT_TCTRLx = &LPIT -> LPIT_TCTRL2;
		}
    else if ( Channelx == 3)
    {
			LPIT_TCTRLx = &LPIT -> LPIT_TCTRL3;
		}
    else 
	 	{
			return; 
		}		
	
		/* Enable chain mode in channelx */
		*LPIT_TCTRLx |= (1u << 1);  /* not using it in channel 0 */
		
}


void LPUART_Init(LPUART_Type*LPUART_x , PORT_Type*PORT_x ,volatile uint32 Pin_Tx, volatile uint32 Pin_Rx, volatile uint32 BaudRate, volatile uint32 PCC_ClockValue, volatile uint32 ModeBitData, volatile uint32 ModeParity){

	/* Declare Temp_Register */
	volatile uint32 * PORTx_PCRn_Tx;
	volatile uint32 * PORTx_PCRn_Rx;
	
		/* 1. Setting Tx/Rx */	
	/* Enable Clock PORT */
	//PCC_EnableClock_Port(PORT_x);  /* Enable PCC PORT_x*/
	
	/* Congfig MUX LPUART_Tx */ 															/* 		UART0: (Rx : PTA2,PTB0) (Tx : PTA3,PTB1) */
	PORTx_PCRn_Tx = &PORT_x -> PORT_PCR0;											/*		UART1: (Rx : PTC6,PTC8) (Tx : PTC7,PTC9)  */
	PORTx_PCRn_Tx += Pin_Tx;																	/*		UART2: (Rx : PTD6,PTD17) (Tx : PTD7,PTE12)  */
	*PORTx_PCRn_Tx |= ( 2u << 8) ;		/* Congfig MUX Tx */		/*		UART3: (Rx : PTA8,PTD13) (Tx : PTA9, PTD14)		*/
	/* Congfig MUX LPUART_Rx */																/*		UART1: (Rx : PTC6,PTC8) (Tx : PTC7,PTC9)  */
	PORTx_PCRn_Rx = &PORT_x -> PORT_PCR0;						
	PORTx_PCRn_Rx += Pin_Rx;
	*PORTx_PCRn_Rx |= ( 2u << 8) ;		/* Congfig MUX Rx */
	
		/* 3. Setting baud rate */
	/* Set div rate */  /* baud is 9600 */
	LPUART_x -> BAUD |= ( ( ((PCC_ClockValue * 1000 ) / BaudRate) / 16) << 0);  /* set value count down */
	
		/* 4. Setting Frame */
	LPUART_x -> BAUD &= ~(1u<<13);  /* Select One stop bit */
	
		/* Select mode data */
	if (ModeBitData == 8)
	{
		LPUART_x -> CTRL &= ~(1u << 4);  /* Select mode using 8 bit data */
	}
	else if ( ModeBitData == 9)
	{
		LPUART_x -> CTRL |= (1u << 4);  /* Select mode using 9 bit data */
	}
	else
	{
		return;
	}
		
		
		/* Congfig Parity */
		if( ModeParity == Disable_Parity)
	{
		LPUART_x -> CTRL &= ~(1u<<1);  /* Disable Parity */
	}
	else if (ModeParity == Even_Parity )
	{		
		LPUART_x -> CTRL &= ~(1u<<0);  /* Set Even Parity */
		LPUART_x -> CTRL |= (1u<<1);   /* Enable Even Parity */
	}
	else if (ModeParity == Odd_Parity )
	{
		LPUART_x -> CTRL |= (1u<<0);  /* Set Odd Parity */
		LPUART_x -> CTRL |= (1u<<1);   /* Enable Even Parity */
	}
	else 
	{
		return;
	}
	
	
}




void LPUART_EnableTransmitter(LPUART_Type*LPUART_x){
	
	LPUART_x -> CTRL |= (1u<<19);  /* Enable Transmitter */
	
}

void LPUART_DisableTransmitter(LPUART_Type*LPUART_x){
	
	LPUART_x -> CTRL &= ~(1u<<19);  /* Disable Transmitter */
	
}

void LPUART_EnableReceiver(LPUART_Type*LPUART_x){
	
	LPUART_x -> CTRL |= (1u<<18);  /* Enable Receiver */
	
}
	

void LPUART_DisableReceiver(LPUART_Type*LPUART_x){
	
	LPUART_x -> CTRL &= ~(1u<<18);  /* Disable Receiver */
}


void LPUART_EnableInterrupt(LPUART_Type*LPUART_x,volatile uint32 ReceiverORTransmitter){
	
	if(ReceiverORTransmitter == LPUART_EnableInterrupt_Receiver)
	{
				/* Enable Interrupt for LPUART */
	LPUART_x -> CTRL |= (1u<<21);  /* Receiver interrupt Enable */
	}
	else if (ReceiverORTransmitter == LPUART_EnableInterrupt_Transmitter )
	{
					/* Enable Interrupt for LPUART */
	LPUART_x -> CTRL |= (1u<<23);  /* Transmitter interrupt Enable */
	}
	else
	{
		return;
	}
	
}


uint32 LPUART_CheckFlagReceiver(LPUART_Type*LPUART_x){

	return (LPUART_x -> STAT & (1u<<21));  /* Check Flag Receiver */

}

void LPUART_ClearFlagReceiver(LPUART_Type*LPUART_x){
	
	LPUART_x -> STAT |= (1u<<21);  /* Write 1 to clear Flag Receiver */
	
}

uint32 LPUART_CheckFlagTransmitter(LPUART_Type*LPUART_x){
	
	return (LPUART_x -> STAT & (1u<<23));  /* Check Flag Transmitter */
	
}


void LPUART_ClearFlagTransmitter(LPUART_Type*LPUART_x){
	
	LPUART_x -> STAT |= (1u<<23);  /* Write 1 to clear Flag Transmitter */
	
}

void LPUART_SendString(volatile uint8 String[], LPUART_Type*LPUART_x){
	
	/* declare varialbe */
	volatile uint32 count = 0;
	
	while( (LPUART_x -> STAT & (1u<<23)) == 0 );  /* wait for buffer is empty */
	while( String[count] != '\0')
	{
		while( !((LPUART1 -> STAT & (1u<<23)) == 0) )
		{
		LPUART1 -> DATA |= String[count];  /* Send char_s */ 
		++count;
		}
		

	} 
	
	
}


void LPUART_Receiver_Char(LPUART_Type*LPUART_x, volatile uint8 *Char_result)
{
	
	while( (LPUART_x -> STAT & (1u<<21)) == 0 ){}  /* wait for receiver buffer is full */		
	*Char_result = (uint8) (LPUART1 -> DATA);
	
}


void LPUART_Receiver_String(LPUART_Type*LPUART_x, volatile uint8 String_result[],volatile uint8 Char_End){
	
	volatile uint32 Count_while = 0;  
					do{
					LPUART_Receiver_Char(LPUART_x,(String_result+Count_while));	/* Receive all string in UART */
					Count_while++;
					}
					while( String_result[Count_while-1] != Char_End);  /* Receiver string until see '=' */
	
	
	
}



void LPUART_SendChar(volatile uint8 Char_Send, LPUART_Type*LPUART_x){
	
	while( (LPUART_x -> STAT & (1u<<23)) == 0 );  /* wait for buffer is empty */
	LPUART_x -> DATA |= Char_Send;  /* Send Char_Send */  
	for(volatile uint32 i = 0; i < 1000; i++);
	
}


	
