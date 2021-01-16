#include <stdlib.h>
#include <time.h>
#include <Windows.h>	

#include "Book.h"

void Book::set(string Bname, string writer, string publisher) {
	this->Bname = Bname; this->writer = writer;
}

void MyBook::set(int Bnum, string Bname, string field, string writer, string star, string appreciation) {
	this->Bnum = Bnum;  this->Bname = Bname; this->field = field;  this->writer = writer; this->star = star; this->appreciation = appreciation;
}

void WishBook::set(int Bnum, string Bname, string field, string writer) {
	this->Bnum = Bnum; this->Bname = Bname; this->field = field; this->writer = writer;
}

void textcolor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void fOutM() {
	textcolor(0x00E0);
	cout << "���� å ���� ���α׷�" << endl;
	textcolor(7);
}

BookManager::BookManager() {
	cout << "å�� ������ �Է��ϼ���:";
	int n;
	cin >> n;
	p = new MyBook[n];
	size = n;
	cout << "���� å�� ������ �Է¹޽��ϴ�. ";
	for (int i = 0; i < size; i++) {
		cout << "å�� ��ȣ, �̸��� ���� �Է����ּ���" << endl;
		cout << "å" << i + 1 << ":";
		cin >> Bnum;
		getline(cin, Bname);
		cout << "�о�, �۾���, ����, ª�� �������� �Է����ּ���" << endl << ":";
		cin >> field >> writer >> star;
		getline(cin, appreciation);
		p[i].set(Bnum, Bname, field, writer, star, appreciation);
	}
	cout << "--------------------------------------------------------------------------------------------" << endl;
}

void BookManager::BSort() {
	for (int s = size - 1; s >= 0; s--) {
		for (int t = 0; t < s; t++) {
			if (p[t].Bnum > p[t + 1].Bnum) {
				MyBook temp = p[t];
				p[t] = p[t + 1];
				p[t + 1] = temp;
			}
		}
	}
}

void BookManager::Bshow() {
	BSort();
	textcolor(2);
	cout << "============================================================================================" << endl;
	cout << "���� ���� ��� å�� ������ " << endl;
	for (int i = 0; i < size; i++) {
		cout << "å��ȣ:" << p[i].Bnum << "\t";
		cout << "å����:" << p[i].getBname() << endl;
		cout << "�о�:" << p[i].getfield() << "\t";
		cout << "�۾���:" << p[i].getwriter() << endl;
		cout << "������:" << p[i].getappreciation() << endl;
		cout << "����:" << p[i].getstar() << endl;
	}
	cout << "============================================================================================" << endl;
	textcolor(7);

}

void BookManager::search() {
	int num;
	cout << "å�� �˻��մϴ� ������ȣ�� �Է����ּ���>>";
	cin >> num;
	for (int i = 0; i < size; i++) {
		if (num == p[i].Bnum) {
			cout << "å ������ " << p[i].getBname() << ", �۾��̴� " << p[i].getwriter() << endl;
			cout << "--------------------------------------------------------------------------------------------" << endl;
			return;
		}
	}
	cout << "���� å�Դϴ�. �ٽ� �˻��� �ּ���." << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;
}

void BookManager::best() {
	int sbest = 0;
	int stari;
	string bbest;
	for (int j = 0; j < size; j++) {
		string sstar = p[j].getstar();
		stari = sstar.length();
		if (sbest < stari) {
			bbest = p[j].getstar();
			reindex = j;
		}
	}
	cout << "���� ������ ���� å��" << p[reindex].getBname() << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;
}

WishBookManager::WishBookManager() {
	cout << "���ϴ� å�� ������ �Է��ϼ���:";
	int a;
	cin >> a;
	s = new WishBook[a];
	ssize = a;
	cout << "�а� ���� å�� ������ �Է¹޽��ϴ�. ";
	for (int i = 0; i < ssize; i++) {
		cout << "�а� ���� å�� ��ȣ, �̸��� ���� �Է����ּ���" << endl;
		cout << "å" << i + 1 << ":";
		cin >> Bnum;
		getline(cin, Bname);
		cout << "å�� �о߿� �۾��̸� �Է����ּ���" << endl << ":";
		cin >> field >> writer;
		s[i].set(Bnum, Bname, field, writer);
	}
	cout << "--------------------------------------------------------------------------------------------" << endl;
}

void WishBookManager::WSort() {
	for (int c = ssize - 1; c >= 0; c--) {
		for (int t = 0; t < c; t++) {
			if (s[t].Bnum > s[t + 1].Bnum) {
				WishBook temp = s[t];
				s[t] = s[t + 1];
				s[t + 1] = temp;
			}
		}
	}
}

void WishBookManager::Wshow() {
	WSort();
	textcolor(5);
	cout << "============================================================================================";
	cout << endl << "���� �а� ���� å�� ��� ������ " << endl;
	for (int i = 0; i < ssize; i++) {
		cout << "å��ȣ:" << s[i].Bnum << "\t";
		cout << "å����:" << s[i].getBname() << endl;
		cout << "�о�:" << s[i].getfield() << "\t";
		cout << "�۾���:" << s[i].getwriter() << endl;
	}
	cout << "============================================================================================" << endl;
	textcolor(7);
}

void WishBookManager::recommend() {
	int rnd;
	srand(unsigned(time(NULL)));
	rnd = rand() % ssize;
	cout << s[rnd].getBname() << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;
}