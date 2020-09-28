
### MSYS2 在 windows 上的开发环境 ###

参考了这个英文网站： 

[MSYS2 development environment for Windows](http://www.davidegrayson.com/windev/msys2/)


最近刚接触 msys2 遇到两类开发环境：

（一） MSYS2 自带的开发环境，安装的包叫 msys2-devel

在 MSYS2 shell 下，可以通过 pacman 命令查询和安装

1）查询，可以看到包含 gcc

	$ pacman -S msys2-devel
	:: 共有 6 组员在组 msys2-devel 中：
	:: 软件库 msys
	   1) binutils  2) cocom  3) gcc  4) gcc-fortran  5) msys2-w32api-headers
	   6) msys2-w32api-runtime

2）安装

	pacman -S msys2-devel

（二）MinGW-w64 的

安装

	$ pacman -S mingw-w64-x86_64-toolchain
	:: 共有 17 组员在组 mingw-w64-x86_64-toolchain 中：
	:: 软件库 mingw64
	   1) mingw-w64-x86_64-binutils
	   2) mingw-w64-x86_64-crt-git
	   3) mingw-w64-x86_64-gcc
	   4) mingw-w64-x86_64-gcc-ada
	   5) mingw-w64-x86_64-gcc-fortran
	   6) mingw-w64-x86_64-gcc-libgfortran
	   7) mingw-w64-x86_64-gcc-libs
	   8) mingw-w64-x86_64-gcc-objc
	   9) mingw-w64-x86_64-gdb
	   10) mingw-w64-x86_64-headers-git
	   11) mingw-w64-x86_64-libmangle-git
	   12) mingw-w64-x86_64-libwinpthread-git
	   13) mingw-w64-x86_64-make
	   14) mingw-w64-x86_64-pkg-config
	   15) mingw-w64-x86_64-tools-git
	   16) mingw-w64-x86_64-winpthreads-git
	   17) mingw-w64-x86_64-winstorecompat-git

可以看到，也有gcc.

运行不同的 shell，则执行对应版本的 gcc.

这里描述如下

	--MSYS2 64bit
	    --MSYS2 MinGW 32-bit
	    --MSYS2 MinGW 64-bit
	    --MSYS2 MSYS

那么，这两者有什么区别呢？

一言以蔽之，前者编译出来的可执行文件，要依赖 MSYS2 提供的动态链接库，而后者不需要。下面详细说明一下：

（一） MSYS2 下的 gcc 编译环境，编译的可执行文件要依赖于 msys-2.0.dll，这个 DLL 提供了 Linux 下编程的提供的函数和接口，例如 fork 函数。

这个编译环境对于编译基于 Linux 下编写的软件，是非常适合的。例如编译 GNU 提供的各种工具。例如，你想编译最新版本的 GNU grep 工具，MSYS2 下的这个环境是非常适合的。

这个环境非常类似于 cygwin.

一个简单的 hello world 程序：


	#include <stdio.h>
	void main()
	{
	        printf("Hello world !\n");
	}


编译出来的 a.exe， 用 dumpbin （这个是visual studio 提供的工具，当然，你也可以安装 Dependency Walker 这个独立小巧的工具来看）来查看 DLL 依赖关系：

	d:\hello_world> dumpbin /dependents a.exe

看到：

	Microsoft (R) COFF/PE Dumper Version 9.00.21022.08
	Copyright (C) Microsoft Corporation.  All rights reserved.

	Dump of file a.exe

	File Type: EXECUTABLE IMAGE

	  Image has the following dependencies:

	    msys-2.0.dll
	    KERNEL32.dll

其中依赖了 msys-2.0.dll. （KERNEL32.dll 是 windows 提供的）。

在 windows 的 cmd 下直接运行，如果没有把 msys-2.0.dll 的路径告知的话，则会运行不成功。

（二）用 MinGW64 的编译环境，得到 a_mingw.exe

	d:\hello_world>dumpbin /dependents a_mingw.exe

看到

	Microsoft (R) COFF/PE Dumper Version 9.00.21022.08
	Copyright (C) Microsoft Corporation.  All rights reserved.


	Dump of file a_mingw.exe

	File Type: EXECUTABLE IMAGE

	  Image has the following dependencies:

	    KERNEL32.dll
	    msvcrt.dll

不再依赖于 msys-2.0.dll，上面两个 dll 都是 windows 提供的。

所以，如果源代码就是基于 windows 开发的，那使用 MinGW 的编译环境比较好，编译出来的可执行文件，不用再依赖 MSYS 提供的动态链接库。当然，前提是代码中不能使用 Linux 的东西，即 POSIX 的那套东西。

备注：

msvcrt.dll 提供的接口，可以参考 [C Run-Time Library Reference](https://msdn.microsoft.com/en-us/library/59ey50w6%28v=vs.140%29.aspx)


