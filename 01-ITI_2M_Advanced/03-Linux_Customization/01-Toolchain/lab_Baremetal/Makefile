CC=arm-none-eabi
CFLAGS=-I, -g
CPU=-mcpu=arm926ej-s
helloworld: test.c
	$(CC)-as $(CPU) $(CFLAGS) startup.s -o startup.o
	$(CC)-gcc -c $(CPU) $(CFLAGS) test.c -o test.o
	$(CC)-ld -T test.ld test.o startup.o -o test.elf
	$(CC)-objcopy -O binary test.elf test.bin


