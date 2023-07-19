#include "Book.h"

Book::~Book()
{
	delete nameBook;
	delete nameAuthors;
}

istream& operator>>(istream& in, Book& book) {
	cout << "������� �������� �����: ";
	cin.getline(book.nameBook, MAX_SIZE);
	cout << "������� ������ �����: ";
	cin.getline(book.nameAuthors, MAX_SIZE);
	cout << "������� ��� �������: ";
	in >> book.year;
	if (book.year < 0) {
		throw exception("Error. Problem with input year");
	}
	return in;
}

ostream& operator<<(ostream& out, const Book& book) {
	out << "�������� �����: " << book.nameBook << endl;
	out << "����� �����: " << book.nameAuthors << endl;
	out << "��� �������: " << book.year << endl;
	return out;
}
