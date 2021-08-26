#pragma once
#include "Book.h"
class MajoredBook:public Book
{
private:
	std::string subject;
public:
	MajoredBook();
	MajoredBook(std::string id, std::string name, std::string publisher, std::string publish_year, std::string subject);
	~MajoredBook();

	virtual void showInfo();
	virtual std::string getSubject();
	virtual void putFile(std::ofstream &out);
};

