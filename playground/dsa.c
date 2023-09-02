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

  while (iterNode->next != NULL) {
    iterNode = iterNode->next;
  }

  iterNode->next = newNode;

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

// [ 5, 6, 24, 0, 5, 10 ]
// 5 < 6
// 6 < 24
// 24 > 0 needs swap??
// 24 > 5 needs swap
//
int bSort(linkedList *list) {
  node *workingNode = list->head;
  node *prevNode = NULL;

  // loop through len
  //  - check if next isn't null
  //  - set workingNode
  //  - if workingNode.val > workingNode.next.val flip two nodes else working
  //  node = next
  while (workingNode != NULL) {
    if (workingNode->next == NULL) {
      break;
    }
    // printf("val 1 %d\nval 2 %d\n", workingNode->val, workingNode->next->val);
    if (workingNode->val > workingNode->next->val) {
      printf("inside of the test case\n");
      if (prevNode == NULL) {
        printf("This branch of it\n");
        list->head = workingNode->next;
        workingNode->next = list->head->next;
        list->head->next = workingNode;
        continue;
      }

      // we have prevNode, and currentNode
      // We have found that current node is greater than the next val so we need
      // to swap them we need to set prevNode->next to workingNode->next we then
      // need to set prevNode->next->next to working node, but first we need to
      // set that value to workingNode->next

      // Move workingNode out of the tree by setting workingNode->next to
      // prevNode->next
      prevNode->next = workingNode->next;
      prevNode = workingNode->next;
      workingNode->next = prevNode->next;
      prevNode->next = workingNode;
    }

    printf("got here\n");
    workingNode = workingNode->next;
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
  add(ll, 69);
  add(ll, 76);
  add(ll, 45);
  add(ll, 62);
  add(ll, 4);
  add(ll, 0);
  add(ll, 1);

  node *iterNode = linkedList.head;
  while (iterNode != NULL) {
    printf("Ran val: %d\n", iterNode->val);
    iterNode = iterNode->next;
  }

  printf("Sort\n");
  bSort(ll);
  printf("After sort\n");

  iterNode = linkedList.head;
  while (iterNode != NULL) {
    printf("Ran val: %d\n", iterNode->val);
    iterNode = iterNode->next;
  }
  free(iterNode);

  freeList(ll);
}
