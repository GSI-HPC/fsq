noinst_LTLIBRARIES = libstubs.la

libstubs_la_SOURCES = \
	lustre/liblustreapi_stub.c \
	ltsm/libltsmapi_stub.c

libstubs_la_CFLAGS = \
	-D_LARGEFILE64_SOURCE \
	-I$(srcdir)/lustre/include \
	-I$(srcdir)/ltsm/include \
	-I$(srcdir)/tsm/include
