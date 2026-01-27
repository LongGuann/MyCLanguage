#include <stdio.h>
#include <stdlib.h>

// typedef struct node
// {
//     int data;
//     struct node *next;
//     struct node *prev;
// } Node;

// 双向链表的节点只是比单向链表多了一个前驱指针
typedef struct node
{
    int data;
    struct node *next, *prev;
} Node;
//创建节点
Node *create_new_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        perror("create_new_node failed!\n");
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
// 头插法
int add_head(Node *head, int data)
{

    Node *new = create_new_node(data);

    if (new == NULL)
    {
        printf("add_head failed!\n");
        return 0;
    }

    new->next = head->next;
    head->next = new;

    if (new->next != NULL)
    {
        new->next->prev = new;
    }

    new->prev = head;

    return 1;
}
// 尾插法
int add_tail(Node *head, int data)
{

    Node *new = create_new_node(data);

    if (new == NULL)
    {
        printf("add_tail failed!\n");
        return 0;
    }

    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    
    p->next = new;
    new->prev = p;

    return 1;
}
//返回链表中 data为target的节点
Node *search_node(Node *head, int target)
{
    Node *search_node = head;
    while(search_node->data != target){
        search_node = search_node->next;
    }
    return search_node;
}
//传入链表节点n，新建一个节点插入到n的后面
int add_current_node(Node *n, int data)
{
    Node *current = create_new_node(data);

    current->next = n->next; 
    current->prev = n;        
      
    if (n->next != NULL) {
        n->next->prev = current;
    }
    
    n->next = current;
    return 1;
}
//删除指定节点
int remove_node(Node *head, int data)
{
    Node *c_node = head;
    while(c_node->data != data){
        c_node = c_node->next;
    }
    Node *current = c_node;
    if(c_node->prev == NULL){
        printf("固定头节点不可删 \n");
        return 0;
    }
    current->prev->next = c_node->next;
    if(c_node->next != NULL)
    c_node->next->prev = current;
    free(c_node); 
    return 1;
}
//头删法
int remove_head(Node *head)
{
    Node *p = head->next;
    if(p == NULL)
    {   
        printf("链表已空！\n");
        return 0;
    } 
    remove_node(head,p->data);
    return 1;
}
//不带头节点的头删法
Node* remove_head_noponit(Node *head)
{
    if(head == NULL)
    {
        printf("链表为空！\n");
        return 0;
    }
    Node *p = head->next;

    p->prev = NULL;
    
    free(head);
    return p;
}
//尾删法
int remove_tail(Node *head)
{
    Node *p = head;
    if(p->next == NULL)
    {
        printf("链表已空！ \n");
        return 0;
    }
    while (p->next != NULL)
    {
        p = p->next;
    }
    remove_node(head,p->data);
    return 1;
}
//销毁链表
int destory_list(Node *head)
{
    Node *current = head->next;
    Node *tail;
    while(current != NULL)
    {
        tail = current->next;
        free(current);
        current = tail;
    }
    free(head);
    return 1;
}
//遍历打印链表值
void for_each_list(Node *head)
{
    Node *p = head->next;

    Node *rp = p;

    while (p != NULL)
    {
        if (p->next == NULL)
       {
           rp = p;
       }

        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    // 倒序循环
    // while(rp->prev != NULL){
    //     printf("%d ",rp->data);
    //     rp = rp->prev;
    // }
    // printf("\n");
}



int main(int argc, char const *argv[])
{
    // 带头节点
    Node *head = create_new_node(-1);
    // 头插法
    add_head(head, 7);
    add_head(head, 8);
    add_head(head, 9);
    add_head(head, 10);
    //尾插
    add_tail(head, 9);
    add_tail(head, 8);
    add_tail(head, 7);
    add_tail(head, 6);
    for_each_list(head);
    //指定节点
    Node *search = search_node(head, 9);
    printf("%d \n", search->data);
    //插入指定节点后
    add_current_node(head->next->next, 4);
    for_each_list(head);
    //指定删除节点
    remove_node(head,9);
    for_each_list(head);
    //头删法
    remove_head(head);
    for_each_list(head);
    //尾删法
    remove_tail(head);
    for_each_list(head);
    //不带头节点的头删
    head = remove_head_noponit(head);
    for_each_list(head);
    //销毁链表
    //destory_list(head);
    //for_each_list(head);
    //head = NULL;
    return 0;
}
