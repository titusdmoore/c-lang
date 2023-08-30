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

  return 0;
}

int bSort(linkedList *list) {
  node *maxNode = list->head;
  node *iterNode = maxNode;

  for (int i = 0; i < list->len; i++) {
    if (iterNode->next != NULL) {
      break;
    }

    iterNode = iterNode->next;

    if (maxNode->val > iterNode->val) {
      maxNode = iterNode;
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
  add(ll, 6);
  add(ll, 6);
  add(ll, 6);
  add(ll, 6);
  add(ll, 6);
  add(ll, 6);
  add(ll, 1);
  printf("%d\n", ll->head->next->val);
}
