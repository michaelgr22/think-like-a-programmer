#pragma once
#include "student.h"
class studentCollection
{
public:
	typedef student* firstStudent;
	void addRecord(firstStudent& sc, int stuNum, int gr);
	double averageRecord(firstStudent sc);
	void showstudentCollection(firstStudent sc);
};

