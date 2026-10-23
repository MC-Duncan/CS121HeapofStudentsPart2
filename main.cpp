#include <iostream>
#include "dates.h"
#include "address.h"
#include "student.h"

void loadStudents(std::vector<Student*>&);
void printStudents(std::vector<Student*>&);
void showStudentNames(std::vector<Student*>&);
void findStudent(std::vector<Student*>&);
void delStudents(std::vector<Student*>&);
std::string menu();

// test functions
void testAddress();
void testDate();
void testStudent();

int main(){
  /*
  std::cout << "Hello!" << std::endl;
  testAddress();
  testDate();
  testStudent();
  return 0;
  */

  std::vector<Student*> students;

  loadStudents(students);
  bool keepGoing = true;
  while (keepGoing){
    std::string userChoice = menu();

      if (userChoice == "0"){
        keepGoing = false
      } // end if
      
      if (userChoice == "1"){
        showStudentNames(students);
      } // end if
      
      if (userChoice == "2"{)
        printStudents(students);
      } // end if
      
      if (userChoice == "3"){
	findStudent(students);
      } // end if

      else {
	std::cout << "Please enter a valid input." << std::endl;
      } // end else
  } // end while
  delStudents(students);
  return 0;
} // end main

void loadStudents(std::vector<Student*>& students){
  std::ifstream inFile;
  std::string currentLine;

  inFile.open("students.csv");
  while(getline(inFile, currentLine)){
    Student* s = new Student;
    s->init(currentLine);
    students.push_back(s);
  } // end while
  inFile.close();
} // end loadStudents

void printStudents(std::vector<Student*>&){
  for (Student* student: students){
    std::cout << student->printStudent() << std::endl;
    std::cout << "____________________________________" << std::endl;
  } // end for
} // end printStudents

void showStudentNames(std::vector<Student*>& students){
  for (Student* student: students){
    std::cout << student->getLastFirst();
    std::cout << ", " << student->getCreditHours() << std::endl;
  } // end for
> // end showStudentNames

void findStudent(std::vector<Student*>& students){


} // end findStudent

void delStudents(std::vector<Student*>&){
  for (Student* student: students){
    delete students
  } // end for
} // end delStudents

std::string menu(){
  std::cout << "Please choose 0-3: "


} // end string menu


//test functions
void testAddress(){
  Address a;
  a.init("123 W Main St", "Muncie", "IN", "47303");
  a.printAddress();
} // end testAddress

void testDate(){
 Dates d;
 d.init("01/27/1997");
 d.printDate();
} // end testDate

void testStudent(){
  std::string studentString = "Danielle,Johnson,32181 Johnson Course Apt. 389,New Jamesside,IN,59379,02/17/2004,05/15/2027,65";
  Student* student = new Student();
  student->init(studentString);
  student->printStudent();
  std::cout << std::endl;
  std::cout << student->getLastFirst();
  delete student;
} // end testStudent
