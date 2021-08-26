#include "Member.h"



Member::Member()
{
}

Member::Member(std::string id, std::string name, std::string department)
{
	this->id = id;
	this->name = name;
	this->department = department;
}


Member::~Member()
{
}

std::string Member::getID()
{
	return id;
}

std::string Member::getName()
{
	return name;
}

std::string Member::getDepartment()
{
	return department;
}

int Member::getGrade()
{
	return 0;
}

std::string Member::getMajor()
{
	return std::string();
}


std::string Member::getContact()
{
	return std::string();
}

void Member::showInfo()
{
}

void Member::putFile(std::ofstream & fout)
{
}

