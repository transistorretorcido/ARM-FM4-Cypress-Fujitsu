/*********************************************************************
*                       TransistorRetorcido                          *
*                        TwistedTransistor                           *
*    Create from sratch (on develop) for use on Linux with GCC-ARM   *
*       Based with: https://www.youtube.com/watch?v=B7oKdUvRhQQ      *
*********************************************************************/

ENTRY(Reset_Handler)

MEMORY
{
  FLASH(rx):ORIGIN =0x00000000,LENGTH =768K
  SRAM(rwx):ORIGIN =0x1fff4000,LENGTH =48K
}

SECTIONS
{
  .text :
  {
    *(.isr_vector)
    *(.text)
    *(.text.*)
    *(.init)
    *(.fini)
    *(.rodata)
    *(.rodata.*)
  . = ALIGN(4);
  _etext = .;
  }> FLASH
  
  _la_data = LOADADDR(.data);
  
  .data :
  {
    _sdata = .;
  *(.data)
  *(.data.*)
  . = ALIGN(4);
  _edata = .;
  }> SRAM AT> FLASH
  
  .bss :
  {
    _sbss = .;
  __bss_start__ = _sbss;
  *(.bss)
  *(.bss.*)
  *(COMMON)
  . = ALIGN(4);
  _ebss = .;
  __bss_end__ = _ebss;
  . = ALIGN(4); 
  end = .;
  __end__ = .;
  }> SRAM  
  
}
