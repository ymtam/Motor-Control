/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG1
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF         // Low Voltage Programming Enable bit (RB3/PGM pin has PGM function, low voltage programming disabled)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */
int status_M1=0;
int status_M2=0;
int status_M3=0;
int status_M4=0;

long counter1=0;
long counter2=0;
long counter3=0;
long counter4=0;
/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
void delay(void)
{
    long i;

    i = 0xffff;
    while(i--)
        ;
}
void main(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();
    
    /* Initialize I/O and Peripherals for application */
    Assign_IO();
    InitApp();
    
    setMOTOR1(0);
    setMOTOR2(0);
    setMOTOR3(0);
    setMOTOR4(0);
    delay();
    setLED1(0);
    setLED2(0);
    setLED2(0);
    setLED2(0);

    while(1)
    {
        /* TODO <INSERT USER APPLICATION CODE HERE> */
        //setLED1(1);
        //delay();
        //setLED1(0);
        //delay();

        if(ADCON0bits.GO_DONE==0)
        {
            ADCON0bits.GO_DONE=1;
        }

        //Switch Setting
       if(getSW1()==0 ||getSW2()==0||getSW3()==0||getSW4()==0)
        {
            //delay();
            if(getSW1()==0)
            {                
                 setLED1(!getLED1());   //if Swtich 1 click reverse LED1
                 while(!getSW1());  //solve debounce and hold press                 
            }
            if(getSW2()==0)
            {
                 setLED2(!getLED2());   //if Swtich 1 click reverse LED1
                 while(!getSW2());  //solve debounce and hold press
            }
            if(getSW3()==0)
            {
                 setLED3(!getLED3());   //if Swtich 1 click reverse LED1
                 while(!getSW3());  //solve debounce and hold press
            }
            if(getSW4()==0)
            {
                 setLED4(!getLED4());   //if Swtich 1 click reverse LED1
                 while(!getSW4());  //solve debounce and hold press
            }
        }

        
        if(getLED1()==1)
        {
            status_M1=1;
        }else
        {
            status_M1=0;
        }

        if(getLED2()==1)
        {
            status_M2=1;
        }else
        {
            status_M2=0;
        }

        if(getLED3()==1)
        {
            status_M3=1;
        }else
        {
            status_M3=0;
        }

        if(getLED4()==1)
        {
            status_M4=1;
        }else
        {
            status_M4=0;
        }

        //Motor Setting
        
        if(status_M1==1)
        {
            
            if(counter1<=0)
            {
                if(getVar1()==0)
                {
                    counter1=0;
                }
                else
                {
                    counter1=getVar1()*100;
                }
                setMOTOR1(getMOTOR1());
            }
            counter1--;
        }else
        {
            setMOTOR1(0);
        }

        if(status_M2==1)
        {

            if(counter2<=0)
            {
                if(getVar2()==0)
                {
                    counter2=0;
                }
                else
                {
                    counter2=getVar2()*100;
                }
                setMOTOR2(getMOTOR2());
            }
            counter2--;
        }else
        {
            setMOTOR2(0);
        }

        if(status_M3==1)
        {

            if(counter3<=0)
            {
                if(getVar3()==0)
                {
                    counter3=0;
                }
                else
                {
                    counter3=getVar3()*100;
                }
                setMOTOR3(getMOTOR3());
            }
            counter3--;
        }else
        {
            setMOTOR3(0);
        }


        if(status_M4==1)
        {

            if(counter4<=0)
            {
                if(getVar4()==0)
                {
                    counter4=0;
                }
                else
                {
                    counter4=getVar4()*100;
                }
                setMOTOR4(getMOTOR4());
            }
            counter4--;
        }else
        {
            setMOTOR4(0);
        }

    }
}

