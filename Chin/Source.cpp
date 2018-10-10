//LTAT0012 - Alphabet Strings
//Khi các chuỗi dữ liệu được truyền vào các chương trình, chúng có thể chứa các kí tự đặc biệt có thể kích hoạt các lệnh hoặc các hành động không mong muốn, điều này dẫn đến các lỗ hổng phần mềm.Vì vậy việc kiểm tra dữ liệu đầu vào trước khi sử dụng chúng là 1 việc vô cùng cần thiết.
//Hãy viết chương trình kiểm tra xem chuỗi nhập vào chỉ gồm chữ cái(in hoa hoặc in thường) và dấu cách hay không.
//
//Input
//Dòng số 1: số tự nhiên t - số lượng testcase.
//t dòng tiếp sau : mỗi dòng ứng với 1 testcase, là 1 chuỗi kí tự cần kiểm tra.
//
//Output
//Ứng với mỗi testcase in ra 1 dòng, là kết quả kiểm tra chuỗi nhập vào có đúng định dạng không.In ra “Valid!” nếu đúng, “Invalid!” nếu sai.
//
//Example
//Input :
//6
//abcde
//AbCde
//dawcaw#125daaw
//cwca124caa
//adawfAFA
//adsva wfaw
//
//Output :
//Valid!
//Valid!
//Invalid!
//Invalid!
//Valid!
//Valid!

#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main()
{
	regex pattern("[a-zA-Z ]+");
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