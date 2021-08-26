#pragma once
#include "Member.h"
class Student : public Member
{
private:
	int grade;
	std::string contact;
public:
	Student();
	Student(std::string id, std::string name, std::string department, int grade, std::string contact);
	~Student();

	virtual void showInfo();
	virtual int getGrade();
	virtual std::string getContact();

	virtual void putFile(std::ofstream& out);
};

