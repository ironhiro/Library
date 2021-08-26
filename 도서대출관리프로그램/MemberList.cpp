#include "MemberList.h"



MemberList::MemberList()
{
	count = 0;
}


MemberList::~MemberList()
{
}

Member * MemberList::getMember(int index)
{
	return mList[index];
}

int MemberList::getCount()
{
	return count;
}

void MemberList::insertMemberList(Member * b)
{
	mList[count] = b;
	count++;
}

void MemberList::deleteMemberList(int index)
{
	delete mList[index];
	mList[index] = mList[count - 1];
	count--;
}

void MemberList::sortMemberList()
{
	for (int i = 1; i < count; i++)
	{
		std::string temp = mList[i]->getName();
		Member* m_temp = mList[i];
		for (int j = i; j > 0; j--)
		{
			if (mList[j - 1]->getName() > temp)
			{
				mList[j] = mList[j - 1];
				if (j == 1)
				{
					mList[j - 1] = m_temp;
					break;
				}
			}
			else
			{
				mList[j] = m_temp;
				break;
			}
		}//삽입정렬 사용하여 이름을 먼저 정렬
	}

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (mList[j]->getID()[0] > mList[j + 1]->getID()[0])
			{
				std::swap(mList[j], mList[j + 1]);
			}
		}
	} //id의 첫글자를 이용해 
}

int MemberList::findMember(std::string id)
{
	for (int i = 0; i < count; i++)
	{
		if (mList[i]->getID() == id)
		{
			return i;
		}
	}
	return NOT_FOUND;
}
