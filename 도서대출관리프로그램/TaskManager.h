#pragma once
#include "BookList.h"
#include "BorrowList.h"
#include "MemberList.h"
#define NOT_FOUND -1

class TaskManager
{
public:
	void insertMember(MemberList& mList);
	void deleteMember(MemberList& mList);
	void displayMember(MemberList mList);
	void insertBook(BookList& bList);
	void deleteBook(BookList& bList);
	void displayBook(BookList bList);
	void insertBorrow(BorrowList& boList,MemberList& mList, BookList& bList);
	void deleteBorrow(BorrowList& boList);
	void displayBorrow(BorrowList boList, BookList& bList, MemberList& mList);
};

