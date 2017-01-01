include ../CPPFLAGS.inc

all: lesson wireframe

lesson: src/lesson.cpp $(TGAIMAGE_DEPS) $(TINYRENDERER_DEPS)
	g++ $< $(TGAIMAGE_OBJECT) $(TINYRENDERER_OBJECT) $(CPPFLAGS) -o $@

wireframe: src/wireframe.cpp $(WAVEFRONT_DEPS) $(TGAIMAGE_DEPS) $(TINYRENDERER_DEPS)
	g++ $< $(TGAIMAGE_OBJECT) $(TINYRENDERER_OBJECT) $(WAVEFRONT_OBJECT) $(CPPFLAGS) -o $@

include ../LDFLAGS.inc
