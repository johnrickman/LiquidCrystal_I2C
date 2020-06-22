AM_CXXFLAGS = 

ACLOCAL_AMFLAGS = -I m4 

lib_LTLIBRARIES = liblci2c.la

liblci2c_la_SOURCES = \
						 RPIImpl.cpp \
						 LiquidCrystal_I2C.cpp \
						 LCI2CImpl.cpp 

liblci2c_la_CXXFLAGS = $(AM_CXXFLAGS) 
liblci2c_la_LIBADD = 

#bin_PROGRAMS = tests
#
#tests_SOURCES = tests.cpp
#tests_CPPFLAGS = $(DBGFLAGS) $(AM_CPPFLAGS) $(CFLAGS_COMMON)
#tests_LDADD = -lhiredis -lswsscommon -lpthread $(top_srcdir)/meta/libsaimetadata.la $(top_srcdir)/meta/libsaimeta.la libsairedis.la
#
#TESTS = tests
