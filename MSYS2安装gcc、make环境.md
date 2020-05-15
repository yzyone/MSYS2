MSYS2安装gcc、make环境

---

下载msys2

    http://www.msys2.org/

修改pacman源

使用过archlinux的应该会知道，pacman在安装的时候，如果源没有设置好，下载是很慢的。

需要修改的文件是：

    \etc\pacman.d\mirrorlist.mingw32
    \etc\pacman.d\mirrorlist.mingw64
    \etc\pacman.d\mirrorlist.msys

这三个文件

镜像源我推荐使用下面的这两个：

    清华大学 https://mirrors.tuna.tsinghua.edu.cn/
    中国科学技术大学 http://mirrors.ustc.edu.cn/

1.pacman基本命令

    pacman -Sy 更新软件包数据 
    pacman -Syu 更新所有 
    pacman -Ss xx 查询软件xx的信息 
    pacman -S xx 安装软件xx
    pacman -R xx 删除软件xx

2.安装gcc、g++编译器

    #查询并找到msys/gcc
    pacman -Ss gcc
    #安装
    pacman -S msys/gcc

3.安装make编译器

    #查询并找到msys/make
    pacman -Ss make
    #安装
    pacman -S msys/make

4.安装Clion编译工具链

    pacman-key --init
    pacman -Syu
    pacman -S mingw-w64-x86_64-cmake mingw-w64-x86_64-extra-cmake-modules
    pacman -S mingw-w64-x86_64-make
    pacman -S mingw-w64-x86_64-gdb
    pacman -S mingw-w64-x86_64-toolchain

pacman 的配置

编辑 /etc/pacman.d/mirrorlist.mingw32 ，在文件开头添加：

    Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/i686

编辑 /etc/pacman.d/mirrorlist.mingw64 ，在文件开头添加：

    Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/x86_64

编辑 /etc/pacman.d/mirrorlist.msys ，在文件开头添加：

    Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/msys/$arch

然后执行 

    pacman -Sy 

刷新软件包数据即可。

参考：

    https://blog.csdn.net/Lazybones_3/article/details/88633738
    https://mirrors.tuna.tsinghua.edu.cn/help/msys2/

---

作者：LatitudeMaster

链接：https://www.jianshu.com/p/04636461341e

来源：简书

著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。