#include "ioHandler.h"
#include <string>
#include <fstream>

int ioHandler::getMainMenu()
{
	while (1)
	{
		std::cout << "====================================================" << std::endl;
		std::cout << "  << ���� �޴� >> " << std::endl;
		std::cout << "  1).  ������ ����" << std::endl;
		std::cout << "  2).  ���� ����" << std::endl;
		std::cout << "  3).  ���� ����" << std::endl;
		std::cout << "  4).  ����" << std::endl;
		

		int select = getInteger("�޴���ȣ �Է�: ");

		if (select >= INSERT && select <= EXIT)
			return select;
	}
}

int ioHandler::getMemberMenu()
{
	while (1)
	{
		std::cout << "====================================================" << std::endl;
		std::cout << "  << ������ �޴� >> " << std::endl;
		std::cout << "  1).  ������ �߰�" << std::endl;
		std::cout << "  2).  ������ ����" << std::endl;
		std::cout << "  3).  ������ ���" << std::endl;
		std::cout << "  4).  ���� �޴�" << std::endl;


		int select = getInteger("�޴���ȣ �Է�: ");

		if (select >= INSERT && select <= EXIT)
			return select;
	}
}

int ioHandler::getBookMenu()
{
	while (1)
	{
		std::cout << "====================================================" << std::endl;
		std::cout << "  << ���� ���� �޴� >>" << std::endl;
		std::cout << "  1).  ���� �߰�" << std::endl;
		std::cout << "  2).  ���� ����" << std::endl;
		std::cout << "  3).  ���� ���" << std::endl;
		std::cout << "  4).  ���� �޴�" << std::endl;


		int select = getInteger("�޴���ȣ �Է�: ");

		if (select >= INSERT && select <= EXIT)
			return select;
	}
}

int ioHandler::getBorrowMenu()
{
	while (1)
	{
		std::cout << "====================================================" << std::endl;
		std::cout << "  << ���� ���� �޴� >>" << std::endl;
		std::cout << "  1).  ���� ����" << std::endl;
		std::cout << "  2).  ���� �ݳ�" << std::endl;
		std::cout << "  3).  ����/�ݳ� ���� ���" << std::endl;
		std::cout << "  4).  ���� �޴�" << std::endl;


		int select = getInteger("�޴���ȣ �Է�: ");

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

	std::string id = getString("id�Է�: ");
	std::string name = getString("�̸� �Է�: ");
	std::string department = getString("�а� �Է�: ");
	int grade = getInteger("�г� �Է�: ");
	std::string contact = getString("����ó �Է�: ");

	Student* s = new Student(id,name,department,grade,contact);
	return s;
}

Professor * ioHandler::getProfessor()
{
	std::string id = getString("id�Է�: ");
	std::string name = getString("�̸� �Է�: ");
	std::string department = getString("�а� �Է�: ");
	std::string major = getString("���� �Է�: ");

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
	std::string id = getString("id�Է�: ");
	std::string name = getString("������ �Է�: ");
	std::string publisher = getString("���ǻ� �Է�: ");
	std::string book_year = getString("���ǳ⵵ �Է�: ");
	int article = getInteger("��/ȣ �Է�: ");

	Megazine* m = new Megazine(id, name, publisher, book_year, article);
	return m;
}

MajoredBook * ioHandler::getMajoredBook()
{
	std::string id = getString("id�Է�: ");
	std::string name = getString("������ �Է�: ");
	std::string publisher = getString("���ǻ� �Է�: ");
	std::string book_year = getString("���ǳ⵵ �Է�: ");
	std::string subject = getString("���� �Է�: ");

	MajoredBook* b = new MajoredBook(id, name, publisher, book_year, subject);
	return b;
}



char ioHandler::getBookType()
{
	char book_type;
	while (1)
	{
		std::cout << std::endl;
		std::cout << "Type Member Type(M:����, B:���� ����) : ";
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
		std::cout << "Type Member Type(U:�л�, F:����) : ";
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
		std::cout << "������ �������� �ʽ��ϴ�." << std::endl;
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
		std::cout << "������ �������� �ʽ��ϴ�." << std::endl;
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
		std::cout << "������ �������� �ʽ��ϴ�." << std::endl;
	}
	else
	{
		std::string division, bid, bookname, mid, membername, checkoutDate, returnDate;
		while (!fin.eof())
		{
			fin >> division >> bid >> bookname >> mid >> membername >> checkoutDate >> returnDate;
			if (returnDate == "��������")
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
