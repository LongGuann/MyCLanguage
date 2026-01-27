#include <stdio.h>
#include <stdlib.h>

// https://www.hello-algo.com/chapter_array_and_linkedlist/list/

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

int is_full(SequeueList *s)
{
    if (s->size == s->capacity)
    {
        printf("列表已满无法添加 \n");
        return 1;
    }

    return 0;
}

int insert_list(SequeueList *s, int data, int index)
{
    if (is_full(s))
    {
        return -1;
    }

    if (index > s->size)
    {
        printf("插入范围异常 \n");
        return -1;
    }

    // 移动
    // 把所有元素向后移动
    for (int i = s->size - 1; i >= index; i--)
    {
        s->arr[i + 1] = s->arr[i];
    }

    s->arr[index] = data;
    s->size++;

    return data;
}

// 尾插法将想要添加的数据,写入列表的尾部
int add_tail(SequeueList *s, int data)
{
    return insert_list(s, data, s->size);
}

int add_head(SequeueList *s, int data)
{
    return insert_list(s, data, 0);
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

int is_empty(SequeueList *s)
{
    if (s->size == 0)
    {
        printf("列表为空无法删除 \n");
        return 1;
    }

    return 0;
}

int remove_list(SequeueList *s, int index)
{
    if (is_empty(s))
    {
        return -1;
    }

    if (index > s->size - 1 || index < 0)
    {
        printf("删除下标异常 \n");
        return -1;
    }

    // 移动元素
    for (int i = index + 1; i < s->size; i++)
    {
        s->arr[i - 1] = s->arr[i];
    }

    s->size--;

    return index;
}

int remove_head(SequeueList *s)
{
    return remove_list(s, 0);
}

int remove_tail(SequeueList *s)
{
    return remove_list(s, s->size - 1);
}

// 销毁列表方法
void destory_list(SequeueList *s) {
    // 先释放内部数组
    free(s->arr);
    free(s);
}

int main(int argc, char const *argv[])
{

    SequeueList *s1 = newSequeueList(100);

    add_tail(s1, 7);
    add_tail(s1, 18);
    add_tail(s1, 19);
    add_tail(s1, 32);
    add_tail(s1, 1);

    add_head(s1, 10);
    add_head(s1, 9);
    add_head(s1, 8);

    insert_list(s1, 99, 6);

    // remove_head(s1);
    // remove_head(s1);
    // remove_head(s1);
    // remove_head(s1);
    // remove_head(s1);
    // remove_head(s1);
    // remove_head(s1);
    // remove_head(s1);
    // remove_head(s1);
    // remove_head(s1);

    // remove_tail(s1);
    // remove_tail(s1);
    // remove_tail(s1);
    // remove_tail(s1);
    // remove_tail(s1);
    // remove_tail(s1);
    // remove_tail(s1);
    // remove_tail(s1);
    // remove_tail(s1);
    // remove_tail(s1);

    remove_list(s1, 4);
    remove_list(s1, 3);
    // remove_list(s1, 13);
    // remove_list(s1, -1);
    for_each_sequeue_list(s1);

    destory_list(s1);
    s1 = NULL;

    // SequeueList *s2 = newSequeueList(20);
    return 0;
}
