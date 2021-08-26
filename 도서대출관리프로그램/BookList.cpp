#include "BookList.h"



BookList::BookList()
{
	count = 0;
}


BookList::~BookList()
{
}

Book * BookList::getBook(int index)
{
	return bList[index];
}

int BookList::getCount()
{
	return count;
}

void BookList::insertBookList(Book * b)
{
	bList[count] = b;
	count++;
}

void BookList::deleteBookList(int index)
{
	delete bList[index];
	bList[index] = bList[count - 1];
	count--;
}

void BookList::sortBookList()
{
	for (int i = 1; i < count; i++)
	{
		std::string temp = bList[i]->getBookName();
		Book* b_temp = bList[i];
		for (int j = i; j > 0; j--)
		{
			if (bList[j - 1]->getBookName() > temp)
			{
				bList[j] = bList[j - 1];
				if (j == 1)
				{
					bList[j - 1] = b_temp;
					break;
				}
			}
			else
			{
				bList[j] = b_temp;
				break;
			}
		}//삽입정렬 사용하여 책이름을 먼저 정렬
	}

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (bList[j]->getID()[0] < bList[j + 1]->getID()[0])
			{
				std::swap(bList[j], bList[j + 1]);
			}
		}
	} //id의 첫글자를 이용
}

int BookList::findBook(std::string id)
{
	for (int i = 0; i < count; i++)
	{
		if (bList[i]->getID() == id)
		{
			return i;
		}
	}
	return NOT_FOUND;
}
