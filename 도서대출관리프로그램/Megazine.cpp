#include "Megazine.h"



Megazine::Megazine()
{
}

Megazine::Megazine(std::string id, std::string name, std::string publisher, std::string publish_year, int volume)
{
	this->id = id;
	this->bookname = name;
	this->publisher = publisher;
	this->publish_year = publish_year;
	this->volume = volume;
}


Megazine::~Megazine()
{
}

int Megazine::getVolume()
{
	return volume;
}

void Megazine::showInfo()
{
	std::cout << id << " " << bookname << " " << publisher << " " << publish_year << " " << volume << std::endl;
}

void Megazine::putFile(std::ofstream & out)
{
	out << id << " " << bookname << " " << publisher << " " << publish_year << " " << volume;
}
