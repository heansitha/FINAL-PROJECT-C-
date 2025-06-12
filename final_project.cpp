#include <iostream>
#include <string>
#include <tabulate/table.hpp>
#include <xlnt/xlnt.hpp>
using namespace std;
using namespace tabulate;

//hotel
// room VIP
// room Book

struct Room {
    int number;
    string type;
    float price;
    bool isBooked;
    string customerName;
    string checkInDate;
    string checkOutDate;
};

const int ROOM_COUNT = 5;

vector<string> menu(){
    vector<string> menu = {
        "Show Room List",
        "Book a Room",
        "View Booked Customers",
        "Exit"
    };
    return menu;
}

void showMenu(vector<string> menu) {
    Table table;
    cout << "====== Hotel Management System ======"<<endl;
    table.add_row({"NO","MENU"});
    for(int i=0; i<menu.size(); i++){
        table.add_row({to_string(i+1), menu[i]});
    }
    cout<< table<<endl;
    cout << "Enter your choice: "<<endl;

}

void showRooms(Room rooms[]) {
    cout << "--- Room List ---"<<endl;
    for (int i = 0; i < ROOM_COUNT; i++) {
        cout << "Room " << rooms[i].number <<endl;
        cout << " | Type: " << rooms[i].type <<endl;
        cout << " | Price: $" << rooms[i].price <<endl;
        cout << " | " << (rooms[i].isBooked ? "Booked" : "Available") << endl;
    }
}

void bookRoom(Room rooms[]) {
    int roomNum;
    cout << "Enter room number to book: "<<endl;
    cin >> roomNum;

    for (int i = 0; i < ROOM_COUNT; i++) {
        if (rooms[i].number == roomNum) {
            if (rooms[i].isBooked) {
                cout << "❌ Room already booked."<<endl;
                return;
            }

            cin.ignore(); // clear input buffer
            cout << "Enter customer name: "<<endl;
            getline(cin, rooms[i].customerName);
            cout << "Enter check-in date (YYYY-MM-DD): "<<endl;
            getline(cin, rooms[i].checkInDate);
            cout << "Enter check-out date (YYYY-MM-DD): "<<endl;
            getline(cin, rooms[i].checkOutDate);

            rooms[i].isBooked = true;
            cout << "✅ Room " << roomNum << " booked successfully!"<<endl;
            return;
        }
    }

    cout << "❌ Room number not found."<<endl;
}

void showCustomerInfo(Room rooms[]) {
    cout << "--- Booked Customers ---"<<endl;
    bool found = false;
    for (int i = 0; i < ROOM_COUNT; i++) {
        if (rooms[i].isBooked) {
            found = true;
            cout << "Room " << rooms[i].number << " (" << rooms[i].type << "";
            cout << "Customer: " << rooms[i].customerName << endl;
            cout << "Check-in: " << rooms[i].checkInDate << endl;
            cout << "Check-out: " << rooms[i].checkOutDate << endl;
            cout << "Price: $" << rooms[i].price << "";
        }
    }
    if (!found) {
        cout << "No rooms booked yet.";
    }
}

int main() {
    system("cls");
    Room rooms[ROOM_COUNT] = {
        {101, "Standard", 100.0, false, "", "", ""},
        {102, "Standard", 100.0, false, "", "", ""},
        {201, "Deluxe",   150.0, false, "", "", ""},
        {301, "VIP",      250.0, false, "", "", ""},
        {302, "VIP",      250.0, false, "", "", ""},
    };
    vector<string> menuList = menu();
    int choice;
    do {
        showMenu(menuList);
        cin >> choice;
        switch (choice) {
            case 1:
                showRooms(rooms);
                break;
            case 2:
                bookRoom(rooms);
                break;
            case 3:
                showCustomerInfo(rooms);
                break;
            case 4:
                cout << "Exiting the system. Goodbye!"<<endl;
                break;
            default:
                cout << "Invalid choice. Try again."<<endl;
        }
    } while (choice != 4);

    return 0;
}