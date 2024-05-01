#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TicketOffice {
protected:
    string departureStation;
    string departureTime;
    string departureDate;
    string arrivalTime;
    string arrivalDate;
    double ticketPrice;

public:
    TicketOffice(string depStation, string depTime, string depDate, string arrTime, string arrDate, double price)
        : departureStation(depStation), departureTime(depTime), departureDate(depDate),
        arrivalTime(arrTime), arrivalDate(arrDate), ticketPrice(price) {}

    virtual void displayInfo() {
        cout << "Departure Station: " << departureStation << endl;
        cout << "Departure Time: " << departureTime << endl;
        cout << "Departure Date: " << departureDate << endl;
        cout << "Arrival Time: " << arrivalTime << endl;
        cout << "Arrival Date: " << arrivalDate << endl;
        cout << "Ticket Price: $" << ticketPrice << endl;
    }

    virtual ~TicketOffice() {}
};

class ExtendedTicketOffice : public TicketOffice {
private:
    int availableSeats;
    string transportType;

public:
    ExtendedTicketOffice(string depStation, string depTime, string depDate,
        string arrTime, string arrDate, double price,
        int seats, string type)
        : TicketOffice(depStation, depTime, depDate, arrTime, arrDate, price),
        availableSeats(seats), transportType(type) {}

    void displayInfo() override {
        TicketOffice::displayInfo();
        cout << "Available Seats: " << availableSeats << endl;
        cout << "Transport Type: " << transportType << endl;
    }
};

int main() {
    vector<ExtendedTicketOffice> tickets;
    string departureStation, departureTime, departureDate, arrivalTime, arrivalDate, transportType;
    double ticketPrice;
    int availableSeats;
    int choice, index;

    do {
        cout << "1. Add Ticket\n";
        cout << "2. Remove Ticket\n";
        cout << "3. Display Tickets\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter departure station: ";
            cin >> departureStation;
            cout << "Enter departure time: ";
            cin >> departureTime;
            cout << "Enter departure date: ";
            cin >> departureDate;
            cout << "Enter arrival time: ";
            cin >> arrivalTime;
            cout << "Enter arrival date: ";
            cin >> arrivalDate;
            cout << "Enter ticket price: ";
            cin >> ticketPrice;
            cout << "Enter available seats: ";
            cin >> availableSeats;
            cout << "Enter transport type: ";
            cin >> transportType;
            tickets.emplace_back(departureStation, departureTime, departureDate, arrivalTime, arrivalDate, ticketPrice, availableSeats, transportType);
            break;
        case 2:
            if (!tickets.empty()) {
                cout << "Enter ticket index to remove (starting from 0): ";
                cin >> index;
                if (index >= 0 && index < tickets.size()) {
                    tickets.erase(tickets.begin() + index);
                }
                else {
                    cout << "Invalid index!\n";
                }
            }
            else {
                cout << "No tickets to remove.\n";
            }
            break;
        case 3:
            if (!tickets.empty()) {
                for (int i = 0; i < tickets.size(); i++) {
                    cout << "Ticket " << i + 1 << ":\n";
                    tickets[i].displayInfo();
                }
            }
            else {
                cout << "No tickets to display.\n";
            }
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
