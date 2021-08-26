#include "MajoredBook.h"



MajoredBook::MajoredBook()
{
}

MajoredBook::MajoredBook(std::string id, std::string name, std::string publisher, std::string publish_year, std::string subject)
{
	this->id = id;
	this->bookname = name;
	this->publisher = publisher;
	this->publish_year = publish_year;
	this->subject = subject;
}


MajoredBook::~MajoredBook()
{
}

void MajoredBook::showInfo()
{
	std::cout << id << " " << bookname << " " << publisher << " " << publish_year << " " << subject << std::endl;
}

std::string MajoredBook::getSubject()
{
	return subject;
}

void MajoredBook::putFile(std::ofstream & out)
{
	out << id << " " << bookname << " " << publisher << " " << publish_year <<" " << subject;
}
