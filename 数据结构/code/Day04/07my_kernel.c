#include <stdio.h>
#include <stdlib.h>

struct my_kernel
{
    struct my_kernel *next, *prev;
};

typedef struct
{
    char *name;
    int weight;
    struct my_kernel list;
} Dog;

struct student
{
    char *name;
    int rank;
    float score;
    struct my_kernel list;
};

// 自己写的内核链表初始化
void init_list_head(struct my_kernel *ptr)
{
    ptr->next = ptr;
    ptr->prev = ptr;
}

// 头插
void list_add(struct my_kernel *new, struct my_kernel *head)
{
    new->next = head->next;
    head->next = new;
    new->next->prev = new;
    new->prev = head;
}

int main(int argc, char const *argv[])
{
    Dog *head = malloc(sizeof(Dog));
    init_list_head(&head->list);

    printf("%ld \n", (char *)head - (char *)&(head->list));

    Dog *d = malloc(sizeof(Dog));
    d->name = "阿福";
    list_add(&d->list, &head->list);
    printf("%ld \n", (char *)d - (char *)&(d->list));

    d = malloc(sizeof(Dog));
    d->name = "旺财";
    list_add(&d->list, &head->list);
    printf("%ld \n", (char *)d - (char *)&(d->list));

    d = malloc(sizeof(Dog));
    d->name = "外教";
    list_add(&d->list, &head->list);

    struct my_kernel *p = head->list.next;

    while (p != &head->list)
    {
        // 我们自己算出来内部list地址比大结构体的地址多16字节
        // 除了使用上面地址相减,可以直接将0x0地址强转为大结构体基地址,0x0地址大结构体内部list地址不需要减,直接就是两者地址差
        Dog * d = (Dog *)((char *)p - (char *)(&((Dog *)(0x0))->list));

        printf("%s \n", d->name);

        p = p->next;
    }

    return 0;
}
