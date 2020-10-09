#LINK    = @echo linking $@ && g++ 
#GCC     = @echo g++ compiling $@ && g++ 
#GC      = @echo gcc compiling $@ && gcc 
LINK    = g++
GCC     = g++
GC      = gcc
FLAGS   = -g -DDEBUG -W -Wall -fPIC
GCCFLAGS = 
DEFINES = 
HEADER  = -I./
LIBS    = 

ifeq ($(OS),Windows_NT)
	uname_S := Windows
else
	uname_S := $(shell uname -s)
endif

#修改的地方1: 这里加了-shared，表示生成动态库
LINKFLAGS = -shared

#HEADER += -I./

#LIBS    += -lrt
#LIBS    += -pthread

#修改的地方2: 表示编译fun.cpp
OBJECT := fun.o \

#修改的地方3: 指出了bin的相对路径
BIN_PATH = ../../bin/

#修改的地方3，生成的文件名叫libfun.so，动态库一般以lib为前缀
ifeq ($(uname_S), Windows)
	TARGET = libfun.dll
endif

ifeq ($(uname_S), Linux)
	TARGET = libfun.so
endif

$(TARGET) : $(OBJECT) 
	$(LINK) $(FLAGS) $(LINKFLAGS) -o $@ $^ $(LIBS)

.cpp.o:
	$(GCC) -c $(HEADER) $(FLAGS) $(GCCFLAGS) -fpermissive -o $@ $<

.c.o:
	$(GC) -c $(HEADER) $(FLAGS) -fpermissive -o $@ $<

install: $(TARGET)
	cp $(TARGET) $(BIN_PATH)

clean:
	rm -rf $(TARGET) *.o *.so *.dll