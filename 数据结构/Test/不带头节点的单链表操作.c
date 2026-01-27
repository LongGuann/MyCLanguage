#include <stdio.h>
#include <stdlib.h>

//定义一个链表节点
typedef struct node
{
  int val;
  struct node *next;
} Node;

//创建一个新节点
Node *create_new_node(int val){
  Node *n = malloc(sizeof(Node));
  if(n == NULL){
    perror("create new node failed");
    return NULL;
  }

  n->val = val;
  n->next = NULL;
  return n;
}

//初始化链表
Node *intial_link_list(){
  Node *node = create_new_node(0);
  if(node == NULL){
    return NULL;
  }

  //创建链表结构体
  Node *list = malloc(sizeof(Node));
  if(list == NULL){
    perror("create LinkList failed!\n");
    free(node);
    return NULL;
 }
    list->next = NULL;

    return list;
}

//不带头节点的链表的头插法
int add_head(Node *list, int val){
  Node *new_node = create_new_node(val);
  if(new_node == NULL){
    perror("new node is failed\n");
    return 0;
  }
  // 让新的节点的next指向链表首节点的next
  new_node->next = list->next;
  // 让链表的next节点指向新节点
  list->next = new_node;
  return 1;
}

//不带头节点的链表的尾插法
int add_tail(Node *list, int val){
  Node *new_node = create_new_node(val);
  if(new_node == NULL){
    perror("new node is failed\n");
    return 0;
  }
  Node *p = list->next;
  while(p->next != NULL){
    p = p->next;
  }
  p->next = new_node;
  new_node->next = NULL;
  return 1;
  //让新的节点的next指向链表尾节点
}

int is_empty(Node *list)
{
    if (list->next == NULL){
        return 1;
    }
    return 0;
}

//不带头节点的链表的头删法
int remove_head(Node *list){
  Node *p = list->next;
  if (is_empty(list)){ 
    printf("链表已经为空!\n");
    return 0;
  }

  list->next = list->next->next;
  free(p);
  return 1;
}

//不带头节点的链表的尾删

int remove_tail(Node *list){

  if (is_empty(list)){ 
    printf("链表已经为空!\n");
    return 0;
  }
  
  Node *p = list->next;

  while(p->next->next != NULL){
    p = p->next;
  }

  Node *tail = p->next;
  p->next = NULL;
  free(tail);

  return 1;
}

//不带头节点的链表的销毁
int destory_list(Node *list){
  if(list == NULL){
    return 0;
  }

  Node *curred = list->next;
  Node *next_node;

  while(curred != NULL){
    next_node = curred->next;
    free(curred);
    curred = next_node;
  }
  free(list);
  return 1;
}

//循环打印链表
void for_each_link_list(Node *list){
  Node *p = list->next;
  while(p){
    printf("%d ", p->val);
    p = p->next;
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
  Node *list = intial_link_list();
  if(list == NULL){
    return -1;
  }

  add_head(list, 1);
  add_head(list, 2);
  add_head(list, 3);
  add_head(list, 4);

  add_tail(list, 1);
  add_tail(list, 2);
  add_tail(list, 3);
  add_tail(list, 4);

  remove_head(list);
  remove_tail(list);

  //destory_list(list);
  
  for_each_link_list(list);

  return 0;
}
