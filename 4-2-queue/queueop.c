#include "queueop.h"
#include <stdlib.h>

void initQueue(Queue *pqueue) {
  pqueue->front = pqueue->rear = 0;
}

bool isFull(Queue *pqueue) {
  return (pqueue->front == (pqueue->rear + 1) % MAX_QUEUE); // rear 한칸은 필수적으로 비워져 있어야 한다.
}
bool isEmpty(Queue *pqueue) {
  return pqueue->front == pqueue->rear;
}

// front 읽어오기
Data peek(Queue *pqueue) {
  if (isEmpty(pqueue))
    exit(1);
  return pqueue->items[pqueue->front];
}
// rear 추가
void enQueue(Queue *pqueue, Data item) {
  if (isEmpty(pqueue))
    exit(1);
  pqueue->items[pqueue->rear] = item;
  pqueue->rear = (pqueue->rear + 1) % MAX_QUEUE;
}
// front 삭제
void deQueue(Queue *pqueue) {
  if (isEmpty(pqueue))
    exit(1);
  pqueue->front = (pqueue->front + 1) % MAX_QUEUE;
}
