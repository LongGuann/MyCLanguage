#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int front;
    // int rear;
    int size; // 因为数组物理连续 队尾可以通过 front 和 size计算出来
    int capacity;
    int *data;
} ArrayQueue;

ArrayQueue *newArrayQueue(int capacity)
{
    ArrayQueue *q = malloc(sizeof(ArrayQueue));

    if (q == NULL)
    {
        perror("newArrayQueue failed!\n");
        return NULL;
    }
    q->capacity = capacity;
    q->size = 0;
    q->front = 3;
    q->data = malloc(sizeof(int) * capacity);
    if (q->data == NULL)
    {
        perror("newArrayQueue malloc  q->data failed!\n");
        free(q);
        return NULL;
    }

    return q;
}

int isFull(ArrayQueue *q)
{
    return q->size >= q->capacity;
}

int isEmpty(ArrayQueue *q)
{
    return q->size == 0;
}

// 入队
void push(ArrayQueue *q, int data)
{

    if (isFull(q))
    {
        printf("队列已满!\n");
        return;
    }

    // 先根据队首值与size值计算出入队时队尾的下标
    // 因为数组需要循环复用,这里需要取余
    int rear = (q->front + q->size) % q->capacity;

    // printf("rear: %d \n", rear);
    q->data[rear] = data;
    q->size++;
}

int peek(ArrayQueue *q)
{
    if (isEmpty(q))
    {
        return -1;
    }

    return q->data[q->front];
}

// 出队
int pop(ArrayQueue *q)
{
    if (isEmpty(q))
    {
        printf("队列为空 !\n");
        return -1;
    }

    int res = peek(q);
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return res;
}

void delArrayQueue(ArrayQueue *q) {
    free(q->data);
    free(q);
}

int main(int argc, char const *argv[])
{
    ArrayQueue *que = newArrayQueue(5);

    push(que, 1);
    push(que, 2);
    push(que, 3);
    push(que, 4);
    push(que, 5);

    printf("出队: %d \n", pop(que));

    push(que, 8);
    printf("出队: %d \n", pop(que));
    printf("出队: %d \n", pop(que));
    push(que, 9);
    push(que, 10);
    printf("出队: %d \n", pop(que));
    push(que, 11);

    printf("出队: %d \n", pop(que));
    push(que, 12);

    printf("出队: %d \n", pop(que));
    printf("出队: %d \n", pop(que));
    printf("出队: %d \n", pop(que));
    push(que, 13);
    push(que, 14);
    push(que, 15);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", que->data[i]);
    }

    printf("\n");

    delArrayQueue(que);
    return 0;
}
