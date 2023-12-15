#include "Student.h"

istream& operator >> (istream& is, Student& student) {
	string id;
	string firstName;
	string lastName;
	string midName;
	string email;
	string address;
	string phoneNumber;

	cout << "So CMND/CC/Ho chieu: ";
	getline(is, id);
	cout << "Ho: ";
	getline(is, lastName);
	cout << "Dem: ";
	getline(is, midName);
	cout << "Ten: ";
	getline(is, firstName);
	cout << "Dia chi: ";
	getline(is, address);
	cout << "Email: ";
	getline(is, email);
	cout << "So dien thoai: ";
	getline(is, phoneNumber);
	cout << "Ma sinh vien: ";
	is.getline(student.studentId, 20);
	cout << "Chuyen nganh: ";
	is.getline(student.major, 40);
	cout << "Nien khoa: ";
	is.getline(student.schoolYear, 20);
	student.setId(id);
	student.setFirstName(firstName);
	student.setLastName(lastName);
	student.setMidName(midName);
	student.setEmail(email);
	student.setAddress(address);
	student.setPhoneNumber(phoneNumber);
	return is;
}

ostream& operator << (ostream& os, const Student& student) {
	os << left << setw(20) << student.getId() << setw(15) << student.studentId
		<< setw(10) << student.getLastName() << setw(20) << student.getMidName()
		<< setw(10) << student.getFirstName() << setw(30) << student.getEmail()
		<< setw(30) << student.getAddress() << setw(15) << student.getPhoneNumber()
		<< setw(30) << student.major << setw(15) << student.schoolYear << endl;
	return os;
}

Student::Student() {};

Student::Student(string studentId) {
	setStudentId(studentId);
}

Student::Student(string studentId, string major, string schoolYear) {
	setStudentId(studentId);
	setMajor(major);
	setSchoolYear(schoolYear);
}

string Student::getStudentId() const { return studentId; }

string Student::getMajor() const { return major; }

string Student::getSchoolYear() const { return schoolYear; }

void Student::setStudentId(string id) {
	int len = id.size();
	len = len < 20 ? len : 19;
	id.copy(this->studentId, len);
	this->studentId[len] = '\0';
}

void Student::setMajor(string major) {
	int len = major.size();
	len = len < 40 ? len : 39;
	major.copy(this->major, len);
	this->major[len] = '\0';
}
void Student::setSchoolYear(string schoolYear) {
	int len = schoolYear.size();
	len = len < 20 ? len : 19;
	schoolYear.copy(this->schoolYear, len);
	this->schoolYear[len] = '\0';
}

bool Student::operator < (const Student& s) const {
	return getFirstName().compare(s.getFirstName()) < 0;
}

bool Student::operator == (const Student& s) const {
	return strcmp(studentId, s.studentId) == 0;
}

bool Student::operator > (const Student& s) const {
	return getFirstName().compare(s.getFirstName()) > 0;
}