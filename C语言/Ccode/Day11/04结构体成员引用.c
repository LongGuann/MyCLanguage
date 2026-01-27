#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[20];
    int age;
    int score;
} Student;

int main(int argc, char const *argv[])
{
    Student tom = {
        .name = "Tom",
        .age = 18,
        .score = 85};

    tom.score = 95;

    printf("%s \n", tom.name);
    printf("%d \n", tom.age);
    printf("%d \n", tom.score);

    Student *s = malloc(sizeof(Student));
    strcpy((*s).name, "Jack");
    (*s).age = 19;
    (*s).score = 88;
    printf("%s \n", (*s).name);
    printf("%d \n", (*s).age);
    printf("%d \n", (*s).score);

    // 结构体指针提供了一个特殊运算符 -> 等价于 (*s).

    Student *s1 = malloc(sizeof(Student));
    s1->age = 22;
    strcpy(s1->name, "Jecia");
    s1->score = 62;

    printf("%s \n", s1->name);
    printf("%d \n", s1->age);
    printf("%d \n", s1->score);

    return 0;
}
