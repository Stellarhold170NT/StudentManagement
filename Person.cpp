#include "Person.h"


Person:: Person() {};

Person::Person(string id) {
	setId(id);
}

Person::Person(string id, string first, string last,
	string mid, string email, string address, string phone) {
	setId(id);
	setFirstName(first);
	setLastName(last);
	setMidName(mid);
	setEmail(email);
	setAddress(address);
	setPhoneNumber(phoneNumber);
}

void Person::setId(string id) {
	int len = id.size();
	len = len < 20 ? len : 19;
	id.copy(this->id, len);
	this->id[len] = '\0';
}

void Person::setFirstName(string firstName) {
	int len = firstName.size();
	len = len < 20 ? len : 19;
	firstName.copy(this->firstName, len);
	this->firstName[len] = '\0';
}

void Person::setLastName(string lastName) {
	int len = lastName.size();
	len = len < 20 ? len : 19;
	lastName.copy(this->lastName, len);
	this->lastName[len] = '\0';
}

void Person::setMidName(string midName) {
	int len = midName.size();
	len = len < 20 ? len : 19;
	midName.copy(this->midName, len);
	this->midName[len] = '\0';
}

void Person::setAddress(string address) {
	int len = address.size();
	len = len < 40 ? len : 39;
	address.copy(this->address, len);
	this->address[len] = '\0';
}

void Person::setPhoneNumber(string phoneNumber) {
	int len = phoneNumber.size();
	len = len < 20 ? len : 19;
	phoneNumber.copy(this->phoneNumber, len);
	this->phoneNumber[len] = '\0';
}

void Person::setEmail(string email) {
	int len = email.size();
	len = len < 40 ? len : 39;
	email.copy(this->email, len);
	this->email[len] = '\0';
}

string Person::getId() const {
	return id;
}


string Person::getFirstName() const {
	return firstName;
}

string Person::getLastName() const {
	return lastName;
}

string Person::getMidName() const {
	return midName;
}

string Person::getEmail() const {
	return email;
}

string Person::getAddress() const {
	return address;
}

string Person::getPhoneNumber() const {
	return phoneNumber;
}

bool Person::operator < (const Person& other) const {
	return strcmp(firstName, other.firstName) < 0;
}

bool Person::operator == (const Person& other) const {
	return strcmp(id, other.id) == 0;
}

bool Person::operator > (const Person& other) const {
	return strcmp(firstName, other.firstName) > 0;
}