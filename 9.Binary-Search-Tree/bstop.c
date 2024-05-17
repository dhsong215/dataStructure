#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "bstop.h"

// 노드 생성
BSTNode* CreateNode(Key key) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode)); // 새 노드에 메모리 할당
    if (newNode == NULL) { // 메모리 할당 실패 시
        return NULL; // NULL 반환
    }
    newNode->key = key; // 노드의 키 값을 설정
    newNode->left_child = NULL; // 왼쪽 자식 노드를 NULL로 초기화
    newNode->right_child = NULL; // 오른쪽 자식 노드를 NULL로 초기화
    return newNode; // 생성된 노드의 주소 반환
}

// 노드 제거
void DestroyNode(BSTNode *node) {
    free(node); // 노드에 할당된 메모리 해제
}

// 재귀, 서브트리 왼쪽 오른쪽 확인하며 bst인지 확인
bool Verify(BSTNode *root, int min, int max) {
    if (root != NULL)
    {
        if (root->key <= min || root->key >= max) return false;
        else 
            return
            Verify(root->left_child, min, root->key) && 
            Verify(root->right_child, root->key, max);
    } else return true; // 빈 트리일때
}

// bst에서 대상 node(root)검색
BSTNode* Search(BSTNode* root, Key key) {
    if (root == NULL || root->key == key)
        return root;
    else if 
        (root->key > key) return Search(root->left_child, key);
    else 
        return Search(root->right_child, key);
}

// 반복문 이용한 Search
BSTNode* SearchIterative(BSTNode* root, Key key) {
    BSTNode* cur = root;
    while (cur != NULL) {
        if (cur->key == key) break;
        else if (cur->key > key)
            cur = cur->left_child;
        else
            cur = cur->right_child;
    }
    return cur;
}

// node(root)삽입 재귀 버전
void Insert(BSTNode* root, Key key) {
    if (root->key == key) exit(1); // bst에 같은값 존재 안함
    // 대상이 key보다 크면 왼쪽으로
    else if (root->key > key) {
        if (root->left_child == NULL) 
            root->left_child = CreateNode(key);
        else
            Insert(root->left_child, key);
    }
    // 대상이 key보다 작으면 오른쪽으로
    else {
        if (root->right_child == NULL)
            root->right_child = CreateNode(key);
        else
            Insert(root->right_child, key);
    }
}

// node(root)삭제 반복문 버전
BSTNode* Remove(BSTNode* root, Key key) {
    BSTNode* cur = root, *parent = NULL;

    // key node의 parent 찾기.
    while (cur != NULL && cur->key != key) {
        parent = cur;
        if (cur->key > key)
            cur = cur->left_child;
        else
            cur = cur->right_child;
    }

    // key를 못찾음
    if (cur == NULL) exit(1);

    // CASE1 : 자식노드 없을때
    if (cur->left_child == NULL && cur->right_child == NULL) {
        // cur == root 일때 parent == NULL 
        if (parent != NULL) {
            if (parent->left_child == cur)
                parent->left_child == NULL;
            else 
                parent->right_child == NULL;
        } else
            root = NULL;
    }

    // CASE2 : 자식노드 1개일 때
    else if (cur->left_child == NULL || cur->right_child == NULL) {
        BSTNode* child;

        // cur 자식노드 찾기
        if (cur->left_child != NULL)
            child = cur->left_child;
        else
            child = cur->right_child;
        
        // cur == root 일때
        if (parent != NULL) {
            if (parent->left_child == cur)
                parent->left_child == child;
            else
                parent->right_child == child;
        }
        else
            root = child;
    }

    // CASE3 : 자식노드가 2개 있을때
    else if (cur->left_child == NULL || cur->right_child == NULL) {
        BSTNode* succ_parent = cur, *succ = cur->right_child; // succ: cur의 오른쪽 자식

        // cur 오른쪽 서브트리의 가장 작은(leftmost) 노드(succ) 찾기
        while (succ->left_child != NULL) {
            succ_parent = succ;
            succ = succ->left_child;
        }

        if (succ_parent->right_child == succ)
            succ_parent->right_child = succ->right_child;
        else
            succ_parent->left_child = succ->right_child;
        cur->key = succ->key, 
        cur = succ;
    }
    DestroyNode(cur);

    return root;
}

// inorder traversal
void Traverse(BSTNode* root) {

}

// clear
void ClearTree(BSTNode* root) {

}
