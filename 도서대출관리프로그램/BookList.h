#pragma once
#include "Book.h"

#define MAX_SIZE 20
#define NOT_FOUND -1

class BookList
{
private:
	Book * bList[MAX_SIZE];
	int count;
public:
	BookList();
	~BookList();

	Book* getBook(int index);
	int getCount();

	void insertBookList(Book* b);
	void deleteBookList(int index);
	void sortBookList();
	int findBook(std::string id);
};

