//LTAT0022 - List IP in log web
//Access log của một trang web thường chứa các thông tin truy cập từ phía người dùng như IP, User - agent, Path, phương thức truy cập, thời gian, ... Việc phân tích dữ liệu file log khi bị tấn công hoặc gặp sự cố là điều rất quan trọng đối với người quản trị để tìm ra nguyên nhân.Có nhiều cách phân tích log khác nhau trong đó có thể sử dụng regex để tìm kiếm thông tin như địa chỉ IP.Hãy viết chương trình tìm kiếm tất cả các địa chỉ IP có trong một file log đó hoặc từ dữ liệu đầu vào cho trước(IP hợp lệ từ 0.0.0.0 = > 255.255.255.255)
//
//Input
//Dòng số 1: số tự nhiên t - số lượng các testcase, t dòng tiếp theo mỗi dòng ứng với 1 testcase là 1 log data chứa thông tin cần tìm kiếm.
//
//Output
//Ứng với mỗi testcase in ra các địa chỉ email có trong testcase đó.In ra Found IP theo từng testcase
//
//Example
//Input :
//5
//123.125.71.35 - -[17 / May / 2015:10 : 05 : 46 + 0000] "GET /blog/tags/release HTTP/1.1" 200 40693 "-" "Baiduspider/2.0; +http://www.baidu.com/search/spider.html)" 110.136.166.128 - -[17 / May / 2015:10 : 05 : 08 + 0000] "GET /images/web/2009/banner.png HTTP/1.1" 200 52315 "http://www.semicomplete.com/" "Mozilla" 50.150.204.184 - -[17 / May / 2015:10 : 05 : 46 + 0000] "GET /images/googledotcom.png HTTP/1.1" 200 65748 "http://www.google.com/search?q=" "Mozilla/5.0 (Linux; ) AppleWebKit/534.30 (KHTML, like Gecko) Version/4.0 Mobile Safari/534.30" 207.241.237.225 - -[17 / May / 2015:10 : 05 : 58 + 0000] "GET /blog/tags/examples HTTP/1.0" 200 9208 "http://www.semicomplete.com/blog/tags/C" "Mozilla/5.0 (compatible; archive.org_bot +http://www.archive.org/details/archive.org_bot)" 192.168.1.256 - -[17 / May / 2015:10 : 05 : 36 + 0000] "GET /reset.css HTTP/1.1" 200 1015 "-" "-" 1.2.3.4 - -[17 / May / 2015:10 : 05 : 38 + 0000] "GET /blog/attack/sql' HTTP/1.1" 200 44019 "-" "QS304 Profile/MIDP-2.0 Configuration/CLDC-1.1"
//123.125.71..35 - -[17 / May / 2015:10 : 05 : 46 + 0000] "GET /blog/tags/release HTTP/1.1" 200 40693 "-" "Baiduspider/2.0; +http://www.baidu.com/search/spider.html)" 110.136.166.128 - -[17 / May / 2015:10 : 05 : 08 + 0000] "GET /images/web/2009/banner.png HTTP/1.1" 200 52315 "http://www.semicomplete.com/" "Mozilla" 50.150.204.5 - -[17 / May / 2015:10 : 05 : 46 + 0000] "GET /images/googledotcom.png HTTP/1.1" 200 65748 "http://www.google.com/search?q=" "Mozilla/5.0 (Linux; ) AppleWebKit/534.30 (KHTML, like Gecko) Version/4.0 Mobile Safari/534.30" 207.241.237.225 - -[17 / May / 2015:10 : 05 : 58 + 0000] "GET /blog/tags/examples HTTP/1.0" 200 9208 "http://www.semicomplete.com/blog/tags/C" "Mozilla/5.0 (compatible; archive.org_bot +http://www.archive.org/details/archive.org_bot)" 200.49.190.101 - -[17 / May / 2015:10 : 05 : 36 + 0000] "GET /reset.css HTTP/1.1" 200 1015 "-" "-" 127.1 - -[17 / May / 2015:10 : 05 : 38 + 0000] "GET /blog/attack/sql' HTTP/1.1" 200 44019 "-" "QS304 Profile/MIDP-2.0 Configuration/CLDC-1.1"
//123a.125.71.35 - -[17 / May / 2015:10 : 05 : 46 + 0000] "GET /blog/tags/release HTTP/1.1" 200 40693 "-" "Baiduspider/2.0; +http://www.baidu.com/search/spider.html)" 110.136.166.128 - -[17 / May / 2015:10 : 05 : 08 + 0000] "GET /images/web/2009/banner.png HTTP/1.1" 200 52315 "http://www.semicomplete.com/" "Mozilla" 0.0.0.0 - -[17 / May / 2015:10 : 05 : 46 + 0000] "GET /images/googledotcom.png HTTP/1.1" 200 65748 "http://www.google.com/search?q=" "Mozilla/5.0 (Linux; ) AppleWebKit/534.30 (KHTML, like Gecko) Version/4.0 Mobile Safari/534.30" 207.241.237.225 - -[17 / May / 2015:10 : 05 : 58 + 0000] "GET /blog/tags/examples HTTP/1.0" 200 9208 "http://www.semicomplete.com/blog/tags/C" "Mozilla/5.0 (compatible; archive.org_bot +http://www.archive.org/details/archive.org_bot)" 3...3 - -[17 / May / 2015:10 : 05 : 36 + 0000] "GET /reset.css HTTP/1.1" 200 1015 "-" "-" 200.49.190.100 - -[17 / May / 2015:10 : 05 : 38 + 0000] "GET /blog/attack/sql' HTTP/1.1" 200 44019 "-" "QS304 Profile/MIDP-2.0 Configuration/CLDC-1.1"
//30.168.1.255.1 - -[17 / May / 2015:10 : 05 : 46 + 0000] "GET /blog/tags/release HTTP/1.1" 200 40693 "-" "Baiduspider/2.0; +http://www.baidu.com/search/spider.html)" 110.136.16g6.128 - -[17 / May / 2015:10 : 05 : 08 + 0000] "GET /images/web/2009/banner.png HTTP/1.1" 200 52315 "http://www.semicomplete.com/" "Mozilla" 50.150.2104.184 - -[17 / May / 2015:10 : 05 : 46 + 0000] "GET /images/googledotcom.png HTTP/1.1" 200 65748 "http://www.google.com/search?q=" "Mozilla/5.0 (Linux; ) AppleWebKit/534.30 (KHTML, like Gecko) Version/4.0 Mobile Safari/534.30" 255.255.255.255 - -[17 / May / 2015:10 : 05 : 58 + 0000] "GET /blog/tags/examples HTTP/1.0" 200 9208 "http://www.semicomplete.com/blog/tags/C" "Mozilla/5.0 (compatible; archive.org_bot +http://www.archive.org/details/archive.org_bot)" 192.168.1.1 - -[17 / May / 2015:10 : 05 : 36 + 0000] "GET /reset.css HTTP/1.1" 200 1015 "-" "-" 200.49.190.100 - -[17 / May / 2015:10 : 05 : 38 + 0000] "GET /blog/attack/sql' HTTP/1.1" 200 44019 "-" "QS304 Profile/MIDP-2.0 Configuration/CLDC-1.1"
//123.125.7 + 1.35 - -[17 / May / 2015:10 : 05 : 46 + 0000] "GET /blog/tags/release HTTP/1.1" 200 40693 "-" "Baiduspider/2.0; +http://www.baidu.com/search/spider.html)" 0.136.166.1 - -[17 / May / 2015:10 : 05 : 08 + 0000] "GET /images/web/2009/banner.png HTTP/1.1" 200 52315 "http://www.semicomplete.com/" "Mozilla" 50.150.2:04.184 - -[17 / May / 2015:10 : 05 : 46 + 0000] "GET /images/googledotcom.png HTTP/1.1" 200 65748 "http://www.google.com/search?q=" "Mozilla/5.0 (Linux; ) AppleWebKit/534.30 (KHTML, like Gecko) Version/4.0 Mobile Safari/534.30" 207.241.237.225 - -[17 / May / 2015:10 : 05 : 58 + 0000] "GET /blog/tags/examples HTTP/1.0" 200 9208 "http://www.semicomplete.com/blog/tags/C" "Mozilla/5.0 (compatible; archive.org_bot +http://www.archive.org/details/archive.org_bot)" 127.0.0.1 - -[17 / May / 2015:10 : 05 : 36 + 0000] "GET /reset.css HTTP/1.1" 200 1015 "-" "-" 4.19.0.1 - -[17 / May / 2015:10 : 05 : 38 + 0000] "GET /blog/attack/sql' HTTP/1.1" 200 44019 "-" "QS304 Profile/MIDP-2.0 Configuration/CLDC-1.1"
//
//Output :
//	1
//	Found 123.125.71.35
//	Found 110.136.166.128
//	Found 50.150.204.184
//	Found 207.241.237.225
//	Found 192.168.1.25
//	Found 1.2.3.4
//	2
//	Found 110.136.166.128
//	Found 50.150.204.5
//	Found 207.241.237.225
//	Found 200.49.190.101
//	3
//	Found 110.136.166.128
//	Found 0.0.0.0
//	Found 207.241.237.225
//	Found 200.49.190.100
//	4
//	Found 30.168.1.255
//	Found 255.255.255.255
//	Found 192.168.1.1
//	Found 200.49.190.100
//	5
//	Found 0.136.166.1
//	Found 207.241.237.225
//	Found 127.0.0.1
//	Found 4.19.0.1

#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
	regex pattern("(1[0-9][0-9]|2[0-4][0-9]|25[0-5]|[1-9][0-9]|[0-9]{1})(\\.(1[0-9][0-9]|2[0-4][0-9]|25[0-5]|[1-9][0-9]|[0-9]{1})){3}");
	//regex pattern("[a-zA-Z\\d][\\w\\-\\_\\.]{1,31}@[\\w]{2,}(\\.[a-z0-9]{2,}){1}");
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