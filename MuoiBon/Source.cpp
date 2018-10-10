//LTAT0021 - List email in raw data
//Việc tìm kiếm một dữ liệu cụ thể trong một tập dữ liệu phức tạp là điều khó khăn và mất thời gian khi làm thủ công.Regular Expressions hay còn được gọi với cái tên ngắn gọn là Regex là một trong những công cụ mạnh mẽ nhất và được áp dụng rộng rãi nhất trong việc lập trình.Trong đó có việc sử dụng regex để tìm kiếm các thông tin cá nhân như số điện thoại, email, số tài khoản tín dụng.Hãy viết chương trình trích xuất tất cả các địa chỉ email có trong một file nào đó hoặc từ dữ liệu đầu vào cho trước.Email hợp lệ có dạng name@domain.xxx(name chỉ bao gồm các ký tự a - z, A - Z, 0 - 9, -, _, .và domain bao gồm các ký tự 0 - 9, a - z, A - Z, _ và xxx bao gồm các ký tự 0 - 9, a - z, A - Z)
//
//Input
//Dòng số 1: số tự nhiên t - số lượng các testcase, t dòng tiếp theo mỗi dòng ứng với 1 testcase là 1 raw data chứa thông tin cần tìm kiếm.
//
//Output
//Ứng với mỗi testcase in ra các địa chỉ email có trong testcase đó.In ra Found email theo từng testcase
//
//Example
//Input :
//5
//mhmhzm@hotmail.com : 37.216.14.161 : a34b25c16d : mmels17@gmail.com : 77.30.18.192 : 712mmels : moazmahde@yahoo.com : 197.33.51.49 : moaz01002351974 : mohammad.motevali1377@yahoo.com : 5.238.199.203 : 09197166299M : mohammadhadi1999'@yahoo.com:188.211.83.70:09391554892gh:mohammedafez609@yahoo.com@lienxo.us:197.160.164.136:2732003zx:momodf@yahoo.com:41.36.126.162:369258147zZ:momodg240@yah_oo.com:41.36.126.162:011436806
//mhmhzm@hotmail..com:37.216.14.161 : a34b25c16d : mmels17@gmail.com : 77.30.18.192 : 712mmels : moazmahde@yahoo.com : 197.33.51.49 : moaz01002351974 : mohammad.motevali1377@yahoo.com : 5.238.199.203 : 09197166299M : mohammadhadi1999@yahoo.c0m : 188.211.83.70 : 09391554892gh : mohammedafez609@yahoo.com : 197.160.164.136 : 2732003zx : momodf@yahoo.com : 41.36.126.162 : 369258147zZ : momodg240@yahoo@.com : 41.36.126.162 : 011436806
//mhmhzm@hotmail.com:37.216.14.161 : a34b25c16d : mmels17@@gmail.com : 77.30.18.192 : 712mmels : moazmahde@yahoo.com : 197.33.51.49 : moaz01002351974 : mohammad.motevali1377@yahoo.com : 5.238.199.203 : 09197166299M : mohammadhad ^ i1999@yahoo.com : 188.211.83.70 : 09391554892gh : mohammedafez609@yahoo.com : 197.160.164.136 : 2732003zx : momodf@yahoo.com : 41.36.126.162 : 369258147zZ : momodg240@yahoo.com : 41.36.126.162 : 011436806
//mhmhzm@hotmail.com:37.216.14.161 : a34b25c16d : mmels17@gmail.com : 77.30.18.192 : 712mmels : moazmahde@yahoo.com : 197.33.51.49 : moaz01002351974 : mohammad.motevali1377@yahoo/.com:5.238.199.203 : 09197166299M : mohammadhadi1 % 999@@yahoo.com : 188.211.83.70 : 09391554892gh : mohammedafez609@yahoo.com.us:197.160.164.136 : 2732003zx : momo_df@yahoo.com : 41.36.126.162 : 369258147zZ : momodg24_0@yahoo.com : 41.36.126.162 : 011436806
//mhmhzm@hotmail.com:37.216.14.161 : a34b25c16d : mmels 17@gmail.com : 77.30.18.192 : 712mmels : moazmahde@yahoo..com:197.33.51.49 : moaz01002351974 : mohammad.motevali1377@yahoo.com : 5.238.199.203 : 09197166299M : mohammadhadi#1999@yahoo.com:188.211.83.70 : 09391554892gh : mohammedafez60.9@yahoo.com : 197.160.164.136 : 2732003zx : momodf@yahoo.com : 41.36.126.162 : 369258147zZ : momoA_1dg240@yahoo.com : 41.36.126.162 : 011436806
//
//Output :
//	1
//	Found mhmhzm@hotmail.com
//	Found mmels17@gmail.com
//	Found moazmahde@yahoo.com
//	Found mohammad.motevali1377@yahoo.com
//	Found mohammedafez609@yahoo.com
//	Found momodf@yahoo.com
//	Found momodg240@yah_oo.com
//	2
//	Found mmels17@gmail.com
//	Found moazmahde@yahoo.com
//	Found mohammad.motevali1377@yahoo.com
//	Found mohammadhadi1999@yahoo.c0m
//	Found mohammedafez609@yahoo.com
//	Found momodf@yahoo.com
//	3
//	Found mhmhzm@hotmail.com
//	Found moazmahde@yahoo.com
//	Found mohammad.motevali1377@yahoo.com
//	Found i1999@yahoo.com
//	Found mohammedafez609@yahoo.com
//	Found momodf@yahoo.com
//	Found momodg240@yahoo.com
//	4
//	Found mhmhzm@hotmail.com
//	Found mmels17@gmail.com
//	Found moazmahde@yahoo.com
//	Found mohammedafez609@yahoo.com.us
//	Found momo_df@yahoo.com
//	Found momodg24_0@yahoo.com
//	5
//	Found mhmhzm@hotmail.com
//	Found 17@gmail.com
//	Found mohammad.motevali1377@yahoo.com
//	Found 1999@yahoo.com
//	Found mohammedafez60.9@yahoo.com
//	Found momodf@yahoo.com
//	Found momoA_1dg240@yahoo.com

#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
	//regex pattern("(1[0-9][0-9]|2[0-4][0-9]|25[0-5]|[1-9][0-9]|[0-9]{1})(\\.(1[0-9][0-9]|2[0-4][0-9]|25[0-5]|[1-9][0-9]|[0-9]{1})){3}");
	regex pattern("(\\w+)(\\.|_|-)?(\\w*)@(\\w+)(\\.(\\w+))+");
	//regex pattern("0[0-9]{9,10}");
	string st;
	int d, i = 1;
	cin >> d;
	getline(cin, st);
	while (i <= d)
	{
		getline(cin, st);
		smatch result;
		sregex_token_iterator pos(st.cbegin(), st.cend(), // sequence
			pattern,              // token separator
			0);
		regex_search(st, result, pattern);
		sregex_token_iterator end;
		cout << i << endl;
		for (; pos != end; ++pos) {
			cout << "Found " << pos->str() << endl;
		}
		i = i + 1;
	}
	cout << endl;
}