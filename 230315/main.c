#include <stdio.h>
#include <malloc.h>

#define SAFE_FREE(p) do{if(p){free(p);(p) = NULL;}} while(0)

// Structure
// Structure Padding
struct SExample {
	// Structure Member Veriable
	char c;

	double d;

	int i;

	// void Func(){}
	// 구조체내 함수 C에서는 불가 C++부터 가능
};

void StructureExample() {
	struct SExample example; //= { 1,10,100,2.3 };
	//example.i = 10;
	//example.f = 3.14f;
	//printf("example Adress: (%p)\n", &example);
	//printf("example.i: %d (%p)\n", example.i, &example.i);
	//printf("example.ii: (%p)\n", &example.ii);
	//printf("example.f: %f (%p)\n", example.f, &example.f);

	printf("SExample Size: %zd byte\n", sizeof(struct SExample));
}




typedef struct _SNode {
	int data;
	struct SNode* pNext;
} SNode;
//typedef struct Snode Node;

void AddNode(SNode* _pHead, int _data);
void PrintAll(SNode* _pHead);
void RemoveAll(SNode* _pHead);

void InsertNode(SNode* _pHead, int _data, int _index);

// 과제
// 현재 몇개의 노드를 가지고있는지 반환해주는 함수
int Count(SNode* _pHead);
// 가장 앞에 데이터를 삽입하는 함수
void AddFront(SNode* _pHead, int _data);
// 가장 뒤에 데이터를 삽입하는 함수
void AddBack(SNode* _pHead, int _data);
// 특정 index에 있는 노드를 찾는 함수
SNode* GetNodeWithIndex(SNode* _pHead, int _index);
// 특정 data를 가지고있는 노드를 찾는 함수
SNode* GetNodeWithData(SNode* _pHead, int _data);
// 특정 인덱스의 노드를 삭제하는 함수
void RemoveAt(SNode* _pHead, int _index);
// 특정 노트를 삭제하는 함수
void Remove(SNode* _pHead, SNode* _delNode);

// Single Linked List
void main() {
	SNode* pNode = (SNode*)malloc(sizeof(SNode));
	if (pNode != NULL) {
		pNode->data = 10;
		SAFE_FREE(pNode);
	}


	SNode head = { NULL };

	PrintAll(&head);

	AddNode(&head, 100);
	AddFront(&head, 11);
	AddBack(&head, 22);
	Count(&head);
	RemoveAt(&head, 0);
	RemoveAt(&head, 3);
	PrintAll(&head);
	GetNodeWithIndex(&head, 0);
	GetNodeWithData(&head, 11);
	GetNodeWithData(&head, 12);
	RemoveAll(&head);
	GetNodeWithIndex(&head, 1);
	GetNodeWithData(&head, 1);

	for (int i = 0; i < 5; ++i)
		AddNode(&head, 10 * (i + 1));
	AddFront(&head, 11);
	AddBack(&head, 22);
	RemoveAt(&head, 5);
	PrintAll(&head);
	GetNodeWithIndex(&head, 5);
	GetNodeWithData(&head, 40);
	GetNodeWithData(&head, 41);


	InsertNode(&head, 77, 14);

	PrintAll(&head);
	Count(&head);


	RemoveAll(&head);
	PrintAll(&head);
}

void AddNode(SNode* _pHead, int _data)
{
	// STL: Interator
	SNode* pCurNode = _pHead;
	while (pCurNode->pNext != NULL) {
		pCurNode = pCurNode->pNext;
	}

	SNode* pNewNode = (SNode*)malloc(sizeof(SNode));
	if (pNewNode != NULL) {
		pNewNode->data = _data;
		pNewNode->pNext = NULL;

		pCurNode->pNext = pNewNode;

	}
}

void PrintAll(SNode* _pHead)
{
	SNode* pCurNode = _pHead->pNext;
	if (pCurNode == NULL) {
		printf("List is empty!\n");
		return;
	}
	do {
		printf("%d - ", pCurNode->data);
		pCurNode = pCurNode->pNext;
	} while (pCurNode != NULL);

	//	printf("(%d\n)", )
	printf("\n");
}

void RemoveAll(SNode* _pHead)
{
	if (_pHead == NULL || _pHead->pNext == NULL)
		return;

	SNode* pCurNode = _pHead->pNext;
	SNode* pDelNode = _pHead->pNext;

	do {
		pCurNode = pDelNode->pNext;
		printf("pDelNode data: %d\n", pDelNode->data);
		SAFE_FREE(pDelNode);
		pDelNode = pCurNode;
	} while (pCurNode != NULL);

	_pHead->pNext = NULL;

}

void InsertNode(SNode* _pHead, int _data, int _index)
{
	if (_pHead == NULL) return;
	if (_index < 0) _index *= -1;

	SNode* pCurNode = _pHead;
	int curIdx = -1;
	while (pCurNode != NULL) {
		if (_index == 0 || curIdx + 1 == _index) break;

		pCurNode = pCurNode->pNext;
		++curIdx;


	}

	if (pCurNode == NULL) {
		AddNode(_pHead, _data);
		return;
	}

	SNode* pCurNextNode = pCurNode->pNext;
	SNode* pNewNode = (SNode*)malloc(sizeof(SNode));


	pNewNode->data = _data;
	pCurNode->pNext = pNewNode;
	pNewNode->pNext = pCurNextNode;

	printf("%d: %d\n", _index, _data);
}

int Count(SNode* _pHead)
{
	int nodeCount = 0;
	SNode* pCurNode = _pHead->pNext;

	if (pCurNode == NULL) {
		printf("List is empty!");
		return nodeCount;
	}
	while (pCurNode != NULL) {
		pCurNode = pCurNode->pNext;
		++nodeCount;
	}
	printf("nodeCount: %d\n", nodeCount);
	return nodeCount;

}

void AddFront(SNode* _pHead, int _data)
{
	SNode* pCurNode = _pHead;

	SNode* pNextNode = _pHead->pNext;

	SNode* pNewNode = (SNode*)malloc(sizeof(SNode));

	pNewNode->data = _data;
	pNewNode->pNext = pNextNode->pNext;
	pCurNode->pNext = pNewNode;
}

void AddBack(SNode* _pHead, int _data)
{
	SNode* pCurNode = _pHead;

	while (pCurNode->pNext != NULL) {
		pCurNode = pCurNode->pNext;

	}

	SNode* pNewNode = (SNode*)malloc(sizeof(SNode));

	pNewNode->data = _data;
	pNewNode->pNext = NULL;
	pCurNode->pNext = pNewNode;
}

SNode* GetNodeWithIndex(SNode* _pHead, int _index)
{
	if (_pHead->pNext == NULL) {
		printf("List is empty! - GetNodeWithIndex\n");
		return;
	}

	SNode* pCurNode = _pHead->pNext;
	int curIdx = 0;

	if (_index < 0) _index *= -1;

	while (pCurNode != NULL) {

		if (curIdx != _index) {
			pCurNode = pCurNode->pNext;
			++curIdx;
		}
		else {
			printf("index %d: NodeData %d\n", curIdx, pCurNode->data);
			return;
		}

	}
	printf("Index %d is not exist!\n", _index);

}


SNode* GetNodeWithData(SNode* _pHead, int _data)
{
	if (_pHead->pNext == NULL) {
		printf("List is empty! - GetNodeWithData\n");
		return;
	}

	SNode* pCurNode = _pHead->pNext;

	int curIdx = 0;
	int targetData = pCurNode->data;


	while (targetData != _data) {
		pCurNode = pCurNode->pNext;

		if (pCurNode != NULL) {
			targetData = pCurNode->data;
			++curIdx;
		}
		else {
			printf("NodeData %d: index %d\n", targetData, curIdx);
			return;
		}
	}
	printf("Data %d is not exist!\n", _data);
}

void RemoveAt(SNode* _pHead, int _index)
{
	if (_pHead->pNext == NULL) {
		printf("List is empty! - GetNodeWithIndex\n");
		return;
	}

	SNode* pCurNode = _pHead->pNext;
	SNode* pPreNode = _pHead->pNext;
	SNode* pBackupNode = _pHead->pNext;

	int curIdx = 0;

	if (_index < 0) _index *= -1;

	while (curIdx != _index) {
		pCurNode = pCurNode->pNext;
		if (pCurNode != NULL) {
			pPreNode = pCurNode;
			++curIdx;
		}
		else {
			pBackupNode = pPreNode;
			printf("RemoveAt Index %d Node data: %d\n", curIdx, pPreNode->data);
			SAFE_FREE(pCurNode);
			pPreNode->pNext = pBackupNode;
			return;
		}

	}
	printf("Index %d is not exist!\n", _index);
}
