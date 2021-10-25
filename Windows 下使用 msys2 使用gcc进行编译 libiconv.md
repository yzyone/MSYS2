# windows 下使用 msys2 使用gcc进行编译 libiconv #

cygwin、MinGW64、MSYS 的区别

cygwin 没有一个好用的包管理工具，无论是官方的 setup.exe，还是第三方的 apt-cyg，像依赖什么的都得额外按照，而且不支持升级操作。另外 cygwin 里面很多软件还是比较老的。

MinGW64（Minimalist GNU for Windows）用于在 Windows 上编译基于GCC的应用程序。他主要提供了针对 win32 应用的 GCC、GNU binutils 等工具，以及对等于 Windows SDK（的子集）的头文件和用于 MinGW 版本的 linker 的库文件（so【动态链接库】、a【静态链接库】 等，而不是 VC 的lib）。MinGW 是用于进行 Windows 应用开发的 GNU 工具链（开发环境），它的编译产物一般是原生 Windows 应用。（mingw 的命令行工具的命令都是基于 windows 的！！！）

MSYS 是用于辅助 Windows 版 MinGW 进行命令行开发的配套软件包，提供了部分 Unix 工具以使得 MinGW 的工具使用起来方便一些（MinGW需要在MSYS内部通过 pacman 安装）

**下载 msys2**

    http://www.msys2.org/

msys2使用pacman作为包管理器。同时，pacman也是ArchLinux上的包管理器。
所以我们使用 pacman 命令安装编译工具链
-S 表示保存，-Q 表示查询

	pacman -S gcc  
	pacman -S mingw-w64-x86_64-toolchain
	pacman -S mingw-w64-i686-toolchain
	pacman -S base-devel
	pacman -S vim
	pacman -S yasm
	pacman -S nasm

**下载 libiconv**

http://www.gnu.org/software/libiconv/

**编译 libiconv**

	./configure --prefix=/usr/local
	make
	make install

也可以连写

	./configure && make && make install

编译结果会放在 configure 指定的路径。如果默认不写–prefix路径的话，会自动安装到/usr/local下面。

默认会在 /usr/local/bin 下生成 libiconv.exe 并在 /usr/local/lib 目录下生成 .a 的静态链接库。

通过 `ls -l` 命令可以查看文件的具体信息。

通过 `./configure -h` 可以查看配置的帮助文档

这里编译 libiconv 只是做一个编译的试验，msys2 已经自带了 libiconv， 通过 whereis 命令可以查看到该位置

从时间上可以看出 libiconv 老早就被加到 msys2 里面了

————————————————

版权声明：本文为CSDN博主「福州-司马懿」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。

原文链接：https://blog.csdn.net/chy555chy/article/details/89189455