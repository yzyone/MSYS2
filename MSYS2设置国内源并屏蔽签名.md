# MSYS2设置国内源并屏蔽签名 #

注意，如果安装过程中出现无法连接服务，请参看第 4条。

1. 设置官方镜像源（包括 core， extra， community， multilib ）

```
$ sudo pacman-mirrors -i -c China -m rank //更新镜像排名
$ sudo pacman -Syy //更新数据源
```

更新 archlinux 签名

```
pacman -S archlinux-keyring 
```

2.设置 archlinuxcn 源

修改 /etc/pacman.conf　　=> 末尾添加

```
[archlinuxcn]
SigLevel = Optional TrustedOnly
Server = https://mirrors.tuna.tsinghua.edu.cn/archlinuxcn/$arch
```

安装 PGP 签名

1>屏蔽签名

修改/etc/pacman.conf，将原有的SigLevel=××××××注释掉，添加`SigLevel = Never`即可。

2>重新签名（这步先跳过，直接执行第3步）

```
pacman -Syu haveged
systemctl start haveged
systemctl enable haveged
rm -rf /etc/pacman.d/gnupg
pacman-key --init
pacman-key --populate manjaro
pacman-key --populate archlinuxcn
```

3>安装 archlinuxcn源（或相应源）的签名

```
$ sudo pacman -Syy
$ sudo pacman -S archlinuxcn-keyring
```

4>运行 以下命令，更新数据源索引及源里的包（此时可还原之前的 SigLevel ）

```
$ sudo pacman -Syy
$ yaourt -Syua
```

3.设置 aur 源

修改 /etc/yaourtrc，去掉 # AURURL 的注释，修改为

```
AURURL="https://aur.tuna.tsinghua.edu.cn"
```

4.注意执行以上操作时，可能需要关闭系统的网络代理（如果之前设置过网络代理的话）。
