#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev, *next;
} Node;

Node *create_new_node(int data)
{
    Node *n = malloc(sizeof(Node));

    if (n == NULL)
    {
        perror("create_new_node failed!\n");
        return NULL;
    }

    n->data = data;
    n->next = NULL;
    n->prev = NULL;

    return n;
}

// 头插法 返回值是新的头结点
Node *add_head(Node *head, int data)
{
    Node *new = create_new_node(data);

    if (new == NULL)
    {
        printf("add head failed!\n");
        return head;
    }
    if (head != NULL)
    {
        head->prev = new;
        new->next = head;
    }

    // 返回新头结点
    return new;
}
// 尾插注意链表为空时
Node *add_tail(Node *head, int data)
{

    Node *new = create_new_node(data);
    if (new == NULL)
    {
        printf("add tail failed \n");
        return head;
    }
    // 链表为空
    if (head == NULL)
    {
        return new;
    }

    // 从头结点向后找尾节点
    Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = new;
    new->prev = p;
    return head;
}

// 头删
Node *remove_head(Node *head)
{
    if (head == NULL)
    {
        printf("链表为空!\n");
        return NULL;
    }

    if (head->next != NULL)
    {
        head->next->prev = NULL;
    }

    Node *new = head->next;
    free(head);

    return new; // 返回新的头结点
}

// 尾删
Node *remove_tail(Node *head)
{
    if (head == NULL)
    {
        printf("链表为空无法删除!\n");
        return NULL;
    }

    Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    // 链表只有一个节点
    if (p == head)
    {
        free(p);
        return NULL;
    }
    // 多个节点
    p->prev->next = NULL;
    free(p);
    return head;
}

// 销毁
void destory(Node *head)
{

    while (head = remove_head(head))
        ;
}

void for_each_list(Node *head)
{
    Node *p = head;

    Node *tail = head;

    // 正序
    printf("正序: ");
    while (p != NULL)
    {
        if (p->next == NULL)
        {
            tail = p;
        }

        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    printf("倒序: ");

    while (tail != NULL)
    {
        printf("%d ", tail->data);
        tail = tail->prev;
    }

    printf("\n");
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    // 通过add_head返回值更新头结点
    head = add_tail(head, 7);
    head = add_tail(head, 8);
    head = add_tail(head, 9);
    head = add_tail(head, 10);

    // head = remove_tail(head);
    // head = remove_tail(head);
    // head = remove_tail(head);
    // head = remove_tail(head);
    // head = remove_tail(head);

    for_each_list(head);
    
    destory(head);

    return 0;
}
