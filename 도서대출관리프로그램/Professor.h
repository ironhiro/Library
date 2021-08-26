#pragma once
#include "Member.h"
class Professor : public Member
{
private:
	std::string major;
public:
	Professor();
	Professor(std::string id, std::string name, std::string department, std::string major);
	~Professor();

	virtual void showInfo();
	virtual std::string getMajor();
	virtual void putFile(std::ofstream& out);
};

