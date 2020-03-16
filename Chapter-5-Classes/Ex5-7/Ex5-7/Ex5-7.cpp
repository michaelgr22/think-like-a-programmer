#include <iostream>
#include "studentCollection.h"
#include "student.h"
using namespace std;
using std::cin;
using std::cout;

int main()
{
    studentCollection collection;

    typedef student* firstStudent;
    firstStudent sc;
    student* node1 = new student;
    node1->studentNum = 1001; node1->grade = 78;
    student* node2 = new student;
    node2->studentNum = 1012; node2->grade = 93;
    student* node3 = new student;
    node3->studentNum = 1076; node3->grade = 85;
    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = node2 = node3 = NULL;

    //collection.showstudentCollection(sc);
    collection.addRecord(sc, 1100, 77);
    collection.showstudentCollection(sc);

}


