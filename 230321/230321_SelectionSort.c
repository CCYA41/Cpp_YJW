#include<stdio.h>



void Print(const int* const _pArr, int _len);

// Selection Sort(선택정렬)
void main() {
	int sourArr[10] = { 3, 6, 1, 8, 3, 7, 5, 2, 9, 4 };

	// 오름차순
	// 1. 최소값 찾기
	// 2. 제일 앞쪽부터 순서대로 배치
	// 2-1. 배치를 위해서 앞쪽 자리에 있는 요소와 교환
	// 3. 이미 정렬된 앞부분을 제외하고 반복

	int arrLen = sizeof(sourArr) / sizeof(sourArr[0]);

	for (int spotIdx = 0; spotIdx < arrLen - 1; ++spotIdx) {
		int minIdx = spotIdx;

		for (int i = minIdx + 1; i < arrLen; ++i) {
			if (sourArr[minIdx] > sourArr[i]) {
				minIdx = i;
			}

		}
		printf("minIdx: %d(%d)\n", minIdx, sourArr[minIdx]);

		// Swap
		int tmp = sourArr[spotIdx];
		sourArr[spotIdx] = sourArr[minIdx];
		sourArr[minIdx] = tmp;
		printf("Swap: %d -> %d\n", spotIdx, minIdx);

		Print(sourArr, arrLen);
		printf("------------------------------- ");
	}
}

void Print(const int* const _pArr, int _len)
{
	if (_pArr == NULL || _len < 1)return;

	for (int i = 0; i < _len; ++i) {
		printf("%d - ", _pArr[i]);
	}
	printf("(%d)\n", _len);
}
