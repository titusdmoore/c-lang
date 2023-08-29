#include <stdio.h>

struct Node {
  int val;
  struct Node *next;
};

struct LinkedList {
  struct Node *head;
  int len;
};

int add(struct LinkedList *list, int val) {
  struct Node newNode;
  newNode.val = val;
  newNode.next = NULL;

  struct Node *iterNode = list->head;

  while (iterNode->next != NULL) {
    *iterNode = *iterNode->next;
  }

  return 0;
}

int main() {}
