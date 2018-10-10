//LTAT0043 - Bound Checking for a Signed Sum
//Cho hai số nguyên kiểu int.Hãy kiểm tra xem tổng hai số có nằm trong phạm vi biểu diễn của kiểu int hay không.
//
//Input
//Hai số nguyên a, b kiểu int được cho trên một dòng, phân tách nhau bằng dấu cách.
//
//Output
//In ra "Yes" nếu tổng của a và b nằm trong phạm vi biểu diễn của kiểu int; in ra "No" trong trường hợp ngược lại.
//
//Example 1
//Input:
//123 93432
//
//Output :
//	Yes
//	Example 2
//	Input :
//	-1222333444 - 1444555666
//
//	Output :
//	No

// lam bang c nhe
#include <stdio.h>
#include <limits.h>
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	if (a == 0 && b == 0)
	{
		printf("Yes");
	}
	else if (a == 0 || b == 0) {
		printf("Yes");
	}

	else if (a > 0 && b > 0)
	{
		if (INT_MAX - a >= b)
		{
			printf("Yes");
		}
		else
		{
			printf("No");
		}
	}
	else if (a < 0 && b < 0)
	{
		if (INT_MIN - a <= b)
		{
			printf("Yes");
		}
		else
			printf("No");
	}
	else
	{
		if (a <= INT_MAX && b >= INT_MIN)
		{
			printf("Yes");
		}
		else if (a >= INT_MIN && b <= INT_MAX)
		{
			printf("Yes");
		}
		else
			printf("No");
	}
	return 0;
}