#pragma once
#include <string>
using namespace std;
class Bus
{
private:
	static const int seat_rows = 10;
	static const int seats_per_row = 4;
public:
	Bus();
	Bus(int BusID, string driver, string arrivaltime, string departuretime, string destination, bool available);

	int getBusID();
	void setBusID(int BusID);
	string getdriver();
	void setdriver(string driver);
	string getarrivaltime();
	void setarrivaltime(string arrivaltime);
	string getdeparturetime();
	void setdeparturetime(string departuretime);
	string getdestination();
	void setdestination(string destination);
	string** getseats();
	void setseats(string *seats[seat_rows * seats_per_row]);

	void addReservation(int seatnumber);
	void removeReservation(int seatnumber);
	void getavailableSeats();
	void getBusInformation();
	bool IsBusAvailable();

	void destructor();

private:
	int BusID;
	string driver;
	string arrivaltime;
	string departuretime;
	string destination;
	string** seats = new string*[seat_rows * seats_per_row];
	bool available;
};

