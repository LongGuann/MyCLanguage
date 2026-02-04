#include <stdio.h>

int main(int argc, char const *argv[])
{
    /*
    - 单精度浮点型（float），在64位系统中典型尺寸是4字节，精确到小数点后6位
    - 双精度浮点型（double），在64位系统中典型尺寸是8字节，精确到小数点后15~16位
    - 长双精度浮点型（long double），典型尺寸是16字节
    */
    float a = 3.14;
    double b = 3.14;
    long double c = 3.14;

    printf("float %ld \n", sizeof(a));
    printf("double %ld \n", sizeof(b));
    printf("long double %ld \n", sizeof(c));

    // 指数形式,e或者E的前面必须有数字后面必须为整数
    float d = 3.14e-2; // 314 *(10^-2)
    printf("%f \n", d);

    // 了解: 0.2 + 0.1 不等于 0.3
    // 尽管浮点数 float 扩展了取值范围，但其副作用是牺牲了精度
    double e = 0.2 + 0.1;
    double f = 0.3;

    printf("%.17lf \n", e);
    printf("%.17lf \n", f);
    printf("%d \n", e == f);     // 假
    printf("%d \n", 0.3 == 0.3); // 真

    return 0;
}
