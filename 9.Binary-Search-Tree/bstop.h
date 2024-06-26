#ifndef BSTOP_H
#define BSTOP_H

#define INT_MIN 0
#define INT_MAX 100

typedef int Key;

typedef struct _BSTNode
{
    Key key;
    struct _BSTNode* left_child;
    struct _BSTNode* right_child;
} BSTNode;

// 노드 생성
BSTNode* CreateNode(Key key);
// 노드 제거
void DestroyNode(BSTNode *node);

// 재귀, 서브트리 왼쪽 오른쪽 확인하며 bst인지 확인
bool Verify(BSTNode *root, int min, int max);
// bst에서 대상 node(root)검색
BSTNode* Search(BSTNode* root, Key key);
// node(root)삽입
void Insert(BSTNode* root, Key key);
// node(root)삭제
BSTNode* Remove(BSTNode* node, Key key);

// inorder traversal
void Traverse(BSTNode* root);
// clear
void ClearTree(BSTNode* root);

#endif
