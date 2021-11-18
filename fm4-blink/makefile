CC=arm-none-eabi-gcc
BIN = arm-none-eabi-objcopy
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0
LDFLAGS= -mcpu=$(MACH) -mthumb -mfloat-abi=soft -nostdlib 

all: fm4_startup.o system_mb9abxxx.o main.o final.elf final.srec

semi: fm4_startup.o main.o

fm4_startup.o:fm4_startup.c
	$(CC) $(CFLAGS) -o $@ $^
	
system_mb9abxxx.o:system_mb9abxxx.c
	$(CC) $(CFLAGS) -Iinclude -o $@ $^

main.o:main.c
	$(CC) $(CFLAGS) -Iinclude -o $@ $^

final.elf: fm4_ls.ld fm4_startup.o system_mb9abxxx.o main.o
	$(CC) $(LDFLAGS) -T fm4_ls.ld -o final.elf fm4_startup.o system_mb9abxxx.o main.o

final.srec: final.elf
	$(BIN) -O srec final.elf final.srec

clean:
	rm -rf *.o *.elf *.srec *.map


