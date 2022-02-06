/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

/* TODO Application specific user parameters used in user.c may go here */

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

/* TODO User level functions prototypes (i.e. InitApp) go here */

int getSW1(void);
int getSW2(void);
int getSW3(void);
int getSW4(void);

void setMOTOR1(int value);
int getMOTOR1(void);
void setMOTOR2(int value);
int getMOTOR2(void);
void setMOTOR3(int value);
int getMOTOR3(void);
void setMOTOR4(int value);
int getMOTOR4(void);


void setLED1(int value);
int getLED1(void);
void setLED2(int value);
int getLED2(void);
void setLED3(int value);
int getLED3(void);
void setLED4(int value);
int getLED4(void);

//void setUart(int value);
//int getUart(void);

void InitApp(void);         /* I/O and Peripheral Initialization */
void Assign_IO(void);

void setVar1(int value);
int getVar1(void);
void setVar2(int value);
int getVar2(void);
void setVar3(int value);
int getVar3(void);
void setVar4(int value);
int getVar4(void);