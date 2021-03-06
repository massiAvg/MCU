/* 
*
*       Created on : June 02, 2022 
*       Last Update: June 09, 2022
*           Author : massiAv
*
*/

#include <stdio.h>
#include "stm32f3x_lib.h"
#include "stm32f3x_api_driver.h"
#include "stm32f3x_timer_driver.h"

int flag = RESET;

void main(){

        RCC_PCLK_AHBEN(RCC_AHBENR_GPIOE,ENABLE);
        RCC_PCLK_APB1EN(RCC_APB1ENR_TIM2,ENABLE);       /*!< ENABLE GPIOE AND TIMER2>*/
                
        GPIOE_OUTMODE(Px8,Px15);                        /*!< SET PEx (WITH x = 8,9,..15) IN OUTPUT_MODE >*/
          
        TIM2->ARR = N_CONT(0.5);                        /*!< TIME (in seconds) as INPUT > */
        
        /*!< ENABLE COUNTER PULL UP BIT CEN >*/
        CNT_EN_TIM(TIM2,ENABLE);                        /*!< WHEN CNT REACHES N_CNT(X) THE UIF IS SET TO 1 >*/
        
        while(1)
        {
            if(CHECK_UIF(TIM2) && !flag)
            {  
              //GPIOE->ODR = GPIOE_ALL_LED_ON;          /*!< ON ALL LED                    > */
              GPIO_BSR_REG(GPIOE,Px10,SET);          /*!< BSRR to Set the corrispondent ODRx bit >*/
              TIM2->SR &=~ SET_UIF;                     /*!< RESET UPDATE INTERRUPT FLAG   > */
              flag = SET;    
            }
            else if(CHECK_UIF(TIM2) && flag)
            {
               //GPIOE->ODR = RESET;                    /*!< OFF ALL LED                 >*/    
               GPIO_BSR_REG(GPIOE,Px10,RESET);       /*!< BSRR to Reset the corrispondent ODRx bit >*/
               TIM2->SR &=~ SET_UIF;                    /*!< RESET UPDATE INTERRUPT FLAG >*/
               flag = RESET;
            }
            
        }
}
