1-sudo arm none eabi as mcpu =arm 926 ej s g startup.s o startup.o
2-sudo arm none eabi gcc c mcpu =arm 926 ej s I g test.c o test.o
3-sudo arm none eabi ld T test.ld test.o startup.o test.elf
4-sudo arm none eabi objcopy O binary test.elf test.bin
5-./run.sh test.bin