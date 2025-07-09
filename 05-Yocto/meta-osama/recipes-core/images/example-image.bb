#Base this image on core-image-Base
include recipes-core/images/core-image-base.bb

COMPATIBLE_MACHINE = "^rpi$"

inherit extrausers
EXTRA_USERS_PARAMS = "\
usermod -p \\\$1\\\$5/Cvv4Tm\\\$JwRm6wn5cS.7KEk3/Lw2C/ root \
"

IMAGE_FSTYPES += "rpi-sdimg"

RM_OLD_IMAGE = "1"

IMAGE_FEATURES:remove = "splash"

do_rootfs:append(){
    # Your code here
    bb.warn("An image has freshly built success!")
}

IMAGE_INSTALL:append = " i2c-tools vim tzdata tzdata-africa networkmanager networkmanager-nmtui networkmanager-bash-completion"

# Add support for wifi and bluetooth
IMAGE_INSTALL:append = " linux-firmware linux-firmware-bcm43430"

IMAGE_INSTALL:append = " openssh xllvnc"

#Install  cpp hello world - sources version
IMAGE_INSTALL:append = " hello-world-cpp-sources"

#Install  cpp hello world - make version
IMAGE_INSTALL:append = " hello-world-cpp-makefile"

IMAGE_INSTALL:append = " python-flask-hello-world"

IMAGE_INSTALL:append = " qtbase-tools qtbase qtdeclarative qt imageformats qtmultimedia qtquickcontrols2 qtquickcontrols qtbase-plugins cinematicexperience"