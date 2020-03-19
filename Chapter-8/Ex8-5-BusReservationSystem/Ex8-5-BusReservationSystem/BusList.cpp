#include "BusList.h"


BusList::BusList() {

}

void BusList::addBus(Bus bus) {
	Bus_List.push_back(bus);
}

void BusList::removeBus(Bus bus) {
	Bus_List.remove(bus);
}

void BusList::getBuses() {
	for (auto it = Bus_List.begin(); it != Bus_List.end(); ++it) {
		it->getBusInformation();
	}
}

bool BusList::isBusavailable(int busnumber) {
	list<Bus> busesavailable = this->getBusesavailable();
	for (Bus& bus : busesavailable) {
		if (bus.getBusID() == busnumber && bus.IsBusAvailable())
			return true;
	}
	return false;

}

list<Bus> BusList::getBusesavailable() {
	list<Bus> busesavailable;
	for (Bus& bus : Bus_List) {
		if (bus.IsBusAvailable())
			busesavailable.push_back(bus);
	}
	return busesavailable;
}

Bus BusList::getBuswithID(int id) {
	for (Bus& bus : Bus_List) {
		if (bus.getBusID() == id)
			return bus;
	}
}

list<Bus> BusList::getBusList() {
	return this->Bus_List;
}
