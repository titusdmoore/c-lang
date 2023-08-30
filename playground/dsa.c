#include <stdio.h>

typedef struct Node {
  int val;
  struct Node *next;
} node;

typedef struct LinkedList {
  node *head;
  int len;
} linkedList;

int add(linkedList *list, int val) {
  struct Node newNode;
  newNode.val = val;
  printf("newNode val %d\nval: %d \n", newNode.val, val);
  newNode.next = NULL;

  list->len++;

  if (list->head == NULL) {
    list->head = &newNode;
    return 0;
  }

  node *iterNode = list->head;

  if (iterNode->next != NULL) {
    while (iterNode->next != NULL) {
      iterNode = iterNode->next;
    }
  }

  iterNode->next = &newNode;
  printf("this: %d\n", iterNode->next->val);

  return 0;
}

int bSort(linkedList *list) {
  node *workingNode = list->head;

  // loop through len
  //  - check if next isn't null
  //  - set workingNode
  //  - if workingNode.val > workingNode.next.val flip two nodes else working
  //  node = next

  for (int i = 0; i < list->len; i++) {
    if (workingNode->val > workingNode->next->val) {
      node *nextNode = workingNode->next;
    }
  }

  return 0;
}

int main() {
  linkedList *ll, linkedList;
  linkedList.len = 0;
  linkedList.head = NULL;
  ll = &linkedList;

  add(ll, 8);
  printf("%d\n", linkedList.len);
  printf("Val %d\n", ll->head->val);
  add(ll, 69);
  printf("%d\n", linkedList.len);
  add(ll, 76);
  printf("%d\n", linkedList.len);
  add(ll, 45);
  printf("%d\n", linkedList.len);
  add(ll, 62);
  printf("%d\n", linkedList.len);
  add(ll, 4);
  printf("%d\n", linkedList.len);
  add(ll, 0);
  printf("%d\n", linkedList.len);
  printf("%d\n", ll->head->next->val);
  add(ll, 1);
  printf("%d\n", linkedList.len);
  printf("%d\n", ll->head->next->val);
}
