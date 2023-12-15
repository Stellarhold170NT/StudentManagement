#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;

class Subject {
	friend istream& operator >> (istream&, Subject&);
	friend ostream& operator << (ostream&, const Subject&);
	static int autoIncrementId;
	int id;
	char name[40];
	int credit;
public:
	Subject();
	Subject(int id);
	Subject(int id, string name, int credit);
	int getId() const;
	string getName() const;
	int getCredit() const;
	static int getAutoIncrementId();
	void setId(int id);
	void setName(string name);
	void setCredit(int credit);
	static void setAutoIncrementId(int autoId);
	bool operator < (const Subject&) const;
	bool operator == (const Subject&) const;
	bool operator > (const Subject&) const;
};