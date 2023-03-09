#include<stdio.h>

#define FULLSCREEN 32
enum EOptions
{
	kBGM = 4,
	kFULLSCREEN = 32
};

// Bitwasi Operator
void main() {
	int lhs = 4;									// Left-Hand Side
	int rhs = 2;									// Right-Hand Side
	printf("lhs & rhs: %d\n", lhs & rhs);	// AND
	printf("lhs | rhs: %d\n", lhs | rhs);		// OR
	printf("lhs ^ rhs: %d\n", lhs ^ rhs);	// XOR
	printf("~lhs: %d\n", ~lhs);				// NOT

	unsigned char options = 0;
	options |= kBGM;
	options |= FULLSCREEN;
	// 00100100
	printf("options: %d\n", options);

	printf("kBGM is enable: %s\n", (options & kBGM) > 0 ? "T" : "F");

	options ^= 32;
	// 00100000
	printf("options: %d\n", options);

	// Shift Operator
	printf("2 << 2: %d\n", 2 << 2);
	printf("10 >> 1: %d\n", 10 >> 1);

}