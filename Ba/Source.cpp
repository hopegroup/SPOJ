//LTAT0006 - 11 - digits Telephone Number
//Hãy viết chương trình kiểm tra xem chuỗi nhập vào có phải là số điện thoại di động 11 số dạng 01xxxxxxxxx hay không(x là các chữ số từ 0 đến 9).
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
//01234567890
//09454635343
//01546d64686
//01542358487
//81354538486
//016484848646
//0154848488
//Output:
//Valid!
//Invalid!
//Invalid!
//Valid!
//Invalid!
//Invalid!
//Invalid!

#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
	regex pattern("01[0-9]{9}");
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