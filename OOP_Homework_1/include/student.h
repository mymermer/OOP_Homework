/* @Author
 * Student Name:  Muhammed Yusuf Mermer
 * Student ID : 150220762
 */

#pragma once
#include <string>
using namespace std;
class Student {
public:
	Student(string n, float gpa, int gre, int toefl); //student consturctor for intilaization
	Student(const Student &); //copy consturctor
	~Student(); 
	void set_name(string);
	float getGPA() const;
	int getGre() const;
	int getToefl() const;
	void plus1NumOfApp()const;  //add 1 more to the number of Applications
	string getName()const;
private:
	string name{""}; //initally empty, name of the student
	const float GPA{}; //initally 0, GPA
	const int GRE{}, TOEFL{}; //initially 0, TOEFL and GRE
	mutable int numOfApp{};//initially 0, number of Applications =>>> To manipulate number of applications, we need to make it mutable to use it in const member function.

};
