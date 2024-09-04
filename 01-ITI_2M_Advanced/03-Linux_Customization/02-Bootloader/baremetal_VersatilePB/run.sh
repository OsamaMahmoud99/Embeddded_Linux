#qemu-system-arm -M versatilepb -m 128M -nographic -kernel test.bin -no-reboot 2> /dev/null
qemu-system-arm -M versatilepb -m 128M \
-kernel $1 \
-no-reboot \
-nographic 


