#include "Book.h"

void Book::loadData(Book& book, const char* fileName)
{
	ifstream file(fileName, ios::binary);
	file.read(reinterpret_cast<char*>(&*book.nameBook), MAX_SIZE);
	file.read(reinterpret_cast<char*>(&*book.nameAuthors), MAX_SIZE);
	file.read(reinterpret_cast<char*>(&book.year), sizeof(year));
	file.close();
}

void Book::saveBook(const char* fileName)
{
	ofstream file(fileName, ios::binary);
	file.write(reinterpret_cast<const char*>(&*this->nameBook), MAX_SIZE);
	file.write(reinterpret_cast<const char*>(&*this->nameAuthors), MAX_SIZE);
	file.write(reinterpret_cast<const char*>(&this->year), sizeof(this->year));
}

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
