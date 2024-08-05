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
	int username;

public:
	Library_management();
	void Library_add_member();
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
	username = 1000;
	cout << "welcome" << endl;
}

void Library_management::Library_add_member()
{
	id.push_back(username);
	id.push_back(0);
	id.push_back(0);
	id.push_back(0);
	cout << "username:" << username << endl;
	username++;
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
	cout << "\nvb" << endl;
}

int main()
{
	Library_management o;
	o.Library_add_member();
	string a = "mohamad";
	string b = "esteghamat";
	string *q, *e;
	q = &a;
	e = &b;
	o.Livrary_add_book(q, e);
	cout<<"\naaaaaaddddd----------\n";
	o.borrow(1000,q,e);
	cout<<"\namanat----------------\n";
	o.book_hire();
	cout<<"\nprint hire-------------------\n";
	o.Livrary_remove_book(q, e);
	cout<<"\nremov-----------------------------\n";
	o.printmember(0);

	return 0;
}
