#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next, *prev;
} Node;

Node *create_new_node(int data)
{
    Node *new = malloc(sizeof(Node));
    if (new == NULL)
    {
        perror("create_new_node failed \n");
        return NULL;
    }

    new->data = data;
    new->next = new;
    new->prev = new;
    return new;
}
// 双向循环链表的头插法
int add_head(Node *head, int data)
{
    Node *new = create_new_node(data);
    if(new == NULL)
    {
        perror("add head node failed \n");
        return 0;
    }
    new->next = head->next;
    head->next = new;
    head->prev = new->next;
    new->prev = head;
    return 1;
}
//双向循环链表的头删法
int remove_head(Node *head)
{
    if(head->next == head)
    {
        printf("链表已经为空！\n");
        return 0;
    }
    Node *c_node = head->next;
    head->next = c_node->next;
    c_node->prev = head;
    free(c_node);
    return 1;
}
// 双向循环链表的尾插法
int add_tail(Node *head, int data)
{
    Node *new = create_new_node(data);
    if(new == NULL)
    {
        perror("add tail node failed \n");
        return 0;
    }
    Node *tail = head;
    while (tail->next != head)
    {
        tail = tail->next;
    }
    
    tail->next = new;
    new->prev = tail;
    new->next = head;
    head->prev = new;


    /*
    //在双向循环链表中，head->prev 就是尾节点
    Node *tail = head->prev;
    
    // 正确设置指针连接
    tail->next = new;      // 原尾节点的next指向新节点
    new->prev = tail;      // 新节点的prev指向原尾节点
    new->next = head;      // 新节点的next指向头节点
    head->prev = new;      // 头节点的prev指向新节点
    
    */

    return 1;
}
// 双向循环链表的插入（插入当前节点的下一个节点）
int insert_current_node(Node *node, int data)
{
    Node *new_node = create_new_node(data);
    if(new_node == NULL)
    {
        perror("new node is failed! \n");
        return 0;
    }

    new_node->next = node->next;
    node->next = new_node;

    new_node->next->prev = new_node;
    new_node->prev = node;
    return 1;
}
// 双向循环链表的尾删
int remove_tail(Node *head)
{
    if(head->next == head)
    {
        perror("链表已经清空！ \n");
        return 0;
    }

    Node *tail = head->prev;  // 尾节点是head的前一个节点
        tail->prev->next = head;
        tail->next->prev = head->prev;
    free(tail);
    
    return 1;
}
// 双向循环链表的删除（删除当前节点）
int remove_current_node(Node *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
    return 1;
}
//销毁链表
void destory(Node *head)
{
    while (!is_empty(head))
    {
        remove_current_node(head->next);
    }

    free(head);
}
// 判断是否为空链表
int is_empty(Node *head)
{
    return head == head->next;
}
// 循环遍历链表
void for_each_list(Node *head)
{
    Node *p = head->next;
    while (p != head)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    Node *head = create_new_node(-1);

    add_head(head, 1);
    add_head(head, 2);
    add_head(head, 3);
    for_each_list(head);

    remove_head(head);
    remove_head(head);
    for_each_list(head);

    add_tail(head, 5);
    add_tail(head, 6);
    add_tail(head, 7);
    for_each_list(head);

    remove_tail(head);
    for_each_list(head);

    insert_current_node(head->next->next, 22);
    for_each_list(head);
    
    Node *current = head->next;
    remove_current_node(current);
    for_each_list(head);
    return 0;
}
