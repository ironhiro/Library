#include "TaskManager.h"
#include "ioHandler.h"

void TaskManager::insertMember(MemberList & mList)
{
	ioHandler ioh;
	char member_type = ioh.getMemberType();
	Member* m = ioh.getMember(member_type);

	if (mList.getCount() >= MAX_SIZE)
	{
		std::cout << "�迭 �ʰ�" << std::endl;
		return;
	}

	int index = mList.findMember(m->getID());
	if (index != NOT_FOUND) {
		std::cout << "ID �ߺ��Դϴ�." << std::endl;
		return;
	}

	mList.insertMemberList(m);
}

void TaskManager::deleteMember(MemberList & mList)
{
	ioHandler ioh;
	std::string id = ioh.getString("ID�� �Է��Ͻÿ�: ");
	int index = mList.findMember(id);
	if (index == NOT_FOUND)
	{
		std::cout << "�������� �ʴ� ������" << std::endl;
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
		std::cout << "�迭 �ʰ�" << std::endl;
		return;
	}

	int index = bList.findBook(b->getID());
	if (index != NOT_FOUND) {
		std::cout << "ID �ߺ��Դϴ�." << std::endl;
		return;
	}

	bList.insertBookList(b);
}

void TaskManager::deleteBook(BookList & bList)
{
	ioHandler ioh;
	std::string id = ioh.getString("ID�� �Է��Ͻÿ�: ");
	int index = bList.findBook(id);
	if (index == NOT_FOUND)
	{
		std::cout << "�������� �ʴ� å" << std::endl;
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
	std::string mid = ioh.getString("������ id �Է�: ");
	int member_index = mList.findMember(mid);
	std::string bid = ioh.getString("å id �Է�: ");
	int book_index = bList.findBook(bid);
	std::string checkoutDate = ioh.getString("����Ⱓ �Է�: ");
	
	int index = boList.findBorrowByID(bid);

	if (member_index == NOT_FOUND || book_index == NOT_FOUND)
	{
		std::cout << "�������� �������� �ʰų� �������� �ʴ� å�Դϴ�." << std::endl;
		return;
	}
	else if (index != NOT_FOUND)
	{
		std::cout << "�̹� ������ å�Դϴ�." << std::endl;
		return;
	}
	std::string diversity;
	if (bid[0] == 'M')
		diversity = "����";
	else
		diversity = "��������";
	std::string membername = mList.getMember(member_index)->getName();
	std::string bookname = bList.getBook(book_index)->getBookName();
	std::cout << "�̸�: " << membername << "," << "å����: " << bookname << std::endl;
	Borrow* b = new Borrow(diversity,bid,bookname, mid,membername, checkoutDate);
	boList.insertBorrowList(b);
}

void TaskManager::deleteBorrow(BorrowList & boList)
{
	ioHandler ioh;
	std::string bid = ioh.getString("åID �Է�: ");
	std::string returndate = ioh.getString("�ݳ��� �Է�: ");
	int index = boList.findBorrowByID(bid);
	if (index == NOT_FOUND)
	{
		std::cout << "�������� �ʰų� �������� �ʴ� å�Դϴ�. " << std::endl;
		return;
	}

	boList.getBorrow(index)->setReturn(returndate);
}

void TaskManager::displayBorrow(BorrowList boList,BookList& bList,MemberList& mList)
{
	std::cout << "==================================================" << std::endl;
	std::cout << "���� ������ ������ ������ �ݳ��� ����Ⱓ" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	for (int i = 0; i < boList.getCount(); i++)
	{
		int book_index = bList.findBook(boList.getBorrow(i)->getBookID());
		int member_index = mList.findMember(boList.getBorrow(i)->getBorrowerID());
		if (book_index == NOT_FOUND)
			continue;
		else if (member_index == NOT_FOUND)
		{
			
			std::string borrower = "������";
			std::string checkoutDate = boList.getBorrow(i)->getCheckOut();
			std::string returnDate = boList.getBorrow(i)->getReturn();
			if (returnDate == "��������")
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
			if (returnDate == "��������")
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
