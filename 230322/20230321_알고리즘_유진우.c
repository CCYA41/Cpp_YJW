#include <stdio.h>
#include <string.h>
#include <malloc.h>



// strlen: 문자열의 길이
int StrLen(const char* const _pStr);

// strcpy: 문자열을 복사
// _pSour -> _pDest 동적할당으로 복사할 배열의 길이만큼 학장
//void StrCpy(char** _pDest, char* _pSour);
char* StrCpy(char** _pDest, char* _pSour);

// strcmp: 두문자열을 비교
// 같은지 다른지만 비교
// 같으면 1, 다르면 0 을 반환
int StrCmp(char* _pLhs, char* _pRhs);

// strcat: 두문자열을 합치기
// String Concatent
// 두 문자열을 합침
char* StrCat(char** _pDest, char* _pSour1, char* _pSour2);

// 문자(character
// 문자열(String)
void CharArray() {
	char c = 'a';
	// String Constant
	char* str = "String";
	//str[1] = 'T';
	// String Array / String Variales
	// \0: 널 문자(Null Character)
	char strArr[] = { 's', 't', 'r', 'i', 'n', 'g', '\0' };
	strArr[2] = 'R';
	int strLen = sizeof(strArr) / sizeof(strArr[0]);
	for (int i = 0; i < strLen; ++i) {
		printf("%c", strArr[i]);

	}
	printf("\n");
	printf("star: %s(%d)\n", str, (int)strlen(str));
	printf("starArr: %s(%d)\n", strArr, (int)strlen(strArr));

}


void main() {
	char* _pStr = "StrLen";
	printf("_pStr Length: %d\n", StrLen(_pStr));


	char** _pDest = NULL;
	char* _pSour = "StringCopy";

	StrCpy(_pDest, _pSour);

	printf("_pDest : %s \n", StrCpy(_pDest, _pSour));

	void free(_pDest);



	char* _pLhs = "Test";
	char* _pRhs = "TeSt";
	StrCmp(_pLhs, _pRhs);

	char* _pSour1 = "String";
	char* _pSour2 = "Concatent";
	printf("_pDest : %s ", StrCat(_pDest, _pSour1, _pSour2));
	void free(_pDest);
}

int StrLen(const char* const _pStr) {
	if (_pStr == NULL) return;

	int whileCount = 0;
	int aryLen = 0;
	while (_pStr[whileCount] != NULL) {
		//if (_pStr[whileCount] == '\0') continue;
		++aryLen;
		//	printf("ary: %C\n", _pStr[whileCount]);
		//	printf("aryLen: %d\n", aryLen);
		++whileCount;
		//	printf("whileCount: %d\n", whileCount);
	}
	return aryLen;
}

// char* stirng이 시작하는 주소값
// char** char* stirng 주소의 주소값
// 포인터를 아직 이해를 못했습니다.
char* StrCpy(char** _pDest, char* _pSour)
//char* StrCpy(char** _pDest, char* _pSour)
{
	if (_pSour == NULL) {
		printf("Null Char Data");
		return;
	}

	_pDest = (char*)malloc(sizeof(char) * StrLen(_pSour));
	//printf("_pDest Len: %d\n", StrLen(_pDest));
	char** _pTmp = (char*)malloc(sizeof(char) * StrLen(_pSour));
	//printf("_pTmp Len: %d\n", StrLen(_pTmp));
	for (int i = 0; i < StrLen(_pSour); ++i) {
		_pTmp[i] = &_pSour[i];
		_pDest[i] = *_pTmp[i];
		//printf("_pTmp[%d]: %c\n", i, *_pTmp[i]);
		//printf("_pDest[%d]: %c\n", i, _pDest[i]);
	}
	_pDest = _pTmp;
	return *_pDest;


}

int StrCmp(char* _pLhs, char* _pRhs)
{
	int _pLhsLen = StrLen(_pLhs);
	int _pRhsLen = strlen(_pRhs);

	if (_pLhsLen != _pRhsLen) {
		printf("Size Diffrent\n");
		return 0;
	}

	int maxLen = _pLhsLen;

	for (int count = 0; count < maxLen; ++count) {
		if (_pLhs[count] != _pRhs[count]) {
			printf("String is Diffrent!\n");
			return 0;
		}

	}
	printf("Two Strings is Match!\n");
	return 1;
}

//void StrCat(char** _pDest, char* _pSour1, char* _pSour2)
char* StrCat(char** _pDest, char* _pSour1, char* _pSour2)
{
	if (_pDest != NULL || _pSour1 == NULL || _pSour2 == NULL) return;

	int destLen = StrLen(_pSour1) + StrLen(_pSour2);
	char* _pTmp = (char*)malloc(sizeof(char) * destLen);
	//printf("len %d\n", StrLen(_pTmp));
	int endValue = 0;
	for (int i = 0; i < StrLen(_pSour1); ++i) {
		_pTmp[i] = _pSour1[i];
		++endValue;
	}

	int restartValue = endValue;

	for (int i = 0; i < StrLen(_pSour2); ++i) {
		_pTmp[restartValue + i] = _pSour2[i];
		++endValue;
	}
	_pTmp[endValue] = '\0';

	//printf("_pTmp: %s \n", _pTmp);
	_pDest = (char*)malloc(sizeof(char) * destLen);
	_pDest = &_pTmp;
	//printf("_pDest: %s \n", *_pDest);
	return *_pDest;
}
