#ifndef QUEUEOP_H
#define QUEUEOP_H
#include <stdbool.h>

#define MAX_QUEUE 100

typedef int Data;

typedef struct 
{
  Data items[MAX_QUEUE];
  int front, rear;
} Queue;

// initialize queue
void initQueue(Queue *pqueue);

bool isFull(Queue *pqueue);
bool isEmpty(Queue *pqueue);

// front 읽어오기
Data peek(Queue *pqueue);
// rear 추가
void enQueue(Queue *pqueue, Data item);
// front 삭제
void deQueue(Queue *pqueue);

#endif