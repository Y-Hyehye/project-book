#include "Book.h"

int main() {
	fOutM();
	while (1) {
		cout << "<1> ���� ���� å �Է�	<2> ���� �а� ���� å �Է�	<3>����" << endl << ">>";
		int input;
		int cinput;
		cin >> input;
		if (input == 1) {
			BookManager mbook;
			while (1) {
				cout << "<1> ���� ���� å ��ƺ���	<2>�ְ��� ���� å	<3>å �˻��ϱ�	<4> ���Է�" << endl;
				cout << "��ü���� ����� �����ϼ��� >> ";
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
				cout << "<1> ���� �а� ���� å ��ƺ���	<2> å ��õ�ޱ� <3> ���Է�" << endl;
				cout << "��ü���� ����� �����ϼ��� >> ";
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