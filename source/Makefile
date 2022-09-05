#!/usr/bin/make -f
# Makefile for simple-test.lv2 #
# ----------------------- #
# Created by falkTX
#
DEBUG=true

include Makefile.mk

# --------------------------------------------------------------

PREFIX  ?= /usr/local
DESTDIR ?=
CDEPS = 
CPPDEPS = TestClass.h LV2Plugin.h
OBJS = simple.o TestClass.o

# --------------------------------------------------------------
# Default target is to build all plugins

all: build
build: simple-test 

# --------------------------------------------------------------
# simple-test build rules
%.o: %.c $(CDEPS)
	$(CC) -c -o $@ $< $(BUILD_C_FLAGS)

%.o: %.cpp $(CPPDEPS)
	$(CXX) -Iincludes -c -o $@ $< $(BUILD_CXX_FLAGS) 

simple-test: simple-test.lv2/simple$(LIB_EXT) simple-test.lv2/manifest.ttl

simple-test.lv2/simple$(LIB_EXT): $(OBJS)
	$(CXX) $^ $(LINK_FLAGS) -lm $(SHARED) -o $@

simple-test.lv2/manifest.ttl: simple-test.lv2/manifest.ttl.in
	sed -e "s|@LIB_EXT@|$(LIB_EXT)|" $< > $@

# --------------------------------------------------------------

clean:
	rm -f simple-test.lv2/simple$(LIB_EXT) simple-test.lv2/manifest.ttl *.o 

# --------------------------------------------------------------

install: build
	install -d $(DESTDIR)$(PREFIX)/lib/lv2/simple-test.lv2

	install -m 644 simple-test.lv2/*.so  $(DESTDIR)$(PREFIX)/lib/lv2/simple-test.lv2/
	install -m 644 simple-test.lv2/*.ttl $(DESTDIR)$(PREFIX)/lib/lv2/simple-test.lv2/

# --------------------------------------------------------------
