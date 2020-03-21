#pragma once
#include "Bus.h"
#include <list>
#include <iostream>
#include <sstream>
#include <fstream>
using std::cin;
using std::cout;

class BusList
{
public:
	BusList();
	void addBus(Bus bus);
	void removeBus(Bus bus);
	void getBuses();
	bool isBusavailable(int busnumber);
	std::list<Bus> getBusesavailable();
	Bus getBuswithID(int id);
	std::list<Bus> getBusList();
	void readfromFile();
	void writetoFile();
private:
	std::list <Bus> Bus_List;
};

