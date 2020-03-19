#include "Bus.h"

#include <iostream>
using std::cin;
using std::cout;


Bus::Bus() {
	this->BusID = -1;
	this->driver = " ";
	this->arrivaltime = "00:00:00";
	this->departuretime = "00:00:00";

	//Initialize seats 
	for (int i = 0; i < seat_rows * seats_per_row; i++) {
		this->seats[i] = new int[seat_rows * seats_per_row];
	}

	//fill seats with numbers
	int seat_number = 1;
	for (int row = 0; row < seat_rows; row++) {
		for (int seat_in_row = 0; seat_in_row < seats_per_row; seat_in_row++) {
			this->seats[row][seat_in_row] = seat_number;
			seat_number++;
		}
	}

	//Initialize passengers 
	for (int i = 0; i < seat_rows * seats_per_row; i++) {
		this->passengers[i] = new string[seat_rows * seats_per_row];
	}

	//fill seats with numbers
	for (int row = 0; row < seat_rows; row++) {
		for (int seat_in_row = 0; seat_in_row < seats_per_row; seat_in_row++) {
			this->passengers[row][seat_in_row] = " ";
		}
	}
}

Bus::Bus(int BusID, string driver, string arrivaltime, string departuretime, string destination) {


	this->BusID = BusID;
	this->driver = driver;
	this->arrivaltime = arrivaltime;
	this->departuretime = departuretime;
	this->destination = destination;

	//Initialize seats 
	for (int i = 0; i < seat_rows * seats_per_row; i++) {
		this->seats[i] = new int[seat_rows * seats_per_row];
	}

	//fill seats with numbers
	int seat_number = 1;
	for (int row = 0; row < seat_rows; row++) {
		for (int seat_in_row = 0; seat_in_row < seats_per_row; seat_in_row++) {
			this->seats[row][seat_in_row] = seat_number;
			seat_number++;
		}
	}

	//Initialize passengers 
	for (int i = 0; i < seat_rows * seats_per_row; i++) {
		this->passengers[i] = new string[seat_rows * seats_per_row];
	}

	//fill seats with numbers
	for (int row = 0; row < seat_rows; row++) {
		for (int seat_in_row = 0; seat_in_row < seats_per_row; seat_in_row++) {
			this->passengers[row][seat_in_row] = " ";
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
int** Bus::getseats() {
	return this->seats;
}
void Bus::setseats(int *seats[seat_rows * seats_per_row]) {
	for (int row = 0; row < seat_rows; row++) {
		for (int seat_in_row = 0; seat_in_row < seats_per_row; seat_in_row++) {
			this->seats[row][seat_in_row] = seats[row][seat_in_row];
		}
	}
}

string** Bus::getpassengers() {
	return this->passengers;
}
void Bus::setpassengers(string* passengers[seat_rows * seats_per_row]) {
	for (int row = 0; row < seat_rows; row++) {
		for (int seat_in_row = 0; seat_in_row < seats_per_row; seat_in_row++) {
			this->passengers[row][seat_in_row] = passengers[row][seat_in_row];
		}
	}

}


void Bus::getBusInformation() {
	cout << "BusID: " << this->BusID << "\n";;
	cout << "Driver: " << this->driver << "\n";;
	cout << "arrivaltime: " << this->arrivaltime << "\n";;
	cout << "departuretime: " << this->departuretime << "\n";;
	cout << "destination: " << this->destination << "\n";;

	this->getavailableSeats();

	cout << "Reservations: " << "\n";
	for (int row = 0; row < seat_rows; row++) {
		for (int seat_in_row = 0; seat_in_row < seats_per_row; seat_in_row++) {
			if (this->passengers[row][seat_in_row] != " ") {
				cout << "Reservation: Seat " << this->seats[row][seat_in_row] << " reservated by " << this->passengers[row][seat_in_row] << "\n";
			}
		}
	}

}

void Bus::getavailableSeats() {
	int count = 1;
	for (int row = 0; row < seat_rows; row++) {
		for (int seat_in_row = 0; seat_in_row < seats_per_row; seat_in_row++) {
			if (this->passengers[row][seat_in_row] == " ") {
				if (count < 10) {
					cout << "0" << this->seats[row][seat_in_row] << " ";
				}
				else {
					cout << this->seats[row][seat_in_row] << " ";
				}
			}
			else
			{
				cout << "xx ";
			}
			if (seat_in_row % 2 == 1) {
				cout << " ";
			}
			count++;
		}
		cout << "\n";
	}
}

void Bus::addReservation(int seatnumber, string passengername) {
	int count = 1;
	for (int row = 0; row < seat_rows; row++) {
		for (int seat_in_row = 0; seat_in_row < seats_per_row; seat_in_row++) {
			if (count == seatnumber && this->passengers[row][seat_in_row] == " ") {
				this->passengers[row][seat_in_row] = passengername;
			}
			else if (count == seatnumber && this->passengers[row][seat_in_row] != " "){
				cout << "This seat is not available.";
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
				this->passengers[row][seat_in_row] = " ";
				break;
			}
			count++;
		}
	}
}

bool Bus::IsBusAvailable() {
	for (int row = 0; row < seat_rows; row++) {
		for (int seat_in_row = 0; seat_in_row < seats_per_row; seat_in_row++) {
			if (this->passengers[row][seat_in_row] == " ") {
				return true;
			}
		}
	}
	return false;
}

void Bus::destructor() {
	for (int i = 0; i < seat_rows * seats_per_row; i++) {
		delete[] this->seats[i];
	}
	for (int i = 0; i < seat_rows * seats_per_row; i++) {
		delete[] this->passengers[i];
	}
}

