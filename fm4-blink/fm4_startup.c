/*********************************************************************
*                       TransistorRetorcido                          *
*                        TwistedTransistor                           *
*    Create from sratch (on develop) for use on Linux with GCC-ARM   *
*       Based with: https://www.youtube.com/watch?v=B7oKdUvRhQQ      *
*********************************************************************/ 

#include<stdint.h>

#define SRAM_START  0x1fff4000U
#define SRAM_SIZE   (48U * 1024U) //48KB
#define SRAM_END    ((SRAM_START) + (SRAM_SIZE))

#define STACK_START   SRAM_END

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _la_data;

extern uint32_t _sbss;
extern uint32_t _ebss;

//prototype of main

int main(void);

void __libc_init_array(void);


/* function prototypes of MB9BF367M system exception and IRQ handlers */

void Reset_Handler(void);

void NMI_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void AnomFreqIRQ_Handler (void) __attribute__ ((weak, alias("Default_Handler")));             
void WWDG_IRQ_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void LVD_IRQ_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void Reloc_IRQ03_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void Reloc_IRQ04_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void Reloc_IRQ05_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void Reloc_IRQ06_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void Reloc_IRQ07_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void Reloc_IRQ08_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void Reloc_IRQ09_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void Reloc_IRQ10_Handler (void) __attribute__ ((weak, alias("Default_Handler")));         
void EXTI0_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI1_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI2_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI3_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI4_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI5_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI6_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI7_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void QPRCCH0_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void QPRCCH1_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));          
void MFT0WFG_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void MFT1WFG_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void MFT2WFG_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));          
void MFT0FRTPEAK_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void MFT0FRTZERO_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));          
void MFT0ICU_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void MFT0OCU_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));          
void MFT1FRTPEAK_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void MFT1FRTZERO_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));          
void MFT1ICU_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void MFT1OCU_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));    
void MFT2FRTPEAK_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void MFT2FRTZERO_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));          
void MFT2ICU_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void MFT2OCU_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));    



uint32_t vectors[] __attribute__((section(".isr_vector")))   = {
  STACK_START,
  (uint32_t)Reset_Handler,
  (uint32_t)NMI_Handler,
  (uint32_t)HardFault_Handler,
  (uint32_t)MemManage_Handler,
  (uint32_t)BusFault_Handler,
  (uint32_t)UsageFault_Handler,
  0,
  0,
  0,
  0,
  (uint32_t)SVC_Handler,
  (uint32_t)DebugMon_Handler,
  0,
  (uint32_t)PendSV_Handler,
  (uint32_t)SysTick_Handler,
  (uint32_t)AnomFreqIRQ_Handler,
  (uint32_t)WWDG_IRQ_Handler,
  (uint32_t)LVD_IRQ_Handler,         
  (uint32_t)Reloc_IRQ03_Handler,
  (uint32_t)Reloc_IRQ04_Handler,  
  (uint32_t)Reloc_IRQ05_Handler,  
  (uint32_t)Reloc_IRQ06_Handler,  
  (uint32_t)Reloc_IRQ07_Handler,  
  (uint32_t)Reloc_IRQ08_Handler,  
  (uint32_t)Reloc_IRQ09_Handler,  
  (uint32_t)Reloc_IRQ10_Handler,  
  (uint32_t)EXTI0_IRQHandler,       
  (uint32_t)EXTI1_IRQHandler,       
  (uint32_t)EXTI2_IRQHandler,       
  (uint32_t)EXTI3_IRQHandler,       
  (uint32_t)EXTI4_IRQHandler,
  (uint32_t)EXTI5_IRQHandler,       
  (uint32_t)EXTI6_IRQHandler,       
  (uint32_t)EXTI7_IRQHandler,
  (uint32_t)QPRCCH0_IRQHandler,
  (uint32_t)QPRCCH1_IRQHandler,
  (uint32_t)MFT0WFG_IRQHandler,       
  (uint32_t)MFT1WFG_IRQHandler,       
  (uint32_t)MFT2WFG_IRQHandler,
  (uint32_t)MFT0FRTPEAK_IRQHandler,
  (uint32_t)MFT0FRTZERO_IRQHandler,
  (uint32_t)MFT0ICU_IRQHandler,
  (uint32_t)MFT0OCU_IRQHandler,       
  (uint32_t)MFT1FRTPEAK_IRQHandler,
  (uint32_t)MFT1FRTZERO_IRQHandler,
  (uint32_t)MFT1ICU_IRQHandler,
  (uint32_t)MFT1OCU_IRQHandler,    
  (uint32_t)MFT2FRTPEAK_IRQHandler,
  (uint32_t)MFT2FRTZERO_IRQHandler,
  (uint32_t)MFT2ICU_IRQHandler,
  (uint32_t)MFT2OCU_IRQHandler,     
  
};


void Default_Handler(void)
{
  while(1);
}

void Reset_Handler(void)
{
  //copy .data section to SRAM
  uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;

  uint8_t *pDst = (uint8_t*)&_sdata; //sram
  uint8_t *pSrc = (uint8_t*)&_la_data; //flash

  for(uint32_t i =0 ; i < size ; i++)
  {
    *pDst++ = *pSrc++;
  }
  
  //Init. the .bss section to zero in SRAM
  size = (uint32_t)&_ebss - (uint32_t)&_sbss;
  pDst = (uint8_t*)&_sbss;
  for(uint32_t i =0 ; i < size ; i++)
  {
    *pDst++ = 0;
  }

main();

}







