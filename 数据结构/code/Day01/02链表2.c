#include <stdio.h>
#include <stdlib.h>

// 内存空间是所有程序的公共资源，在一个复杂的系统运行环境下，空闲的内存空间可能散落在内存各处。
// 我们知道，存储数组的内存空间必须是连续的，而当数组非常大时，内存可能无法提供如此大的连续空间。
// 此时链表的灵活性优势就体现出来了。

// 链表（linked list）是一种线性数据结构，其中的每个元素都是一个节点对象，
// 各个节点通过“指针”相连接。指针记录了下一个节点的内存地址，通过它可以从当前节点访问到下一个节点。

// 链表的设计使得各个节点可以分散存储在内存各处，它们的内存地址无须连续。

// 定义链表的节点数据, 链表节点结构体不能是匿名的
typedef struct node
{
    int val;
    struct node *next;
} Node;

// 链表结构体
typedef struct
{
    int size;
    Node *head;
} LinkList;

// 链表有两种 常见形式 带头节点(固定头结点) 不带头节点
// 所谓的头结点创建一个不存放有效数据的节点永远作为当前链表头，目的仅仅用来方便操作

// 创建一个新节点
Node *create_new_node(int val)
{
    Node *n = malloc(sizeof(Node));

    if (n == NULL)
    {
        perror("create new node failed ! \n");
        return NULL;
    }

    n->val = val;
    n->next = NULL;

    return n;
}

// 初始化链表,创建一个带头节点的空链表
LinkList *initial_link_list()
{
    Node *head = create_new_node(-1); // 带头节点头结点的val是多少不重要
    if (head == NULL)
    {
        return NULL;
    }

    // 创建链表结构体
    LinkList *list = malloc(sizeof(LinkList));
    if (list == NULL)
    {
        perror("create LinkList failed!\n");
        free(head);
        return NULL;
    }

    list->size = 0;
    list->head = head;

    return list;
}

// 链表的头插法
int add_head(LinkList *list, int val)
{
    Node *new_node = create_new_node(val);

    if (new_node == NULL)
    {
        perror("add_head failed \n");
        return 0;
    }
    // 推荐自己画图
    // 新节点的next指向头结点的next
    new_node->next = list->head->next;

    // 让头结点next指向new
    list->head->next = new_node;

    list->size++;

    return 1;
}

// 链表的尾插
int add_tail(LinkList *list, int val)
{
    Node *new_node = create_new_node(val);

    if (new_node == NULL)
    {
        perror("add_head failed \n");
        return 0;
    }

    // 找到当前链表的尾节点
    // 节点的next 若为 NULL 表示该节点是我们的尾节点
    Node *tail = list->head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = new_node;

    list->size++;

    return 1;
}

int is_empty(LinkList *list)
{
    if (list->head->next == NULL)
    {
        return 1;
    }
    return 0;
}

// 头删
int remove_head(LinkList *list)
{
    if (is_empty(list))
    {
        printf("链表已经为空!\n");
        return 0;
    }

    Node *c_node = list->head->next;
    list->head->next = c_node->next;
    // 节点被删除后一定要释放这段内存
    free(c_node);
    // c_node = NULL;

    return 1;
}

// 作业 带头节 单链表 尾删 销毁 以及 不带头节点 头插 头删 尾插 尾删 销毁

void for_each_link_list(LinkList *list)
{
    Node *p = list->head->next;

    while (p != NULL) //  while (p)
    {
        printf("%d ", p->val);
        p = p->next; // 更新节点让节点变成下一个节点
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    LinkList *list = initial_link_list();

    if (list == NULL)
    {
        return -1;
    }

    add_head(list, 7);
    add_head(list, 8);
    add_head(list, 9);
    add_head(list, 10);
    add_head(list, 11);
    add_head(list, 12);

    add_tail(list, 10);
    add_tail(list, 9);
    add_tail(list, 8);
    add_tail(list, 7);

    remove_head(list);
    remove_head(list);
    remove_head(list);
    remove_head(list);
    remove_head(list);
    remove_head(list);

    remove_head(list);
    remove_head(list);
    remove_head(list);
    remove_head(list);

    remove_head(list);

    for_each_link_list(list);

    return 0;
}
