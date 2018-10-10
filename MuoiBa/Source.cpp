//LTAT0020 - List link in a tag html
//Việc tìm kiếm một dữ liệu cụ thể trong một tập dữ liệu phức tạp là điều khó khăn và mất thời gian khi làm thủ công.Regular Expressions hay còn được gọi với cái tên ngắn gọn là Regex là một trong những công cụ mạnh mẽ nhất và được áp dụng rộng rãi nhất trong việc lập trình.Trong đó có việc sử dụng regex để tìm kiếm các chuỗi thông tin trên một trang web.Thẻ <a href > chứa thông tin các liên kết có trong một trang web.Hãy viết chương trình liệt kê tất cả các đường link có trong các thẻ <a> trong một file nào đó(hoặc trong một chuỗi thể hiện đủ một trang HTML nào đó).Các đường link hợp lệ có dạng schema ://host:port/path. Schema có thể là http,https hoặc ftp.
//
//Input
//Dòng số 1 : số tự nhiên t - số lượng các testcase, t dòng tiếp theo mỗi dòng ứng với 1 testcase là 1 đoạn code html chứa các thẻ a cần tìm kiếm link trong đó
//
//Output
//Ứng với mỗi testcase in ra các đường liên kết có trong testcase đó.In ra Found liên kết theo từng testcase.
//
//Example
//Input :
//5
//< li class = "-item" > <a href = "https://stackexchange.com" class = "-link js-site-switcher-button js-gps-track" data - gps - track = "site_switcher.show" title = "A list of all 174 Stack Exchange sites"> <svg aria - hidden = "true" class = "svg-icon iconStackExchange" width = "18" height = "18" viewBox = "0 0 18 18"><path d = "M1 13c0 1.1.9 2 2 2h8v3l3-3h1a2 2 0 0 0 2-2v-2H1v2zM15 1H3a2 2 0 0 0-2 2v2h16V3a2 2 0 0 0-2-2zM1 6h16v4H1V6z" / >< / svg> < / a> < / li> <li class = "-ctas"> <a href = "https://stackoverflow.com/" class = "login-link s-btn btn-topbar-clear py8" rel = "nofollow">Log In< / a> <a href = "https://google.com/" class = "login-link s-btn s-btn__primary py8 btn-topbar-primary" rel = "nofollow" data - ga = "["sign up","Sign Up Navigation","Header",null,null]">Sign Up< / a> < / li>
//<li class = "-item"> <a href = "https://.stackexchange.com" class = "-link js-site-switcher-button js-gps-track" data - gps - track = "site_switcher.show" title = "A list of all 174 Stack Exchange sites"> <svg aria - hidden = "true" class = "svg-icon iconStackExchange" width = "18" height = "18" viewBox = "0 0 18 18"><path d = "M1 13c0 1.1.9 2 2 2h8v3l3-3h1a2 2 0 0 0 2-2v-2H1v2zM15 1H3a2 2 0 0 0-2 2v2h16V3a2 2 0 0 0-2-2zM1 6h16v4H1V6z" / >< / svg> < / a> < / li> <li class = "-ctas"> <a href = "https://stackoverflow.com/abc" class = "login-link s-btn btn-topbar-clear py8" rel = "nofollow">Log In< / a> <a href = "htt://google.com./" class = "login-link s-btn s-btn__primary py8 btn-topbar-primary" rel = "nofollow" data - ga = "["sign up","Sign Up Navigation","Header",null,null]">Sign Up< / a> < / li>
//<li class = "-item"> <a href = "https:://stackexchange.com" class = "-link js-site-switcher-button js-gps-track" data - gps - track = "site_switcher.show" title = "A list of all 174 Stack Exchange sites"> <svg aria - hidden = "true" class = "svg-icon iconStackExchange" width = "18" height = "18" viewBox = "0 0 18 18"><path d = "M1 13c0 1.1.9 2 2 2h8v3l3-3h1a2 2 0 0 0 2-2v-2H1v2zM15 1H3a2 2 0 0 0-2 2v2h16V3a2 2 0 0 0-2-2zM1 6h16v4H1V6z" / >< / svg> < / a> < / li> <li class = "-ctas"> <a href = "https://113.45.65.12/" class = "login-link s-btn btn-topbar-clear py8" rel = "nofollow">Log In< / a> <a href = "ftp://google.com/" class = "login-link s-btn s-btn__primary py8 btn-topbar-primary" rel = "nofollow" data - ga = "["sign up","Sign Up Navigation","Header",null,null]">Sign Up< / a> < / li>
//<li class = "-item"> <a href = "https://stac4kexchange.com" class = "-link js-site-switcher-button js-gps-track" data - gps - track = "site_switcher.show" title = "A list of all 174 Stack Exchange sites"> <svg aria - hidden = "true" class = "svg-icon iconStackExchange" width = "18" height = "18" viewBox = "0 0 18 18"><path d = "M1 13c0 1.1.9 2 2 2h8v3l3-3h1a2 2 0 0 0 2-2v-2H1v2zM15 1H3a2 2 0 0 0-2 2v2h16V3a2 2 0 0 0-2-2zM1 6h16v4H1V6z" / >< / svg> < / a> < / li> <li class = "-ctas"> <a href = "https://stackoverflow.com:8080" class = "login-link s-btn btn-topbar-clear py8" rel = "nofollow">Log In< / a> <a href = "https://12312-google.com/" class = "login-link s-btn s-btn__primary py8 btn-topbar-primary" rel = "nofollow" data - ga = "["sign up","Sign Up Navigation","Header",null,null]">Sign Up< / a> < / li>
//<li class = "-item"> <a href = "https:///stackexchange.com" class = "-link js-site-switcher-button js-gps-track" data - gps - track = "site_switcher.show" title = "A list of all 174 Stack Exchange sites"> <svg aria - hidden = "true" class = "svg-icon iconStackExchange" width = "18" height = "18" viewBox = "0 0 18 18"><path d = "M1 13c0 1.1.9 2 2 2h8v3l3-3h1a2 2 0 0 0 2-2v-2H1v2zM15 1H3a2 2 0 0 0-2 2v2h16V3a2 2 0 0 0-2-2zM1 6h16v4H1V6z" / >< / svg> < / a> < / li> <li class = "-ctas"> <a href = "https://stackoverflow.net/" class = "login-link s-btn btn-topbar-clear py8" rel = "nofollow">Log In< / a> <a href = "http://google.com:8080/search" class = "login-link s-btn s-btn__primary py8 btn-topbar-primary" rel = "nofollow" data - ga = "["sign up","Sign Up Navigation","Header",null,null]">Sign Up< / a> < / li>
//Output:
//1
//Found : https ://stackexchange.com
//	Found : https ://stackoverflow.com/
//	Found : https ://google.com/
//	2
//	Found : https ://.stackexchange.com
//	Found : https ://stackoverflow.com/abc
//	3
//	Found : https ://113.45.65.12/
//	Found : ftp ://google.com/
//	4
//	Found : https ://stac4kexchange.com
//	Found : https ://stackoverflow.com:8080
//	Found : https ://12312-google.com/
//	5
//	Found : https ://stackoverflow.net/
//	Found : http ://google.com:8080/search

#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
	regex pattern("(http|https|ftp)://(\\.?\\w+)+(-\\w+)*(\\.[\\w]+)+(:[0-9]+)*(/[\\w]+)*/{0,1}");
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
			cout << "Found: " << pos->str() << endl;
		}
		i = i + 1;
	}
	cout << endl;
}