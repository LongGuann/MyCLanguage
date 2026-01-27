#include <stdio.h>
#include <stdlib.h>
#include "kernel_list.h"

typedef struct snode // 外部数据节点被称为大结构体
{
    int data;
    // 使用内核链表避免不同的链表复写增删改查规则
    // 小结构体必须是小结构体变量本身不能是指针
    struct list_head list; // 只包含指针内核链表结构体被称为小结构体
} StudentNode;

typedef struct tnode
{
    char *name;
    struct list_head list;
} TeacherNode;

StudentNode *create_student(int data)
{
    StudentNode *s = malloc(sizeof(StudentNode));
    s->data = data;
    // 指针初始化只需要直接调用内核提供的宏
    INIT_LIST_HEAD(&s->list);
    return s;
}

TeacherNode *create_teacher(char *name)
{
    TeacherNode *t = malloc(sizeof(TeacherNode));
    t->name = name;
    // 指针初始化只需要直接调用内核提供的宏
    INIT_LIST_HEAD(&t->list);
    return t;
}

int main(int argc, char const *argv[])
{
    // 内核链表是带头节点的链表
    StudentNode *shead = create_student(-1);
    TeacherNode *thead = create_teacher("");

    StudentNode *s = create_student(1);
    // list_add 内核链表提供的头插法
    // 参数一新节点小结构体地址
    // 参数二头节点小结构体地址
    list_add(&s->list, &shead->list);

    s = create_student(2);
    list_add(&s->list, &shead->list);

    s = create_student(3);
    list_add(&s->list, &shead->list);

    s = create_student(4);
    list_add(&s->list, &shead->list);

    s = create_student(5);
    list_add(&s->list, &shead->list);

    // 老师节点头插
    TeacherNode *t = create_teacher("小王");
    list_add(&t->list, &thead->list);

    t = create_teacher("小张");
    list_add(&t->list, &thead->list);
    t = create_teacher("小李");
    list_add(&t->list, &thead->list);
    t = create_teacher("小赵");
    list_add(&t->list, &thead->list);

    return 0;
}
