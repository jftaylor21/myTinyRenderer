include ../CPPFLAGS.inc

all: lesson1 wireframe

lesson1: src/lesson1.cpp $(TGAIMAGE_DEPS) $(TINYRENDERER_DEPS) src/TGAColors.hpp
	g++ $< $(TGAIMAGE_OBJECT) $(TINYRENDERER_OBJECT) $(CPPFLAGS) -o $@

wireframe: src/wireframe.cpp $(WAVEFRONT_DEPS) $(TGAIMAGE_DEPS) $(TINYRENDERER_DEPS) src/TGAColors.hpp
	g++ $< $(TGAIMAGE_OBJECT) $(TINYRENDERER_OBJECT) $(WAVEFRONT_OBJECT) $(CPPFLAGS) -o $@

include ../LDFLAGS.inc
