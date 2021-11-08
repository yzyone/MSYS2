
# 在MSYS2上配置SDL2 #

## 安装GCC ##

MSYS2中有两种工具链：一种是原生GCC，其编译的是UNIX代码，运行依赖msys2xxx.dll；另一种是mingw工具链，用于编译windows代码（能调用windows API，不能调用unix系统调用）的，生成exe，运行时只依赖windows系统的dll。

因此，我们这里应该安装mingw工具链。

输入命令：

    pacman -Ss gcc

找到里面有一个长得像这样的gcc：

```
mingw64/mingw-w64-x86_64-gcc 9.2.0-2 (mingw-w64-x86_64-toolchain)
    GNU Compiler Collection (C,C++,OpenMP) for MinGW-w64
```

然后安装：

	pacman -S mingw-w64-x86_64-gcc

**设置环境变量**

我的MSYS2安装目录为C:\ProgramFiles\msys64，这里的路径根据自己实际安装路径修改：

右键此电脑->高级系统设置->高级->环境变量(N)...。

选中Path那一行，点击编辑(I)...，在最后一行加入MSYS2中mingw64的bin文件夹路径，例如我的是C:\ProgramFiles\msys64\mingw64\bin。

在系统变量(S)对应的区域点击新建(W)...，变量名填C_INCLUDEDE_PATH，值填MSYS2中mingw64的include文件夹，例如我的是C:\ProgramFiles\msys64\mingw64\include。

在系统变量(S)对应的区域点击新建(W)...，变量名填CPLUS_INCLUDE_PATH，值填MSYS2中mingw64的include文件夹以及里面c++文件夹中gcc版本号的文件夹，例如我的是C:\ProgramFiles\msys64\mingw64\include;C:\ProgramFiles\msys64\mingw64\include\c++\9.2.0。

在系统变量(S)对应的区域点击新建(W)...，变量名填LIBRARY_PATH，值填MSYS2中mingw64的lib文件夹，例如我的是C:\ProgramFiles\msys64\mingw64\lib。

## 安装 SDL ##

输入命令：

    pacman -Ss sdl2

其中有一个长得像这样的：

```
mingw64/mingw-w64-x86_64-SDL2 2.0.10-1
    A library for portable low-level access to a video framebuffer, audio
    output, mouse, and keyboard (Version 2) (mingw-w64)
```

安装：

	pacman -S mingw-w64-x86_64-SDL2

发现还有一些其它模块，可以按需安装：

```
mingw64/mingw-w64-x86_64-SDL2_gfx 1.0.4-1
    SDL graphics drawing primitives and other support functions (Version 2)
    (mingw-w64)
mingw64/mingw-w64-x86_64-SDL2_image 2.0.5-1
    A simple library to load images of various formats as SDL surfaces (Version
    2) (mingw-w64)
mingw64/mingw-w64-x86_64-SDL2_mixer 2.0.4-1
    A simple multi-channel audio mixer (Version 2) (mingw-w64)
mingw64/mingw-w64-x86_64-SDL2_net 2.0.1-1
    A small sample cross-platform networking library (Version 2) (mingw-w64)
mingw64/mingw-w64-x86_64-SDL2_ttf 2.0.15-1
    A library that allows you to use TrueType fonts in your SDL applications
    (Version 2) (mingw-w64)
mingw64/mingw-w64-x86_64-smpeg2 2.0.0-5
    SDL2 MPEG Player Library (mingw-w64)
```

## 测试 ##

将以下代码存为a.cpp：

```
#include<SDL.h>

SDL_Window *g_pWindow = nullptr;
SDL_Renderer *g_pRenderer = nullptr;

int main(int argc, char *args[]){
    // initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){
        // if succeeded create our window
        g_pWindow = SDL_CreateWindow("Chapter 1: Setting up SDL",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        640, 480,
        SDL_WINDOW_SHOWN);

        // if the window creation succeeded create our renderer
        if(g_pWindow != nullptr){
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
        }
    }else{
        return 1;   // SDL could not initialize
    }

    // everything succeeded lets draw the window

    // set to black // This function expects Red, Green, Blue and Alpha as color values
    SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 0, 255);

    // clear the window to black
    SDL_RenderClear(g_pRenderer);

    // show the window
    SDL_RenderPresent(g_pRenderer);

    // set a delay before quitting
    SDL_Delay(5000);

    // clean up SDL
    SDL_Quit();

    return 0;
}
```


编译用以下命令，这里我的SDL库的位置在C:\ProgramFiles\msys64\mingw64\include\SDL2:，这里用的是反斜杠而不是斜杠：

	g++ a.cpp -o a.exe -lmingw32 -mwindows -lSDL2main -lSDL2 -I/C/ProgramFiles/msys64/mingw64/include/SDL2

之后运行：

	./a.exe

屏幕上应该会出现一个红色的方框，持续5秒后自动关闭。

参考资料：

[关于MSYS2的一点经验](http://bbs.chinaunix.net/forum.php?mod=viewthread&tid=4256341)

[msys2和SDL2环境搭建](https://dongqiceo.github.io/the-post-9982/)

————————————————

版权声明：本文为CSDN博主「摇光65535」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。

原文链接：https://blog.csdn.net/willian113/article/details/106538384/