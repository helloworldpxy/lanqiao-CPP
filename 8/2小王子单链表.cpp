#include <iostream>
using namespace std;

typedef struct Node {
  int data;
  struct Node* next;
} Node, *LinkList;

//  查找重新排序  
LinkList secList(LinkList L, int num) {
  Node* p = L;
  Node* q;
  while (p->next) {
    if (p->next->data == num) {
      // 删除结点
      q = p->next;
      p->next = q->next;
      delete q;
      // 在头结点插入
      Node* s = new Node;
      s->data = num;
      s->next = L->next;
      L->next = s;
      return L;
    }
    p = p->next;
  }
  return L;
}
//  输出链表
void printList (LinkList L) {
  Node* p = L;
  while (p->next) {
    p = p->next;
    printf("%4d", p->data);

  }
  printf("\n");
  
}

int main()
{
  // 初始化链表
  LinkList L;
  Node* s;
  s = new Node;
  s->next = NULL;
  L = s;

  // 给链表赋值
  Node* p = L;
  for (int i=1; i<=10; i++) {
    s = new Node;
    s->data = i;
    s->next = NULL;
    p->next = s;
    p = p->next;
  }

  // 小王子要排序的次数
  int n = 0;
  int m = 0;
  scanf("%d", &n);
  while (n>0) {
    scanf("%d",&m);
    L = secList(L, m);
    printList(L);
    n--;
  }

  // 清除链表
  while (L != NULL ) {
    p = L;
    L = L->next;
    delete p;
  }
  return 0;
}
