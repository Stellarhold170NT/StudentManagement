#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Student.h"
#include "Subject.h"
using namespace std;

class Transcript {
	friend istream& operator >> (istream&, Transcript&);
	friend ostream& operator << (ostream&, const Transcript&);
	static int autoId;
	int id;
	Student student;
	Subject subject;
	float gradeLevel1;
	float gradeLevel2;
	float gradeLevel3;
	float gradeLevel4;
	float gpa;
	char rank[10];
public:
	Transcript();
	Transcript(int id);
	Transcript(const Student& st, const Subject& sj);
	Transcript(int id, Student student, Subject subject, float gradeLevel1,
		float gradeLevel2, float gradeLevel3, float gradeLevel4, float gpa = 0, string rank = "");
	void setId(int id);
	void setStudent(const Student& student);
	void setSubject(const Subject& subject);
	void setRank(string rank);
	void setGradeLevel1(float gl1);
	void setGradeLevel2(float gl2);
	void setGradeLevel3(float gl3);
	void setGradeLevel4(float gl4);
	void setGpa(float gpa);
	string getRank() const;
	int getId() const;
	Student getStudent() const;
	Subject getSubject() const;
	float getGradeLevel1() const;
	float getGradeLevel2() const;
	float getGradeLevel3() const;
	float getGradeLevel4() const;
	float getGPA() const;
	bool operator < (const Transcript&) const;
	bool operator == (const Transcript&) const;
	bool operator > (const Transcript&) const;
	void calculateGPA();
};
