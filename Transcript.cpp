#include "Transcript.h"

int Transcript::autoId = 10000;

istream& operator >> (istream& is, Transcript& subject) {
	subject.id = Transcript::autoId++;
	cout << "Nhap diem he so 1: ";
	is >> subject.gradeLevel1;
	cout << "Nhap diem he so 2: ";
	is >> subject.gradeLevel2;
	cout << "Nhap diem he so 3: ";
	is >> subject.gradeLevel3;
	cout << "Nhap diem he so 4: ";
	is >> subject.gradeLevel4;
	return is;
}

ostream& operator << (ostream& os, const Transcript& tran) {
	os << left << setw(10) << tran.getId() << setw(15) << tran.getStudent().getId()
		<< setw(10) << tran.getStudent().getLastName() << setw(20) << tran.getStudent().getMidName()
		<< setw(10) << tran.getStudent().getFirstName() << setw(10) << tran.getSubject().getId()
		<< setw(10) << tran.getSubject().getName() << setw(10) << tran.getGradeLevel1()
		<< setw(10) << tran.getGradeLevel2() << setw(10) << tran.getGradeLevel3()
		<< setw(10) << tran.getGradeLevel4() << setw(10) << setprecision(2) << tran.getGPA()
		<< setw(10) << tran.getRank() << endl;
	return os;
}

void Transcript::calculateGPA() {
	gpa = 0.1f * gradeLevel1 + 0.2f * gradeLevel3 + 0.3f * gradeLevel3 + 0.4f * gradeLevel4;
	string currentRank = "";
	if (gpa >= 9.0f) {
		currentRank = "A+";
	}
	else if (gpa >= 8.5f) {
		currentRank = "A";
	}
	else if (gpa >= 8.0f) {
		currentRank = "B+";
	}
	else if (gpa >= 7.0f) {
		currentRank = "B";
	}
	else if (gpa >= 6.0f) {
		currentRank = "C+";
	}
	else if (gpa >= 5.0f) {
		currentRank = "C";
	}
	else if (gpa >= 4.0f) {
		currentRank = "D";
	}
	else {
		currentRank = "F";
	}

	int len = currentRank.length();
	currentRank.copy(rank, len);
	rank[len] = '\0';
}

Transcript::Transcript() {
	id = 0;
	gpa = 0;
	gradeLevel1 = 0;
	gradeLevel2 = 0;
	gradeLevel3 = 0;
	gradeLevel4 = 0;
}

Transcript::Transcript(int id) : id(id) {
	gpa = 0;
	gradeLevel1 = 0;
	gradeLevel2 = 0;
	gradeLevel3 = 0;
	gradeLevel4 = 0;
}

Transcript::Transcript(const Student& st, const Subject& sj) {
	gpa = 0;
	gradeLevel1 = 0;
	gradeLevel2 = 0;
	gradeLevel3 = 0;
	gradeLevel4 = 0;
	setSubject(sj);
	setStudent(st);
}
	
Transcript::Transcript(int id, Student student, Subject subject, float gradeLevel1,
	float gradeLevel2, float gradeLevel3, float gradeLevel4, float gpa, string rank) {
	setId(id);
	setStudent(student);
	setSubject(subject);
	setGradeLevel1(gradeLevel1);
	setGradeLevel2(gradeLevel2);
	setGradeLevel3(gradeLevel3);
	setGradeLevel4(gradeLevel4);
	setGpa(gpa);
}
	
void Transcript::setId(int id) {
	this->id = id == 0 ? Transcript::autoId++ : id;
}

void Transcript::setStudent(const Student& student) {
	this->student = student;
}

void Transcript::setSubject(const Subject& subject) {
	this->subject = subject;
}

void Transcript::setRank(string rank) {
	int len = rank.size();
	len = len < 10 ? len : 9;
	rank.copy(this->rank, len);
	this->rank[len] = '\0';
}

void Transcript::setGradeLevel1(float gl1) {
	this->gradeLevel1 = gl1;
}

void Transcript::setGradeLevel2(float gl2) {
	this->gradeLevel2 = gl2;
}

void Transcript::setGradeLevel3(float gl3) {
	this->gradeLevel3 = gl3;
}

void Transcript::setGradeLevel4(float gl4) {
	this->gradeLevel4 = gl4;
}

void Transcript::setGpa(float gpa) {
	this->gpa = gpa;
}

string Transcript::getRank() const {
	return rank;
}

int Transcript::getId() const {
	return id;
}

Student Transcript::getStudent() const { return student; }
Subject Transcript::getSubject() const { return subject; }
float Transcript::getGradeLevel1() const { return gradeLevel1; }
float Transcript::getGradeLevel2() const { return gradeLevel2; }
float Transcript::getGradeLevel3() const { return gradeLevel3; }
float Transcript::getGradeLevel4() const { return gradeLevel4; }
float Transcript::getGPA() const { return gpa; }
bool Transcript::operator < (const Transcript& s) const {
	return gpa < s.gpa;
}
bool Transcript::operator == (const Transcript& s) const {
	return student.getId().compare(s.student.getId()) == 0
		&& subject.getId() == s.subject.getId();
}
bool Transcript::operator > (const Transcript& s) const {
	return gpa > s.gpa;
}