#pragma once
#include <iostream>
#include <string>

#define MAX_SIZE 50
using namespace std;
class Book
{
	char* nameBook;
	char* nameAuthors;
	int year;
public:
	Book() : Book(new char[MAX_SIZE] {"0"}, new char[MAX_SIZE]{"0"}, 0) {};
	Book(char* nameBook, char* nameAuthors, int year) : nameBook{ nameBook }, nameAuthors{ nameAuthors }, year{ year } {};
	friend istream& operator>>(istream& in, Book& book);
	friend ostream& operator<<(ostream& out,const Book& book);
	~Book();
};