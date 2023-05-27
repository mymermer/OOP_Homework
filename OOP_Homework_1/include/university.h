/* @Author
 * Student Name:  Muhammed Yusuf Mermer
 * Student ID : 150220762
 */


#pragma once
#include <string>
#include "student.h"
#include<iostream>
using namespace std;

class University {
public:
	University(string n, float gpa, float gre, float toefl, float bias, string c=""); // country name didn't given for some object initlizations, so it is better to have default value for it.
	void evaluate_student(const Student&) const;  // reference assignment, no new object created for this operation

private:
	const string name{} ;//name of school, empty
	const float gpaW, greW, toeflW; //weight of GPA,GRE and TOEFL. All are random 
	const float bias;//bias, random value
	const string country{""};//country is empty intially
	

};