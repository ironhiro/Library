#include "Book.h"



Book::Book()
{
	
}


Book::~Book()
{
}

std::string Book::getID()
{
	return id;
}

std::string Book::getBookName()
{
	return bookname;
}

std::string Book::getPublisher()
{
	return publisher;
}

std::string Book::getPublishYear()
{
	return publish_year;
}

int Book::getVolume()
{
	return 0;
}

std::string Book::getSubject()
{
	return std::string();
}

void Book::showInfo()
{
}

void Book::putFile(std::ofstream & out)
{
}




