/* @Author
 * Student Name:  Muhammed Yusuf Mermer
 * Student ID : 150220762
 */


#include "student.h"
#include <iostream>
using namespace std;

Student::Student(string n, float gpa, int gre, int toefl): name(n), GPA(gpa), GRE(gre), TOEFL(toefl)  { //member initilizers
	cout << name << " logged in to the system."<<endl;
}

Student::Student(const Student& other): name(other.name), GPA(other.GPA),GRE(other.GRE),TOEFL(other.TOEFL) { //member initilizers
	cout << name << " logged in to the system." << endl;
}

Student::~Student() {
	cout << name << " logged out of the system with " << numOfApp << " application(s)."<<endl; //there is no dynamic member varibles, so no need to delete a thing
}

void Student::set_name(string n) { //no need to make it const as const object won't use it
	name = n;

}

int  Student::getToefl()const{ //no change occurs, so we can make it const
	return TOEFL;
}
float Student::getGPA()const { //no change occurs, so we can make it const
	return GPA;
}
int Student::getGre()const {//no change occurs, so we can make it const
	return GRE;
}

string Student::getName()const {//no change occurs, so we can make it const
	return name;
}

void Student::plus1NumOfApp()const { //we used this method in const object, so we need to make this method const. 
	numOfApp++;   //To manipulate number of applications, we need to make it mutable to use it in const member function.
}



