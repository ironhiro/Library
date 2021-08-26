#pragma once

#include "MemberList.h"
#include "BookList.h"
#include "BorrowList.h"
#include "Student.h"
#include "Professor.h"
#include "Megazine.h"
#include "MajoredBook.h"

enum
{
	INSERT = 1, DELETE, DISPLAY, EXIT
};

class ioHandler
{
public:
	int getMainMenu();
	int getMemberMenu();
	int getBookMenu();
	int getBorrowMenu();
	int getInteger(std::string msg);

	std::string getString(std::string msg);

	Member* getMember(char member_type);
	Student* getStudent();
	Professor* getProfessor();

	Book* getBook(char book_type);
	Megazine* getMegazine();
	MajoredBook* getMajoredBook();
	
	

	char getBookType();
	char getMemberType();


	void loadMember(MemberList& mList);
	void loadBook(BookList& bList);
	void loadBorrow(BorrowList& bList);
	void saveMember(MemberList mList);
	void saveBook(BookList bList);
	void saveBorrow(BorrowList bList);
};

