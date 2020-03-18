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

void BusList::getBusesavailable() {
	for (auto it = Bus_List.begin(); it != Bus_List.end(); ++it) {
		if (it->IsBusAvailable())
			it->getBusInformation();
	}
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
