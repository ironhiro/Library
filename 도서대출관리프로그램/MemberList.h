#pragma once
#include "Member.h"
#define MAX_SIZE 20
#define NOT_FOUND -1

class MemberList
{
private:
	Member * mList[MAX_SIZE];
	int count;
public:
	MemberList();
	~MemberList();

	Member* getMember(int index);
	int getCount();

	void insertMemberList(Member* b);
	void deleteMemberList(int index);
	void sortMemberList();
	int findMember(std::string id);
};

