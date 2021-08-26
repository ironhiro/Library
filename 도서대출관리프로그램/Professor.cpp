#include "Professor.h"



Professor::Professor()
{
}

Professor::Professor(std::string id, std::string name, std::string department, std::string major)
{
	this->id = id;
	this->name = name;
	this->department = department;
	this->major = major;
}


Professor::~Professor()
{
}

void Professor::showInfo()
{
	std::cout << id << " " << name << " " << department << " " << major << std::endl;
}

std::string Professor::getMajor()
{
	return major;
}

void Professor::putFile(std::ofstream & out)
{
	out << id << " " << name << " " << department << " " << major;
}
