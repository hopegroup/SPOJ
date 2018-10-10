//LTAT0025 - Find IP Attack
//Việc thu thập và phân tích log là điều quan trọng trong quá trình xử lý sự cố và điều tra các cuộc tấn công mạng.Có nhiều cách để thu thập log trong đó có việc capture request trên hệ thống mạng bằng công cụ wireshark.Wireshark sẽ liên tục capture các request trong mạng và lưu thành file pcap và đẩy về server log tập trung.Người quản trị sẽ phân tích các file pcap này để tìm ra nguyên nhân khi có sự cố.File pcap chứa một số thông tin như Time, địa chỉ IP nguồn, IP đích, giao thức, Lenght, Info.Hãy viết chương trình để phân tích 1 đoạn log trong pcap in ra các dòng log chứa địa chỉ IP nguồn tấn công 192.168.200.137
//
//Cấu trúc của dòng log : STT Time IP_Source IP_Destination Protocol Length Info
//Việc thu thập và phân tích log là điều quan trọng trong quá trình xử lý sự cố và điều tra các cuộc tấn công mạng.Có nhiều cách để thu thập log trong đó có việc capture request trên hệ thống mạng bằng công cụ wireshark.Wireshark sẽ liên tục capture các request trong mạng và lưu thành file pcap và đẩy về server log tập trung.Người quản trị sẽ phân tích các file pcap này để tìm ra nguyên nhân khi có sự cố.File pcap chứa một số thông tin như Time, địa chỉ IP nguồn, IP đích, giao thức, Lenght, Info.Hãy viết chương trình để phân tích 1 đoạn log trong pcap in ra các dòng log chứa địa chỉ IP nguồn tấn công 192.168.200.137
//
//Cấu trúc của dòng log :
//
//STT Time IP_Source IP_Destination Protocol Length Info
//
//Trường Info sau length có độ dài và các thông tin khác nhau.
//
//Mỗi dòng log cách nhau bởi dấu \n
//
//Input
//Dòng số 1: số tự nhiên t - số lượng các testcase, t dòng tiếp theo mỗi dòng ứng với 1 testcase là 1 đoạn log cần phân tích.
//
//Output
//Ứng với mỗi testcase in ra file đã được lọc và phân loại.In ra Found : dòng log chứa IP nguồn tấn công
//
//Example
//Input :
//3
//2 0.000040 10.65.170.58 192.168.200.1 TCP 54 80 56978[RST] Seq = 1 Win = 0 Len = 0\n8 17.900574 192.168.200.1 10.65.170.58 HTTP 374 HEAD //web-console/ServerInfo.jsp HTTP/1.1\n12 17.923315 192.168.200.1 10.65.170.58 HTTP 425 HEAD //jmx-console/HtmlAdaptor?action=inspectMBean&name=jboss.system:type=ServerInfo HTTP/1.1\n23 39.938431 fe:ff:ff:ff:ff:ff 22:00:0a:41:aa:3a ARP 42 Who has 10.65.170.58? Tell 10.65.170.1\n35 46.183360 192.168.200.1 10.65.170.58 HTTP 340 HEAD //invoker/JMXInvokerServlet HTTP/1.1\n80 64.435331 10.65.170.58 69.89.27.239 TCP 74 51361 80 [SYN] Seq=0 Win=14600 Len=0 MSS=1460 SACK_PERM=1 TSval=1299648 TSecr=0 WS=16\n79 64.378104 172.16.0.23 10.65.170.58 DNS 108 Standard query response 0xe1e0 A www.joaomatosf.com CNAME joaomatosf.com A 192.168.200.1\n115 79.377537 192.168.200.1 10.65.170.58 HTTP 286 GET //jbossass/jbossass.jsp?ppp=uname+-a HTTP/1.1
//2 0.000040 10.65.170.58 192.168.200.1 TCP 54 80 56978[RST] Seq = 1 Win = 0 Len = 0\n8 17.900574 192.168.200.1 10.65.170.58 HTTP 374 HEAD //web-console/ServerInfo.jsp HTTP/1.1\n12 17.923315 192.168.200.1 10.65.170.58 HTTP 425 HEAD //jmx-console/HtmlAdaptor?action=inspectMBean&name=jboss.system:type=ServerInfo HTTP/1.1\n23 39.938431 fe:ff:ff:ff:ff:ff 22:00:0a:41:aa:3a ARP 42 Who has 10.65.170.58? Tell 10.65.170.1\n35 46.183360 192.168.200.1s 10.65.170.58 HTTP 340 HEAD //invoker/JMXInvokerServlet HTTP/1.1\n80 64.435331 10.65.170.58 69.89.27.239 TCP 74 51361 80 [SYN] Seq=0 Win=14600 Len=0 MSS=1460 SACK_PERM=1 TSval=1299648 TSecr=0 WS=16\n79 64.378104 172.16.0.23 10.65.170.58 DNS 108 Standard query response 0xe1e0 A www.joaomatosf.com CNAME joaomatosf.com A 192.168.200.1\n115 79.377537 192.168.200.1 10.65.170.58 HTTP 286 GET //jbossass/jbossass.jsp?ppp=uname+-a HTTP/1.1
//2 0.000040 10.65.170.58 192.168.200.1 TCP 54 80 56978[RST] Seq = 1 Win = 0 Len = 0\n8 17.900574 192.168.200.1a 10.65.170.58 HTTP 374 HEAD //web-console/ServerInfo.jsp HTTP/1.1\n12 17.923315 192.168.200.1 10.65.170.58 HTTP 425 HEAD //jmx-console/HtmlAdaptor?action=inspectMBean&name=jboss.system:type=ServerInfo HTTP/1.1\n23 39.938431 fe:ff:ff:ff:ff:ff 22:00:0a:41:aa:3a ARP 42 Who has 10.65.170.58? Tell 10.65.170.1\n35 46.183360 192.168.200.1 10.65.170.58 HTTP 340 HEAD //invoker/JMXInvokerServlet HTTP/1.1\n80 64.435331 10.65.170.58 69.89.27.239 TCP 74 51361 80 [SYN] Seq=0 Win=14600 Len=0 MSS=1460 SACK_PERM=1 TSval=1299648 TSecr=0 WS=16\n79 64.378104 172.16.0.23 10.65.170.58 DNS 108 Standard query response 0xe1e0 A www.joaomatosf.com CNAME joaomatosf.com A 192.168.200.1\n115 79.377537 192.168.200.1 1a0.65.170.58 HTTP 286 GET //jbossass/jbossass.jsp?ppp=uname+-a HTTP/1.1
//
//Output :
//1
//Found 8 17.900574 192.168.200.1 10.65.170.58 HTTP 374 HEAD //web-console/ServerInfo.jsp HTTP/1.1
//Found 12 17.923315 192.168.200.1 10.65.170.58 HTTP 425 HEAD //jmx-console/HtmlAdaptor?action=inspectMBean&name=jboss.system:type=ServerInfo HTTP/1.1
//Found 35 46.183360 192.168.200.1 10.65.170.58 HTTP 340 HEAD //invoker/JMXInvokerServlet HTTP/1.1
//Found 115 79.377537 192.168.200.1 10.65.170.58 HTTP 286 GET //jbossass/jbossass.jsp?ppp=uname+-a HTTP/1.1
//2
//Found 8 17.900574 192.168.200.1 10.65.170.58 HTTP 374 HEAD //web-console/ServerInfo.jsp HTTP/1.1
//Found 12 17.923315 192.168.200.1 10.65.170.58 HTTP 425 HEAD //jmx-console/HtmlAdaptor?action=inspectMBean&name=jboss.system:type=ServerInfo HTTP/1.1
//Found 115 79.377537 192.168.200.1 10.65.170.58 HTTP 286 GET //jbossass/jbossass.jsp?ppp=uname+-a HTTP/1.1
//3
//Found 12 17.923315 192.168.200.1 10.65.170.58 HTTP 425 HEAD //jmx-console/HtmlAdaptor?action=inspectMBean&name=jboss.system:type=ServerInfo HTTP/1.1
//Found 35 46.183360 192.168.200.1 10.65.170.58 HTTP 340 HEAD //invoker/JMXInvokerServlet HTTP/1.1

//Found 12 17.923315 192.168.200.1 10.65.170.58 HTTP 425 HEAD //jmx-console/HtmlAdaptor?action=inspectMBean&name=jboss.system:type=ServerInfo HTTP/1.1//
//Found 35 46.183360 192.168.200.1 10.65.170.58 HTTP 340 HEAD //invoker/JMXInvokerServlet HTTP/1.1

#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main()
{
	regex pattern("[0-9]+ [0-9]+.[0-9]{6} ((1[0-9][0-9]|2[0-4][0-9]|25[0-5]|[1-9][0-9]|[0-9]{1})(\\.(1[0-9][0-9]|2[0-4][0-9]|25[0-5]|[1-9][0-9]|[0-9]{1})){3} ){2}[A-Z]+ [0-9]+ [A-Z]+ //\\w+([/\\?\\.:&=\\w+-])* [A-Z]+/[0-9].[0-9]");
	string st;
	int d, i = 1;
	cin >> d;
	getline(cin, st);
	while (i <= d)
	{
		getline(cin, st);
		sregex_token_iterator pos(st.cbegin(), st.cend(), pattern, 0);
		sregex_token_iterator end;
		cout << i << endl;
		for (; pos != end; ++pos)
		{
			cout << "Found " << pos->str() << endl;
		}
		i++;
	}
}