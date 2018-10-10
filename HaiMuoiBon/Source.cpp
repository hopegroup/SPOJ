//LTAT0046 - Bound Checking for the LCM
//Viết chương trình tìm bội số chung nhỏ nhất(LCM - Least Common Multiple) của 2 số nguyên kiểu unsigned long long
//
//Input
//Hai số nguyên a, b kiểu unsigned long long, phân tách nhau bởi dấu cách.
//
//Output
//In ra BCNN của a và b nếu BCNN đó nằm trong phạm vi biểu diễn của kiểu unsigned long long, in ra "N/A" trong trường hợp ngược lại.
//
//Example 1
//Input:
//12 18
//Output :
//	36
//	Example 2
//	Input :
//	9111222333111222333 5
//	Output :
//	N / A

// lam bang c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned long long gcd(unsigned long long a, unsigned long long b) {
	while (b != 0) {
		unsigned long long tam = a % b;
		a = b;
		b = tam;
	}
	return a;
}
int main()
{
	unsigned long long a, b, UCLN, tam;
	scanf("%llu%llu", &a, &b);
	if (a == 0 && b == 0)
		printf("0");
	else if (a == 0 || b == 0)
		printf("N/A");
	else {
		UCLN = gcd(a, b);
		tam = a / UCLN;
		if ((ULLONG_MAX / tam) >= b)
			printf("%llu", (tam*b));
		else
			printf("N/A");
	}
	return 0;
}