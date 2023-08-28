#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isNumeric(char test) {
  if (test >= 48 && test <= 57)
    return 1;

  return 0;
}

int lexInput(char input[], char *tokens) {
  char *ptr = input;
  int tokenHead = 0;

  while (*ptr != '\0') {
    // Check if char in *ptr is numeric or a valid operation
    if (isNumeric(*ptr) || *ptr == '+' || *ptr == '-' || *ptr == '/' ||
        *ptr == '*') {

      // Add valid token to tokens arr
      tokens[tokenHead] = *ptr;
      tokenHead++;
    } else {
      if (*ptr != ' ' && *ptr != '\n')
        return 1;
    }

    ptr++;
  }
  // Needed to be seen as valid string
  tokens[tokenHead] = '\0';

  return 0;
}

int sliceArrToInt(char input[], int start, int end, long long *outVal) {
  char *slice;
  int sliceLen = (end - start) + 2;
  slice = calloc(sliceLen, sizeof(char));

  if (slice == NULL) {
    fprintf(stderr, "Unable to allocate space new slice!\n");
    return 1;
  }

  for (int i = start; i < end + 1; i++) {
    slice[i - start] = input[i];
  }

  *outVal = atoi(slice);

  free(slice);
  return 0;
}

int parseTokens(char tokens[], int maxLen, long long **val) {
  // This is a tempory implementation that I can iterate on. I don't want to go
  // home with it not functioning Current only supports x <OPERATION> y
  long long *numbers;
  char *operations;
  int numbersPointer = 0;
  int operationsPointer = 0;

  numbers = calloc(maxLen, sizeof(long long));
  int numbersCount = 0;
  operations = calloc(maxLen, sizeof(char));

  char *token = tokens;
  int anchor = 0;
  int head = 0;

  while (*token != '\0') {
    if (isNumeric(*token)) {
      head++;
      token++;
      continue;
    }

    operations[operationsPointer] = *token;
    operationsPointer++;
    long long temp;
    sliceArrToInt(tokens, anchor, head - 1, &temp);
    head += 1;
    anchor = head;
    numbers[numbersPointer] = temp;
    numbersCount = numbersPointer;
    numbersPointer++;
    token++;
  }

  // This means that the loop finished on a digit, and needs to be added
  if (anchor != head) {
    long long temp;
    sliceArrToInt(tokens, anchor, head - 1, &temp);
    numbers[numbersPointer] = temp;
    numbersCount++;
  }

  int numbersIter = 1;
  int operationsIter = 0;
  long long out = numbers[0];

  while (numbersIter <= numbersCount) {
    switch (operations[operationsIter]) {
    case '+':
      out = out + numbers[numbersIter];
      break;
    case '-':
      out = out - numbers[numbersIter];
      break;
    case '*':
      out = out * numbers[numbersIter];
      break;
    case '/':
      out = out / numbers[numbersIter];
      break;
    }

    numbersIter++;
    operationsIter++;
  }

  **val = out;

  // Clean up
  free(numbers);
  free(operations);

  return 0;
}

int strLen(const char *str) {
  const char *s;
  for (s = str; *s; ++s)
    ;
  return (s - str);
}

int calcInput(char input[], long long *val) {
  char *tokens;
  int tokensLen = strLen(input);

  tokens = calloc(tokensLen, sizeof(char));

  if (tokens == NULL) {
    fprintf(stderr, "Unable to allocate tokens array!");
    return 1;
  }

  // call lexInput and parseTokens
  int lexResult = lexInput(input, tokens);
  parseTokens(tokens, tokensLen, &val);

  free(tokens);

  return 0;
}

void calcLoop() {
  int exit = 0;

  printf("Welcome to my awesome calculator! To exit type quit.");

  while (exit == 0) {
    char input[30];

    printf("\n> ");
    fgets(input, sizeof(input), stdin);

    if (strcmp("quit\n", input) == 0) {
      exit = 1;
      break;
    }

    long long val;
    calcInput(input, &val);

    printf("Result %lld\n", val);
  }
}

int main() { calcLoop(); }
