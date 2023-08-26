#include <stdio.h>

int main() {
  int a;
  int *c;

  c = &a;
  *c = 7;

  printf("%d\n", *c);

  return 0;
}
