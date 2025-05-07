
# 🧠 Buildroot for ARM Cortex-A9 (VExpress / QEMU)

This project builds a minimal embedded Linux image for the **ARM Cortex-A9 Versatile Express** platform using [Buildroot](https://buildroot.org/), running in **QEMU** for quick development and testing.

---

## 📁 Project Structure

```
buildroot-2024.02/
├── configs/
├── output/
└── README.md
```

---

## 🛠️ Prerequisites

Install required packages on Ubuntu:

```bash
sudo apt-get update
sudo apt-get install \
    sed make binutils gcc g++ bash patch \
    gzip bzip2 perl tar cpio python-is-python3 unzip rsync wget \
    libncurses-dev qemu-system-arm
```

---

## 📦 Download Buildroot

```bash
wget https://buildroot.org/downloads/buildroot-2024.02.tar.gz
tar -xvzf buildroot-2024.02.tar.gz
cd buildroot-2024.02
```

Alternatively, clone the latest version:

```bash
git clone https://github.com/buildroot/buildroot.git
cd buildroot
```

---

## ⚙️ Configure for VExpress (ARM Cortex-A9)

Use the default config provided by Buildroot:

```bash
make qemu_vexpress_defconfig
```

Optional: Customize the build using menuconfig:

```bash
make menuconfig
```

You may wish to:
- Enable `dropbear` for SSH support
- Add `nano`, `htop`, `busybox` features

---

## 🔨 Build the System

> ⚠️ **Do NOT use `sudo` during `make`!**

```bash
make -j$(nproc)
```

If you previously ran `sudo make` by mistake, fix permissions with:

```bash
sudo chown -R $USER:$USER output/
```

---

## ▶️ Run with QEMU

After a successful build, run the image with QEMU:

```bash
qemu-system-arm \
  -M vexpress-a9 \
  -m 256M \
  -kernel output/images/zImage \
  -dtb output/images/vexpress-v2p-ca9.dtb \
  -drive file=output/images/rootfs.ext2,if=none,format=raw,id=hd0 \
  -device virtio-blk-device,drive=hd0 \
  -netdev user,id=net0,hostfwd=tcp::2222-:22 \
  -device virtio-net-device,netdev=net0 \
  -append "root=/dev/vda console=ttyAMA0" \
  -nographic
```
or run the shell script in output/images

```bash

sudo ./output/images/start-qemu.sh

```
✅ This runs the Linux image and connects serial output to your terminal.

---

## 💡 Useful Tips

- Login as `root` (no password)
- To SSH (if enabled):  
  ```bash
  ssh -p 2222 root@localhost
  ```

---

## 📘 License

This project uses [Buildroot](https://buildroot.org/), which is licensed under GPLv2.

---

## 🙋 Support

Feel free to open an issue or submit a pull request with enhancements or bug fixes!
