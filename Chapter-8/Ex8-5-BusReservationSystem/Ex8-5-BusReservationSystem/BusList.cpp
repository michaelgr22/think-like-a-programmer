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

void BusList::readfromFile() {
	
	
	ifstream file;

	file.open("data.txt");

	string line;

	string id;
	string driver;
	string arrivaltime;
	string departuretime;
	string destination;
	string seats_passengers_complete_str;
	list<string> seatnumbers_str;
	list<string> passengers;


	while (!file.eof()) {
		
		getline(file, line);

		istringstream lineStream(line);

		getline(lineStream, id, ',');
		getline(lineStream, driver, ',');
		getline(lineStream, arrivaltime, ',');
		getline(lineStream, departuretime, ',');
		getline(lineStream, destination, ',');
		getline(lineStream, seats_passengers_complete_str, ',');

		string seat_seat_delimiter = ";";
		size_t seat_seat_pos = 0;
		string seat_pas;

		string seat_pas_delimiter = "-";
		size_t seat_pas_pos = 0;

		//seats-passenger
		while ((seat_seat_pos = seats_passengers_complete_str.find(seat_seat_delimiter)) != string::npos) {
			seat_pas = seats_passengers_complete_str.substr(0, seat_seat_pos);

			//seats
			while ((seat_pas_pos = seat_pas.find(seat_pas_delimiter)) != string::npos) {
				seatnumbers_str.push_back(seat_pas.substr(0, seat_pas_pos));
				seat_pas.erase(0, seat_pas_pos + seat_pas_delimiter.length());
			}

			//passengers
			passengers.push_back(seat_pas);

			seats_passengers_complete_str.erase(0, seat_seat_pos + seat_seat_delimiter.length());
		}

		//last one
		seat_pas_pos = 0;
		while ((seat_pas_pos = seats_passengers_complete_str.find(seat_pas_delimiter)) != string::npos) {
			seatnumbers_str.push_back(seats_passengers_complete_str.substr(0, seat_pas_pos));
			seats_passengers_complete_str.erase(0, seat_pas_pos + seat_pas_delimiter.length());
		}
		passengers.push_back(seats_passengers_complete_str);

		Bus newbus(stoi(id), driver, arrivaltime, departuretime, destination);
		this->Bus_List.push_back(newbus);
		list<int> seatnumbers;
		for (auto it = seatnumbers_str.begin(); it != seatnumbers_str.end(); ++it) {
			seatnumbers.push_back(stoi(*it));
		}

		if (seatnumbers.size() == passengers.size())
		{
			auto itseats = seatnumbers.begin();
			auto itpassengers = passengers.begin();
			for (; itseats != seatnumbers.end() && itpassengers != passengers.end(); itseats++, itpassengers++) {
				newbus.addReservation(*itseats, *itpassengers);
			}
		}

	}

}
