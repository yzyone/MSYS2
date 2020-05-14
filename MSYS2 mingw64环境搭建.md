MSYS2 mingw64环境搭建

---

pacman 镜像

## MSYS2 repository mirrorlist

    Server = http://mirrors.ustc.edu.cn/msys2/REPOS/MSYS2/$arch
    
    Server = http://mirror.bit.edu.cn/msys2/REPOS/MSYS2/$arch
    
    Server = http://www.mirrorservice.org/sites/download.sourceforge.net/pub/sourceforge/m/ms/msys2/REPOS/MSYS2/$arch
    
    Server = http://downloads.sourceforge.net/project/msys2/REPOS/MSYS2/$arch


## 32-bit Mingw-w64 repository mirrorlist

    Server = http://mirrors.ustc.edu.cn/msys2/REPOS/MINGW/i686
    
    Server = http://mirror.bit.edu.cn/msys2/REPOS/MINGW/i686
    
    Server = http://www.mirrorservice.org/sites/download.sourceforge.net/pub/sourceforge/m/ms/msys2/REPOS/MINGW/i686
    
    Server = http://downloads.sourceforge.net/project/msys2/REPOS/MINGW/i686


## 64-bit Mingw-w64 repository mirrorlist

    Server = http://mirrors.ustc.edu.cn/msys2/REPOS/MINGW/x86_64
    
    Server = http://mirror.bit.edu.cn/msys2/REPOS/MINGW/x86_64
    
    Server = http://www.mirrorservice.org/sites/download.sourceforge.net/pub/sourceforge/m/ms/msys2/REPOS/MINGW/x86_64
    
    Server = http://downloads.sourceforge.net/project/msys2/REPOS/MINGW/x86_64


 

1、下载MSYS2后安装

2、运行安装目录下的msys2_shell.bat初始化，首次更新数据库，

    pacman --needed -Sy bash pacman pacman-mirrors msys2-runtime

然后退出bat

3、启动msys2.exe,输入

    pacman -Syu

4、安装自己需要的软件

    pacman -S  base-devel  git  mercurial  cvs  wget  p7zip  perl  ruby  python2

 5、安装mingw64

    pacman -S  mingw-w64-x86_64-toolchain