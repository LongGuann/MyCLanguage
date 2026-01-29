#include <stdio.h>
#include <stdlib.h>

#define list_entry(ptr, type, member) \
    (type *)((char *)(ptr) - (char *)(&(((type *)(0x0))->member)))

struct my_kernel
{
    struct my_kernel *next, *prev;
};

typedef struct student
{
    char *name;
    int rank;
    float score;
    struct my_kernel list;
} Student;

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
    Student *s = malloc(sizeof(Student));

    init_list_head(&s->list);

    Student *s1 = malloc(sizeof(Student));
    s1->name = "张三";
    list_add(&s1->list, &s->list);

    s1 = malloc(sizeof(Student));
    s1->name = "李四";
    list_add(&s1->list, &s->list);
    s1 = malloc(sizeof(Student));
    s1->name = "王五";
    list_add(&s1->list, &s->list);

    s1 = malloc(sizeof(Student));
    s1->name = "赵六";
    list_add(&s1->list, &s->list);

    struct my_kernel *p;

    for (p = s->list.next; p != &s->list; p = p->next)
    {
        // Student *s = (Student *)((char *)p - (char *)(&(((Student *)(0x0))->list)));
        Student *s = list_entry(p, Student, list);
        printf("%s \n", s->name);
    }

    return 0;
}
