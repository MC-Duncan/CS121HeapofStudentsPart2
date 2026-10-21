#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS

#include <string>
#include "dates.h"
#include "address.h"

class Student{
  private:
    std::string studentString;
    std::string firstName;
    std::string lastName;
    Dates* dob;
    Dates* expectedGrad;
    Address* address;
    int creditHours;

  public:
    Student();
    Student(std::string studentString);
    ~Student();
    void init(std::string studentString);
    void printStudent();
    std::string getLastFirst();
}; // end class def

#endif
