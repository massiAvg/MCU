/*
*
*       Created on : June 10, 2022 
*      Last Update : June 10, 2022
*           Author : massiAv
*
*/

#include <stdio.h>
#include "stm32f3x_lib.h"
#include "stm32f3x_api_driver.h"
#include "stm32f3x_timer_driver.h"

float voltage = RESET;

void main()
{
          RCC_PCLK_AHBEN(RCC_AHBENR_ADC12,ENABLE);                      /*!< ENABLE ADC12 BECAUSE PA0 (ANALOG_MODE) IS LINKED TO ADC12      >*/
          RCC_PCLK_AHBEN(RCC_AHBENR_GPIOA,ENABLE);                      /*!< ENABLE PORT A      >*/        
          RCC_PCLK_AHBEN(RCC_AHBENR_GPIOE,ENABLE);                      /*!< ENABLE PORT E      >*/
          
          GPIO_MODE(GPIOA,ANALOG_MODE,Px0);                             /*!< ENABLE PA0 in analog mode      >*/
          
          GPIOE->MODER|=0x55555000;
         
          config_ADC(ADC1,ADC1_2);
         
          ADC1->CR |= ADC_CR_ADSTART;                                           /*!< Start CONVERSIONE pull up bit ADSTART >*/
         
          while(1)
          {
              while((ADC1->ISR & (ADC_ISR_EOC))!= (ADC_ISR_EOC));               /*!< Wait that EOC change to 1, when EOC=1 can read the result in ADC->DR*/
             
              voltage=ADC1->DR*(3.0/4096.0);
             
              if(voltage<=3 && voltage>=2.9986)
              {
                GPIOE->ODR^=0x0000FF00;                                         /*!< Inverter the state on LED >*/
                printf("Value of voltage %f\n",voltage);
              }
          }
}

