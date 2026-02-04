#include <stdio.h>

int main() {
    // 普通char变量：默认对齐1字节，地址无严格限制
    char normal_c;
    // 强制32字节对齐的char变量：地址必须是32的整数倍
    char align_c __attribute__((aligned(32)));

    // 打印地址（十六进制），验证对齐规则
    printf("普通char变量地址：0x%lx\n", (unsigned long)&normal_c);
    printf("32字节对齐char变量地址：0x%lx\n", (unsigned long)&align_c);
    
    // 验证地址是否是32的整数倍（32的十六进制是0x20）
    if (((unsigned long)&align_c) % 32 == 0) {
        printf("✅ align_c 满足32字节对齐\n");
    } else {
        printf("❌ align_c 不满足32字节对齐\n");
    }

    // 额外：查看变量占用的内存大小（对齐会影响“有效占用大小”）
    printf("normal_c 占用大小：%zu 字节\n", sizeof(normal_c));       // 输出 1
    printf("align_c 占用大小：%zu 字节\n", sizeof(align_c));         // 输出 32（编译器为了对齐，会扩展占用空间）
    return 0;
}