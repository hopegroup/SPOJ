//LTAT0015 - Email Addresses
//Khi các chuỗi dữ liệu được truyền vào các chương trình, chúng có thể chứa các kí tự đặc biệt có thể kích hoạt các lệnh hoặc các hành động không mong muốn, điều này dẫn đến các lỗ hổng phần mềm.Vì vậy việc kiểm tra dữ liệu đầu vào trước khi sử dụng chúng là 1 việc vô cùng cần thiết.Hãy viết chương trình kiểm tra xem chuỗi nhập vào có phải là một địa chỉ email hợp lệ hay không.
//Một địa chỉ email hợp lệ có định dạng local - part@domain .
//Local - part: các kí tự hợp lệ :
//•	A – Z, a – z, 0 – 9
//•	Các kí tự đặc biệt : !#$%&'*+-/=?^_`{|}~
//•	dấu . (không phải là kí tự bắt đầu hoặc kết thúc, các dấu chấm không được liền kề nhau)
//Domain: có thể gồm nhiều nhãn DNS được ngăn cách bằng dấu chấm(.).Các nhãn này có các kí tự hợp lệ sau :
//•	A – Z, a – z, 0 – 9
//•	Kí tự gạch nối  "-" (không phải là kí tự bắt đầu hoặc kết thúc).
//
//Input
//Dòng số 1 : số tự nhiên t - số lượng testcase.
//t dòng tiếp sau : mỗi dòng ứng với 1 testcase, là 1 chuỗi kí tự cần kiểm tra.
//
//Output
//Ứng với mỗi testcase in ra 1 dòng, là kết quả kiểm tra chuỗi nhập vào có đúng định dạng không.In ra “Valid!” nếu đúng, “Invalid!” nếu sai.
//
//Example
//Input :
//13
//aBc@gmail.com
//abc.def.ghi@abc.abc.abc.abc.com
//abc!#$%&'*+-/=?^_`{|}~@gmail.com
//a.b@gmail-abc.gmail - abc.com
//Abc.example.com
//A@b@c@example.com
//john..doe@example.com
//john.doe@example..com
//abc@-gmail.com
//abc@gmail-.com
//a"b(c)d,e:f;gi[j\k]l@example.com
//.a@gmail.com
//a.@gmail.com
//
//Output :
//Valid!
//Valid!
//Valid!
//Valid!
//Invalid!
//Invalid!
//Invalid!
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
	regex pattern("[\\w!#$%&'*/=?^`{|}~+-]+(\\.[\\w!#$%&'*/=?^`{|}~+-]+)*@[a-zA-Z0-9]+(-?\\.?[a-zA-Z0-9]+)*(\\.[a-zA-Z0-9]+)+");
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