#include "Bus.h"

#include <iostream>
using std::cin;
using std::cout;


Bus::Bus() {
	this->BusID = -1;
	this->driver = " ";
	this->arrivaltime = "00:00:00";
	this->departuretime = "00:00:00";
	this->destination = " ";
	this->available = false;
	for (int i = 0; i < seat_rows * seats_per_row; i++) {
		this->seats[i] = new string[seat_rows * seats_per_row];
	}
	int seat_number = 1;
	for (int row = 0; row < seat_rows; row++) {
		for (int seat_in_row = 0; seat_in_row < seats_per_row; seat_in_row++) {
			this->seats[row][seat_in_row] = to_string(seat_number);
			seat_number++;
		}
	}
}

Bus::Bus(int BusID, string driver, string arrivaltime, string departuretime, string destination, bool available) {
	this->BusID = BusID;
	this->driver = driver;
	this->arrivaltime = arrivaltime;
	this->departuretime = departuretime;
	this->destination = destination;
	this->available = available;
	for (int i = 0; i < seat_rows * seats_per_row; i++) {
		this->seats[i] = new string[seat_rows * seats_per_row];
	}
	int seat_number = 1;
	for (int row = 0; row < seat_rows; row++) {
		for (int seat_in_row = 0; seat_in_row < seats_per_row; seat_in_row++) {
			this->seats[row][seat_in_row] = to_string(seat_number);
			seat_number++;
		}
	}
}

int Bus::getBusID() {
	return this->BusID;
}
void Bus::setBusID(int BusID) {
	this->BusID = BusID;
}
string Bus::getdriver() {
	return this->driver;
}
void Bus::setdriver(string driver) {
	this->driver = driver;
}
string Bus::getarrivaltime() {
	return this->arrivaltime;
}
void Bus::setarrivaltime(string arrivaltime) {
	this->arrivaltime = arrivaltime;
}
string Bus::getdeparturetime() {
	return this->departuretime;
}
void Bus::setdeparturetime(string departuretime) {
	this->departuretime = departuretime;
}
string Bus::getdestination() {
	return this->destination;
}
void Bus::setdestination(string destination) {
	this->destination = destination;
}
string** Bus::getseats() {
	return this->seats;
}
void Bus::setseats(string *seats[seat_rows * seats_per_row]) {
	for (int row = 0; row < seat_rows; row++) {
		for (int seat_in_row = 0; seat_in_row < seats_per_row; seat_in_row++) {
			this->seats[row][seat_in_row] = seats[row][seat_in_row];
		}
	}
}

void Bus::getBusInformation() {
	cout << "BusID: " << this->BusID << "\n";;
	cout << "Driver: " << this->driver << "\n";;
	cout << "arrivaltime: " << this->arrivaltime << "\n";;
	cout << "departuretime: " << this->departuretime << "\n";;
	cout << "destination: " << this->destination << "\n";;

	int count = 1;
	for (int row = 0; row < seat_rows; row++) {
		for (int seat_in_row = 0; seat_in_row < seats_per_row; seat_in_row++) {
			if (seat_in_row % 2 == 1) {
				if (count < 10) {
					cout << "0" << this->seats[row][seat_in_row] << "   ";
				}
				else {
					cout << this->seats[row][seat_in_row] << "   ";
				}
			}
			else {
				if (count < 10) {
					cout << "0" << this->seats[row][seat_in_row] << " ";
				}
				else {
					cout << this->seats[row][seat_in_row] << " ";
				}
			}
			count++;
		}
		cout << "\n";
	}
}

void Bus::getavailableSeats() {
	int count = 1;
	for (int row = 0; row < seat_rows; row++) {
		for (int seat_in_row = 0; seat_in_row < seats_per_row; seat_in_row++) {
			if (this->seats[row][seat_in_row] != "xx") {
				if (seat_in_row % 2 == 1) {
					if (count < 10) {
						cout << "0" << this->seats[row][seat_in_row] << "   ";
					}
					else {
						cout << this->seats[row][seat_in_row] << "   ";
					}
				}
				else {
					if (count < 10) {
						cout << "0" << this->seats[row][seat_in_row] << " ";
					}
					else {
						cout << this->seats[row][seat_in_row] << " ";
					}
				}
			}
			count++;
		}
		cout << "\n";
	}
}

void Bus::addReservation(int seatnumber) {
	int count = 1;
	for (int row = 0; row < seat_rows; row++) {
		for (int seat_in_row = 0; seat_in_row < seats_per_row; seat_in_row++) {
			if (count == seatnumber) {
				cout << row;
				cout << seat_in_row;
				this->seats[row][seat_in_row] = "--";
			}
			count++;
		}
	}
}

void Bus::removeReservation(int seatnumber) {
	int count = 1;
	for (int row = 0; row < seat_rows; row++) {
		for (int seat_in_row = 0; seat_in_row < seats_per_row; seat_in_row++) {
			if (count == seatnumber) {
				this->seats[row][seat_in_row] = to_string(count);
			}
			count++;
		}
	}
}

bool Bus::IsBusAvailable() {
	return this->available;
}

void Bus::destructor() {
	for (int i = 0; i < seat_rows * seats_per_row; i++) {
		delete[] this->seats[i];
	}
}

