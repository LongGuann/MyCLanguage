#include <stdio.h>
#include <stdlib.h>
#include "kernel_list.h"

typedef struct node
{
    int data;
    struct list_head list;
} Node;

typedef struct
{
    struct node *top;
    int size;
} LinkedListStack;

LinkedListStack *newLinkedListStack()
{
    LinkedListStack *s = malloc(sizeof(Node));
    if (s == NULL)
    {
        perror("newLinkedListStack failed!\n");
        return NULL;
    }
    
    s->size = 0;
    s->top = malloc(sizeof(Node));
    if (s->top == NULL)
    {
        perror("s.top failed ! \n");
        free(s);
        return NULL;
    }
    
    INIT_LIST_HEAD(&(s->top->list));
    return s;
}

int isEmpty(LinkedListStack *s)
{
    return s->size == 0;
}

int push(LinkedListStack *s,int data)
{
    Node *new = malloc(sizeof(Node));
    if(new == NULL)
    {
        perror("puzh failed !\n");
        return -1;
    }
   
    new->data = data;
    list_add(&new->list, &(s->top->list));
    s->size++;

    return data;
}

int peek(LinkedListStack *s)
{
    if(isEmpty(s))
    {
        printf("空栈\n");
        return -1;
    }
    Node *n = list_entry(s->top->list.next, Node, list);
    return n->data;
}

int pop(LinkedListStack *s)
{
    if(isEmpty(s))
    {
        printf("空栈\n");
        return -1;
    }
    int res = peek(s);

    struct list_head *sn = s->top->list.next;
    list_del(sn);

    Node *bgn = list_entry(sn, Node, list);
    free(bgn);
    s->size--;
    return res;
}

void delLinkedListStack(LinkedListStack *s)
{
    while (isEmpty)
    {
        pop(s);
    }
    free(s->top);
    free(s);
}


int main(int argc, char const *argv[])
{
    LinkedListStack *t = newLinkedListStack();
    push(t, 1);

    printf("%d ", pop(t));

    delLinkedListStack(t);
    return 0;
}
