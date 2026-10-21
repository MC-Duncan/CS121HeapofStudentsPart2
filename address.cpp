#include "address.h"
#include <iostream>
#include <sstream>

Address::Address(){
  street = "";
  city = "";
  state = "";
  zip = "";
} // end constructor

void Address::init(std::string street, std::string city, std::string state, std::string zip){
  Address::street = street;
  Address::city = city;
  Address::state = state;
  Address::zip = zip;
} // end init

std::string Address::getAddressStr() {
  std::stringstream ss;
  ss << street << std::endl << city << ", " << state << "  " << zip;
  return ss.str();
}

void Address::printAddress(){
   std::cout << getAddressStr() << std::endl;
} // end printAddress
