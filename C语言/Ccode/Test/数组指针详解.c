#include <stdio.h>

// 函数指针数组类型声明
int (*e[7])(int, char);

// 符合签名的函数定义
int add(int a, char b)
{
  printf("执行加法: %d + %d = ", a, b);
  return a + b;
}

int subtract(int a, char b)
{
  printf("执行减法: %d - %d = ", a, b);
  return a - b;
}

int multiply(int a, char b)
{
  printf("执行乘法: %d × %d = ", a, b);
  return a * b;
}

int divide(int a, char b)
{
  if (b == 0)
  {
    printf("错误：除数不能为0\n");
    return 0;
  }
  printf("执行除法: %d ÷ %d = ", a, b);
  return a / b;
}

int modulus(int a, char b)
{
  if (b == 0)
  {
    printf("错误：模运算除数不能为0\n");
    return 0;
  }
  printf("执行取模: %d %% %d = ", a, b);
  return a % b;
}

int bitwise_and(int a, char b)
{
  printf("执行按位与: %d & %d = ", a, b);
  return a & b;
}

int bitwise_or(int a, char b)
{
  printf("执行按位或: %d | %d = ", a, b);
  return a | b;
}

// 初始化函数指针数组
void init_function_table()
{
  e[0] = add;
  e[1] = subtract;
  e[2] = multiply;
  e[3] = divide;
  e[4] = modulus;
  e[5] = bitwise_and;
  e[6] = bitwise_or;
}

// 显示菜单
void show_menu()
{
  printf("\n=== 计算器函数表 ===\n");
  printf("0. 加法\n");
  printf("1. 减法\n");
  printf("2. 乘法\n");
  printf("3. 除法\n");
  printf("4. 取模\n");
  printf("5. 按位与\n");
  printf("6. 按位或\n");
  printf("7. 退出\n");
  printf("===================\n");
}

int main()
{
  int choice;
  int num1;
  char num2;

  // 初始化函数指针数组
  init_function_table();

  while (1)
  {
    show_menu();
    printf("请选择操作 (0-7): ");
    scanf("%d", &choice);

    if (choice == 7)
    {
      printf("退出程序\n");
      break;
    }

    if (choice < 0 || choice > 6)
    {
      printf("无效选择，请重试\n");
      continue;
    }

    printf("请输入两个数（第二个数会自动转为char）: ");
    scanf("%d %hhd", &num1, &num2);

    // 通过函数指针数组调用对应的函数
    int result = e[choice](num1, num2);
    printf("%d\n", result);
  }

  return 0;
}