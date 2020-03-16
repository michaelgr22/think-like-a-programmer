#include "student.h"

student::student() {
	this->studentNum = 0;
	this->grade = 0;
}

student::student(int studentNum, int grade) {
	this->studentNum = studentNum;
	this->grade = grade;
}