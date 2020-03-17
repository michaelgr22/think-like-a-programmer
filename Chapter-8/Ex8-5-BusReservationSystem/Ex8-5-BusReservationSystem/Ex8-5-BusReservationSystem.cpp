#include <iostream>
#include "Bus.h"
#include "BusList.h"

using std::cin;
using std::cout;


int main()
{

    Bus bus1(1, "Michael", "01:00:00", "02:00:00", "Munich", true);
    Bus bus2(1, "Hans", "02:00:00", "03:00:00", "Stuttgart", true);
    Bus bus3(1, "Claus", "03:00:00", "04:00:00", "Nuremberg", false);
    Bus bus4(1, "Toto", "04:00:00", "05:00:00", "Berlin", true);

    bus2.getavailableSeats();
    bus2.addReservation(10);
    cout << "\n";
    bus2.getavailableSeats();
    bus2.removeReservation(10);
    cout << "\n";
    bus2.getavailableSeats();

    BusList buslist;

    buslist.addBus(bus1);
    buslist.addBus(bus2);
    buslist.addBus(bus3);
    buslist.addBus(bus4);

    buslist.getBuses();
    buslist.getBusesavailable();

}