CXX = gcc
CXXFLAGS = -O2 -I.

SHELL = /bin/sh
LIBS = -L. -lLCStr

APPNAME = main

SRCFILES := $(wildcard *.c)
SRCFILES := $(filter-out LCString.c, $(SRCFILES))
OBJFILES := $(addprefix obj/, $(patsubst %.c, %.o, $(SRCFILES)))

LIBOBJFILES := $(filter-out main.o, $(OBJFILES))

obj/%.o: %.c
	$(CXX) $(CXXFLAGS) -c -o $@ $^

all: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $< -o $(APPNAME) $(LIBS)

lib:
	$(CXX) $(CXXFLAGS) -c -o obj/LCString.o LCString.c
	ar rcs LCStr.lib obj/LCString.o

both: lib all

clean:
	rm obj/*.o
