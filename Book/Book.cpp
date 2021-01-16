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
	cout << "나의 책 관리 프로그램" << endl;
	textcolor(7);
}

BookManager::BookManager() {
	cout << "책의 개수를 입력하세요:";
	int n;
	cin >> n;
	p = new MyBook[n];
	size = n;
	cout << "읽은 책의 정보를 입력받습니다. ";
	for (int i = 0; i < size; i++) {
		cout << "책의 번호, 이름을 먼저 입력해주세요" << endl;
		cout << "책" << i + 1 << ":";
		cin >> Bnum;
		getline(cin, Bname);
		cout << "분야, 글쓴이, 별점, 짧은 느낀점을 입력해주세요" << endl << ":";
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
	cout << "내가 읽은 모든 책의 정보는 " << endl;
	for (int i = 0; i < size; i++) {
		cout << "책번호:" << p[i].Bnum << "\t";
		cout << "책제목:" << p[i].getBname() << endl;
		cout << "분야:" << p[i].getfield() << "\t";
		cout << "글쓴이:" << p[i].getwriter() << endl;
		cout << "느낀점:" << p[i].getappreciation() << endl;
		cout << "별점:" << p[i].getstar() << endl;
	}
	cout << "============================================================================================" << endl;
	textcolor(7);

}

void BookManager::search() {
	int num;
	cout << "책을 검색합니다 고유번호를 입력해주세요>>";
	cin >> num;
	for (int i = 0; i < size; i++) {
		if (num == p[i].Bnum) {
			cout << "책 제목은 " << p[i].getBname() << ", 글쓴이는 " << p[i].getwriter() << endl;
			cout << "--------------------------------------------------------------------------------------------" << endl;
			return;
		}
	}
	cout << "없는 책입니다. 다시 검색해 주세요." << endl;
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
	cout << "가장 별점이 높은 책은" << p[reindex].getBname() << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;
}

WishBookManager::WishBookManager() {
	cout << "원하는 책의 개수를 입력하세요:";
	int a;
	cin >> a;
	s = new WishBook[a];
	ssize = a;
	cout << "읽고 싶은 책의 정보를 입력받습니다. ";
	for (int i = 0; i < ssize; i++) {
		cout << "읽고 싶은 책의 번호, 이름을 먼저 입력해주세요" << endl;
		cout << "책" << i + 1 << ":";
		cin >> Bnum;
		getline(cin, Bname);
		cout << "책의 분야와 글쓴이를 입력해주세요" << endl << ":";
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
	cout << endl << "내가 읽고 싶은 책의 모든 정보는 " << endl;
	for (int i = 0; i < ssize; i++) {
		cout << "책번호:" << s[i].Bnum << "\t";
		cout << "책제목:" << s[i].getBname() << endl;
		cout << "분야:" << s[i].getfield() << "\t";
		cout << "글쓴이:" << s[i].getwriter() << endl;
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