#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person {
	char id[20];
	char firstName[20];
	char lastName[20];
	char midName[20];
	char address[40];
	char email[40];
	char phoneNumber[20];

public:
	Person();
	Person(string id);
	Person(string id, string first, string last,
		string mid, string email, string address, string phone);
	void setId(string id);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setMidName(string midName);
	void setAddress(string address);
	void setPhoneNumber(string phoneNumber);
	void setEmail(string email);
	string getId() const;
	string getFirstName() const;
	string getLastName() const;
	string getMidName() const;
	string getEmail() const;
	string getAddress() const;
	string getPhoneNumber() const;
	bool operator < (const Person&) const;
	bool operator == (const Person&) const;
	bool operator > (const Person&) const;
};