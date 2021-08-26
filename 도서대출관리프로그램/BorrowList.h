#pragma once
#include "Borrow.h"
#define MAX_SIZE 20
#define NOT_FOUND -1


class BorrowList
{
private:
	Borrow * boList[MAX_SIZE];
	int count;
	int b_id;
public:
	BorrowList();
	~BorrowList();
	
	Borrow* getBorrow(int index);
	int getCount();

	void insertBorrowList(Borrow* b);
	void sortBorrowList();
	int findBorrowByID(std::string name);
};

