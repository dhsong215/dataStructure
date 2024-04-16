#include <stdio.h>
#include <string.h> // strlen
#include <ctype.h> // type 판별 함수

#include "stackop.h"

// 문자열을 받아 거꾸로 출력하는 함수를 Stack을 이용해 구현
void ReversePrint(char* s, int len) {
  Stack stack;
  Stack* pstack = &stack;
  char ch;

  initStack(pstack);
  for (int i = 0; i < len; i++)
    push(pstack, s[i]);

  while (!isEmpty(pstack)) {
    ch = peek(pstack);
    printf("%c", ch);
    pop(pstack);
  }
  printf("\n");
}

// 균형잡힌 괄호 판단 함수
// (() -> unbalanced -> error(false)
// (()) -> balanced
bool isParanBalanced(char* exp, int len) {
  Stack stack;
  initStack(&stack);

  for (int i = 0; i < len; i++) {
    if (exp[i] == '(')
      push(&stack, exp[i]);
    else if (exp[i] == ')') {
      if (isEmpty(&stack))
        return false;
      else
        pop(&stack);
    }
  }
  
  if (isEmpty(&stack)) {
    printf("true\n");
    return true;
    }
  else {
    printf("false\n");
    return false;
  }
}

// eval postfix notation
int evalPostfix(char* exp, int len) {
  Stack stack;
  int op1, op2;
  initStack(&stack);

  for (int i = 0; i < len; i++) {
    if (isdigit(exp[i]))
      push(&stack, exp[i] - '0'); // 숫자면 스택에 숫자 추가
    else {
      // 기호면 스택에 쌓인 숫자 2개와 연산
      op2 = peek(&stack);
      pop(&stack);
      op1 = peek(&stack);
      pop(&stack);
      switch (exp[i]) {
        case '+':
          push(&stack, op1 + op2);
          break;
        case '-':
          push(&stack, op1 - op2);
          break;
        case '*':
          push(&stack, op1 * op2);
          break;
        case '/':
          push(&stack, op1 / op2);
          break;
        default:
          break;
      }
    }
  }

  return peek(&stack);
}


  int comPriority(char op1, char op2) {
    return 0;
  }

// infix수식 -> postfix수식
void convInfixToPostfix(char* exp, char* convExp, int len) {
  Stack stack;
  int idx = 0;
  initStack(&stack);
  
  for (int i = 1; i < len; i++) {
    if (isdigit(exp[i]))
      convExp[idx++] = exp[i];
    else {
      while (!isEmpty(&stack) && comPriority(peek(&stack), exp[i])) {
        convExp[idx++] = peek(&stack);
        pop(&stack);
      }
      push(&stack, exp[i]);
    }
  }

  while (!isEmpty(&stack)) {
    convExp[idx++] =  peek(&stack);
    pop(&stack);
  }
}


int main() {
  // 1. 문자열을 역순으로 print
  char hello[] = "Hello";
  ReversePrint(hello, strlen(hello));

  // 2. isParanBalanced
  char balancedParan[] = "((()(())))";
  // char unBalancedParan[] = "((()(()))";
  isParanBalanced(balancedParan, strlen(balancedParan));

  // 3. postfix 문자열 수행
  char exp1[] = "23+4*";
  printf("%d\n",evalPostfix(exp1, strlen(exp1))); 

  // 4. infix를 postfix로

  return 0;
}
