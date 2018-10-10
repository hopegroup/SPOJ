//LTAT0013 - Alpha - numberic Strings With Limited Length
//Khi các chuỗi dữ liệu được truyền vào các chương trình, chúng có thể chứa các kí tự đặc biệt có thể kích hoạt các lệnh hoặc các hành động không mong muốn, điều này dẫn đến các lỗ hổng phần mềm.Vì vậy việc kiểm tra dữ liệu đầu vào trước khi sử dụng chúng là 1 việc vô cùng cần thiết.
//Hãy viết chương trình kiểm tra xem chuỗi nhập vào có phải chỉ gồm các chữ cái in thường và chữ số, và độ dài từ 6 đến 20 ký tự hay không(ứng dụng kiểm tra username hợp lệ).
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
//dawdaw415
//daw124
//4125f1f2f12412612f15b62v22
//eqxw1v4
//dawdawAD42
//dqwfqfwfqgqw125125FWA24c14
//
//Output :
//Valid!
//Valid!
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
	regex pattern("[a-z0-9]{6,20}");
	int i, d = 0;
	string st;
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