#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    // 文件描述符（File Descriptor，FD）：是用户进程视角的非负整数索引，本质是进程内指向「文件描述符表」的指针，通过它间接访问内核中的文件资源，避免用户态直接操作内核数据结构。

    // 文件描述符表(就是个数组), 内部都是指针指向对应的打开文件表项(元素), 文件描述符就是数组对应的下标

    //  打开文件表,表中的每个元素都是一个结构体: 记录文件的当前操作状态（偏移量、打开标志）以及指向inode的指针 , 注意一个文件可对应多个表项

    // 索引节点表: 记录文件的元信息和物理存储信息（磁盘级），一个文件只有一个唯一 inode

    /*
1. 调用C库open()，传入path/flags/mode
   ↓（封装参数，触发syscall）
2. 陷入内核，执行sys_open()系统调用
   ↓
3. 内核解析路径名pathname（如"/home/test.txt"）
   → 从根目录inode开始，逐层查找目录项，最终找到目标文件的**inode**
   → 若O_CREAT：目标文件不存在则在磁盘创建，生成新inode和目录项
   ↓
4. 内核权限校验
   → 检查进程是否有访问该文件的权限（基于inode的权限位+进程UID/GID）
   → 若O_CREAT：检查进程是否有创建文件的目录权限
   → 校验失败：返回-1，设置errno（EACCES/ENOENT等）
   ↓
5. 内核分配**打开文件表项**
   → 初始化表项：设置文件偏移量（默认0）、状态标志（flags）、指向inode的指针
   → 增加inode的**引用计数**（i_count++）
   ↓
6. 内核操作进程的**文件描述符表**
   → 查找表中**最小的未使用FD**（如3/4/5...）
   → 将该FD对应的表项指向**步骤5的打开文件表项**
   → 增加打开文件表项的**引用计数**（f_count++）
   ↓
7. 内核返回FD给用户态
   → 完成内核态→用户态切换
   → C库open()返回该FD，进程可通过FD执行read/write/close
   ↓（后续IO操作）
8. 进程通过FD调用read/write：内核通过FD找到文件表项→inode→磁盘文件，完成数据读写
    
重点: 文件偏移量的初始化：open 成功后，打开文件表项的文件偏移量默认初始化为 0，后续 read/write 会修改该偏移量（除非用 O_APPEND，写操作会强制将偏移量移到文件末尾）。

重点: open方法打开的文件描述符是有限的,用完记得关闭

*/

    int fd;
    while (fd = open("./test.txt", O_RDWR | O_APPEND))
    {
        printf("%d \n", fd);
        if (fd == -1)
        {
            perror("open test.txt failed!\n");
            return -1;
        }
    }

    return 0;
}
