qemu-system-arm -M vexpress-a9 -m 512M \
-kernel $1 \
-no-reboot \
-monitor telnet:127.0.0.1:1111,server,nowait \
-serial stdio \
-nographic 

