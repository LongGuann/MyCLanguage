#include <stdio.h>

// 示例1：默认对齐（32位系统，默认m值=最大成员大小=4）
struct DefaultAlign {
    char a;    // 1字节，默认对齐到4字节（补3个空字节）
    int b;     // 4字节，对齐到4字节
    short c;   // 2字节，默认对齐到4字节（补2个空字节）
};

// 示例2：手动设置按1字节对齐（取消所有填充）
#pragma pack(1)  // 开始按1字节对齐
struct Pack1Align {
    char a;     // 1字节，无填充
    int b;      // 4字节，紧跟a，无填充
    short c;    // 2字节，紧跟b，无填充
};
#pragma pack()   // 恢复默认对齐规则

// 示例3：更安全的用法（push/pop，避免影响其他代码）
#pragma pack(push, 2)  // 保存当前规则，设置按2字节对齐
struct Pack2Align {
    char a;     // 1字节，补1个空字节（对齐到2字节）
    int b;      // 4字节，对齐到2字节（本身是2的倍数，无额外填充）
    short c;    // 2字节，无填充
};
#pragma pack(pop)      // 恢复到push前的默认规则

int main() {
    // 输出各结构体大小，直观看到对齐的影响
    printf("默认对齐结构体大小：%zu 字节\n", sizeof(struct DefaultAlign));  // 输出 12
    printf("pack(1)结构体大小：%zu 字节\n", sizeof(struct Pack1Align));    // 输出 7
    printf("pack(2)结构体大小：%zu 字节\n", sizeof(struct Pack2Align));    // 输出 8
    return 0;
}