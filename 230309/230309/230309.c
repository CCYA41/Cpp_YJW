#include<stdio.h>
#include <iostream>

int main()
{
    //Print-Format
    printf("Hello, World!\n");

    //자료형(Data-Type)

    unsigned char c = 'a'; //→문자를 저장하기 위한 자료형(Character)
    printf("c: %c\n", c);
    
    printf("c Size: %zd Byte\n", sizeof(c));
    printf("c Address: %p\n", &c);

    //정수 (Integer)
    short s = 1; 
    printf("s: %zd Byte\n", sizeof(short));
    int i = 10;
    printf("i: %i(%zd Byte)\n", i, sizeof(i));
    long int l = 100;
    printf("l: %zd Byte\n", sizeof(l));
    long long int ll = 1000;
    printf("ll: %zd Byte\n", sizeof(ll));

    // 3.14 = 1.2;
    // Literal constant
    float f = 3.14f;
    // Type Casting
    // 묵시적 형번환
    int f2i = f;
    // 명시적 형번환
    int _f2i = (int)f;

    double d = 3.14;

    long double ld = 3.14;

    // 5, 2 는 int형 값이기 때문에 따로 형변환을 선언하거나
    // 변수에 넣어서 계산하지 않는이상 int로 계산한다
    // 자료형의 승격, 서로 다른 자료형을 연산시 정밀도가
    // 더 높은 자료형으로 자동으로 변환하여 계산
	float result = (float)5 / 2;
    printf("result: %f\n", result);

    // 부동소수점 오차
    double dsum = 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < 1000; ++i) {
        sum += 0.001f;
        dsum += 0.001f;
    }
	printf("sum: %f\n", sum);
    printf("sum: %f\n", dsum);

    return 0;
}
