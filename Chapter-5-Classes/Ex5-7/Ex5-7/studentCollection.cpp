#include "studentCollection.h"
#include "student.h"
#include <iostream>
using std::cin;
using std::cout;

void studentCollection::addRecord(firstStudent& sc, int stuNum, int gr) {
    student* newNode = new student;
    newNode->studentNum = stuNum;
    newNode->grade = gr;
    newNode->next = sc;
    sc = newNode;
}

double studentCollection::averageRecord(firstStudent sc) {
    int count = 0;
    double sum = 0;
    student* loopPtr = sc;
    while (loopPtr != NULL) {
        sum += loopPtr->grade;
        count++;
        loopPtr = loopPtr->next;
    }
    double average = sum / count;
    return average;
}

void studentCollection::showstudentCollection(firstStudent sc) {
    student* loopPtr = sc;
    while (loopPtr != NULL) {
        cout << loopPtr->studentNum << "\n";
        loopPtr = loopPtr->next;
    }
}
