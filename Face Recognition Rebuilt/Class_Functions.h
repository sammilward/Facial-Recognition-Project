#pragma once
#include <string>
#include <iostream>
#include <iostream>
#include <cstddef>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Windows.h"
#include <limits>


class Profile;

using namespace std;


class Profile {
public:
	Profile(int ID, string name, string DOB, bool isMale, string N_number, string course);
	Profile();
	~Profile();
	string getValues();
	void SaveProfile();

private:
	int ID;
	string name;
	string DOB;
	bool isMale;
	string N_number;
	string course;
	Profile* ptrProfile;
	Profile* ptrNextProfile;

};



Profile::Profile(int ID, string name, string DOB, bool isMale, string N_number, string course) {
	this->ID = ID;
	this->name = name;
	this->DOB = DOB;
	this->isMale = isMale;
	this->N_number = N_number;
	this->course = course;
	SaveProfile();

}
Profile::Profile() {

}
Profile::~Profile() {
	cout << "Profile destroyed" << endl;
}
string Profile::getValues() {
	return name;
}
void Profile::SaveProfile() {
	ofstream writer("Profiles.txt", ios_base::app);
	std::cout << ID << endl;
	writer << ID << "\t" << name << "\t" << DOB << "\t" << isMale << "\t" << N_number << "\t" << course << endl;
	writer.close();
} 