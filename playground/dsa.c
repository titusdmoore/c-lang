#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node *next;
} node;

typedef struct LinkedList {
  node *head;
  int len;
} linkedList;

node *add(linkedList *list, int val) {
  node *newNode;
  newNode = malloc(sizeof(struct Node));
  newNode->val = val;
  newNode->next = NULL;

  list->len++;

  if (list->head == NULL) {
    list->head = newNode;
    return 0;
  }

  node *iterNode = list->head;
  printf("test %d\n", iterNode->next != NULL);

  while (iterNode->next != NULL) {
    iterNode = iterNode->next;
    printf("I am running oh so very hard\n");
  }

  iterNode->next = newNode;
  printf("this: %d\n", iterNode->next->val);

  return newNode;
}

int freeList(linkedList *list) {
  node *iterNode = list->head;

  if (iterNode == NULL) {
    return 0;
  }

  while (iterNode->next != NULL) {
    node *nextNode = iterNode->next;
    free(iterNode);
    iterNode = nextNode;
  }

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

// TODO implement freeList which runs free on every node

int main() {
  linkedList *ll, linkedList;
  linkedList.len = 0;
  linkedList.head = NULL;
  ll = &linkedList;

  // Create nodes
  // refactor to pass nodes. or you could just return a node pointer ot add

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

  freeList(ll);
}
