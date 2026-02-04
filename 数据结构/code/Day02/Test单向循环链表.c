#include <stdio.h>
#include <stdlib.h>
//定义一个链表结构体（循环）
typedef struct node
{
    int val;
    struct node *next;
} Node;
//创建一个新节点
Node *create_new_node(int val)
{
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
    {
        perror("new node failed! \n");
        return 0;
    }
    new_node->val = val;
    new_node->next = new_node;
    return new_node;
}
// 头插法
int add_head(Node *head, int val)
{
    Node *new_node = create_new_node(val);
    if(new_node == NULL)
    {
        perror("node failed! \n");
        return 0;
    }
    new_node->next = head->next;
    head->next = new_node;
    return 1;
}
//尾插法
int add_tail(Node *head, int val)
{
    Node *new_node = create_new_node(val);
    if(new_node == NULL)
    {
        perror("new node failed! \n");
        return 0;
    }
    Node *tail = head->next;
    while (tail->next != head)
    {
        tail = tail->next;
    }  
    tail->next = new_node;
    new_node->next = head;
    return 1;
}
// 头删法
int remove_head(Node *head)
{
    if(head->next == head)
    {
        printf("链表已经清空！ \n");
        return 0;
    }
    Node *c_node = head->next;
    head->next = c_node->next;
    free(c_node);
    return 1;
}
// 尾删法
int remove_tail(Node *head)
{
    if(head->next == head)
    {
        printf("链表已经清空");
        return 0;
    }
    Node *c_node = head;
    Node *tail;
    while(c_node->next->next != head)
    {
        c_node = c_node->next;
    }
    tail = c_node->next;
    c_node->next = head;
    free(tail);
    return 1;
}
// 销毁循环链表
int destory_loop_link(Node *head)
{
    if(head == NULL)
    {
        return 0;
    }
    Node *current = head->next;
    Node *next_node;
    while(current != head)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    free(head);
    return 1;
}
//循环遍历链表
void for_each_list(Node *head)
{
    Node *p = head->next;
    while (p != head)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    Node *head = create_new_node(-1);
    // 头插
    add_head(head, 1);
    add_head(head, 2);
    add_head(head, 3);
    add_head(head, 4);
    //尾插
    add_tail(head, 5);
    add_tail(head, 6);
    add_tail(head, 7);
    add_tail(head, 8);

    for_each_list(head);
    //头删法
    remove_head(head);
    for_each_list(head);

    //尾删
    remove_tail(head);
    for_each_list(head);

    //销毁链表
    destory_loop_link(head);
    head = NULL;
    return 0;
}
