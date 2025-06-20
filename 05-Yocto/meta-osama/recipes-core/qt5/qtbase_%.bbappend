PACKAGECONFIG:append = " gl directfb eglfs gles2 journald"


FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI += "\
file://qt-qpa.sh \
"

do_install:append() {
    install -d "${D}${sysconfdir}/profile.d"
    install -m 0644 "${WORKDIR}/qt-qpa.sh" "${D}${sysconfdir}/profile.d"
}