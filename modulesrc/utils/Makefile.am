# -*- Makefile -*-
#
# ----------------------------------------------------------------------
#
#                           Brad T. Aagaard
#                        U.S. Geological Survey
#
# <LicenseText>
#
# ----------------------------------------------------------------------
#

subpackage = utils
include $(top_srcdir)/subpackage.am

subpkgpyexec_LTLIBRARIES = \
	simplearraymodule.la \
	utilsmodule.la

INCLUDES += -I$(PYTHON_INCDIR)

# simple array
simplearraymodule_la_LDFLAGS = -module
simplearraymodule_la_SOURCES = simplearray.pyxe
nodist_simplearraymodule_la_SOURCES = \
	simplearray.c simplearray_embed.cpp simplearray_embed.h

# utils
utilsmodule_la_LDFLAGS = -module
utilsmodule_la_SOURCES = utils.pyxe
nodist_utilsmodule_la_SOURCES = \
	utils.c utils_embed.cpp utils_embed.h
utilsmodule_la_LIBADD = \
	$(top_builddir)/libsrc/utils/libspatialdatautils.la

# simple array targets
simplearray.pyx simplearray_embed.cpp  simplearray_embed.h: simplearray.pyxe
	cp $< . && pyrexembed.py simplearray.pyxe && rm -f simplearray.pyxe
simplearray_embed.cpp: simplearray_embed.h
simplearray_embed.h: simplearray.pyx

# utils targets
utils.pyx utils_embed.cpp  utils_embed.h: utils.pyxe
	cp $< . && pyrexembed.py utils.pyxe && rm -f utils.pyxe
utils_embed.cpp: utils_embed.h
utils_embed.h: utils.pyx

.pyx.c:
	pyrexc $<

CLEANFILES = utils.pyx utils.c *_embed.*

# End of file 