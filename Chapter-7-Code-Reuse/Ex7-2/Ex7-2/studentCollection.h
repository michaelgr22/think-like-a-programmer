#pragma once
#include "student.h"
#include <list>

using namespace std;

class studentCollection
{
public:
	void addRecord(int stuNum, int gr);
	double averageRecord();
	void showstudentCollection();
	list <student> studentlist;
};

