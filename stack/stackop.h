#ifndef STACKOP_H
#define STACKOP_H

#include <stdlib.h>
#define MAX_STACK 100

typedef enum { false, true } bool;
typedef int Data;

typedef struct 
{
  Data items[MAX_STACK];
  int top;
} Stack;

void initStack(Stack *pstack);
bool isFull(Stack *pstack);
bool isEmpty(Stack *pstack);
Data peek(Stack *pstack);
void push(Stack *pstack, Data item);
void pop(Stack *pstack);

#endif