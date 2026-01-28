#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int capacity; // 总容量
    int size;     // 入栈元素的个数
    int *data;
} ArrayStack;

ArrayStack *newArrayStack(int capacity)
{
    ArrayStack *s = malloc(sizeof(ArrayStack));
    if (s == NULL)
    {
        perror("newArrayStack malloc ArrayStack failed!\n");
        return NULL;
    }

    s->capacity = capacity;
    s->size = 0;
    s->data = malloc(sizeof(int) * capacity);
    if (s->data == NULL)
    {
        perror("newArrayStack malloc data failed!\n");
        free(s);
        return NULL;
    }

    return s;
}

int isFull(ArrayStack *s)
{
    return s->size >= s->capacity;
}

void push(ArrayStack *s, int data)
{
    if (isFull(s))
    {
        printf("栈已满!\n");
        return;
    }

    s->data[(s->size)++] = data;
}

int isEmpty(ArrayStack *s)
{
    return s->size == 0;
}

int peek(ArrayStack *s)
{
    if (isEmpty(s))
    {
        printf("栈为空!\n");
        return -1;
    }

    return s->data[s->size - 1];
}

int pop(ArrayStack *s)
{
    if (isEmpty(s))
    {
        printf("栈为空!\n");
        return -1;
    }

    int res = peek(s);
    s->size--; // 出栈
    return res;
}

void delArrayStack(ArrayStack *s) {
    
    free(s->data);
    free(s);
}

int main(int argc, char const *argv[])
{
    ArrayStack *s = newArrayStack(100);
    if (s == NULL)
    {
        return -1;
    }

    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);

    printf("%d \n", peek(s));
    printf("%d \n", pop(s));
    printf("%d \n", pop(s));
    printf("%d \n", pop(s));
    printf("%d \n", pop(s));
    printf("%d \n", pop(s));
    return 0;
}
