#include <iostream>
#include "Bus.h"
#include "BusList.h"

using std::cin;
using std::cout;


int main()
{

    /*
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
    buslist.getBusesavailable();*/


    BusList buslist;

    buslist.readfromFile();
    

    int choice;
    do {
        
        cout << "1. Install" << "\n";
        cout << "2. Reservation" << "\n";
        cout << "3. Show" << "\n";
        cout << "4. Buses Available" << "\n";
        cout << "5. Exit" << "\n";
        cout << "Enter your choice: ->";
        
        cin >> choice;

        if (choice == 1) {
            cout << "BusID: " << "\n";
            int BusId;
            cin >> BusId;
            while (cin.fail()) {
                cout << "Error: Enter a number!" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> BusId;
            }
            cout << "driver: " << "\n";
            string driver;
            cin >> driver;
            cout << "Arrival Time (Format: 00:00:00): " << "\n";
            string arrivaltime;
            cin >> arrivaltime;
            cout << "Departure Time (Format: 00:00:00): " << "\n";
            string departuretime;
            cin >> departuretime;
            cout << "Destination: " << "\n";
            string destination;
            cin >> destination;

            Bus newbus(BusId, driver, arrivaltime, departuretime, destination);
            buslist.addBus(newbus);
        }
        else if (choice == 2) {
            cout << "Enter Bus Number: " << "\n";

            int busnumber;
            cin >> busnumber;

            while (buslist.isBusavailable(busnumber) == false)
            {
                cout << "Bus not available enter new ID";
                cin >> busnumber;
            }
            Bus bustoreservate = buslist.getBuswithID(busnumber);          

            cout << "Enter seat you want reservate: " << "\n";
            int seatnumber;
            cin >> seatnumber;
            cout << "Enter your name: " << "\n";
            string name;
            cin >> name;

            bustoreservate.addReservation(seatnumber, name);
        }
        else if (choice == 3) {
            buslist.getBuses();
        }
        else if (choice == 4) {
            for (Bus& bus : buslist.getBusList()) {
                if (bus.IsBusAvailable())
                    cout << bus.getBusID() << "\n";
            }
        }
        else if (choice == 5)
        {
            buslist.writetoFile();
        }
        else
        {
            cout << "False Number, try again!";
        }
    } while (choice != 5);
}