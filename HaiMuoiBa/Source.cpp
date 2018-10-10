//LTAT0045 - Bound Checking for an Integer
//Viết chương trình nhập vào một chuỗi ký tự, kiểm tra xem chuỗi nhập vào có phải là một số nguyên trong phạm vi biểu diễn(ở dạng thập phân) của kiểu int hay không.
//
//Input
//Một chuỗi ký tự st
//
//Output
//In ra "Yes" nếu st là biểu diễn của một số nguyên kiểu int; in ra "No" trong trường hợp ngược lại
//
//Example 1
//Input:
//-1234
//
//Output :
//	Yes
//	Example 2
//	Input :
//	9888777666
//
//	Output :
//	No

// lam bang c
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *number = (char*)calloc(15, sizeof(char));
	char *check = (char*)calloc(15, sizeof(char));
	fgets(number, 12, stdin);
	number[strcspn(number, "\n")] = '\0';
	int number_int = atoi(number);
	sprintf(check, "%d", number_int);
	if (strcmp(number, check) != 0)
		printf("No");
	else
		printf("Yes");
	return 0;
}