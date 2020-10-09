#LINK    = @echo linking $@ && g++
#GCC     = @echo compiling $@ && g++
#GC      = @echo compiling $@ && gcc
LINK    = g++
GCC     = g++
GC      = gcc
AR      = @echo generating static library $@ && ar crv
FLAGS   = -g -DDEBUG -W -Wall -fPIC
GCCFLAGS =
DEFINES =
HEADER  = -I./
LIBS    =
LINKFLAGS =

HEADER += -I./fun

#LIBS    += -lrt
#LIBS    += -pthread
#这里表示链接的时候从bin目录下找libfun.so
LIBS    += -L../bin -lfun

OBJECT := main.o \

#这里加了bin的相对路径,编完的main会install到bin目录下
BIN_PATH = ../bin/

TARGET = main

$(TARGET) : $(OBJECT)
	$(LINK) $(FLAGS) $(LINKFLAGS) $(LIBS) -o $@ $^

.cpp.o:
	$(GCC) -c $(HEADER) $(FLAGS) $(GCCFLAGS) -fpermissive -o $@ $<

.c.o:
	$(GC) -c $(HEADER) $(FLAGS) -fpermissive -o $@ $<

install: $(TARGET)
	cp $(TARGET) $(BIN_PATH)

clean:
	rm -rf $(TARGET) *.o *.so