/*  Author  : Fatma                          */
/*  Date    : 15 February 2022               */
/*  version : V1                             */




#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "STP_interface.h"



void main(void)
{
	MRCC_voidInitSysClock();                 /*chose clock system to HSE 8MHZ */
    MRCC_voidEnableClock(APB2, IOPA);         /*Enable GPIOA clock*/

    /*pin Direction */
    MGPIO_voidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);   /*  A0 output push pull  */
    MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);   /*  A1 output push pull  */
    MGPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);   /*  A2 output push pull  */

    /*timer initialization */
    MSTK_voidInit();

   u8 i=0;
  // Infinite loop
  while (1)
    {
	  for(i=0; i<8; i++)
	  {
	    STP_voidSendSynchronus(1<<i);   /* Ping_Pong  */
	    MSTK_voidSetBusyWait(300000);
	  }

    }
}

