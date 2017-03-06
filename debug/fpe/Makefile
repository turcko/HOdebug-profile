.PHONY: default help object executable all clean segfault dynamic static nobugs
CC = gcc 
CFLAGS = -Wall

LD = $(CC)

SOURCE_C = $(wildcard *.c)
OBJECTS_C = $(patsubst %.c, %_c.o, $(SOURCE_C))
EXECUTABLES = $(patsubst %.c, %.e, $(SOURCE_C))

default: all

help:
	@echo "\
Options:\n\n\
  make all:           make every executable (default)\n\
  make comparison:       dynamic arrays with no segfault (doesn't mean no errors!)\n\
  make division:      example with a segfault\n\
  make square_root:        static arrays, wrong result\n\
  make clean:         delete output files\n\
  make help:          display this help"

objects: $(OBJECTS_C)

executable: $(EXECUTABLES)

all: objects executable

comparison: comparison.e 

division: division.e 

square_root: square_root.e 

%_c.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

%.e: %_c.o
	$(LD) $^ -o $@

clean:
	rm -rfv $(OBJECTS_C) $(EXECUTABLES)
