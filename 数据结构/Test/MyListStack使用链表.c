#include <stdio.h>
#include <stdlib.h>

// 创建链表结构体
typedef struct node
{
    int data;
    struct node *next;
} Node;

// 创建栈结构体
typedef struct 
{
    struct node *top; // 用来表示栈顶的位置
    int size; // 用来存储栈的大小
} ListStack;

// 初始化栈
ListStack *newListStack()
{
    ListStack *s_node = malloc(sizeof(ListStack));
    if (s_node == NULL)
    {
        perror("newListStack is failed ! \n");
        return NULL;
    }
    s_node->size = 0;
    s_node->top = NULL;

    return s_node;
}

// 入栈
int push(ListStack *Stack, int data)
{
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
    {
        perror("new node is failed !\n");
        return 0;
    }

    new_node->data = data;
    new_node->next = Stack->top;
    Stack->top = new_node;
    Stack->size++;

    return 1;

}

// 判断栈是否为空
int isEmpty(ListStack *Stack)
{
    return Stack->top == 0;
}

// 取栈顶元素
int peek(ListStack *Stack)
{
    if (isEmpty(Stack))
    {
        printf("栈为空! \n");
        return -1;
    }

    return Stack->top->data;
}

// 出栈
int pop(ListStack *Stack)
{
    if(isEmpty(Stack))
    {
        printf("栈为空! \n");
        return 0;
    }
    Node *c_node = Stack->top;
    Stack->top = Stack->top->next;
    int res = c_node->data;
    free(c_node);
    Stack->size--;

    return res;
}

//销毁栈
int delListStack(ListStack *Stack)
{
    while(!isEmpty(Stack))
    {
        pop(Stack);
    }

    free(Stack);
}
int main(int argc, char const *argv[])
{
    ListStack *Stack = newListStack();

    // 入栈
    push(Stack, 1);
    push(Stack, 2);
    push(Stack, 3);
    push(Stack, 4);

    // 出栈
    printf("%d ", pop(Stack));
    printf("%d ", pop(Stack));

    // 销毁栈
    delListStack(Stack);

    Node *p = Stack->top;
    while(Stack->top != NULL)
    {
        printf("%d ",Stack->top->data);
        Stack->top = Stack->top->next;
    }

    peek(Stack);
    return 0;
}
