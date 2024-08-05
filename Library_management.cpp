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

public:
	Library_management();
	void Library_add_member(int National_code);
	void Library_remove_member(int i);
	void Livrary_add_book(string *name, string *authar1);
	void Livrary_remove_book(string *name, string *authar1);
	void borrow(int i, string *name, string *authar1);
	void book_hire();
	void printmember(int i);
	void printid();
	~Library_management();
};

Library_management::Library_management()
{
	cout << "welcome" << endl;
}

void Library_management::Library_add_member(int National_code)
{
	for (size_t i = 0; i < id.size(); i += 4)
	{
		if (id.at(i) == National_code)
		{
			cout << "The user with this national code is a member and her username is "
				 << i + 1000 << endl;
				 return;
		}
	}

	id.push_back(National_code);
	id.push_back(0);
	id.push_back(0);
	id.push_back(0);
	cout << "username:" <<id.size()/4+999<< endl;
}

void Library_management::Library_remove_member(int b)
{
	size_t i;
	for (i = 0; i < id.size(); i += 4)
	{
		if (id.at(i) == b)
		{
			break;
		}
	}

	it = id.begin() + i;
	id.erase(it, it + 4);
}

void Library_management::Livrary_add_book(string *name, string *authar1)
{
	namebook.push_back(*name);
	authar.push_back(*authar1);
	hire.push_back(0);
	bprrower.push_back(0);
}

void Library_management::Livrary_remove_book(string *name, string *authar1)
{
	size_t i;
	for (i = 0; i < namebook.size(); i++)
	{
		if (namebook.at(i) == *name)
			if (authar.at(i) == *authar1)
				break;
	}
	it = id.begin() + i;
	its = namebook.begin() + i;
	namebook.erase(its);
	authar.erase(its);
	hire.erase(it);
	bprrower.erase(it);
}

void Library_management::borrow(int b, string *name, string *authar1)
{
	size_t i;
	for (i = 0; i < namebook.size(); i++)
	{
		if (namebook.at(i) == *name)
			if (authar.at(i) == *authar1)
			{
				hire.at(i) = 1;
				bprrower.at(i) = b;
			}
	}
}

void Library_management::book_hire()
{
	for (size_t i = 0; i < hire.size(); i++)
	{
		if (hire.at(i) == 1)
		{
			cout << "namebook = " << namebook.at(i) << " authar = " << authar.at(i)
				 << " id = " << bprrower.at(i) << endl;
		}
	}
}

void Library_management::printid()
{
	for (size_t i = 0; i < id.size(); i++)
	{
		cout << id.at(i) << ' ';
	}
}

void Library_management::printmember(int i)
{
	if (namebook.size() == 0)
		return;
	cout << namebook.at(i) << authar.at(i) << hire.at(i) << bprrower.at(i);
}

Library_management::~Library_management()
{
	cout << "\nfhffhh" << endl;
}

int main()
{
	Library_management o;
	o.Library_add_member(4812);
	o.Library_add_member(555);
	o.Library_add_member(4812);

	return 0;
}
