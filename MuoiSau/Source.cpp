//LTAT0024 - Matching specific filenames
//Trong các trang web thường có chức năng upload ảnh hoặc file tài liệu như upload avatar, upload file pdf, word.Việc kiểm soát các tập tin được upload lên website là điều rất quan trọng và bắt buộc với các lập trình viên.Nếu không có sự kiểm soát càc tập tin chặt chẽ sẽ tạo điều kiện cho hacker upload lên các tập tin độc hại như webshell hay file html, txt với mục đích phá hoại.Hãy viết chương trình để kiểm tra định dạng của các tệp tin là ảnh, media, video hoặc file tài liệu.
//
//Với hình ảnh có định dạng.png, .jpg, .gifVới tài liệu có định dạng.pdf, .doc, .pptxVới media file có định dạng.mp3, .mp4, .avi
//Với hình ảnh có định dạng.png, .jpg, .gif
//
//Với tài liệu có định dạng.pdf, .doc, .pptx
//
//Với media file có định dạng.mp3, .mp4, .avi
//
//Lưu ý : Tên file bao gồm các ký tự a - z, A - Z, 0 - 9, _.Đuôi file không phân biệt hoa thường.Ví dụ : pNg, PNG, pDf...
//
//Input
//Dòng số 1 : số tự nhiên t - số lượng các testcase, t dòng tiếp theo mỗi dòng ứng với 1 testcase là 1 danh sách các filename đã được lọc và phân loại.
//
//Output
//Ứng với mỗi testcase in ra file đã được lọc và phân loại.In ra File : loại file(hinh anh, media, tai lieu) theo từng testcase.
//
//Example
//Input :
//4
//.bash_profile phimhay.avi workspace.doc img0912.jpg updated_img0912.png documentation.html favicon.gif img0912.php.jpg access.lock thatgirl.mp3 video.mp4 de_cuong.pptx hacked.htm r57.php shell.aspx huongdan.pdf
//.bash_profile phimhay.AVI workspace..doc img0912.jpg updated_img0912.png documentation.html favicon.gif img0912.php; .jpg access.lock thatgirl.mp3 video..mp4 de_cuong.pptx hacked.htm r57.php shell.aspx huongdan.php.pdf
//.bash_profile phimhay@#$%^.AVI workspace..doc img0912_ - .jpg updated_img0912\.png documentation.html favicon.gif img0912.php; .jpg access.lock thatgirl.mp3 video..mp4 de_cuong.pptx hacked.htm r57.php shell.aspx huongdan.pdf.pdf
//.bash_profile phimhay.aVI workspace..doc img0912_ - .jpg updated_img0912\.png documentation.html favicon.GIF img0912.php; .jpg access.lock thatgirl.mp3 video.mp4 de_cuong.PPTX hacked.htm r57.php shell.aspx huongdan + .pdf
//
//
//Output :
//1
//img0912.jpg : hinh anh
//updated_img0912.png : hinh anh
//favicon.gif : hinh anh
//img0912.php.jpg : hinh anh
//phimhay.avi : media
//thatgirl.mp3 : media
//video.mp4 : media
//workspace.doc : tai lieu
//de_cuong.pptx : tai lieu
//huongdan.pdf : tai lieu
//2
//img0912.jpg : hinh anh
//updated_img0912.png : hinh anh
//favicon.gif : hinh anh
//phimhay.AVI : media
//thatgirl.mp3 : media
//de_cuong.pptx : tai lieu
//huongdan.php.pdf : tai lieu
//3
//favicon.gif : hinh anh
//thatgirl.mp3 : media
//de_cuong.pptx : tai lieu
//huongdan.pdf.pdf : tai lieu
//4
//favicon.GIF : hinh anh
//phimhay.aVI : media
//video.mp4 : media
//de_cuong.PPTX : tai lieu

#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
	regex hinhanh("[\\w]+(\\.\\w+)*\\.(([pP][nN][gG])|([jJ][pP][gG])|([gG][iI][fF]))");
	regex document("[\\w]+(\\.\\w+)*\\.(([pP][dD][fF])|([dD][oO][cC])|([pP][pP][tT][xX]))");
	regex media("[\\w]+(\\.\\w+)*\\.(([mM][pP](3|4))|([aA][vV][iI]))");
	string st;
	int d, i = 1;
	cin >> d;
	getline(cin, st);
	while (i <= d)
	{
		getline(cin, st);
		cout << i << endl;
		sregex_token_iterator pos(st.cbegin(), st.cend(), hinhanh, 0);
		sregex_token_iterator end;

		for (; pos != end; ++pos)
		{
			cout << pos->str() << " : hinh anh" << endl;
		}

		sregex_token_iterator pos3(st.cbegin(), st.cend(), media, 0);
		sregex_token_iterator end3;
		for (; pos3 != end3; ++pos3)
		{
			cout << pos3->str() << " : media" << endl;
		}

		sregex_token_iterator pos2(st.cbegin(), st.cend(), document, 0);
		sregex_token_iterator end2;
		for (; pos2 != end2; ++pos2)
		{
			cout << pos2->str() << " : tai lieu" << endl;
		}

		i++;
	}
	cout << endl;
}