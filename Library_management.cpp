#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Library_management
{
private:
	vector<string> namebook;
	vector<string> authar;
	vector<int> hire;
	vector<int> bprrower;

	vector<int> id;
	vector<int>::iterator it;
	vector<string>::iterator its;
	bool __book_hire__(int National_code)
	{
		int flg{1};
		for (size_t i = 0; i < bprrower.size(); i++)
		{
			if (bprrower.at(i) == National_code)
			{
				flg = 0;
				cout << "namebook : " << namebook.at(i) << " authar : " << authar.at(i) << endl;
			}
		}
		return flg;
	}

public:
	Library_management();
	void Library_add_member(int National_code);
	void Library_remove_member(int National_code);
	void Livrary_add_book(string *name, string *authar1);
	void Livrary_remove_book(string *name, string *authar1);
	void book_hire(int National_code);
	void borrow(int National_code, string *name, string *authar1);
	void Return_book(int National_code, string *name, string *authar1);
	void Borrowed_books();
	~Library_management();
};

Library_management::Library_management()
{
	cout << "welcome" << endl;
}

void Library_management::Library_add_member(int National_code)
{
	for (size_t i = 0; i < id.size(); i++)
	{
		if (id.at(i) == National_code)
		{
			cout << "The user with national code " << National_code << " is a member." << endl;
			return;
		}
	}

	id.push_back(National_code);
	cout << "username:" << National_code << endl;
}

void Library_management::Library_remove_member(int National_code)
{
	if (__book_hire__(National_code))
	{
		for (size_t i = 0; i < id.size(); i++)
		{
			if (id.at(i) == National_code)
			{
				it = id.begin() + i;
				id.erase(it);
				cout << "The user with national code " << National_code
					 << " was deleted." << endl;
				return;
			}
		}
	}
	else
	{
		cout << "The user with national code " << National_code
			 << " has not returned the above books." << endl;
	}
}

void Library_management::Livrary_add_book(string *name, string *authar1)
{
	namebook.push_back(*name);
	authar.push_back(*authar1);
	hire.push_back(0);
	bprrower.push_back(0);
	cout << "The book was added to the library." << endl;
}

void Library_management::Livrary_remove_book(string *name, string *authar1)
{
	for (size_t i = 0; i < namebook.size(); i++)
	{
		if (namebook.at(i) == *name)
		{
			if (authar.at(i) == *authar1)
			{
				its = namebook.begin() + i;
				namebook.erase(its);
				its = authar.begin() + i;
				authar.erase(its);
				it = hire.begin() + i;
				hire.erase(it);
				it = bprrower.begin() + i;
				bprrower.erase(it);
				cout << "The book was removed from the library." << endl;
				return;
			}
		}
	}
	cout << "The book was not found." << endl;
}

void Library_management::book_hire(int National_code)
{
	__book_hire__(National_code);
}

void Library_management::borrow(int National_code, string *name, string *authar1)
{
	for (size_t i = 0; i < namebook.size(); i++)
	{
		if (namebook.at(i) == *name)
			if (authar.at(i) == *authar1)
			{
				if (hire.at(i) == 0)
				{
					hire.at(i) = 1;
					bprrower.at(i) = National_code;
					cout << "The book was loaned." << endl;
				}
				else
				{
					cout << "The book has already been lent." << endl;
				}
				return;
			}
	}
	cout << "The book was not found." << endl;
}

void Library_management::Return_book(int National_code, string *name, string *authar1)
{
	for (size_t i = 0; i < namebook.size(); i++)
	{
		if (namebook.at(i) == *name)
			if (authar.at(i) == *authar1)
			{
				hire.at(i) = 0;
				bprrower.at(i) = 0;
				cout << "The book returned to the library." << endl;
				return;
			}
	}
	cout << "The book was not found." << endl;
}

void Library_management::Borrowed_books()
{
	for (size_t i = 0; i < namebook.size(); i++)
	{
		if (hire.at(i) == 0)
		{
			cout << "namebook : " << namebook.at(i) << " authar : " << authar.at(i) << endl;
		}
	}
}

Library_management::~Library_management()
{
	cout << "fhffhh" << endl;
}

int main()
{
	string a = "mohammad";
	string b = "esteghmat";
	Library_management o;
	o.Library_add_member(4812);
	o.Library_add_member(444);
	o.Library_add_member(4812);
	o.Livrary_add_book(&a, &b);
	o.Borrowed_books();
	o.borrow(4812, &a, &b);
	o.Borrowed_books();
	o.borrow(444, &a, &b);
	o.borrow(444, &b, &a);
	o.book_hire(4812);
	o.Return_book(4812, &a, &b);
	o.Library_remove_member(4812);
	o.Library_remove_member(444);
	return 0;
}
