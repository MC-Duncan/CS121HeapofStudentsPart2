#include "dates.h"
#include <iostream>
#include <sstream>
#include <string>

Dates::Dates(){
  month = 1;
  day = 1;
  year = 2000;
} // end constructor

void Dates::init(std::string dateString){
  // make a stringstream
  Dates::dateString = dateString;
  std::stringstream ss;
  std::string tMonth;
  std::string tDay;
  std::string tYear;
  
  ss.clear();
  ss.str(Dates::dateString);

  // convert to temp strings
  getline(ss, tMonth, '/');
  getline(ss, tDay, '/');
  getline(ss, tYear, '/');

  ss.clear();
  ss.str("");

  // convert to ints
  std::stringstream converter;
  converter << tMonth << " " << tDay << " " << tYear;
  converter >> month >> day >> year;
} // end init

std::string Dates::getDateStr() {
  std::stringstream ss;
  std::string months[] = {"Null", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  ss << months[month] << " " << std::to_string(day) << ", " << std::to_string(year);
  return ss.str();
}

void Dates::printDate(){
  std::cout << getDateStr() << std::endl;
} // end printDate
