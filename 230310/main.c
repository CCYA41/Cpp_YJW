#include <stdio.h>

void main() {
	// Array
	int arr[3] = { 1, 2, 3 };

	//pointer
	int* dest = arr;
	printf("dest		: %d\n", *(dest + 1));
	printf("dest		: %d\n", dest[1]);

	// Call by Value
	// Call by Reference
	// arr 배열의 이름은 배열의 주소값
	// ex) arr = (00001234)
	printf("int* Size	: %zd byte\n", sizeof(int*));
	printf("char* Size	: %zd byte\n", sizeof(char*));
	printf("double* Size	: %zd byte\n", sizeof(double*));

	printf("arr Size	: %zd byte\n", sizeof(arr));
	printf("arr Length	: %zd\n", sizeof(arr) / sizeof(*arr));


	for (int i = 0; i < 3; ++i) {
		printf("arr[%d]		: %d(%p)\n", i, arr[i], &arr[i]);
		printf("*(arr + %d)	: %d(%p)\n", i, *(arr + i), arr + i);
	}

	printf("arr + 0		: %p\n", arr + 0);
	printf("arr + 1		: %p\n", arr + 1);

	////////////////////////////////////////////////////////////////////////

	printf("=========================================================\n\n");

	int arr2D[2][3] = {
		{11,12,13},
		{21,22,23}
	};
	printf("arr2D Adress	: %p\n", arr2D);

	for (int row = 0; row < 2; ++row) {
		for (int col = 0; col < 3; ++col)
			printf("arr2D[%d][%d]	: %d (%p)\n", row, col, arr2D[row][col], &arr2D[row][col]);
	}

	printf("arr2D + 0	: %p\n", arr2D + 0);
	printf("arr2D + 1	: %p\n", arr2D + 1);
	printf("*(arr2D +0) +1	: %p\n", *(arr2D + 0) + 1);
	printf("*(*(arr2D + 0) +1)	: %d\n", *(*(arr2D + 0) + 1));


	printf("=========================================================\n\n");

	int makeArr1D[6] = { 11,12,13,21,22,23 };
	int* arr0 = &makeArr1D[0];
	int* arr3 = &makeArr1D[3];
	int* makeArr2D[2] = { arr0, arr3 };
	int** destArr2D = makeArr2D;
	printf("arr0			: %p\n", arr0);
	printf("arr3			: %p\n", arr3);
	printf("*(destArr2D + 0)	: %p\n", *(destArr2D + 0));
	printf("*(destArr2D + 1)	: %p\n", *(destArr2D + 1));
	printf("destArr2D[0]		: %p\n", destArr2D[0]);
	printf("destArr2D[1]		: %p\n", destArr2D[1]);
	printf("destArr2D[0][1]		: %d\n", (destArr2D[0])[1]);

		
}



