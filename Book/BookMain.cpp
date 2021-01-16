#include "Book.h"

int main() {
	fOutM();
	while (1) {
		cout << "<1> 내가 읽은 책 입력	<2> 내가 읽고 싶은 책 입력	<3>종료" << endl << ">>";
		int input;
		int cinput;
		cin >> input;
		if (input == 1) {
			BookManager mbook;
			while (1) {
				cout << "<1> 내가 읽은 책 모아보기	<2>최고의 별점 책	<3>책 검색하기	<4> 재입력" << endl;
				cout << "구체적인 기능을 선택하세요 >> ";
				cin >> cinput;
				if (cinput == 1)
					mbook.Bshow();
				if (cinput == 2)
					mbook.best();
				if (cinput == 3)
					mbook.search();
				if (cinput == 4) {
					cout << endl << endl;
					break;
				}
			}
		}
		else if (input == 2) {
			WishBookManager wbook;
			while (1) {
				cout << "<1> 내가 읽고 싶은 책 모아보기	<2> 책 추천받기 <3> 재입력" << endl;
				cout << "구체적인 기능을 선택하세요 >> ";
				cin >> cinput;
				if (cinput == 1)
					wbook.Wshow();
				if (cinput == 2)
					wbook.recommend();
				if (cinput == 3) {
					cout << endl << endl;
					break;
				}
			}
		}
		else if (input == 3) {
			break;
		}
	}
	getchar();
}