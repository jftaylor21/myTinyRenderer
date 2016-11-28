TGAIMAGE_PATH = ../tgaimage
TGAIMAGE_INCLUDEPATH = $(TGAIMAGE_PATH)/include
TGAIMAGE_OBJECT = $(TGAIMAGE_PATH)/obj/tgaimage.o
TGAIMAGE_DEPS = $(TGAIMAGE_OBJECT) $(TGAIMAGE_PATH)/include/tgaimage/tgaimage.h $(TGAIMAGE_PATH)/Makefile

lesson0: src/lesson0.cpp $(TGAIMAGE_DEPS)
	g++ $< $(TGAIMAGE_OBJECT) -I $(TGAIMAGE_INCLUDEPATH) -o $@

$(TGAIMAGE_OBJECT):
	cd $(TGAIMAGE_PATH) && $(MAKE)