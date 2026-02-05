## echo
```shell
# 使用echo 123123 输出屏幕上
echo 123123 
# 使用echo 将 aaaaaa 以文件末尾追加形式输出1.txt上
echo aaaaaa >> 1.txt

# 使用echo 将 aaaaaa 以覆盖的形式输出1.txt上
echo aaaaaa > 1.txt
```


## 管道
- 概念：在shell命令中，可以使用一种特殊的符号来连接两个不同的命令，使得前面命令的输出，变成后面命令的输入或参数，这种特殊的符号叫做管道。
- 用法：
- 将前面命令的输出，成为后面命令的输入：cmd1 | cmd2
- 将前面命令的输出，成为后面命令的参数：cmd1 | xargs cmd2
- 举例：
1. 将当前目录下的文件，按反序列出：
```shell
gec@ubuntu:~$ ls | sort -r
```
2. 将当前文件下的文件，逐个删除掉：
```shell
gec@ubuntu:~$ ls | xargs rm
```

注意: `>` 和 `>>`也属于管道表示数据输出到指定文件

## 软连接

**注意**: 软连接文件直接拿到windows中会失效

硬链接
```shell
ln      target   link_name
```
软链接(符号链接)
```shell
ln  -s  target   link_name
```
## cp
- 释义：copy，复制文件或者复制整个目录
- 常见用法：
```shell
gec@ubuntu:~$ cp file1 file2    ==> 将文件file1复制为file2
gec@ubuntu:~$ cp dir1/ dir2/ -r ==> 将目录dir1/复制为dir2/
```

**注意**：
1. 如果file2或者dir2已存在，那么它们将会被覆盖
2. 目录名称 dir1/ 和 dir2/ 末尾的"/"是可选的，可写可不写，写上去只是为了强调 dir1 和 dir2 是目录，别无他意


## touch
- 释义：
1. 在文件存在的情况下：将文件最近修改时间更新为当前时间
2. 在文件不存在的情况下：创建一个空文件
- 常见用法：
```shell
#假设文件a.txt已存在
gec@ubuntu:~$ touch a.txt ==> 更新a.txt的最近修改时间到当前时间
```

## mkdir

创建空目录
```shell
gec@ubuntu:~$ mkdir a      ==> 创建空目录a
```

## rm
- 释义：删除文件或目录
```shell
gec@ubuntu:~$ rm file
gec@ubuntu:~$ rm -r dir/
```

## find
- 释义：在指定目录中，按指定条件寻找文件

```shell
gec@ubuntu:~$ find /usr -name "*.h" ==> 在/usr中查找以.h结尾的文件
gec@ubuntu:~$ find /tmp -type d     ==> 在/tmp中查找类型为套接字的文件
```

## grep

在指定文件或目录中，按指定条件寻找字符串

```shell
gec@ubuntu:~$ grep 'apple' /usr -rn ==> 在/usr中查找包含apple的文件
```

## mv
- 释义：move，移动文件，或给文件重命名
```shell
# 将文件 aaa.c移动到当前目录外部
mv aaa.c ../
# 将文件 aaa.c移动到linux/目录并重名名为qqq.c
mv aaa.c ./linux/qqq.c
# 将文件 qqq.c重名名为aaa.c
mv qqq.c aaa.c
```
## chmod
- 释义：修改文件权限
- 常见用法：
```shell
# 将文件权限改为644  rw-r--r--
gec@ubuntu:~$ chmod 644 file 
# 将目录权限改为755  rwxr-xr-x
gec@ubuntu:~$ chmod 755 dir/ 
```
在Linux中，文件的权限一般用rwx来表示：
- r 代表read，可读
- w 代表write，可写
- x 代表excute，可执行

## ifconfig

释义：查看/设置系统IP地址

```shell
# 查看当前活跃的网络接口
gec@ubuntu:~$ ifconfig

# 设置指定的网络接口的IP地址
gec@ubuntu:~$ ifconfig ens33 192.168.1.100
```
注意: 使用ifconfig设置的IP是临时的

## ifup / ifdown

- 释义：启停指定网络接口卡
- 常见用法：
```shell
# 禁用网络接口卡ens33
gec@ubuntu:~$ sudo ifdown ens33  
# 启用网络接口卡ens33
gec@ubuntu:~$ sudo ifup ens33    
```
## ping
- 释义：向指定主机发送要求回应的ICMP数据包
```shell
gec@ubuntu:~$ ping 192.168.1.200 
gec@ubuntu:~$ ping www.qq.com
```

## 软件包管理工具

功能需求 | 现代化apt命令（推荐） | 传统apt-get/apt-cache命令
---|---|---
更新软件源索引（必做） | apt update | apt-get update（二者完全一致）
升级所有已装软件 | apt upgrade | apt-get upgrade
智能升级（处理依赖 / 新增包） | 	apt full-upgrade | apt-get dist-upgrade
安装软件包 | apt install 包名 | apt-get install 包名
卸载软件（保留配置） | apt remove 包名 | apt-get remove 包名
彻底卸载（删除配置 + 文件） | apt purge 包名 | apt-get purge 包名
查看软件包详情 | apt show 包名 | apt-cache show 包名
清理下载的安装包缓存 | apt clean | apt-get clean

注意：apt update和apt-get update完全无区别，都是更新软件源的索引文件，安装 / 升级软件前必须先执行，否则系统不知道最新的软件版本和下载地址。

## 环境变量

env: 查看当前系统环境变量


### 临时修改
修改PATH环境变量
效果：把一个可执行程序（hyc） 添加到环境变量中，让可执行程序在系统的任何目录下都能够直接运行
```shell
export PATH=$PATH:/mnt/hgfs/GZ2418/03-C/13/1-code
```

修改C_INCLUDE_PATH环境变量
效果：把一个目录添加到环境变量中，让程序在编译时省去指定头文件路径参数 `-I /mnt/hgfs/share/code/C/day12/project/inc`
```shell
export C_INCLUDE_PATH=/mnt/hgfs/share/code/C/day12/project/inc:$C_INCLUDE_PATH
```

### 永久修改

理解：系统每次启动时，都会执行启动脚本。所以把修改环境变量的语句加入启动脚本中，每次系统启动都会执行。

1. 终端的启动脚本位置
```shell
cd  ~
ls -a  
# 终端启动时，就会默认执行这个文件
.bashrc  
```


2. 编辑.bashrc 脚本文件，把命令写入该文件末尾
```shell
export PATH=$PATH:/home/gec/dir33 
```

3. 这时候，只是修改文件，但是脚本还没有运行,需要运行脚本：
    1. 使用命令运行脚本：  `source .bashrc`
    2. 重启终端terminal

## 文件压缩

Linux下最常用的压缩包格式: `gz`、`bz2`、`xz`、`zip`。

其中： `gz`、`bz2`、`xz` 都可以linux自带 **tar** 工具进行压缩。

解释tar指令的参数： 
- c : 创建压缩/归档文件
- x : 解压缩/解归档文件
- t	: 查看压缩包内容	
- v : 可视化(可选)
- f : 压缩时指定压缩的文件

- z : 使用gz(gzip)算法压缩
- j : 使用bz2(bzip2)算法压缩
- J : 使用xz算法压缩

注意: 压缩时不指定压缩算法,就执行归档操作

例子
```shell
# 将 a.c b.c c.c 归档为 demo.tar 文件(不压缩)
tar -cf demo.tar a.c b.c c.c 
# 将 a.c b.c c.c 归档为 demo.tar 文件(不压缩)并可视化进度
tar -cvf demo.tar a.c b.c c.c 

# 解归档
tar -xf demo.tar 
tar -xvf demo.tar 

# 将 a.c b.c c.c 使用gz算法压缩为 demo.tar.gz 文件
tar -czf demo.tar.gz a.c b.c c.c 
# 将 a.c b.c c.c 使用gz算法压缩为 demo.tar.gz 文件并可视化进度
tar -cvzf demo.tar.gz a.c b.c c.c 

# 解压gz
tar -xzf demo.tar.gz
tar -xvzf demo.tar.gz

# 将 a.c b.c c.c 使用bz2算法压缩为 demo.tar.bz2 文件
tar -cjf demo.tar.bz2 a.c b.c c.c 
# 将 a.c b.c c.c 使用bz2算法压缩为 demo.tar.bz2 文件并可视化进度
tar -cvjf demo.tar.bz2 a.c b.c c.c 

# 解压bz2
tar -xjf demo.tar.bz2
tar -xvjf demo.tar.bz2

# 将 a.c b.c c.c 使用bz2算法压缩为 demo.tar.xz 文件
tar -cJf demo.tar.xz a.c b.c c.c 
# 将 a.c b.c c.c 使用bz2算法压缩为 demo.tar.xz 文件并可视化进度
tar -cvJf demo.tar.xz a.c b.c c.c 

# 解压bz2
tar -xJf demo.tar.xz
tar -xvJf demo.tar.xz

# 查看指定压缩或回档文件内部内容
tar -tf demo.tar.xz 
```

### zip 压缩
zip不是系统自带的命令，一般需要自己手工安装：
```shell
gec@ubuntu:~$ sudo apt install zip

# 将指定的文件和目录压缩成a.zip
gec@ubuntu:~$ zip a.zip file dir/ 
# 解压zip
gec@ubuntu:~$ unzip a.zip          
```

## df 

核心作用是统计文件 / 目录的磁盘实际占用空间
```shell
# 统计当前目录总大小（人性化显示）
du -sh

# 统计指定目录总大小（如/var/log/，日志目录排查必备）
du -sh /var/log/

# 统计指定文件大小（如大日志文件）
du -sh test.log
```
## fdisk
- 释义：查看/设置硬盘分区
- 常见用法：
```shell
# 查看当前系统已识别的分区。
gec@ubuntu:~$ sudo fdisk -l 
```

提醒：df只能查看已经识别且挂载了的分区，而fdisk可以查看未挂载的分区实际上，在系统识别出了分区之后，一般需要使用fdisk来查看分区的名称，然后才能使用mount来挂载，然后才能使用df查看到。

# mount/umount

mount 是 Linux 核心的挂载命令，用于将磁盘 / 分区 / 镜像 / 网络存储等设备的文件系统挂载到系统的挂载点（空目录），让系统能访问设备内容；umount 是对应的卸载命令，用于解除设备与挂载点的关联，二者是操作 Linux 存储的基础.

1. 挂载点：必须是空目录，若目录有文件，挂载后原文件会被隐藏，卸载后恢复；
2. 文件系统：挂载时需指定设备的文件系统格式,Linux 默认支持 ext4/xfs，NTFS/FAT32 需装依赖；

### 基础命令格式

```shell
# 通用格式：mount [参数] 设备名 挂载点
mount [-t 文件系统] [-o 挂载选项] /dev/sdb1 /mnt/usb
```

参数 | 功能说明	| 常用场景
---|---|---
-t `<fstype>`	 | 指定文件系统格式	 | 挂载 U 盘（fat32/ntfs）、ISO 镜像（iso9660）、网络存储（nfs/cifs）时必用；ext4/xfs 可省略，系统自动识别
-o  `<options>`	 | 指定挂载选项（多个选项用逗号分隔，无空格）	控制设备的挂载权限（读写 / 只读）、缓存、用户权限等，最常用的核心参数


```shell
# 通用格式：mount -t nfs -o nolock 服务端IP:共享目录 本地挂载点
mount -t nfs -o nolock 192.168.1.100:/data/nfs /mnt/nfs
```
注意: 加了nolock，NFS 共享就不再做文件锁的校验，多个客户端同时操作文件时，系统不会做任何互斥限制。

### umount

mount 用于解除设备与挂载点的关联，卸载前必须保证挂载点无进程访问

```shell
# 按挂载点卸载（推荐，唯一标识，不会错）
umount 挂载点
```

## 进程管理命令

- 释义：process state，获取进程当前状态
- 常见用法：
```shell
gec@ubuntu:~$ ps -ef
gec@ubuntu:~$ ps aux
```

## top
- 释义：持续跟踪进程状态
- 常见用法：
```shell
gec@ubuntu:~$ top
gec@ubuntu:~$ top -p PID
```

## kill
- 释义：向指定进程发送信号
- 常见用法：
```shell
# 查看系统所支持的所有的信号列表
gec@ubuntu:~$ kill -l           
gec@ubuntu:~$ kill -s SIGXXX PID ==> 向进程PID发送信号SIGXXX
gec@ubuntu:~$ kill n PID        ==> 向进程PID发送第n号信号
