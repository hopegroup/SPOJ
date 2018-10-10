//LTAT0042 - Bound Checking for a Product
//Cho hai số nguyên không âm kiểu unsigned int.Hãy kiểm tra xem tích của hai số có nằm trong phạm vi biểu diễn của kiểu unsigned int hay không.
//
//Input
//Hai số nguyên a, b kiểu unsigned int được cho trên một dòng, phân tách nhau bằng dấu cách.
//
//Output
//In ra "Yes" nếu tích của a và b nằm trong phạm vi biểu diễn của kiểu unsigned int; in ra "No" trong trường hợp ngược lại.
//
//Example 1
//Input:
//123 93432
//
//Output :
//	Yes
//	Example 2
//	Input :
//	1222333444 4
//
//	Output :
//	No

//lam bang c
//Cho hai số nguyên không âm kiểu unsigned int. Hãy kiểm tra xem tích của hai số có nằm trong phạm vi biểu
//diễn của kiểu unsigned int hay không
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
		if (UINT_MAX / a >= b)
		{
			printf("Yes");
		}
		else
			printf("No");
	}
	return 0;
}