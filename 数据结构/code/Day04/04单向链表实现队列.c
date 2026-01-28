#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct
{
    int size;
    struct node *front, *rear;
} LinkedListQueue;

/* 构造函数 */
LinkedListQueue *newLinkedListQueue()
{
    LinkedListQueue *q = malloc(sizeof(LinkedListQueue));
    if (q == NULL)
    {
        perror("newLinkedListQueue failed!\n");
        return NULL;
    }
    q->size = 0;
    q->rear = NULL;
    q->front = NULL;
    return q;
}

// 判断队列是否为空
int isEmpty(LinkedListQueue *q)
{
    return q->size == 0;
}

// 入队
void push(LinkedListQueue *q, int data)
{
    Node *n = malloc(sizeof(Node));
    if (n == NULL)
    {
        perror("push malloc failed!\n");
        return;
    }
    n->data = data;
    n->next = NULL;

    if (isEmpty(q))
    {
        // 若队列为空队列第一个入队元素既是对首也是队尾
        q->front = n;
    }
    else
    {
        q->rear->next = n;
    }

    q->rear = n; // 让节点变为新的队尾
    q->size++;
}

int main(int argc, char const *argv[])
{
    LinkedListQueue *que = newLinkedListQueue();
    if (que == NULL)
    {
        return -1;
    }

    push(que, 7);
    push(que, 8);
    push(que, 9);
    push(que, 10);

    Node *p = que->front;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");

    return 0;
}
