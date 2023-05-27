/* @Author
 * Student Name:  Muhammed Yusuf Mermer
 * Student ID : 150220762
 */


#include "university.h"
University::University(string n, float gpa, float gre, float toefl, float b, string c) : name{ n }, gpaW{gpa}, greW(gre),toeflW(toefl),bias(b), country(c) {}//just member initilizer is enough.
void University::evaluate_student(const Student& st) const { //doesn't change a thing in university class, therfore it's constant
	if (st.getGPA() * gpaW + st.getGre() * greW + st.getToefl() * toeflW + bias > 0) {//perceptron
		cout << st.getName() << " is admitted to " << name<<"."<<endl;
		st.plus1NumOfApp();     //increase by 1 as they applied
	}
	else {
		cout << st.getName() << " is rejected from " << name << "."<<endl;
		st.plus1NumOfApp();       //increase by 1 as they applied
	}

}