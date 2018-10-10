//TABEG003 - Nhập và xuất số nguyên 1
//Nhiệm vụ : nhập vào một số nguyên và xuất ra chính số đó
//
//Input
//Hai số nguyên a và b cách nhau bởi dấu cách
//- 2100000000 < a < 2100000000
//	0 < b < 4200000000
//
//	Output
//	Lần lượt xuất ra hai số a, b trên hai dòng khác nhau
//
//	Example 1
//	Input:
//-123 888777666
//
//Output :
//	-123
//	888777666

#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main()
{
	regex pattern("([0-9]{1,4}) ([0-9]{1,4})");
	string replacement = "$1\n$2";
	string stin, stout;
	getline(cin, stin);
	stout = regex_replace(stin, pattern, replacement);
	cout << stout << endl;
	return 0;
}