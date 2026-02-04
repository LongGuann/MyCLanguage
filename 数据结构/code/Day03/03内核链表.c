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
    // 遍历链表   方法一
    // 遍历小结构体
    // 参数一 不断遍历next小结构体指针
    // 参数二 头节点小结构体的地址
    struct list_head *pos;
    list_for_each(pos, &shead->list)
    {
        // pos是不断更新的小结构体

        // 想要拿到数据必须使用大结构体
        // 内核链表提供了一个小结构体转大结构体是的方法
        // 参数一：小结构体指针
        // 参数二：大结构体类型
        // 参数三：小结构体在大结构体内的成员名
        StudentNode *sn = list_entry(pos, StudentNode, list);
        printf("%d ", sn->data);
    }
    printf("\n");
    //遍历链表   方法二
    //list_for_each_prev   倒序遍历小结构体   
    //参数一 不断遍历next小结构体指针
    // 参数二 头节点小结构体的地址

    //遍历链表   方法三   // 没有倒叙模式
    //list_for_each_safe   安全模式遍历小结构体  
    //在遍历过程中删除节点或添加节点
    //参数一 不断遍历next小结构体指针
    //参数二 避免指针删除时指错顺序小结构体指针
    //参数三 头结点小结构体地址
    struct list_head *pos1, *n;
    list_for_each_safe(pos1, n, &shead->list){
        StudentNode *s = list_entry(pos1, StudentNode, list);
        printf("%d ", s->data);
    }
    printf("\n");
    // 遍历链表 四
    // 遍历链表并且直接将其转换为大结构体
    //参数一   大结构体指针
    // 参数二 头节点小结构体的地址
    // 参数三 小结构体在大结构体内成员名
    StudentNode *sp;
    list_for_each_entry(sp, &shead->list, list){
        printf("%d ", sp->data);
    }
    printf("\n");
    //// 遍历链表 方法五
    // list_for_each_entry_safe 安全模式遍历链表并直接将其转为大结构体
    StudentNode *sp1, *sn;
    list_for_each_entry_safe(sp1, sn, &shead->list, list)
    {
        printf("%d ", sp1->data);
    };
    printf("\n");


    // 老师节点头插
    TeacherNode *t = create_teacher("小王");
    list_add(&t->list, &thead->list);

    t = create_teacher("小张");
    list_add(&t->list, &thead->list);
    t = create_teacher("小李");
    list_add(&t->list, &thead->list);
    t = create_teacher("小赵");
    list_add(&t->list, &thead->list);

list_for_each(pos, &thead->list)
    {
        // pos是不断更新的小结构体

        // 想要拿到数据必须使用大结构体
        // 内核链表提供了一个小结构体转大结构体是的方法
        // 参数一：小结构体指针
        // 参数二：大结构体类型
        // 参数三：小结构体在大结构体内的成员名
        TeacherNode *tn = list_entry(pos, TeacherNode, list);
        printf("%s ", tn->name);
    }

    return 0;
}
