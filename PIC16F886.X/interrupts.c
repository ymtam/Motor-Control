/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "user.h"

/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/

/* Baseline devices don't have interrupts. Note that some PIC16's 
 * are baseline devices.  Unfortunately the baseline detection macro is 
 * _PIC12 */
#ifndef _PIC12

void interrupt isr(void)
{
    /* This code stub shows general interrupt handling.  Note that these
    conditional statements are not handled within 3 seperate if blocks.
    Do not use a seperate if block for each interrupt flag to avoid run
    time errors. */

    if(PIR1bits.ADIF)
    {
        ADCON0bits.GO_DONE=0;
        PIR1bits.ADIF=0;
        if(ADCON0bits.CHS==0)
        {
            setVar1(ADRESH);
        }else if(ADCON0bits.CHS==1)
        {
            setVar2(ADRESH);
        }else if(ADCON0bits.CHS==2)
        {
            setVar3(ADRESH);
        }else if(ADCON0bits.CHS==3)
        {
            setVar4(ADRESH);
        }
        if(ADCON0bits.CHS<4)
        {
            ADCON0bits.CHS=ADCON0bits.CHS+1;
        }else
        {
            ADCON0bits.CHS=0;
        }       

    }
    if(PIR1bits.RCIF==1)
    {
        //TXREG=RCREG;
        if(RCREG=='a')
        {
            setLED1(!getLED1());
        }
        if(RCREG=='b')
        {
            setLED2(!getLED2());
        }
        if(RCREG=='c')
        {
            setLED3(!getLED3());
        }
        if(RCREG=='d')
        {
            setLED4(!getLED4());
        }
        PIR1bits.RCIF=0;

    }else if(PIR1bits.TXIF)
    {
        PIR1bits.TXIF=0;
    }

#if 0
    
    /* TODO Add interrupt routine code here. */

    /* Determine which flag generated the interrupt */
    if(<Interrupt Flag 1>)
    {
        <Interrupt Flag 1=0>; /* Clear Interrupt Flag 1 */
    }
    else if (<Interrupt Flag 2>)
    {
        <Interrupt Flag 2=0>; /* Clear Interrupt Flag 2 */
    }
    else
    {
        /* Unhandled interrupts */
    }


#endif

}
#endif


