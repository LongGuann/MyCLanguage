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
int push(LinkedListStack *s,int data) {
    // 从栈顶添加一个链表节点 (头插)
    // 让栈的 size++
    Node *new = malloc(sizeof(Node));
    if(new == NULL)
    {
        perror("puzh failed !\n");
        return -1;
    }
   
    new->data = data;
    new->next = s->top;
    s->top = new;
    s->size++;
    
    return data;
}

// 出栈
int pop(LinkedListStack *s) {
    // 从栈顶添加一个链表节点 (头删)
    // 让栈的 size--
    if(isEmpty(s))
    {
        printf("栈为空  \n");
        return -1;
    }

    Node *node = s->top;
    s->top = node->next;

    int res = node->data; // 将出栈值返回;
    free(node);
    s->size--;

    return res;
}

// 访问栈顶元素;
int peek(LinkedListStack *s)
{
    if(isEmpty(s))
    {
        printf("栈为空 ! \n");
        return -1;
    }
    return s->top->data;
}

// 销毁栈
void delLinkedListStack(LinkedListStack *s)
{
    while (isEmpty)
    {
        pop(s);
    }
    free(s);
}

int main(int argc, char const *argv[])
{
    LinkedListStack *s = newLinkedListStack();
    return 0;
}
