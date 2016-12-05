include ../CPPFLAGS.inc

all: lesson

lesson: src/lesson.cpp $(TGAIMAGE_DEPS) $(TINYRENDERER_DEPS)
	g++ $< $(TGAIMAGE_OBJECT) $(TINYRENDERER_OBJECT) $(CPPFLAGS) -o $@

include ../LDFLAGS.inc
