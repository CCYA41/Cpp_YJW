#include<stdio.h>


Print(const int* const _pArr, int _len);

// Insertion Sort(삽입정렬)
void InsertionSort() {
	int sourArr[10] = { 3, 6, 1, 8, 3, 7, 5, 2, 9, 4 };
	int arrLen = sizeof(sourArr) / sizeof(sourArr[0]);

	for (int curIdx = 1; curIdx < arrLen; ++curIdx) {
		printf("------------------ Cycle%d ------------------\n", curIdx);
		for (int preIdx = 0; preIdx < curIdx; ++preIdx) {
			if (sourArr[curIdx] < sourArr[preIdx]) {
				printf("--- Swap : sourArr[%d]: %d-> sourArr[%d]: %d ---\n", curIdx, sourArr[curIdx], preIdx, sourArr[preIdx]);

				int tmp = sourArr[curIdx];
				sourArr[curIdx] = sourArr[preIdx];
				sourArr[preIdx] = tmp;

				Print(sourArr, arrLen);

				continue;
			}
			printf("--- Staay: sourArr[%d]: %d > sourArr[%d]: %d ---\n", curIdx, sourArr[curIdx], preIdx, sourArr[preIdx]);
		}
		printf("------------------ Result ------------------\n");
		Print(sourArr, arrLen);
		printf("--------------------------------------------\n\n");

	}
}

void InsertionSort2() {
	int sourArr[10] = { 3, 6, 1, 8, 3, 7, 5, 2, 9, 4 };
	int arrLen = sizeof(sourArr) / sizeof(sourArr[0]);

	for (int curIdx = 1; curIdx < arrLen; ++curIdx) {
		printf("------------------ Cycle%d ------------------\n", curIdx);
		int tempIdx = curIdx;

		for (int preIdx = curIdx - 1; preIdx >= 0; --preIdx) {
			if (sourArr[tempIdx] < sourArr[preIdx]) {
				printf("--- Swap : sourArr[%d]: %d-> sourArr[%d]: %d ---\n", curIdx, sourArr[curIdx], preIdx, sourArr[preIdx]);
				
				int tmp = sourArr[tempIdx];
				sourArr[tempIdx] = sourArr[preIdx];
				sourArr[preIdx] = tmp;

				Print(sourArr, arrLen);
				tempIdx = preIdx;
				continue;

			}
			printf("--- Staay: sourArr[%d]: %d > sourArr[%d]: %d ---\n", curIdx, sourArr[curIdx], preIdx, sourArr[preIdx]);

		}
		printf("------------------ Result ------------------\n");
		Print(sourArr, arrLen);
		printf("--------------------------------------------\n\n");

	}
}


Print(const int* const _pArr, int _len)
{
	if (_pArr == NULL || _len < 1) return;

	for (int i = 0; i < _len; ++i) {
		printf("%d - ", _pArr[i]);

	}
	printf("(%d)\n", _len);
}
