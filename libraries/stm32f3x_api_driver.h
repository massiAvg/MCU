/* STM32_F3X_DRIVER_H
*
*       Created on : June 01, 2022 
*           Author : massiAv
*
*/

#ifndef STM32_F3X_DRIVER_H
#define STM32_F3X_DRIVER_H

/*!----------------------------------------------------------
          DEFINE GENERAL PURPOSE MACROS FOR STM32F3DISCOVERY
-------------------------------------------------------------*/

/*!< define GENERAL MACROS >*/
#define OUT_MODE                1
#define IN_MODE                 3           /*!< IN_MODE DEFINED 3 BECAUSE OF NEGATIVE LOGIC.
                                            TO SET PINY (WITH Y = A,B,C,...,F) IN IN_MODE WE WRITE:   
                                            PYx & = ~ (3 << x) 
                                            INSTEAD OF
                                            PYx | = (0 << x) >*/   
#define SET                     1
#define RESET                   0

/*!< MACROS TO DEFINE bits that are written by software to select the source input for the EXTIx with x = 0,1,2,3>*/

#define PA0                     3          /*!< TO SELECT PA0 FOR EXTI0 MUST BE WRITTEN 0 BUT DUE TO SOFTWARE NEGATIVE LOGIC 
                                             WE MUST WRITTEN 3. >*/       
#define PB0                     1
#define PC0                     2
#define PD0                     3
#define PE0                     4
#define PF0                     5

/*!< MACROS TO DEFINE NUMBER PIN OF PORT SELECTED.
 -- > PxN is can be:
         - PA0, PB0, PC0, PD0, PE0, PF0;
         - PA1, PB1, PC1, PD1, PE1, PF1;
         - PA2, PB2, PC2, PD2, PE2, PF2;
          ......
          ......
         - PA0, PB0, PC0, PD0, PE0, PF0;
         - PA0, PB0, PC0, PD0, PE0, PF0; 
<*/
#define Px0                     0
#define Px1                     1
#define Px2                     2
#define Px3                     3
#define Px4                     4
#define Px5                     5
#define Px6                     6
#define Px7                     7
#define Px8                     8
#define Px9                     9
#define Px10                    10
#define Px11                    11
#define Px12                    12
#define Px13                    13
#define Px14                    14
#define Px15                    15

/*!< define MACROS for GPIOA_IDR>*/
#define PA0_IDR_MASK            1
#define PA1_IDR_MASK            2
#define PA2_IDR_MASK            3
#define GPIOA_IDR_IN0()         while(((GPIOA->IDR) & (PA0_IDR_MASK)) == 0)
#define GPIOA_IDR_IN1()         while(((GPIOA->IDR) & (PA0_IDR_MASK)) == 1)


/*!< define MACROS for GPIOE_ODR>*/
#define GPIOE_TURN_LED(x)       GPIOE->ODR=(x)<<8
#define GPIOE_ALL_LED_ON        0x0000FF00      

/*!< define MACROS for GPIOE_MODER>*/
#define SET_PE_IN_OUT_MODE()             for(int i = 8; i < 16; i++){GPIOE->MODER|= (OUT_MODE << 2*i);}

/*!< prototypes FUNCTIONS >*/
int index_EXTI(int PinNumber);
int bit_pos_EXTI(int PinNumber);
int bit_pos_GPIO_MODER(int PinNumber);

#endif /* STM32_F3X_DRIVER_H */