//LTAT003LTAT003 - Modify Telephone Numbers
//Thực hiện chủ trương nhằm quy hoạch lại kho số di động của Bộ Thông tin & Truyền thông cũng như Đảng và Nhà nước đưa ra.Toàn bộ thuê bao di động 11 số tại Việt Nam sẽ phải đổi đầu số để trở thành thuê bao 10 số.Việc chuyển đổi nhằm thống nhất định dạng số điện thoại di động ở Việt Nam ở cùng mức 10 chữ số.Hãy viết chương trình kiểm tra dữ liệu nhập vào có phải số điện thoại 11 số bắt đầu bằng 012 không và chuyển đổi các đầu số 11 số cũ của nhà mạng Vinaphone sang đầu số 10 số mới.
//- Đầu số 0123 -> 083
//- Đầu số 0124 -> 084
//- Đầu số 0125 -> 085
//- Đầu số 0127 -> 081
//- Đầu số 0129 -> 082
//
//Input
//Dòng số 1: số tự nhiên t - số lượng các testcase, t dòng tiếp theo mỗi dòng ứng với 1 testcase là 1 danh sách các số điện thoại 11 số cần đổi đầu số.
//
//Output
//Ứng với mỗi testcase in ra các số điện thoại mới đã được đổi đầu số.In ra Thay doi : so dien thoai theo từng testcase
//
//Example
//Input :
//5
//01239437995 01249009998 01259998999 0127a9998098 01279998099 01299998098 01299998099
//01239437995 01249.009.998 01259998999 01279998098 01279998099 01299998098 10299998099
//A2039437995 01249009998 012099989 01279998098 01279998099 12299998098 016299998099
//012.394.37995 012a49009998 09259998999 01689998098 012579998099 01299998098 01299998099
//01239437995 001249009998 01259998999 01279998098 01279998099 01299998098 011299998099
//
//Output:
//1
//Thay doi : 0839437995
//Thay doi : 0849009998
//Thay doi : 0859998999
//Thay doi : 0819998099
//Thay doi : 0829998098
//Thay doi : 0829998099
//2
//Thay doi : 0839437995
//Thay doi : 0859998999
//Thay doi : 0819998098
//Thay doi : 0819998099
//Thay doi : 0829998098
//3
//Thay doi : 0849009998
//Thay doi : 0819998098
//Thay doi : 0819998099
//4
//Thay doi : 0857999809
//Thay doi : 0829998098
//Thay doi : 0829998099
//5
//Thay doi : 0839437995
//Thay doi : 0849009998
//Thay doi : 0859998999
//Thay doi : 0819998098
//Thay doi : 0819998099
//Thay doi : 0829998098

#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
	regex pattern("012([3-5]|7|9)([0-9]{7})");
	string st;
	int d, i = 1;
	cin >> d;
	getline(cin, st);
	while (i <= d)
	{
		string result;
		getline(cin, st);
		sregex_token_iterator pos(st.cbegin(), st.cend(), // sequence
			pattern,              // token separator
			0);
		sregex_token_iterator end;
		cout << i << endl;
		for (; pos != end; ++pos) {
			result = pos->str();

			// Tìm và thay thế các số 0123 0124 0125

			regex pattern3("012([3-5])([0-9]{7})");
			sregex_token_iterator pos3(result.cbegin(), result.cend(), // sequence
				pattern3,              // token separato
				0);
			if (pos3 != end)
			{
				string replacement = "08$1$2";
				string stout;
				stout = regex_replace(result, pattern3, replacement);
				cout << "Thay doi: " << stout << endl;
			}

			// Tìm và thay thế các số 0127

			regex pattern1("0127([0-9]{7})");
			sregex_token_iterator pos1(result.cbegin(), result.cend(), // sequence
				pattern1,              // token separato
				0);
			if (pos1 != end)
			{
				string replacement = "081$1";
				string stout;
				stout = regex_replace(result, pattern1, replacement);
				cout << "Thay doi: " << stout << endl;
			}

			// Tìm và thay thế các số 0129
			regex pattern2("0129([0-9]{7})");
			sregex_token_iterator pos2(result.cbegin(), result.cend(), // sequence
				pattern2,              // token separato
				0);
			if (pos2 != end)
			{
				string replacement = "082$1";
				string stout;
				stout = regex_replace(result, pattern2, replacement);
				cout << "Thay doi: " << stout << endl;
			}
		}
		i = i + 1;
	}

	cout << endl;
}