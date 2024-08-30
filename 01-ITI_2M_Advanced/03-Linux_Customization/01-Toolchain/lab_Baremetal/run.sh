qemu-system-arm -M versatilepb -m 128M -nographic -kernel test.bin 2> /dev/null


#-M versatilepb : specifies qemu to emulate Versatile PB.
#-m 128M tells qemu to use 128MB Ram for this system
#-nographic : Dont use graphic and provide terminal output
#-kernel test.bin : Load this binary as the system image.
