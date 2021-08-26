#include "TaskManager.h"
#include "ioHandler.h"

void TaskManager::insertMember(MemberList & mList)
{
	ioHandler ioh;
	char member_type = ioh.getMemberType();
	Member* m = ioh.getMember(member_type);

	if (mList.getCount() >= MAX_SIZE)
	{
		std::cout << "배열 초과" << std::endl;
		return;
	}

	int index = mList.findMember(m->getID());
	if (index != NOT_FOUND) {
		std::cout << "ID 중복입니다." << std::endl;
		return;
	}

	mList.insertMemberList(m);
}

void TaskManager::deleteMember(MemberList & mList)
{
	ioHandler ioh;
	std::string id = ioh.getString("ID를 입력하시오: ");
	int index = mList.findMember(id);
	if (index == NOT_FOUND)
	{
		std::cout << "존재하지 않는 구성원" << std::endl;
		return;
	}

	mList.deleteMemberList(index);
}

void TaskManager::displayMember(MemberList mList)
{
	mList.sortMemberList();
	for (int i = 0; i < mList.getCount(); i++)
	{
		mList.getMember(i)->showInfo();
	}
}

void TaskManager::insertBook(BookList & bList)
{
	ioHandler ioh;
	char book_type = ioh.getBookType();
	Book* b = ioh.getBook(book_type);

	if (bList.getCount() >= MAX_SIZE)
	{
		std::cout << "배열 초과" << std::endl;
		return;
	}

	int index = bList.findBook(b->getID());
	if (index != NOT_FOUND) {
		std::cout << "ID 중복입니다." << std::endl;
		return;
	}

	bList.insertBookList(b);
}

void TaskManager::deleteBook(BookList & bList)
{
	ioHandler ioh;
	std::string id = ioh.getString("ID를 입력하시오: ");
	int index = bList.findBook(id);
	if (index == NOT_FOUND)
	{
		std::cout << "존재하지 않는 책" << std::endl;
		return;
	}

	bList.deleteBookList(index);
}

void TaskManager::displayBook(BookList bList)
{
	bList.sortBookList();
	for (int i = 0; i < bList.getCount(); i++)
	{
		bList.getBook(i)->showInfo();
	}
}

void TaskManager::insertBorrow(BorrowList& boList, MemberList& mList, BookList& bList)
{
	ioHandler ioh;
	std::string mid = ioh.getString("구성원 id 입력: ");
	int member_index = mList.findMember(mid);
	std::string bid = ioh.getString("책 id 입력: ");
	int book_index = bList.findBook(bid);
	std::string checkoutDate = ioh.getString("대출기간 입력: ");
	
	int index = boList.findBorrowByID(bid);

	if (member_index == NOT_FOUND || book_index == NOT_FOUND)
	{
		std::cout << "구성원이 존재하지 않거나 존재하지 않는 책입니다." << std::endl;
		return;
	}
	else if (index != NOT_FOUND)
	{
		std::cout << "이미 대출한 책입니다." << std::endl;
		return;
	}
	std::string diversity;
	if (bid[0] == 'M')
		diversity = "잡지";
	else
		diversity = "전공서적";
	std::string membername = mList.getMember(member_index)->getName();
	std::string bookname = bList.getBook(book_index)->getBookName();
	std::cout << "이름: " << membername << "," << "책제목: " << bookname << std::endl;
	Borrow* b = new Borrow(diversity,bid,bookname, mid,membername, checkoutDate);
	boList.insertBorrowList(b);
}

void TaskManager::deleteBorrow(BorrowList & boList)
{
	ioHandler ioh;
	std::string bid = ioh.getString("책ID 입력: ");
	std::string returndate = ioh.getString("반납일 입력: ");
	int index = boList.findBorrowByID(bid);
	if (index == NOT_FOUND)
	{
		std::cout << "대출하지 않거나 존재하지 않는 책입니다. " << std::endl;
		return;
	}

	boList.getBorrow(index)->setReturn(returndate);
}

void TaskManager::displayBorrow(BorrowList boList,BookList& bList,MemberList& mList)
{
	std::cout << "==================================================" << std::endl;
	std::cout << "구분 도서명 대출자 대출일 반납일 대출기간" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	for (int i = 0; i < boList.getCount(); i++)
	{
		int book_index = bList.findBook(boList.getBorrow(i)->getBookID());
		int member_index = mList.findMember(boList.getBorrow(i)->getBorrowerID());
		if (book_index == NOT_FOUND)
			continue;
		else if (member_index == NOT_FOUND)
		{
			
			std::string borrower = "ㅇㅇㅇ";
			std::string checkoutDate = boList.getBorrow(i)->getCheckOut();
			std::string returnDate = boList.getBorrow(i)->getReturn();
			if (returnDate == "정보없음")
			{
				std::string borrowDate = " ";
				std::cout << "       " << borrower << " " << checkoutDate << " " << returnDate << " " << borrowDate << std::endl;
				return;
			}
			int year1 = atoi(checkoutDate.substr(0, 4).c_str());
			int month1 = atoi(checkoutDate.substr(4, 2).c_str());
			int day1 = atoi(checkoutDate.substr(6, 2).c_str());
			int year2 = atoi(returnDate.substr(0, 4).c_str());
			int month2 = atoi(returnDate.substr(4, 2).c_str());
			int day2 = atoi(returnDate.substr(6, 2).c_str());
			
			int borrowDate = (year2 - year1) * 365 + (month2 - month1) * 12 + (day2 - day1);
			std::cout << "       " << borrower << " " << checkoutDate << " " << returnDate << " " << borrowDate << std::endl;
		}
		else
		{
			std::string diversity = boList.getBorrow(i)->getDivision();
			std::string title = bList.getBook(book_index)->getBookName();
			std::string borrower = mList.getMember(member_index)->getName();
			std::string checkoutDate = boList.getBorrow(i)->getCheckOut();
			std::string returnDate = boList.getBorrow(i)->getReturn();
			if (returnDate == "정보없음")
			{
				std::string borrowDate = " ";
				std::cout << diversity << " " << title << " " << borrower << " " << checkoutDate << " " << returnDate << " " << borrowDate << std::endl;
				return;
			}
			int year1 = atoi(checkoutDate.substr(0, 4).c_str());
			int month1 = atoi(checkoutDate.substr(4, 2).c_str());
			int day1 = atoi(checkoutDate.substr(6, 2).c_str());
			int year2 = atoi(returnDate.substr(0, 4).c_str());
			int month2 = atoi(returnDate.substr(4, 2).c_str());
			int day2 = atoi(returnDate.substr(6, 2).c_str());
			
			
			int borrowDate = (year2 - year1) * 365 + (month2 - month1) * 12 + (day2 - day1);
			std::cout << diversity << " " << title << " " << borrower << " " << checkoutDate << " " << returnDate << " " << borrowDate << std::endl;
			
		}
	}
	std::cout << "==================================================" << std::endl;
}
