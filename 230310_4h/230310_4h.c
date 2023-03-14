#include<stdio.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define ERROR_CODE INT_MIN
#define DATA_TYPE int
//#define DATAA 5
// int를 DATA로 정의
typedef int DATA;
// STL Standard Templete Library
//enum DATA {
//	DAAA = 5
//};
// Function Declaration

void Push(int* const _pStack, int _stackSize, int* const _pIndex, int _data);
int Pop(const int* const _pStack, int* const _pIndex);
void Print(int* _pStack, int _stackSize, int _index);
int CheckStackOverflow(int _stackSize, int _index);

void main()
{

	// Strack
	int stack[5] = { 0 };
	int stackSize = sizeof(stack) / sizeof(stack[0]);
	int index = 0;
	int pop = Pop(stack, &index);

	//if (index < 5) {

	//	stack[index] = 5;
	//	++index;
	//}

	//Push(stack, stackSize, &index, 5);
	//Print(stack, stackSize, index);
	//Push(stack, stackSize, &index, 3);
	//Print(stack, stackSize, index);

	//stack[index] = 3;
	//++index;


	for (int i = 0; i < 5; ++i) {
		Push(stack, stackSize, &index, i + 1);
		Print(stack, stackSize, index);

		printf("Pop: %d\n", Pop(stack, &index));
		Print(stack, stackSize, index);
	}
}


// Function Definition


void Push(int* const _pStack, int _stackSize, int* const _pIndex, int _data)
{
	// Exception
	if (_pStack == NULL) return;
	if (_pIndex == NULL) return;

	// 주소의 값을 변경하는식
	int i = 0;
	const int* const p = &i;
	//p = _pStack;
	// 포인터로 받아온 주소에 있는 값을 변경하는 방법
	//*p = 10;
	// const는 보호하려고자 하는 곳에 적용해야함
	// ex) const int i=> 자료형을 보호, 변수의 값은 변경가능
	// ex) int const i => 변수의 값을 보호(자료형도 지켜야함)
	// ex) const int const i => 변수와 자료형 둘다 다른형식으로 변경을 금지

	//if (*_pIndex < _stackSize)
	if (!CheckStackOverflow(_stackSize, *_pIndex))
	{
		_pStack[*_pIndex] = _data;
		++(*_pIndex);
	}
}

int Pop(const int* const _pStack, int* const _pIndex)
{
	if (_pStack == NULL || _pIndex == NULL)
		return ERROR_CODE;

	if (*_pIndex == 0) return ERROR_CODE;

	int returnValue = _pStack[*_pIndex - 1];
	--(*_pIndex);
	return returnValue;
}


void Print(const int* const _pStack, int _stackSize, int _index)
{

	if (_index == 0) {
		printf("Stack is empty!\n");
		return;
	}

	for (int i = 0; i < _index; ++i) {
		printf("%d - ", _pStack[i]);
	}
	printf("(%d)\n", _index);


}

int CheckStackOverflow(int _stackSize, int _index) {


	return (_index >= _stackSize) ? TRUE : FALSE;
}



