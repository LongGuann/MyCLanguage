#include <stdio.h>
#include <stdlib.h>
#include "kernel_list.h"

typedef struct
{
    int data;
    struct list_head list;
} Node;

Node *create_node(int data)
{
    Node *n = malloc(sizeof(Node));
    if (n == NULL)
    {
        perror("create_node failed!\n");
        return NULL;
    }
    n->data = data;
    INIT_LIST_HEAD(&n->list);
}

int insert(Node *head, int data, int tail)
{
    Node *new = create_node(data);
    if (new == NULL)
    {
        printf("add_head failed \n");
        return -1;
    }

    if (tail) // 尾插
    {
        list_add_tail(&new->list, &head->list);
    }
    else // 头插
    {
        list_add(&new->list, &head->list);
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    Node *head = create_node(-1);

    insert(head, 7, 1);
    insert(head, 8, 1);
    insert(head, 9, 1);
    insert(head, 10, 1);
    insert(head, 11, 1);
    insert(head, 12, 1);
    insert(head, 13, 1);

    // list_del(head->list.next); // 头删 没有free
    // list_del(head->list.prev); // 尾删 没有free
    /*
    struct list_head *p;
    list_for_each(p, &head->list)
    {
        Node *n = list_entry(p, Node, list);

        printf("%d ", n->data);
    }
    printf("\n");

    struct list_head *n;
    list_for_each_safe(p, n, &head->list)
    {
        Node *node = list_entry(p, Node, list);
        if (node->data % 2 == 0)
        {
            // 删除 list_del 接受小结构体地址
            list_del(&node->list);
            free(node);
        }
    }
    */

    Node *pos, *n;
    list_for_each_entry_safe(pos, n, &head->list, list)
    {
        printf("%d ", pos->data);
        if (pos->data % 2)
        {
            list_del(&pos->list);
            free(pos);
        }
        
    }
    printf("\n");

  
    list_for_each_entry(pos, &head->list, list)
    {
        printf("%d ", pos->data);
    }
    printf("\n");

    return 0;
}
