#include <stdio.h>
#include <stdlib.h>
#include "kernel_list.h" //引入内核链表头文件

//创建一个新的类型为PhoneNode的结构体
typedef struct pNode
{    
    char *name;
    int num;
    // list_head用来创建一个链表的前驱（prev）和后继（list）
    // 等价于 struct list_head *next, *prev;
    struct list_head list;
}PhoneNode;

// 创建一个新的类型为pNode的节点,其中的数据是name
PhoneNode *create_phone(char *name, int num)
{
    PhoneNode *p = malloc(sizeof(PhoneNode));
    // PhoneNode结构体类型的指针变量的解引用后调用name用来接收传入参数
    p->name = name;
    p->num = num;
    //初始化链表，传入的参数是p的地址所指向的结构体类型list_head的list参数
    // 等价于p->list->next = p->list
    //       p->list->prev = p->list
    INIT_LIST_HEAD(&p->list);

    // 节点创建完成，返回新节点
    return p;
}

int main(int argc, char const *argv[])
{
    //内核链表是具有头节点的双向循环链表，需要设置一个头节点
    PhoneNode *phead = create_phone("",-1);

    // 创建一个某种类型的指针变量 并给予这个指针变量一个节点//头节点指向的下一个值就是" "内的值
    PhoneNode *p = create_phone("MOTO",12);
    // 头插法将节点加入链表
    list_add(&p->list, &phead->list);

    p = create_phone("XiaoMi",17);
    list_add(&p->list, &phead->list);
    
    // 传入链表
    struct list_head *pos;
    // 参数为逻辑链表 和链表数据  //数据分离使得不同数据不完全依赖与不同链表，可以共享链表
    // 循环打印链表中的数据内容
    list_for_each(pos, &phead->list)
    {
        // 定义一个结构体指针变量接受链表的节点
        // list_entry做到了从外部的大结构体到内部小结构体的转换
        // 内核链表的操作永远是小结构体
        PhoneNode *sn = list_entry(pos, PhoneNode, list);
        printf("%s %d ", sn->name, sn->num);
    }

    struct list_head *n;
    list_for_each_safe(pos, n, &phead->list)
    {
        PhoneNode *node = list_entry(pos, PhoneNode, list);
        // 删除 list_del 接受小结构体地址
        list_del(&node->list);
        free(node);  
    }

    list_for_each(pos, &phead->list)
    {
        PhoneNode *sn = list_entry(pos, PhoneNode, list);
        printf("%s %d ", sn->name, sn->num);
    }
    return 0;
}
