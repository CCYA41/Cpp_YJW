#include<stdio.h>

// Function Declaration
void Add(int* _pStack, int _stackSize, int* _pIndex, int _data);
void Print(int _stack, int _stackSize, int _index);


void main()
{

	// Strack
	int stack[5] = { 0 };
	int stackSize = sizeof(stack) / sizeof(stack[0]);
	int index = 0;

	//if (index < 5) {

	//	stack[index] = 5;
	//	++index;
	//}

	add(stack, stackSize, &index, 3);
	



}


// Function Definition
void Add(int* _pStack, int _stackSize, int* _pIndex, int _data)
{
	if (*_pIndex < _stackSize) {
		_pStack[*_pIndex] = _data;
		++(*_pIndex);
	}
}

void Print(int _stack[], int _stackSize, int _index)
{

	if (_index == 0) {
		printf("Stack is empty!\n");
		return;
	}

	for (int i = 0; i < _index; ++i) {
		printf("%d - ", _stack[i]);
	}
	printf("(%d)\n", _index);
}
