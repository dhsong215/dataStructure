#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "heapop.h"

// heap비우기
void InitHeap(Heap *pheap) {
    pheap->num = 0;
}
// 비어있는지 확인
bool IsEmpty(Heap *pheap) {
    return pheap->num == 0;
}
// 꽉 찼는지 확인
bool IsFull(Heap *pheap) {
    return pheap->num == MAX_HEAP;
}

// 노드 삽입
void Insert(Heap *pheap, Data data, int priority) {
    HNode newNode;
    // 새 노드를 leaf rightmost에 넣음(complete binary tree형태 유지)
    int idx = pheap->num + 1;

    if (IsFull(pheap)) exit(1);

    while (idx > 1) {
        int parentIdx = GetParent(idx);
        if (priority > pheap->items[parentIdx].priority) { // newNode(예정)의 priority가 부모보다 높으면
            pheap->items[idx] = pheap->items[parentIdx]; // 부모노드를 새로 들어온 노드 자리에 복사
            idx = parentIdx;
        } else break;
    }

    // break 하고 나온 idx에 새 노드 집어넣고 끗
    newNode.data = data;
    newNode.priority = priority;

    pheap->items[idx] = newNode;
    pheap->num++;
}
// 노드 삭제
Data Delete(Heap *pheap) {
    Data max = pheap->items[1].data; // root의 data
    HNode last = pheap->items[pheap->num];
    int parent = 1, child;

    // 말단노드(last)를 root로 올렸다 가정하고 자식노드와 비교 반복
    // 자식이 존재하면 계속 반복
    while (child = GetHighPriorityChild(pheap, parent)) {
        if (last.priority < pheap->items[child].priority) {
            pheap->items[parent] = pheap->items[child];
            parent = child;
        }
        // 자식의 우선순위가 더 낮으면 종료
        else break;
    }

    pheap->items[parent] = last;
    pheap->num--;

    return max;
}

int GetParent(int idx) {
    return idx / 2;
}
int GetLChild(int idx) {
    return idx * 2;
}
int GetRChild(int idx) {
    return idx * 2 + 1;
}
// 두 자식 노드 중에 더 높은priority child get
int GetHighPriorityChild(Heap *pheap, int idx) {
    if (GetLChild(idx) > pheap->num)
        return 0; // 자식 없으면 return 0;
    else if (GetLChild(idx) == pheap->num)
        return GetLChild(idx); // 왼쪽 노드밖에 없으면 왼쪽 return
    else {
        int left = GetLChild(idx), right = GetRChild(idx);
        // 둘 다 있으면 비교해서 return
        if (pheap->items[left].priority > pheap->items[right].priority)
            return left;
        else
            return right;
    }
}
