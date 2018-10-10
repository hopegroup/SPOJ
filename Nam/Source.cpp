//LTAT0008 - Dual Format Telephone Number
//Khi các chuỗi dữ liệu được truyền vào các chương trình, chúng có thể chứa các kí tự đặc biệt có thể kích hoạt các lệnh hoặc các hành động không mong muốn, điều này dẫn đến các lỗ hổng phần mềm.Vì vậy việc kiểm tra dữ liệu đầu vào trước khi sử dụng chúng là 1 việc vô cùng cần thiết.Hãy viết chương trình kiểm tra xem chuỗi nhập vào có phải là số điện thoại di động 11 số dạng số dạng 01xxxxxxxxx hoặc + 841xxxxxxxxx hay không(x là các chữ số từ 0 đến 9).
//
//Input
//Dòng số 1: số tự nhiên t - số lượng testcase.t dòng tiếp sau : mỗi dòng ứng với 1 testcase, là 1 chuỗi kí tự cần kiểm tra.
//
//Output
//Ứng với mỗi testcase in ra 1 dòng, là kết quả kiểm tra chuỗi nhập vào có đúng định dạng không.In ra “Valid!” nếu đúng, “Invalid!” nếu sai.
//
//Example
//Input :
//9
//01234567890
//+ 841123456789
//+ 840156786778
//11234567890
//02234567890
//+ 841161866789
//+ 8411236181673
//01548646877
//01a34567890
//
//Output :
//Valid!
//Invalid!
//Invalid!
//Invalid!
//Valid!
//Invalid!
//Valid!
//Invalid!

#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
	regex pattern("(\\+841|01)[0-9]{9}");
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