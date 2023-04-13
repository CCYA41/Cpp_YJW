#include <stdio.h>
#include <string.h>
#include <malloc.h>

void SetVal(int _i) {
	_i = 789;
	printf("_i: %d (%p)\n", _i, &_i);
}

void SetValue(int* _pI) {
	*_pI = 123;
	printf("_pI: %d (%p) (%p)\n", *_pI, _pI, &_pI);
}


void PointExam() {
	int i = 10;
	printf("I: %d (%p)\n", i, &i);

	int* pI = &i;
	printf("pI: %d (%p) (%p)\n", *pI, pI, &pI);

	int** p2 = &pI;
	int*** p3 = &p2;
	printf("\n");
	printf("p2: %d %p\n", **p2, &**p2);
	SetValue(pI);
	printf("pI: %d (%p) (%p)\n", *pI, pI, &pI);
	printf("\n");
	SetVal(i);
	printf("i: %d (%p)\n", i, &i);
}



void StrCpy(char** _pDest, char* _pSour) {
	int sourLen = strlen(_pSour);
	int destSize = sourLen + 1;

	(*_pDest) = (char*)malloc(sizeof(char) * destSize);
	// _pDest의 주소는 새로 할당 받게된다.

	int i = 0;
	while (_pSour[i] != '\0') {
		(*_pDest)[i] = _pSour[i];
		++i;
	}
	(*_pDest)[i] = '\0';

}

void main() {

	char pSour[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	char** pDest = NULL;

	StrCpy(&pDest, pSour);
	pSour[0] = 'z';
	*(pSour + 2) = 'z';
	printf("%s\n", pDest);

	free(pDest);
	printf("%s\n", pDest);
}