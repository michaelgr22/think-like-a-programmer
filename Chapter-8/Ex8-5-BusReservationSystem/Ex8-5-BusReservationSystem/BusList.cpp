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
	std::list<Bus> busesavailable = this->getBusesavailable();
	for (Bus& bus : busesavailable) {
		if (bus.getBusID() == busnumber && bus.IsBusAvailable())
			return true;
	}
	return false;

}

std::list<Bus> BusList::getBusesavailable() {
	std::list<Bus> busesavailable;
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

std::list<Bus> BusList::getBusList() {
	return this->Bus_List;
}

void BusList::readfromFile() {
		
	std::ifstream file;

	file.open("data.txt");

	std::string line;

	while (!file.eof()) {
		
		std::string id;
		std::string driver;
		std::string arrivaltime;
		std::string departuretime;
		std::string destination;
		std::string seats_passengers_complete_str;
		std::list<std::string> seatnumbers_str;
		std::list<std::string> passengers;

		getline(file, line);

		if (!line.empty())
		{

			std::istringstream lineStream(line);

			getline(lineStream, id, ',');
			getline(lineStream, driver, ',');
			getline(lineStream, arrivaltime, ',');
			getline(lineStream, departuretime, ',');
			getline(lineStream, destination, ',');
			getline(lineStream, seats_passengers_complete_str, ',');

			std::string seat_seat_delimiter = ";";
			size_t seat_seat_pos = 0;
			std::string seat_pas;

			std::string seat_pas_delimiter = "-";
			size_t seat_pas_pos = 0;

			//seats-passenger
			while ((seat_seat_pos = seats_passengers_complete_str.find(seat_seat_delimiter)) != std::string::npos) {
				seat_pas = seats_passengers_complete_str.substr(0, seat_seat_pos);

				//seats
				while ((seat_pas_pos = seat_pas.find(seat_pas_delimiter)) != std::string::npos) {
					seatnumbers_str.push_back(seat_pas.substr(0, seat_pas_pos));
					seat_pas.erase(0, seat_pas_pos + seat_pas_delimiter.length());
				}

				//passengers
				passengers.push_back(seat_pas);

				seats_passengers_complete_str.erase(0, seat_seat_pos + seat_seat_delimiter.length());
			}

			//last one
			seat_pas_pos = 0;
			while ((seat_pas_pos = seats_passengers_complete_str.find(seat_pas_delimiter)) != std::string::npos) {
				seatnumbers_str.push_back(seats_passengers_complete_str.substr(0, seat_pas_pos));
				seats_passengers_complete_str.erase(0, seat_pas_pos + seat_pas_delimiter.length());
			}

			Bus newbus(stoi(id), driver, arrivaltime, departuretime, destination);
			this->Bus_List.push_back(newbus);
			std::list<int> seatnumbers;
			for (auto it = seatnumbers_str.begin(); it != seatnumbers_str.end(); ++it) {
				seatnumbers.push_back(std::stoi(*it));
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

	file.close();

}

void BusList::writetoFile() {
	
	std::ofstream file;

	file.open("data.txt", std::ofstream::trunc);

	for (auto it = this->Bus_List.begin(); it != this->Bus_List.end(); it++) {
		std::string str = std::to_string(it->getBusID()) + "," + it->getdriver() + "," + it->getarrivaltime() + "," + it->getdeparturetime() + "," + it->getdestination() + ",";
		file << str;

		int** seats = it->getseats();
		std::string** passengers = it->getpassengers();

		for (int row = 0; row < it->getseat_rows(); row++) {
			for (int seat_in_row = 0; seat_in_row < it->getseats_per_row(); seat_in_row++) {
				if (passengers[row][seat_in_row] != " ") {
					std::string seat_pas = std::to_string(seats[row][seat_in_row]) + "-" + passengers[row][seat_in_row] + ";";
					file << seat_pas;
				}
			}
		}

		if (std::next(it) != Bus_List.end()) {
			cout << "Test";
			file << std::endl;
		}
			
	}

}
