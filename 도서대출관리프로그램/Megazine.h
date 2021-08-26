#pragma once
#include "Book.h"
class Megazine : public Book
{
private:
	int volume;
public:
	Megazine();
	Megazine(std::string id, std::string name, std::string publisher, std::string publish_year, int volume);
	~Megazine();

	virtual int getVolume();
	virtual void showInfo();
	virtual void putFile(std::ofstream &out);
};

