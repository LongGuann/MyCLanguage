#include <stdio.h>
#include <stdlib.h>
#include "kernel_list.h"

typedef struct
{
    int data;
    struct list_head list;
} Node;

typedef struct
{
    int size;
    struct list_head *head;         // 内核链表头结点指针
    struct list_head *front, *rear; // 队列队首队尾小结构体指针
} KernelListQueue;

KernelListQueue *newKernelListQueue()
{
    // 创建内核链表队列结构体
    KernelListQueue *q = malloc(sizeof(KernelListQueue));
    if (q == NULL)
    {
        perror("newKernelListQueue failed !\n");
        return NULL;
    }
    // 创建内核链表头结点
    Node *n = malloc(sizeof(Node));
    if (n == NULL)
    {
        perror("newKernelListQueue failed !\n");
        free(q);
        return NULL;
    }

    // 初始化内核链表节点
    INIT_LIST_HEAD(&n->list);

    q->head = &n->list;
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;

    return q;
}

int isEmpty(KernelListQueue *q)
{
    return q->size == 0;
}

// 队列先进先出 尾插头删

void push(KernelListQueue *q, int data)
{
    // 创建内核链表节点
    Node *n = malloc(sizeof(Node));
    if (n == NULL)
    {
        perror("push malloc failed!\n");
        return;
    }

    n->data = data;
    // 内核链表提供的尾插
    list_add_tail(&n->list, q->head);
    // 更新队尾
    q->rear = &(n->list);
    // 若队列为空,更新队首
    if (isEmpty(q))
    {
        q->front = &(n->list);
    }
    q->size++;
}

int peek(KernelListQueue *q)
{
    if (isEmpty(q))
    {
        printf("队列为空!\n");
        return -1;
    }

    Node *n = list_entry(q->front, Node, list);

    return n->data;
}

int pop(KernelListQueue *q)
{
    if (isEmpty(q))
    {
        printf("队列为空无法出队 \n");
        return -1;
    }

    int res = peek(q);
    // 头删,拿到要删除的那个小结构体对应的大结构体
    Node *n = list_entry(q->front, Node, list);

    q->front = q->front->next;
    // 调用内核链表的删除节点方法
    list_del(&n->list);

    free(n);

    q->size--;

    return res;
}

void delKernelListQueue(KernelListQueue *q)
{
    while (!isEmpty(q))
    {
        pop(q);
    }

    Node *head = list_entry(q->head, Node, list);
    free(head);
    free(q);
}

int main(int argc, char const *argv[])
{
    KernelListQueue *que = newKernelListQueue();

    push(que, 2);
    push(que, 3);
    push(que, 4);
    push(que, 5);
    push(que, 6);

    printf("pop: %d \n", pop(que));
    printf("pop: %d \n", pop(que));
    printf("pop: %d \n", pop(que));
    printf("pop: %d \n", pop(que));
    printf("pop: %d \n", pop(que));
    printf("pop: %d \n", pop(que));

    push(que, 9);
    push(que, 10);
    push(que, 11);
    push(que, 12);
    push(que, 13);

    

    struct list_head *p = que->front;

    while (p != que->head)
    {
        Node *n = list_entry(p, Node, list);
        printf("%d ", n->data);
        if (p == que->rear)
        {
            printf("结束");
        }
        p = p->next;
    }

    printf("\n");

    delKernelListQueue(que);
    return 0;
}
