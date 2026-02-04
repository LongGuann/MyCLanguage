#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct
{
    struct node *top; // 栈顶
    int size;         // 栈的大小
} LinkedListStack;

LinkedListStack *newLinkedListStack()
{
    LinkedListStack *s = malloc(sizeof(LinkedListStack));
    if (s == NULL)
    {
        perror("newLinkedListStack failed!\n");
        return NULL;
    }

    s->size = 0;
    s->top = NULL;
    return s;
}

int isEmpty(LinkedListStack *s)
{
    return s->size == 0;
}

// 入栈
int push(LinkedListStack *s, int data)
{
    // 从栈顶添加一个链表节点 (头插)
    // 让栈的 size++
    Node *n = malloc(sizeof(Node));
    if (n == NULL)
    {
        perror("push failed!\n");
        return -1;
    }

    n->data = data;
    n->next = s->top;
    s->top = n;
    s->size++;
    return data;
}

// 出栈
int pop(LinkedListStack *s)
{
    if (isEmpty(s))
    {
        printf("栈为空!\n");
        return -1;
    }
    // 从栈顶添加一个链表节点 (头删)

    Node *n = s->top;
    s->top = n->next;
    int res = n->data; // 目的将出战元素的值返回到函数外部
    free(n);
    // n = NULL;
    // 让栈的 size--
    s->size--;
    return res;
}

int peek(LinkedListStack *s)
{
    if (isEmpty(s))
    {
        printf("栈为空! \n");
        return -1;
    }

    return s->top->data;
}

void delLinkedListStack(LinkedListStack *s) {
    while (!isEmpty(s))
    {
        pop(s);
    }
    
    free(s);
}

int main(int argc, char const *argv[])
{
    LinkedListStack *s = newLinkedListStack();
    push(s, 10);
    push(s, 9);
    push(s, 8);
    push(s, 7);

    delLinkedListStack(s);

    printf("%d \n", peek(s));
    // printf("%d \n", pop(s));
    // printf("%d \n", pop(s));
    // printf("%d \n", pop(s));
    // printf("%d \n", pop(s));

    return 0;
}
