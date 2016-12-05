include ../CPPFLAGS.inc

obj/wavefront.o: src/wavefront.cpp include/wavefront/wavefront.hpp
	mkdir -p $(@D)
	g++ -c $< $(CPPFLAGS) -o $@

include ../LDFLAGS.inc