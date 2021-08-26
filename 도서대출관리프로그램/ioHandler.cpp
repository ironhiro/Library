#include "ioHandler.h"
#include <string>
#include <fstream>

int ioHandler::getMainMenu()
{
	while (1)
	{
		std::cout << "====================================================" << std::endl;
		std::cout << "  << 메인 메뉴 >> " << std::endl;
		std::cout << "  1).  구성원 관리" << std::endl;
		std::cout << "  2).  도서 관리" << std::endl;
		std::cout << "  3).  대출 관리" << std::endl;
		std::cout << "  4).  종료" << std::endl;
		

		int select = getInteger("메뉴번호 입력: ");

		if (select >= INSERT && select <= EXIT)
			return select;
	}
}

int ioHandler::getMemberMenu()
{
	while (1)
	{
		std::cout << "====================================================" << std::endl;
		std::cout << "  << 구성원 메뉴 >> " << std::endl;
		std::cout << "  1).  구성원 추가" << std::endl;
		std::cout << "  2).  구성원 삭제" << std::endl;
		std::cout << "  3).  구성원 출력" << std::endl;
		std::cout << "  4).  메인 메뉴" << std::endl;


		int select = getInteger("메뉴번호 입력: ");

		if (select >= INSERT && select <= EXIT)
			return select;
	}
}

int ioHandler::getBookMenu()
{
	while (1)
	{
		std::cout << "====================================================" << std::endl;
		std::cout << "  << 도서 관리 메뉴 >>" << std::endl;
		std::cout << "  1).  도서 추가" << std::endl;
		std::cout << "  2).  도서 삭제" << std::endl;
		std::cout << "  3).  도서 출력" << std::endl;
		std::cout << "  4).  메인 메뉴" << std::endl;


		int select = getInteger("메뉴번호 입력: ");

		if (select >= INSERT && select <= EXIT)
			return select;
	}
}

int ioHandler::getBorrowMenu()
{
	while (1)
	{
		std::cout << "====================================================" << std::endl;
		std::cout << "  << 대출 관리 메뉴 >>" << std::endl;
		std::cout << "  1).  도서 대출" << std::endl;
		std::cout << "  2).  도서 반납" << std::endl;
		std::cout << "  3).  대출/반납 정보 출력" << std::endl;
		std::cout << "  4).  메인 메뉴" << std::endl;


		int select = getInteger("메뉴번호 입력: ");

		if (select >= INSERT && select <= EXIT)
			return select;
	}
}

int ioHandler::getInteger(std::string msg)
{
	int a;
	std::cout << msg;
	std::cin >> a;
	return a;
}

std::string ioHandler::getString(std::string msg)
{
	std::string a;
	std::cout << msg;
	std::cin >> a;
	return a;
}

Member * ioHandler::getMember(char member_type)
{
	Member* m;
	if (member_type == 'F')
		m = getProfessor();
	else
		m = getStudent();
	return m;
}

Student * ioHandler::getStudent()
{

	std::string id = getString("id입력: ");
	std::string name = getString("이름 입력: ");
	std::string department = getString("학과 입력: ");
	int grade = getInteger("학년 입력: ");
	std::string contact = getString("연락처 입력: ");

	Student* s = new Student(id,name,department,grade,contact);
	return s;
}

Professor * ioHandler::getProfessor()
{
	std::string id = getString("id입력: ");
	std::string name = getString("이름 입력: ");
	std::string department = getString("학과 입력: ");
	std::string major = getString("전공 입력: ");

	Professor* p = new Professor(id, name, department, major);
	return p;
}

Book * ioHandler::getBook(char book_type)
{
	Book* b;
	if (book_type == 'M')
		b = getMegazine();
	else
		b = getMajoredBook();
	return b;
}

Megazine * ioHandler::getMegazine()
{
	std::string id = getString("id입력: ");
	std::string name = getString("도서명 입력: ");
	std::string publisher = getString("출판사 입력: ");
	std::string book_year = getString("출판년도 입력: ");
	int article = getInteger("권/호 입력: ");

	Megazine* m = new Megazine(id, name, publisher, book_year, article);
	return m;
}

MajoredBook * ioHandler::getMajoredBook()
{
	std::string id = getString("id입력: ");
	std::string name = getString("도서명 입력: ");
	std::string publisher = getString("출판사 입력: ");
	std::string book_year = getString("출판년도 입력: ");
	std::string subject = getString("주제 입력: ");

	MajoredBook* b = new MajoredBook(id, name, publisher, book_year, subject);
	return b;
}



char ioHandler::getBookType()
{
	char book_type;
	while (1)
	{
		std::cout << std::endl;
		std::cout << "Type Member Type(M:잡지, B:전공 서적) : ";
		std::cin >> book_type;

		if (book_type == 'M' || book_type == 'B')
			return book_type;
	}
}

char ioHandler::getMemberType()
{
	char member_type;
	while (1)
	{
		std::cout << std::endl;
		std::cout << "Type Member Type(U:학생, F:교수) : ";
		std::cin >> member_type;

		if (member_type == 'F' || member_type == 'U')
			return member_type;
	}
	
}

void ioHandler::loadMember(MemberList & mList)
{
	std::ifstream fin("member.dat");

	if (!fin)
	{
		std::cout << "파일이 존재하지 않습니다." << std::endl;
	}
	else
	{
		std::string id, name, department, major, contact;
		int grade;
		while (!fin.eof())
		{
			fin >> id >> name >> department;
			if (id[0] == 'F')
			{
				fin >> major;
				Professor* p = new Professor(id, name, department, major);
				mList.insertMemberList(p);
			}
			else if (id[0] == 'U')
			{
				fin >> grade >> contact;
				Student* s = new Student(id, name, department, grade, contact);
				mList.insertMemberList(s);
			}
		}
	}
}

void ioHandler::loadBook(BookList & bList)
{
	std::ifstream fin("book.dat");

	if (!fin)
	{
		std::cout << "파일이 존재하지 않습니다." << std::endl;
	}
	else
	{
		std::string id, name, publisher, publish_year, subject;
		int volume;
		while (!fin.eof())
		{
			fin >> id >> name >> publisher >> publish_year;
			if (id[0] == 'M')
			{
				fin >> volume;
				Megazine* m = new Megazine(id,name,publisher,publish_year,volume);
				bList.insertBookList(m);
			}
			else if (id[0] == 'B')
			{
				fin >> subject;
				MajoredBook* b = new MajoredBook(id, name, publisher, publish_year, subject);
				bList.insertBookList(b);
			}
		}
	}
}

void ioHandler::loadBorrow(BorrowList & bList)
{
	std::ifstream fin("borrow.dat");

	if (!fin)
	{
		std::cout << "파일이 존재하지 않습니다." << std::endl;
	}
	else
	{
		std::string division, bid, bookname, mid, membername, checkoutDate, returnDate;
		while (!fin.eof())
		{
			fin >> division >> bid >> bookname >> mid >> membername >> checkoutDate >> returnDate;
			if (returnDate == "정보없음")
			{
				Borrow* b = new Borrow(division, bid, bookname, mid, membername, checkoutDate);
				bList.insertBorrowList(b);
			}
			else
			{
				Borrow* b = new Borrow(division, bid, bookname, mid, membername, checkoutDate);
				b->setReturn(returnDate);
				bList.insertBorrowList(b);
			}
		}
		
	}
	fin.close();
}

void ioHandler::saveMember(MemberList mList)
{
	std::ofstream out("member.dat");
	int count = mList.getCount();
	for (int i = 0; i < count; i++)
	{
		Member* m = mList.getMember(i);
		m->putFile(out);
		if (i < count - 1)
			out << std::endl;
		
	}
	out.close();
}

void ioHandler::saveBook(BookList bList)
{
	std::ofstream out("book.dat");
	int count = bList.getCount();
	for (int i = 0; i < count; i++)
	{
		Book* b = bList.getBook(i);
		b->putFile(out);
		if (i < count - 1)
			out << std::endl;
	}
	out.close();
}

void ioHandler::saveBorrow(BorrowList bList)
{
	std::ofstream out("borrow.dat");
	int count = bList.getCount();
	for (int i = 0; i < count; i++)
	{
		Borrow* b = bList.getBorrow(i);
		b->putFile(out);
		if (i < count - 1)
			out << std::endl;
	}
	out.close();
}
