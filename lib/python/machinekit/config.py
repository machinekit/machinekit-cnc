# access configure (and eventually runtime) variables           -*-python-*-
# from Python
#
# use like so:
# import machinekit.config
# c = machinekit.config.Config()
# if c.is_rt():
#    ....
# define useful aggregate methods in Config() - this is preferrable to
# tests of raw config variables in usercode
#
# edit src/machinekitcfg.py-tmp.in
# run src/configure
# this will build lib/python/machinekit/config.py
#
# Author: Michael Haberler <license AT mah DOT priv DOT at>
# License: GPL Version 2 or later
# Copyright (c) 2013 All rights reserved.
import sys
if sys.version_info >= (3, 0):
    import configparser
else:
    import ConfigParser as configparser

_cfg = None  # global ConfigParser object


# type guessing helpers from http://stackoverflow.com/questions/7019283/automatically-type-cast-parameters-in-python
def __boolify(s):
    if s == 'True' or s == 'true':
        return True
    if s == 'False' or s == 'false':
        return False
    raise ValueError('Not Boolean Value!')


def __estimateType(var):
    '''guesses the str representation of the variables type'''
    for caster in (__boolify, int, float, str):
        try:
            return caster(var)
        except ValueError:
            pass
    return var


# loads a ini file to the config
def load_ini(iniName):
    global _cfg
    if _cfg is None:
        _cfg = configparser.ConfigParser()
    _cfg.read(iniName)


# find a config entry, compatible to linuxcnc.ini
# note: the module acts as singleton
def find(section, option, default=None):
    if _cfg is None:
        return default
    try:
        return __estimateType(_cfg.get(section, option))
    except (configparser.NoOptionError, configparser.NoSectionError):
        return default


class Config(object):

    def does_io(self):
        if self.BUILD_DRIVERS: return True

    # automatic substitution by configure starts here

    def __init__(self):
        self.GIT_VERSION = "unknown"
        self.GIT_CONFIG_SHA=""
        self.EMC2_HOME = "/usr/src/machinekit-cnc"
        self.BUILD_DRIVERS=True
        self.SUBST=True
        self.MACHINEKIT_INI="/usr/src/machinekit-cnc/etc/linuxcnc/machinekit.ini"
        self.BUILD_THREAD_FLAVORS=" posix rt-preempt"

        # Directories
        self.prefix="/usr/src/machinekit-cnc"
        self.exec_prefix="/usr/src/machinekit-cnc"
        self.rundir= "/tmp"
        self.EMC2_HOME="/usr/src/machinekit-cnc"
        self.LIB_DIR="/usr/src/machinekit-cnc/lib"

        #used for install stuff
        #but have them here as reference
        #build system only uses EMC2_RTLIB_DIR when creating rtapi.ini
        self.EMC2_BIN_DIR="/usr/src/machinekit-cnc/bin"
        self.EMC2_LIBEXEC_DIR="/usr/src/machinekit-cnc/libexec"
        self.EMC2_TCL_DIR="/usr/src/machinekit-cnc/tcl"
        self.EMC2_HELP_DIR="/usr/src/machinekit-cnc/help"
        self.EMC2_RTLIB_DIR="/usr/src/machinekit-cnc/rtlib"
        self.EMC2_USER_CONFIG_DIR="~/emc2/configs"
        self.EMC2_SYSTEM_CONFIG_DIR="/usr/src/machinekit-cnc/etc/linuxcnc"
        self.EMC2_NCFILES_DIR="/usr/src/machinekit-cnc/nc_files"
        self.REALTIME="/usr/src/machinekit-cnc/scripts/realtime"
        self.EMC2_IMAGEDIR="/usr/src/machinekit-cnc"


        # Standard configure directories
        # do we really need these?
        self.bindir = "/usr/src/machinekit-cnc/bin"
        self.sbindir = "/usr/src/machinekit-cnc/sbin"
        self.libexecdir = "/usr/src/machinekit-cnc/libexec"
        self.datadir = "/usr/src/machinekit-cnc/share"
        self.datarootdir = "/usr/src/machinekit-cnc/share"
        self.sysconfdir = "/usr/src/machinekit-cnc/etc"
        self.sharedstatedir = "/usr/src/machinekit-cnc/com"
        self.localstatedir = "/usr/src/machinekit-cnc/var"
        self.libdir = "/usr/src/machinekit-cnc/lib"
        self.infodir = "/usr/src/machinekit-cnc/share/info"
        self.mandir = "/usr/src/machinekit-cnc/share/man"
        self.includedir = "/usr/src/machinekit-cnc/include"
        self.docdir = "/usr/src/machinekit-cnc/share/doc/linuxcnc"
        self.sampleconfsdir = self.datadir +                               "/linuxcnc/examples/sample-configs"
        self.ncfilesdir = self.prefix + "/share/linuxcnc/ncfiles"
        self.tcldir = self.prefix + "/lib/tcltk/linuxcnc"


        # i18n variables:
        self.package = "machinekit"
        self.localedir = "/usr/share/locale"
        self.LANGUAGES = ""


        # /Standard configure directories
        self.RUN_IN_PLACE = True
        self.CC = "gcc"
        self.MANDB = "/usr/bin/mandb"
        self.HIDRAW_H_USABLE = True


        self.BUILD_DRIVERS = True
        self.USE_PORTABLE_PARPORT_IO = False
        self.TARGET_PLATFORM_PC = True
        self.TARGET_PLATFORM_SOCFPGA = ""
        self.TARGET_PLATFORM_BEAGLEBONE = ""
        self.TARGET_PLATFORM_RASPBERRY = ""

        self.USERMODE_PCI=True

        #libudev for if USERMODE_PCI==yes
        self.LIBUDEV_CFLAGS=""
        self.LIBUDEV_LIBS="-ludev"

        # deps for xemc
        self.CFLAGS_X = ""
        self.XLIBS = ""
        self.HAVE_XAW = False

        # ncurses support for keystick
        self.KEYSTICKLIBS =  "-lncurses"
        self.HAVE_NCURSES = True

        # readline support for halcmd
        self.READLINE_LIBS =  "-lreadline"

        # flags for glib
        self.GLIB_CFLAGS = "-I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include"
        self.GLIB_LIBS = "-lglib-2.0"

        # local flags for GTK include
        self.HAVE_GTK = True
        self.GTK_CFLAGS = "-pthread -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/gio-unix-2.0/ -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/libpng16 -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/pango-1.0 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/freetype2 -I/usr/include/libpng16"
        self.GTK_LIBS = "-lgtk-x11-2.0 -lgdk-x11-2.0 -lpangocairo-1.0 -latk-1.0 -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lpangoft2-1.0 -lpango-1.0 -lgobject-2.0 -lglib-2.0 -lfontconfig -lfreetype"
        self.HAVE_GNOMEPRINT = ""

        # tcl tk cflags, includes and libs
        self.TCL_DBGX=""
        self.TK_DBGX=""
        self.TCL_CFLAGS="-I/usr/include/tcl8.6 -DUSE_TCL_STUBS -I/usr/include/tcl8.6 "
        self.TCL_LIBS="-L/usr/lib/x86_64-linux-gnu -ltclstub8.6 -lX11 -lXss -lXext -lXft -lfontconfig -lfreetype -lfontconfig -lpthread -ldl -lz -lpthread -lieee -lm -L/usr/lib/x86_64-linux-gnu -ltk8.6 -lGL  -lXinerama "
        self.HAVE_WORKING_BLT=False


        self.AR = "/usr/bin/ar"
        self.ARFLAGS = "cr" #??
        self.CXX = "g++"
        self.CXXFLAGS = "-g -O2"
        self.RANLIB = "ranlib"
        self.MSGFMT = "/usr/bin/msgfmt"
        self.XGETTEXT = "/usr/bin/xgettext"

        self.BUILD_DOCS = False
        self.BUILD_DOCS_PDF = "@BUILD_DOCS_PDF@"
        self.BUILD_DOCS_HTML = "@BUILD_DOCS_HTML@"
        self.PYTHON = "/usr/bin/python2"

#
# i18n
#
#       self.CONFIG_RTAPI=m

# # rtapi examples
#       self.CONFIG_RTAPI_EXAMPLES_EXTINT=m
#       self.CONFIG_RTAPI_EXAMPLES_FIFO=m
#       self.CONFIG_RTAPI_EXAMPLES_SEM=m
#       self.CONFIG_RTAPI_EXAMPLES_SHMEM=m
#       self.CONFIG_RTAPI_EXAMPLES_TIMER=m

# # emc motion module
#       self.CONFIG_MOTMOD=m

# # HAL components
#       self.CONFIG_BLOCKS=m
#       self.CONFIG_BOSS_PLC=m
#       self.CONFIG_DEBOUNCE=m
#       self.CONFIG_ENCODER=m
#       self.CONFIG_COUNTER=m
#       self.CONFIG_ENCODER_RATIO=m
#       self.CONFIG_STEPGEN=m
#       self.CONFIG_LCD=m
#       self.CONFIG_FREQGEN=m
#       self.CONFIG_PWMGEN=m
#       self.CONFIG_SIGGEN=m
#       self.CONFIG_AT_PID=m
#       self.CONFIG_PID=m
#       self.CONFIG_PEPPER=m
#       self.CONFIG_SUPPLY=m
#       self.CONFIG_CLASSICLADDER_RT=m
#       self.CONFIG_TIMEDELAY=m
#       self.CONFIG_SIM_ENCODER=m
#       self.CONFIG_WEIGHTED_SUM=m
#       self.CONFIG_WATCHDOG=m
#       self.CONFIG_MODMATH=m
#       self.CONFIG_STREAMER=m
#       self.CONFIG_SAMPLER=m

# # HAL drivers
#       self.CONFIG_HAL_PARPORT=m
#       self.CONFIG_PROBE_PARPORT=m
#       self.CONFIG_HAL_TIRO=m
#       self.CONFIG_HAL_EVOREG=m
#       self.CONFIG_HAL_MOTENC=m
#       self.CONFIG_HAL_SKELETON=m
#       self.CONFIG_HAL_GPIO=m
#       self.CONFIG_HM2_SOC=m
#       self.CONFIG_HAL_SPI=m
#       self.CONFIG_HAL_SPEAKER=m
#       self.CONFIG_HAL_STG=m
#       self.CONFIG_HAL_VTI=m
#       self.CONFIG_HAL_AX521H=m
#       self.CONFIG_HAL_PPMC=m
#       self.CONFIG_PCI_8255=m
#       self.CONFIG_HOSTMOT2=m
#       self.CONFIG_OPTO_AC5=m


        self.BUILD_PYTHON=True
        self.INCLUDEPY="@INCLUDEPY@"
        self.SITEPY="/usr/lib/python2.7/dist-packages"


# global Config exposes variable to module
__config = Config()
for attr in dir(__config):
    if not attr.startswith("__"):
        setattr(sys.modules[__name__], attr, getattr(__config, attr))
