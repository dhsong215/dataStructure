#include <stdlib.h>
#include "stackop.h"

// Stack 초기화(Stack 비우기)
void initStack(Stack *pstack) {
  pstack->top = -1;
}

// Stack이 차있는지 확인
bool isFull(Stack *pstack) {
  return pstack->top == MAX_STACK -1;
}

// Stack이 비어있는지 확인
bool isEmpty(Stack *pstack) {
  return pstack->top == -1;
}

// top에 있는 데이터 읽음
Data peek(Stack *pstack) {
  if (isEmpty(pstack)) exit(1); // 비어있는 스택에는 top이 없으므로 exit
  return pstack->items[pstack->top];
}

// push 구현
void push(Stack *pstack, Data item) {
  if (isFull(pstack)) exit(1); // 스택이 모두 차면 push 안됨
  pstack->items[++(pstack->top)] = item;
}

// pop 구현
void pop(Stack *pstack) {
  if (isEmpty(pstack)) exit(1); // 스택이 비어있으면 pop 못함
  --(pstack->top); // top의 위치만 바꿔준다.
}
