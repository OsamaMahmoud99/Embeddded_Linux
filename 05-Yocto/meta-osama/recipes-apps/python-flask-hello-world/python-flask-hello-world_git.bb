SUMMARY = "Python Flask Hello World App"
LICENSE = "CLOSED"
LIC_FILES_CHKSUM = ""

SRC_URI = "\
    git://github.com/hubshuffle/python-flask-hello-world.git;protocol=https;branch=master \
    file://python-flask-hello-world.service \
	file://0001-change-port-to-7777.patch \
"

PV = "1.00+git${SRCPV}"
SRCREV = "ef935ecdf7b081fbc86ae9a71812e64a6a138301"

RDEPENDS_${PN} = "python3 python3-flask"


S = "${WORKDIR}/git"

inherit systemd

do_install() {
    install -d "${D}${bindir}"
    install -m 0755 "${S}/app.py" "${D}${bindir}/python-flask-hello-world.py"

    install -d "${D}${systemd_system_unitdir}"
    install -m 0644 "${WORKDIR}/python-flask-hello-world.service" \
        "${D}${systemd_system_unitdir}/python-flask-hello-world.service"
}

FILES:${PN} += "\
    ${bindir}/python-flask-hello-world.py \
    /lib/systemd/system/ \
"

SYSTEMD_SERVICE:${PN} = "python-flask-hello-world.service"
