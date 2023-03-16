
#include <stdio.h>
#//include <stdlib.h>	
#include <malloc.h>

#define SAFE_FREE(p)\
do{\
	if (p) {\
		free(p);\
		 (p) = NULL;\
		}\
} while (0)

//
//void MallocExample() {
//
//	// size_t
//	// Dynamic Memory Allocate
//	int arrLen = 10;
//	int* pArr = (int*)malloc(sizeof(int) * arrLen);
//	if (pArr == NULL) {
//		printf("malloc Failed!\n");
//		return  -1;
//	}
//	//int arr[5];
//	//arr[100] = 5;
//	//pArr[0] = 10;
//	//*(pArr + 1) = 20;
//	//printf("arr[100: %d\n", arr[10]);
//
//	//*(pArr + 100) = 100;
//	//printf("*(pArr +100): %d\n", *(pArr + 100));
//
//
//	if (pArr != NULL) {
//		SAFE_FREE(pArr);
//		pArr = NULL;
//	}
//
//
//	//SAFE_FREE(pArr);
//	//pArr = NULL;
//	//SAFE_FREE(pArr);
//
//	if (5 > 3) {
//		SAFE_FREE(pArr);
//	}
//	//if (pArr) {
//	//	free)[Arr_;
//	//	pArr = NULL;
//	//}
//
//
//	else printf("test!\n");
//}

// _size: 바이트 단위 메모리 크기 전달
void CreateArray(int** _pArr, int _size);
void Add(int** _pArr, int* _pArrLen, int* _pIndex, int _data);
void Print(int* _pArr, int _index);

// Vector
// ArrayList
void main()
{
	// 동적할당 배열
	// 배열의 크기를 벗어나는 배열이 들어오면 가변적으로 변경되어야함
	int* pArr = NULL;
	int arrLen = 5;
	int index = 0;
	CreateArray(&pArr, sizeof(int) * arrLen);

	for (int i = 0; i < 4; ++i) {
		Add(&pArr, &arrLen, &index, i + 1);
		Print(pArr, index);
	}

	SAFE_FREE(pArr);

}

void CreateArray(int** _pArr, size_t _size)
{
	SAFE_FREE(*_pArr);

	*_pArr = (int*)malloc(_size);
	if (*_pArr == NULL)
		printf("CreateArray Failed!\n");
}

void Add(int** _pArr, int* _pArrLen, int* _pIndex, int _data)
{
	// 배열이 가득 찼는지 검사
	if (*_pIndex = *_pArrLen) {
		// 늘어난 길이 만큼 새로운 배열 할당
		int* pExtends = NULL;
		// * 2 = << 1;
		CreateArray(&pExtends, sizeof(int)*((*_pArrLen) * 2));

		// 복사
		for (int i = 0; i < (*_pArrLen); ++i) {
			pExtends[i] = (*_pArr)[i];

			//길이 바꾸기
			*_pArrLen *= 2;

			// 기존 배열 해제
			SAFE_FREE(*_pArr);

			//주소 바꾸기
			(*_pArr) = pExtends;

			printf("Extends: %d\n", *_pArrLen);
		}
	}

	(*_pArr)[*_pIndex] = _data;
	++(*_pIndex);
}

void Print(int* _pArr, int _index)
{
	for (int i = 0; i < _index; ++i) {
		printf("%d = ", +_pArr[i]);
		printf("(%d)\n", *_pArr);
	}
}
