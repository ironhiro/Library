#include "BorrowList.h"



BorrowList::BorrowList()
{
	count = 0;
	b_id = 0;
}


BorrowList::~BorrowList()
{
}

Borrow * BorrowList::getBorrow(int index)
{
	return boList[index];
}

int BorrowList::getCount()
{
	return count;
}

void BorrowList::insertBorrowList(Borrow * b)
{
	boList[count] = b;
	boList[count]->setID(++b_id);
	count++;
}



void BorrowList::sortBorrowList()
{
	for (int i = 1; i < count; i++)
	{
		std::string temp = boList[i]->getBookName();
		Borrow* b_temp = boList[i];
		for (int j = i; j > 0; j--)
		{
			if (boList[j - 1]->getBookName() > temp)
			{
				boList[j] = boList[j - 1];
				if (j == 1)
				{
					boList[j - 1] = b_temp;
					break;
				}
			}
			else
			{
				boList[j] = b_temp;
				break;
			}
		}//삽입정렬 사용하여 책이름을 먼저 정렬
	}

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (boList[j]->getBookID()[0] < boList[j + 1]->getBookID()[0])
			{
				std::swap(boList[j], boList[j + 1]);
			}
		}
	} //id의 첫글자를 이용
}

int BorrowList::findBorrowByID(std::string id)
{
	for (int i = 0; i < count; i++)
	{
		if (boList[i]->getBookID() == id)
			return i;
	}
	return NOT_FOUND;
}


