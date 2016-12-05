TGAIMAGE_PATH = ../tgaimage
TGAIMAGE_INCLUDEPATH = $(TGAIMAGE_PATH)/include
TGAIMAGE_DEPS = $(TGAIMAGE_PATH)/include/tgaimage/tgaimage.h $(TGAIMAGE_PATH)/Makefile

obj/line.o: src/line.cpp $(TGAIMAGE_DEPS) include/tinyrenderer/line.hpp
	mkdir -p $(@D)
	g++ -c $< -I $(TGAIMAGE_INCLUDEPATH) -I include -pg -g -o $@
	