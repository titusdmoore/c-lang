#include <stdio.h>
#include <string.h>

int main() {
  int age;
  char name[25];

  printf("What is your name > ");
  fgets(name, 25, stdin);

  printf("How old are you > ");
  scanf("%d", &age);

  name[strlen(name) - 1] = '\0';

  printf("You name is: %s\n", name);
  printf("You are %d years old!", age);

  return 0;
}
