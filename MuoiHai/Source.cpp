//LTAT0019 - List phone numbers
//Việc tìm kiếm một dữ liệu cụ thể trong một tập dữ liệu phức tạp là điều khó khăn và mất thời gian khi làm thủ công.Regular Expressions hay còn được gọi với cái tên ngắn gọn là Regex là một trong những công cụ mạnh mẽ nhất và được áp dụng rộng rãi nhất trong việc lập trình.Trong đó có việc sử dụng regex để tìm kiếm các chuỗi thông tin như số điện thoại, email, địa chỉ website thường được áp dụng trong các công cụ crawler.Hãy viết một chương trình liệt kê tất cả các số điện thoại có trong chuỗi nhập vào và chỉ ra vị trí xuất hiện của các số đó(số điện thoại có dạng 10 số hoặc 11 số và bắt đầu bằng số 0)
//
//Input
//Dòng số 1: số tự nhiên t - số lượng các testcase,
//t dòng tiếp theo mỗi dòng ứng với 1 testcase là 1 chuỗi ký tự cần tìm kiếm
//
//Output
//Ứng với mỗi testcase in ra các số điện thoại có trong testcase đó và vị trí xuất hiện của các số đó.In ra Found số điện thoai at vị trí xuất hiện theo từng testcase
//
//Example
//Input :
//5
//01206627581 12345574093890 0918662782 1000a10291775790 01206627583 12345940022595
//0a206627581 0918662782 1001 + 0291775790 + 1012 06627583 12345940022595
//0206627581aa 12345574093890 0918662782 1001 + 0291775790 + 101206627583 12345940022595
//0a + 206627581 12345574093890 0918.662.782 1001 + 0291775790 + 101206627583 12345940022595
//0206627581 12345574093890 091 866 2782 1001 + 0291775790 3614037 + 101206627583 12345940022595
//
//Output:
//1
//Found 01206627581 at 0
//Found 0918662782 at 27
//Found 0291775790 at 44
//Found 01206627583 at 55
//2
//Found 0918662782 at 12
//Found 0291775790 at 28
//3
//Found 0206627581 at 0
//Found 0918662782 at 28
//Found 0291775790 at 44
//Found 01206627583 at 57
//4
//Found 0291775790 at 46
//Found 01206627583 at 59
//5
//Found 0206627581 at 0
//Found 0291775790 at 44
//Found 01206627583 at 65

#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
	//regex pattern("(1[0-9][0-9]|2[0-4][0-9]|25[0-5]|[1-9][0-9]|[0-9]{1})(\\.(1[0-9][0-9]|2[0-4][0-9]|25[0-5]|[1-9][0-9]|[0-9]{1})){3}");
	//regex pattern("[a-zA-Z\\d][\\w\\-\\_\\.]{1,31}@[\\w]{2,}(\\.[a-z0-9]{2,}){1}");
	regex pattern("0[0-9]{9,10}");
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
			cout << "Found " << pos->str() << " at " << pos->first - st.cbegin() << endl;
		}
		i = i + 1;
	}
	cout << endl;
}