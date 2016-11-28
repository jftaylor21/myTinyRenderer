TGAIMAGE_PATH = ../tgaimage
TGAIMAGE_INCLUDEPATH = $(TGAIMAGE_PATH)/include
TGAIMAGE_OBJECT = $(TGAIMAGE_PATH)/obj/tgaimage.o
TGAIMAGE_DEPS = $(TGAIMAGE_OBJECT) $(TGAIMAGE_PATH)/include/tgaimage/tgaimage.h $(TGAIMAGE_PATH)/Makefile

lesson1: src/lesson1.cpp $(TGAIMAGE_DEPS) src/TGAColors.hpp
	g++ $< $(TGAIMAGE_OBJECT) -I $(TGAIMAGE_INCLUDEPATH) -pg -o $@

$(TGAIMAGE_OBJECT):
	cd $(TGAIMAGE_PATH) && $(MAKE)