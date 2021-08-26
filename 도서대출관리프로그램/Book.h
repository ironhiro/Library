#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Book
{
protected:
	std::string id;
	std::string bookname;
	std::string publisher;
	std::string publish_year;
	
public:
	Book();
	~Book();

	virtual std::string getID();
	virtual std::string getBookName();
	virtual std::string getPublisher();
	virtual std::string getPublishYear();
	virtual int getVolume();
	virtual std::string getSubject();
	virtual void showInfo();
	virtual void putFile(std::ofstream &out);
	
};

