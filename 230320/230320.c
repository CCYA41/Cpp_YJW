#include <stdio.h>
#include <malloc.h>


typedef struct _SNode
{
	int data;

	struct _SNode* pLeft;
	struct _SNode* pRight;
} SNode;

SNode* g_pHead = NULL;

void BuildTree(int* _pArr, int _len);
void AddNode(SNode* _pCompareNode, SNode* _pNewNode);
void PrintAll();
void PrintRecursive(SNode* _pCurNode);
void RemoveAll();
void RemoveRecursive(SNode* _pCurNode);

// 과제
// 트리의 깊이
int Count();
// 트리에 있는 데이터를 찾기
SNode* GetNodeWithData(int _data);
//트리의 레벨 -> 입력된 트리의 깊이에 해당하는 트리를 출력
void PrintWithLevel(int _lv);
// 입력한 값의 트리를 삭제
void RemoveWithData(int _data);



// Graph
// Hash-Table
// Binary-Tree
// Quad-Tree
// Oct-Tree

void main() {
	int arr[] = { 8, 5, 10, 2, 15, 31, 25, 19 };

	BuildTree(arr, sizeof(arr) / sizeof(arr[0]));

	PrintAll();

	RemoveAll();
}

void BuildTree(int* _pArr, int _len) {
	if (_pArr == NULL || _len < 1)
		return;

	int centerIdx = _len >> 1;

	// if(g_pHead == NULL;) return;
	g_pHead = (SNode*)malloc(sizeof(SNode));
	g_pHead->data = _pArr[centerIdx];
	g_pHead->pLeft = NULL;
	g_pHead->pRight = NULL;

	for (int i = 0; i < _len; ++i) {
		if (i == centerIdx) continue;

		SNode* pNewNode = (SNode*)malloc(sizeof(SNode));
		pNewNode->data = _pArr[i];
		pNewNode->pLeft = NULL;
		pNewNode->pRight = NULL;

		printf("[Data: %d\n", pNewNode->data);

		AddNode(g_pHead, pNewNode);
	}
}

void AddNode(SNode* _pCompareNode, SNode* _pNewNode) {
	if (_pCompareNode == NULL || _pNewNode == NULL) {
		printf("Node is NULL!\n");
		return;
	}
	if (_pNewNode->data < _pCompareNode->data) {
		if (_pCompareNode->pLeft == NULL) {
			_pCompareNode->pLeft = _pNewNode;
			printf("Add Left: %d\n", _pNewNode->data);

			return;

		}
		else {
			printf("Move Left: %d -> %d\n", _pCompareNode->data, _pCompareNode->pLeft);
			AddNode(_pCompareNode->pLeft, _pNewNode);

		}
	}
	else {
		if (_pCompareNode->pRight == NULL) {
			_pCompareNode->pRight = _pNewNode;
			printf("Add Right: %d\n", _pNewNode->data);
			return;

		}
		else {
			printf("Move Right: %d -> %d", _pCompareNode->data, _pCompareNode->pRight);
			AddNode(_pCompareNode->pRight, _pNewNode);

		}

	}
}

void PrintAll() {
	if (g_pHead == NULL) {
		printf("Tree is empty!\n");
		return;
	}

	PrintRecursive(g_pHead);


	//printf("(%d) \n", Count());
}

void PrintRecursive(SNode* _pCurNode) {
	if (_pCurNode == NULL) return;

	if (_pCurNode->pLeft != NULL) {
		PrintRecursive(_pCurNode->pLeft);
	}

	printf("%d - ", _pCurNode->data);

	if (_pCurNode->pRight != NULL) {
		PrintRecursive(_pCurNode->pRight);
	}
}

void RemoveAll() {
	if (g_pHead == NULL) return;

	RemoveRecursive(g_pHead);

	g_pHead = NULL;
}

void RemoveRecursive(SNode* _pCurNode) {
	if (_pCurNode->pLeft != NULL) {
		RemoveRecursive(_pCurNode->pLeft);
	}

	if (_pCurNode->pRight != NULL) {
		RemoveRecursive(_pCurNode->pRight);
	}

	printf("Del Node: %d\n", _pCurNode->data);

	if (_pCurNode != NULL) {
		free(_pCurNode);
		_pCurNode = NULL;
	}


}

//
//#include <stdio.h>
//#include <malloc.h>
//
//typedef struct _SNode
//{
//	int data;
//
//	struct _SNode* pLeft;
//	struct _SNode* pRight;
//} SNode;
//
//SNode* g_pHead = NULL;
//
//void BuildTree(int* _pArr, int _len);
//void AddNode(SNode* _pCompareNode,
//	SNode* _pNewNode);
//void PrintAll();
//void PrintRecursive(SNode* _pCurNode);
//void RemoveAll();
//void RemoveRecursive(SNode* _pCurNode);
//
//// 과제
//int Count();
//SNode* GetNodeWithData(int _data);
//void PrintWithLevel(int _lv);
//void RemoveWithData(int _data);
//
//// Graph
//// Hash-Table
//// Binary-Tree
//// Quad-Tree, Oc-Tree
//void main()
//{
//	int arr[] =
//	{ 8, 5, 10, 2, 15, 31, 25, 19 };
//
//	BuildTree(
//		arr,
//		sizeof(arr) / sizeof(arr[0]));
//	PrintAll();
//	RemoveAll();
//}
//
//void BuildTree(int* _pArr, int _len)
//{
//	if (_pArr == NULL ||
//		_len < 1) return;
//
//	int centerIdx = _len >> 1;
//
//	g_pHead = (SNode*)malloc(sizeof(SNode));
//	g_pHead->data = _pArr[centerIdx];
//	g_pHead->pLeft = NULL;
//	g_pHead->pRight = NULL;
//
//	for (int i = 0; i < _len; ++i) {
//		if (i == centerIdx) continue;
//
//		SNode* pNewNode =
//			(SNode*)malloc(sizeof(SNode));
//		pNewNode->data = _pArr[i];
//		pNewNode->pLeft = NULL;
//		pNewNode->pRight = NULL;
//
//		printf("[Data: %d]\n", pNewNode->data);
//		AddNode(g_pHead, pNewNode);
//	}
//}
//
//void AddNode(SNode* _pCompareNode,
//	SNode* _pNewNode)
//{
//	if (_pCompareNode == NULL ||
//		_pNewNode == NULL) {
//		printf("Node is NULL!\n");
//		return;
//	}
//
//	if (_pNewNode->data <
//		_pCompareNode->data) {
//		if (_pCompareNode->pLeft == NULL) {
//			_pCompareNode->pLeft =
//				_pNewNode;
//			printf("Add Left: %d\n",
//				_pNewNode->data);
//			return;
//		}
//		else {
//			printf("Move Left: %d -> %p\n",
//				_pCompareNode->data,
//				_pCompareNode->pLeft);
//			AddNode(
//				_pCompareNode->pLeft,
//				_pNewNode);
//		}
//	}
//	else {
//		if (_pCompareNode->pRight == NULL) {
//			_pCompareNode->pRight =
//				_pNewNode;
//			printf("Add Right: %d\n",
//				_pNewNode->data);
//			return;
//		}
//		else {
//			printf("Move Right: %d -> %p\n",
//				_pCompareNode->data,
//				_pCompareNode->pRight);
//			AddNode(
//				_pCompareNode->pRight,
//				_pNewNode);
//		}
//	}
//}
//
//void PrintAll()
//{
//	if (g_pHead == NULL) {
//		printf("Tree is empty!\b");
//		return;
//	}
//
//	PrintRecursive(g_pHead);
//
//	//printf("(%d)\n", Count());
//}
//
//void PrintRecursive(SNode* _pCurNode)
//{
//	if (_pCurNode == NULL) return;
//
//	if (_pCurNode->pLeft != NULL)
//		PrintRecursive(_pCurNode->pLeft);
//
//	printf("%d - ", _pCurNode->data);
//
//	if (_pCurNode->pRight != NULL)
//		PrintRecursive(_pCurNode->pRight);
//}
//
//void RemoveAll()
//{
//	if (g_pHead == NULL) return;
//
//	RemoveRecursive(g_pHead);
//
//	g_pHead = NULL;
//}
//
//void RemoveRecursive(SNode* _pCurNode)
//{
//	if (_pCurNode->pLeft != NULL)
//		RemoveRecursive(_pCurNode->pLeft);
//
//	if (_pCurNode->pRight != NULL)
//		RemoveRecursive(_pCurNode->pRight);
//
//	printf("Del Node: %d\n",
//		_pCurNode->data);
//	if (_pCurNode != NULL) {
//		free(_pCurNode);
//		_pCurNode = NULL;
//	}
//}