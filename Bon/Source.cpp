//LTAT0007 - Telephone number in International Format
//Hãy viết chương trình kiểm tra xem chuỗi nhập vào có phải là số điện thoại di động 11 số dạng + 841.xxx.xxx.xxx hay không(x là các chữ số từ 0 đến 9).
//
//Input
//Dòng số 1: số tự nhiên t - số lượng testcase.t dòng tiếp sau : mỗi dòng ứng với 1 testcase, là 1 chuỗi kí tự cần kiểm tra.
//
//Output
//Ứng với mỗi testcase in ra 1 dòng, là kết quả kiểm tra chuỗi nhập vào có đúng định dạng không.In ra “Valid!” nếu đúng, “Invalid!” nếu sai.
//
//Example
//Input :
//7
//+ 841.979.123.456
//+ 841.979.123.4567
//+ 841.979.123.45
//+ 841.979a123.456
//+ 841.979. 1d3.456
//841.978.465.123
//+ 741.979.123.456
//Output:
//Valid!
//Invalid!
//Invalid!
//Invalid!
//Invalid!
//Invalid!
//Invalid!

#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
	regex pattern("\\+841(\\.[0-9]{3}){3}");
	string st;
	int i, d = 0;
	cin >> i;
	getline(cin, st);
	while (d < i)
	{
		getline(cin, st);
		if (regex_match(st, pattern))
			cout << "Valid!" << endl;
		else
			cout << "Invalid!" << endl;
		d++;
	}
}