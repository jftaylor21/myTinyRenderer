include ../CPPFLAGS.inc

obj/tgaimage.o: src/tgaimage.cpp include/tgaimage/tgaimage.h
	mkdir -p $(@D)
	g++ -c $< $(CPPFLAGS) -o $@