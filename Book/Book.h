#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
using namespace std;


class Book {
protected:
	string Bname;
	string writer;
	string field;
public:
	int Bnum;
	Book() {}
	Book(string a1, string a2) {
		Bname = a1; writer = a2;
	}
	string getBname() { return Bname; }
	string getwriter() { return writer; }
	string getfield() { return field; }
	void set(string Bname, string writer, string publisher);
};

class MyBook :public Book {
protected:
	string star;						//별점
	string appreciation;				//짧은 감상
public:
	MyBook() {}
	string getstar() { return star; }
	string getappreciation() { return appreciation; }
	void set(int Bnum, string Bname, string field, string writer, string star, string appreciation);
};

class WishBook : public Book {
public:
	WishBook() {}
	void set(int Bnum, string Bname, string field, string writer);
};

void textcolor(int color);
void fOutM();

class BookManager : public MyBook {
protected:
	MyBook *p;
	int size;
	int reindex;
public:
	BookManager();
	void BSort();
	void Bshow();
	void search();
	void best();
};

class WishBookManager :public WishBook {
	WishBook *s;
	int ssize;
public:
	WishBookManager();
	void WSort();
	void Wshow();
	void recommend();
};

#endif