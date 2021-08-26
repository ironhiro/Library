#include "Borrow.h"



Borrow::Borrow()
{
}

Borrow::Borrow(std::string division, std::string bid,std::string bookname, std::string mid,std::string membername, std::string checkoutDate)
{
	this->division = division;
	this->bid = bid;
	this->bookname = bookname;
	this->mid = mid;
	this->membername = membername;
	this->checkoutDate = checkoutDate;
	this->returnDate = "정보없음";
	
}


Borrow::~Borrow()
{
}

std::string Borrow::getDivision()
{
	return division;
}

std::string Borrow::getBookID()
{
	return bid;
}

std::string Borrow::getBookName()
{
	return bookname;
}

std::string Borrow::getBorrowerID()
{
	return mid;
}

std::string Borrow::getBorrowerName()
{
	return membername;
}

std::string Borrow::getCheckOut()
{
	return checkoutDate;
}

std::string Borrow::getReturn()
{
	return returnDate;
}

void Borrow::setReturn(std::string returnDate)
{
	this->returnDate = returnDate;
}

void Borrow::setID(int id)
{
	this->id = id;
}

void Borrow::putFile(std::ofstream & out)
{
	out << division << " " << bid << " " << bookname << " " << mid << " " << membername << " " << checkoutDate << " " << returnDate;
}

