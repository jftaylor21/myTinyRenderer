include ../CPPFLAGS.inc

all: obj/line.o obj/triangle.o

obj/line.o: src/line.cpp $(TGAIMAGE_DEPS) include/tinyrenderer/line.hpp
	mkdir -p $(@D)
	g++ -c $< $(CPPFLAGS) -o $@
	
obj/triangle.o: src/triangle.cpp $(TGAIMAGE_DEPS) include/tinyrenderer/triangle.hpp
	mkdir -p $(@D)
	g++ -c $< $(CPPFLAGS) -o $@
	