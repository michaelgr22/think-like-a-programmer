#include "studentCollection.h"
#include "student.h"
#include <iostream>
using std::cin;
using std::cout;

void studentCollection::addRecord(int stuNum, int gr) {
    student newstudent = student(stuNum, gr);
    studentlist.push_back(newstudent);
}

double studentCollection::averageRecord() {
    int count = 0;
    double sum = 0;

    for (auto it = studentlist.begin(); it != studentlist.end(); ++it) {
        sum += it->grade;
        count++;
    }

    double average = sum / count;
    return average;
}

void studentCollection::showstudentCollection() {
    for (auto it = studentlist.begin(); it != studentlist.end(); ++it) {
        cout << it->studentNum << "\n";
    }
}
