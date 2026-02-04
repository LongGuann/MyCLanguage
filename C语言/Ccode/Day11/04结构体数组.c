#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *name;
    int age;
    int score;
} Student;

int main(int argc, char const *argv[])
{
    Student s_arr[10] = {
        {
            .age = 17,
            .name = "小王",
            .score = 80
        }
    };

    printf("%s %d %d \n", s_arr[0].name, s_arr[0].age, s_arr[0].score);

    Student *s_arr2 = malloc(sizeof(Student) * 10);

    s_arr2[0].name = "hello";
    s_arr2[0].age = 18;
    s_arr2[0].score = 88;

    printf("%s %d %d \n", s_arr2[0].name, s_arr2[0].age, s_arr2[0].score);


    return 0;
}
