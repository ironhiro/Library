#include "Student.h"



Student::Student()
{
}

Student::Student(std::string id, std::string name, std::string department, int grade, std::string contact)
{
	this->id = id;
	this->name = name;
	this->department = department;
	this->grade = grade;
	this->contact = contact;
}


Student::~Student()
{
}

void Student::showInfo()
{
	std::cout << id << " " << name << " " << department << " " << grade << " " << contact << std::endl;
}

int Student::getGrade()
{
	return grade;
}

std::string Student::getContact()
{
	return contact;
}

void Student::putFile(std::ofstream & out)
{
	out << id << " " << name << " " << department << " " << grade << " " << contact;
}


