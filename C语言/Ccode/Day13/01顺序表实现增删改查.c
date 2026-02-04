#include <stdio.h>
#include <stdlib.h>

// 列表（list）是一个抽象的数据结构概念，它表示元素的有序集合，
// 支持元素访问、修改、添加、删除和遍历等操作，列表可以基于链表或数组实现 我们用数组实现。

typedef struct
{
    int capacity; // 列表容量
    int size;     // 列表大小
    int *arr;
} SequeueList;

/* 构造函数 初始化顺序表结构体 */
SequeueList *newSequeueList(int capacity)
{
    SequeueList *s = malloc(sizeof(SequeueList));

    s->capacity = capacity; // 数组最大容量

    s->size = 0; // 表示数组中已经存放了多少数据

    s->arr = malloc(sizeof(int) * s->capacity);

    return s;
}
// 尾插法将想要添加的数据,写入列表的尾部
int add_tail(SequeueList *s, int data)
{

    if (s->size == s->capacity)
    {
        printf("列表已满无法添加 \n");
        return -1;
    }

    s->arr[s->size] = data;
    s->size++;

    return data;
}

// 遍历列表
void for_each_sequeue_list(SequeueList *s)
{
    for (int i = 0; i < s->size; i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{

    SequeueList *s1 = newSequeueList(100);

    add_tail(s1, 7);
    add_tail(s1, 18);
    add_tail(s1, 19);
    add_tail(s1, 32);
    add_tail(s1, 1);

    for_each_sequeue_list(s1);


    // SequeueList *s2 = newSequeueList(20);
    return 0;
}
