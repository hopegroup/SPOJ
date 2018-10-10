//LTAT0010 - Numeric String Without Leading Zeros
//Khi các chuỗi dữ liệu được truyền vào các chương trình, chúng có thể chứa các kí tự đặc biệt có thể kích hoạt các lệnh hoặc các hành động không mong muốn, điều này dẫn đến các lỗ hổng phần mềm.Vì vậy việc kiểm tra dữ liệu đầu vào trước khi sử dụng chúng là 1 việc vô cùng cần thiết.
//Hãy viết chương trình kiểm tra xem chuỗi nhập vào có phải chỉ gồm các chữ số và không bắt đầu bằng chữ số 0 hay không.
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
//1231412
//01321412
//1321c1312
//16746
//012412c123d112
//sacwacawawf
//
//Output :
//Valid!
//Invalid!
//Invalid!
//Valid!
//Invalid!
//Invalid!

#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
	regex pattern("[1-9][0-9]*");
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