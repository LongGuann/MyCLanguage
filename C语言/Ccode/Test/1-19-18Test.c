

#include <stdio.h>
#include <string.h>

int decToBin(int n);
int peachNum(int n);

int main(int argc, char const *argv[])
{
  int day = 4;
  // printf("请输入猴子吃桃的天数: ");
  // scanf("%d",&day);
  printf("桃子的最初数量有%d个\n",peachNum(day));
  
  int decNum;
  printf("请输入一个数字:");
  scanf("%d",&decNum);
  decToBin(decNum);
  
  return 0;
}

/*
  C 语言编程面试题：猴子吃桃子问题
题目描述
    有一只猴子吃一堆桃子，它每天都会吃掉当前桃子数量的一半多一个。
  当吃到第 n 天（n≥1）时，发现只剩下 1 个桃子。
  请编写 C 语言程序，计算这堆桃子最初有多少个。
要求
输入：从控制台输入一个正整数 n（表示第 n 天只剩 1 个桃子）。
输出：输出桃子最初的数量。
*/

//每天吃掉的桃子个数为  n/2 + 1
// n  1 2 3 4   5   6
// fi 1 3 7 15  31  63    fi = 2fi + 1 

int peachNum(int n){
  // int fi = 1;
  if(n == 1)  return 1; 
  // for(;n>1;n--){
  //   fi = (fi+1) *2;
  // }
  //return fi; 
  return (peachNum(--n)+ 1)*2 ;
}
//使用递归 将十进制输出为2进制
//10  1010 
// int decToBin(int dec){
//   if(dec == 0)
//    return 0;
   
//   //printf("%d",dec % 2);
//   int date = dec % 2;
//   // return decToBin(dec / 2);
//   return printf("%d",date,decToBin(dec / 2));
//  }

int decToBin(int dec){
  if(dec == 0)
   return 0;
   
  //printf("%d",dec % 2);
  int date = dec % 2;
  // return decToBin(dec / 2);
   printf("%d",date,decToBin(dec / 2));
 }