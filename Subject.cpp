#include "Subject.h"

int Subject::autoIncrementId = 10000;

istream& operator >> (istream& is, Subject& subject) {
	cout << "Ten mon: ";
	is.getline(subject.name, 40);
	cout << "So tin chi: ";
	is >> subject.credit;
	subject.setId(Subject::autoIncrementId++);
	return is;
}

ostream& operator << (ostream& os, const Subject& subject) {
	os << left << setw(15) << subject.id << setw(30) << subject.name
		<< setw(15) << subject.credit << endl;
	return os;
}

Subject::Subject() {
	id = 0;
	credit = 0;
}

Subject::Subject(int id) : id(id) {
	credit = 0;
}

Subject::Subject(int id, string name, int credit) {
	setId(id);
	setName(name);
	setCredit(credit);
}

int Subject::getId() const {
	return id;
}

string Subject::getName() const {
	return name;
}

int Subject::getCredit() const {
	return credit;
}

int Subject::getAutoIncrementId() {
	return autoIncrementId;
}

void Subject::setId(int id) {
	this->id = id;
}

void Subject::setName(string name) {
	int len = name.size();
	len = len < 40 ? len : 39;
	name.copy(this->name, len);
	this->name[len] = '\0';
}

void Subject::setCredit(int credit) {
	this->credit = credit;
}

void Subject::setAutoIncrementId(int autoId) {
	Subject::autoIncrementId = autoId;
}

bool Subject::operator < (const Subject& s) const {
	return getName().compare(s.getName()) < 0;
}

bool Subject::operator == (const Subject& s) const {
	return id == s.id;
}

bool Subject::operator > (const Subject& s) const {
	return getName().compare(s.getName()) > 0;
}