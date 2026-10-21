#include "student.h"
#include <iostream>
#include <sstream>
#include "address.h"
#include "dates.h"

Student::Student(){
  studentString = "";
  firstName = "";
  lastName = "";
  dob = new Dates();
  expectedGrad = new Dates();
  address = new Address();
  creditHours = 0;
} // end constructor

Student::Student(std::string studentString){
  Student::init(studentString);
}

Student::~Student(){
  delete dob;
  delete expectedGrad;
  delete address;
} // end destructor


void Student::init(std::string studentString){
  Student::studentString = studentString;

  // make a stringstream
  std::stringstream ss;
  std::string street;
  std::string city;
  std::string state;
  std::string zip;

  std::string tFirstName;
  std::string tLastName;
  std::string tDob;
  std::string tGradDate;
  std::string tCreditHours;

  ss.str(studentString);
  
  getline(ss, tFirstName, ',');
  getline(ss, tLastName, ',');
  getline(ss, street, ',');
  getline(ss, city, ',');
  getline(ss, state, ',');
  getline(ss, zip, ',');
  getline(ss, tDob, ',');
  getline(ss, tGradDate, ',');
  getline(ss, tCreditHours);

  firstName = tFirstName;
  lastName = tLastName;
  address->init(street, city, state, zip);
  dob->init(tDob);
  expectedGrad->init(tGradDate);

  ss.clear();
  ss.str(tCreditHours);
  ss >> creditHours;

} // end init

void Student::printStudent(){
  std::cout << firstName << " " << lastName << std::endl;
  std::cout << address->getAddressStr() << std::endl;
  std::cout << "DOB: " << dob->getDateStr() << std::endl;
  std::cout << "Grad: " << expectedGrad->getDateStr() << std::endl;
  std::cout << "Credits: " << creditHours << std::endl;

} // end printStudent

std::string Student::getLastFirst(){
  std::string lastFirst = lastName + " " + firstName;
  return lastFirst;
} // end getLastFirst
