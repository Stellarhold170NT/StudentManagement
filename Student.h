#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Person.h"
using namespace std;

class Student : public Person {
	friend istream& operator >> (istream&, Student&);
	friend ostream& operator << (ostream&, const Student&);
	char studentId[20];
	char major[40];
	char schoolYear[20];
public:
	Student();
	Student(string studentId);
	Student(string studentId, string major, string schoolYear);
	string getStudentId() const;
	string getMajor() const;
	string getSchoolYear() const;
	void setStudentId(string id);
	void setMajor(string major);
	void setSchoolYear(string schoolYear);
	bool operator < (const Student&) const;
	bool operator == (const Student&) const;
	bool operator > (const Student&) const;
};
