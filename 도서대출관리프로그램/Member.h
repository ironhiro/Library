#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Member
{
protected:
	std::string id;
	std::string name;
	std::string department;
public:
	Member();
	Member(std::string id,
		std::string name,
		std::string department);
	~Member();


	virtual std::string getID();
	virtual std::string getName();
	virtual std::string getDepartment();
	virtual int getGrade();
	virtual std::string getMajor();
	virtual std::string getContact();
	virtual void showInfo();
	virtual void putFile(std::ofstream& fout);
};

