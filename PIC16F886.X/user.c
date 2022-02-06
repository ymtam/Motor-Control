/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "user.h"
#include "system.h"

#define     LED1    PORTCbits.RC0
#define     LED2    PORTCbits.RC1
#define     LED3    PORTCbits.RC2
#define     LED4    PORTCbits.RC3

#define     SW1     PORTBbits.RB4
#define     SW2     PORTBbits.RB5
#define     SW3     PORTBbits.RB6
#define     SW4     PORTBbits.RB7

#define     MOTOR1      PORTBbits.RB0
#define     MOTOR2      PORTBbits.RB1
#define     MOTOR3      PORTBbits.RB2
#define     MOTOR4      PORTBbits.RB3

#define     TR1         PORTCints.RA0
#define     TR2         PORTCints.RA1
#define     TR3         PORTCints.RA2
#define     TR4         PORTCints.RA3
/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

int var1=0;
int var2=0;
int var3=0;
int var4=0;

int getSW1(void)
{
    return SW1;
}
int getSW2(void)
{
    return SW2;
}
int getSW3(void)
{
    return SW3;
}
int getSW4(void)
{
    return SW4;
}


void setMOTOR1(int value)
{
    MOTOR1=!value;
}
int getMOTOR1(void)
{
    return MOTOR1;
}
void setMOTOR2(int value)
{
    MOTOR2=!value;
}
int getMOTOR2(void)
{
    return MOTOR2;
}
void setMOTOR3(int value)
{
    MOTOR3=!value;
}
int getMOTOR3(void)
{
    return MOTOR3;
}
void setMOTOR4(int value)
{
    MOTOR4=!value;
}
int getMOTOR4(void)
{
    return MOTOR4;
}


void setLED1(int value)
{
    LED1=value;
}
int getLED1(void)
{
    return LED1;
}
void setLED2(int value)
{
    LED2=value;
}
int getLED2(void)
{
    return LED2;
}
void setLED3(int value)
{
    LED3=value;
}
int getLED3(void)
{
    return LED3;
}
void setLED4(int value)
{
    LED4=value;
}
int getLED4(void)
{
    return LED4;
}


void setVar1(int value)
{
    var1=value;
}
int getVar1(void)
{
    return var1;
}
void setVar2(int value)
{
    var2=value;
}
int getVar2(void)
{
    return var2;
}
void setVar3(int value)
{
    var3=value;
}
int getVar3(void)
{
    return var3;
}
void setVar4(int value)
{
    var4=value;
}
int getVar4(void)
{
    return var4;
}
/*
void setUart(int value)
{
    TXREG=value;
}
int getUart(void)
{
    return RCREG;
}
*/
void InitApp(void)
{

    /* Enable interrupts */
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;

    /* TODO Initialize User Ports/Peripherals/Project here */
    
    //WPUB=0xff;
    //IOCB=0;
    //PORTB=0;
    //TRISB=0b11110000;
    //PORTB=0;

    //ANSEL=0b00001111;
    //PORTA=0;
    //TRISA=0b00001111;
    
    //PORTC=0;
    //TRISC=0;

    //PORTCbits.RC6=0;
    //TRISCbits.TRISC6=0;
    //PORTCbits.RC7=0;
    //TRISCbits.TRISC7=1;

    ADRESL=0;
    ADRESH=0;
    ADCON0=0x00;
    ADCON1=0;
    PIR1bits.ADIF=0;
    PIE1bits.ADIE=1;
    ADCON0bits.ADON=1;


    TXSTA=0;
    TXSTAbits.BRGH=1;
    TXSTAbits.TXEN=1;

    RCSTA=0;
    RCSTAbits.CREN=1;
    RCSTAbits.SPEN=1;

    SPBRG=64;
    SPBRGH=0;

    PIR1bits.RCIF=0;
    PIR1bits.TXIF=0;
    PIE1bits.RCIE=1;
    PIE1bits.TXIE=0;

}

void Assign_IO(void)
{

    //PORTA Assignment
    ANSEL=0b00001111;
    PORTA=0;
    TRISA=0b00001111;
    PORTA=0;
    
    //PORTB Assignment
    ANSELH=0;
    WPUB=0xff;
    IOCB=0;
    PORTB=0;
    TRISB=0b11110000;
    PORTB=0;

    PORTC=0;
    TRISC=0;
    PORTCbits.RC6=0;
    TRISCbits.TRISC6=0;
    PORTCbits.RC7=0;
    TRISCbits.TRISC7=1;
}

