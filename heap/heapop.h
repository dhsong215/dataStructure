#ifndef HEAPOP_H
#define HEAPOP_H

#define MAX_HEAP 100

typedef char Data;

typedef struct 
{
    Data data;
    int priority;
} HNode;

typedef struct {
    HNode items[MAX_HEAP + 1];
    int num;
} Heap;

// heap control
void InitHeap(Heap *pheap);
bool IsEmpty(Heap *pheap);
bool IsFull(Heap *pheap);

// insert & delete
void Insert(Heap *pheap, Data data, int priority);
Data Delete(Heap *pheap);

// get
int GetParent(int idx);
int GetLChild(int idx);
int GetRChild(int idx);
int GetHighPriorityChild(Heap *pheap, int idx);

#endif
