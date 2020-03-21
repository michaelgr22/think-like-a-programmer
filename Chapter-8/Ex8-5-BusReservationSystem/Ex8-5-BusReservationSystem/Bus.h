#pragma once
#include <string>

class Bus
{
private:
	static const int seat_rows = 1;
	static const int seats_per_row = 4;
public:
	Bus();
	Bus(int BusID, std::string driver, std::string arrivaltime, std::string departuretime, std::string destination);

	int getBusID();
	void setBusID(int BusID);
	std::string getdriver();
	void setdriver(std::string driver);
	std::string getarrivaltime();
	void setarrivaltime(std::string arrivaltime);
	std::string getdeparturetime();
	void setdeparturetime(std::string departuretime);
	std::string getdestination();
	void setdestination(std::string destination);
	int** getseats();
	void setseats(int *seats[seat_rows * seats_per_row]);
	std::string** getpassengers();
	void setpassengers(std::string* seats[seat_rows * seats_per_row]);
	int getseat_rows();
	int getseats_per_row();

	void addReservation(int seatnumber, std::string passengername);
	void removeReservation(int seatnumber);
	void getavailableSeats();
	void getBusInformation();
	bool IsBusAvailable();

	void destructor();

	bool operator == (const Bus& bus) const { return BusID == bus.BusID; };

private:
	int BusID;
	std::string driver;
	std::string arrivaltime;
	std::string departuretime;
	std::string destination;
	int** seats = new int*[seat_rows * seats_per_row];
	std::string** passengers = new std::string * [seat_rows * seats_per_row];
};

