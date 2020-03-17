#pragma once
#include "Bus.h"
#include <list>
#include <iostream>
using std::cin;
using std::cout;

class BusList
{
public:
	BusList();
	void addBus(Bus bus);
	void removeBus(Bus bus);
	void getBuses();
	void getBusesavailable();
private:
	list <Bus> Bus_List;
};

