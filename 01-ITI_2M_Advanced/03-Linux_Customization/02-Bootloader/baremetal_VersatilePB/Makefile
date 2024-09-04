
CC=arm-none-eabi
CFLAGS= -I . -g
CPU= -mcpu=arm926ej-s
OBJ=test.o startup.o 
	
%.o: %.c
	$(CC)-gcc -c $(CPU)  $(CFLAGS)  $< -o $@

startup.o: startup.s
	$(CC)-as  $(CPU)  $(CFLAGS)  $<  -o  $@


test.elf: $(OBJ)
	$(CC)-ld -T test.ld $(OBJ) -o $@

test.bin: test.elf
	$(CC)-objcopy -O binary $< $@

all: test.bin
	echo "finished"


clean: 
	rm test.o startup.o test.elf test.bin

.PHONY: test.bin
	
