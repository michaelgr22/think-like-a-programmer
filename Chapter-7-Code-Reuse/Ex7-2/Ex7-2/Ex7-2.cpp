#include <iostream>
#include <list>

#include "studentCollection.h"
#include "student.h"

using namespace std;
using std::cin;
using std::cout;

int main()
{
    studentCollection collection;

    student student1 = student(1001, 78);
    student student2 = student(1012, 93);
    student student3 = student(1076, 85);

    
    collection.studentlist.push_back(student1);
    collection.studentlist.push_back(student2);
    collection.studentlist.push_back(student3);

    collection.addRecord(1100, 77);
    collection.showstudentCollection();
    
}


