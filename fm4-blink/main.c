/*********************************************************************
*                       TransistorRetorcido                          *
*                        TwistedTransistor                           *
*    Edited from SEGGER Examples for use on Linux with GCC-ARM       *
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "mcu.h"


/*********************************************************************
*
*       main()
*********************************************************************/

int main(void) {
  uint32_t i;
  //printf("Hello World %d!\n", i);
  SystemInit(); // From system_mb9bf36xr -> Init clock module
  
  /*Set pin as a GPIO (Disable Altern Function)*/
  FM4_GPIO->PFR0_f.P09 = 0;
  FM4_GPIO->PFR4_f.P45 = 0;  
  
  /*Use P09 as digital (Disable Analog input)*/
  FM4_GPIO->ADE_f.AN19 = 0;  
  
  /*Set pin to HIGH*/  
  FM4_GPIO->PDOR4_f.P45 = 1;
  FM4_GPIO->PDOR0_f.P09 = 1;

  /*Set pin as output*/  
  FM4_GPIO->DDR4_f.P45 = 1;  
  FM4_GPIO->DDR0_f.P09 = 1;

  while (1){
  for (i = 0; i < 5000000; i++) {
    bFM4_GPIO_PDOR4_P45 = 1;    
    bFM4_GPIO_PDOR0_P09 = 1;   
    
    }
  for (i = 0; i < 5000000; i++) {
    bFM4_GPIO_PDOR4_P45 = 0;    
    bFM4_GPIO_PDOR0_P09 = 0;
   
    }
  }
}

/*************************** End of file ****************************/
