#include "ioHandler.h"
#include "MemberList.h"
#include "BorrowList.h"
#include "BookList.h"
#include "TaskManager.h"

int main()
{
	MemberList mList;
	BorrowList boList;
	BookList bList;
	ioHandler ioh;
	TaskManager tm;

	ioh.loadMember(mList);
	ioh.loadBook(bList);
	ioh.loadBorrow(boList);

	while (1)
	{
		int select = ioh.getMainMenu();
		if (select == EXIT) break;
		switch (select)
		{
			int menu;
		case INSERT:
		{
			menu = ioh.getMemberMenu();
			if (menu == EXIT) break;
			switch (menu)
			{
			case INSERT:
			{
				tm.insertMember(mList);
				break;
			}
			case DELETE:
			{
				tm.deleteMember(mList);
				break;
			}
			case DISPLAY:
			{
				tm.displayMember(mList);
				break;
			}
			}
			break;
		}
		case DELETE:
		{
			menu = ioh.getBookMenu();
			if (menu == EXIT) break;
			switch (menu)
			{
			case INSERT:
			{
				tm.insertBook(bList);
				break;
			}
			case DELETE:
			{
				tm.deleteBook(bList);
				break;
			}
			case DISPLAY:
			{
				tm.displayBook(bList);
				break;
			}
			}
			break;
		}
		case DISPLAY:
		{
			menu = ioh.getBorrowMenu();
			if (menu == EXIT) break;
			switch (menu)
			{
			case INSERT:
			{
				tm.insertBorrow(boList,mList,bList);
				break;
			}
			case DELETE:
			{
				tm.deleteBorrow(boList);
				break;
			}
			case DISPLAY:
			{
				tm.displayBorrow(boList,bList,mList);
				break;
			}
			}
			break;
		}
		}
	}

	ioh.saveMember(mList);
	ioh.saveBook(bList);
	ioh.saveBorrow(boList);

	return 0;
}