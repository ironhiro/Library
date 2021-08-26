#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Borrow
{
private:
	int id;
	std::string division;
	std::string bid;
	std::string bookname;
	std::string mid;
	std::string membername;
	std::string checkoutDate;
	std::string returnDate;
public:
	Borrow();
	Borrow(std::string division, std::string bid, std::string bookname, std::string mid, std::string membername, std::string checkoutDate);
	~Borrow();

	std::string getDivision();
	std::string getBookID();
	std::string getBookName();
	std::string getBorrowerID();
	std::string getBorrowerName();
	std::string getCheckOut();
	std::string getReturn();

	void setReturn(std::string returnDate);
	void setID(int id);
	void putFile(std::ofstream& out);
};

