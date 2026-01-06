#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

struct Ticket
{
    string name;
    int flight;
    int seat;
};

void showFlights()
{
    cout << "\nAvailable Flights:\n";
    cout << "1. Karachi to Lahore\n";
    cout << "2. Lahore to Islamabad\n";
    cout << "3. Karachi to Islamabad\n";
}

void saveTicket(Ticket t)
{
    ofstream file("tickets.txt", ios::app);
    file << t.name << " " << t.flight << " " << t.seat << endl;
    file.close();
}

void bookTicket(vector<Ticket>& tickets)
{
    Ticket t;

    cout << "\nEnter Passenger Name: ";
    cin >> t.name;

    showFlights();
    cout << "Select Flight (1-3): ";
    cin >> t.flight;

    if (t.flight < 1 || t.flight > 3)
    {
        cout << "Invalid Flight Selection!\n";
        return;
    }

    cout << "Select Seat (1-5): ";
    cin >> t.seat;

    if (t.seat < 1 || t.seat > 5)
    {
        cout << "Invalid Seat Number!\n";
        return;
    }

    tickets.push_back(t);
    saveTicket(t);

    cout << "\nTicket Booked Successfully!\n";
}

void viewTickets()
{
    ifstream file("tickets.txt");
    Ticket t;

    cout << "\nBooked Tickets:\n";

    while (file >> t.name >> t.flight >> t.seat)
    {
        cout << "Name   : " << t.name << endl;
        cout << "Flight : " << t.flight << endl;
        cout << "Seat   : " << t.seat << endl;
    }

    file.close();
}

int main()
{
    vector<Ticket> tickets;
    int choice;

    cout << "   AIR TICKET RESERVATION SYSTEM\n";
    
    while (true)
    {
        cout << "\n1. View Flights";
        cout << "\n2. Book Ticket";
        cout << "\n3. View Booked Tickets";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";

        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input!\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            showFlights();
            break;
        case 2:
            bookTicket(tickets);
            break;
        case 3:
            viewTickets();
            break;
        case 4:
            cout << "\nThank you for using the system!\n";
            return 0;
        default:
            cout << "Invalid Choice!\n";
        }
    }
}
