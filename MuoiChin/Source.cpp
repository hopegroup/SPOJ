//LTAT0041 - Bound Checking for a Sum
//Cho hai số nguyên không âm kiểu unsigned int.Hãy kiểm tra xem tổng hai số có nằm trong phạm vi biểu diễn của kiểu unsigned int hay không.
//
//Input
//Hai số nguyên a, b kiểu unsigned int được cho trên một dòng, phân tách nhau bằng dấu cách.
//
//Output
//In ra "Yes" nếu tổng của a và b nằm trong phạm vi biểu diễn của kiểu unsigned int; in ra "No" trong trường hợp ngược lại.
//
//Example 1
//Input:
//123 93432
//
//Output :
//	Yes
//	Example 2
//	Input :
//	1222333444 3444555666
//
//	Output :
//	No

// lam bang c nhe cac cau
#include <stdio.h>
#include <limits.h>
int main()
{
	unsigned int a, b;
	scanf("%u%u", &a, &b);
	if (a == 0 && b == 0)
	{
		printf("Yes");
	}
	else if (a == 0 || b == 0)
	{
		printf("Yes");
	}
	else
	{
		if (UINT_MAX - a >= b)
		{
			printf("Yes");
		}
		else
		{
			printf("No");
		}
	}
	return 0;
}