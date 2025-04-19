// Nick Williams
//4/15/2025
// SNHU
// CS 210
//04/19/2025

// Main loop for the Corner Grocer program

#include <iostream>
#include <limits>
#include "ItemTracker.h"

using namespace std;

int main() {
    ItemTracker tracker;
    tracker.LoadData("CS210_Project_Three_Input_File.txt");
    tracker.SaveFrequencyData("frequency.dat");

    int choice;
    string item;

    do {
        cout << "\n====== Corner Grocer Menu ======" << endl;
        cout << "1. Look up item frequency" << endl;
        cout << "2. Print all item frequencies" << endl;
        cout << "3. Print histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number from 1 to 4.\n";
            continue;
        }

        cin.ignore();  // Clear newline after number input

        switch (choice) {
        case 1:
            cout << "Enter item name: ";
            getline(cin, item);
            cout << item << " was purchased " << tracker.GetItemFrequency(item) << " times.\n";
            break;

        case 2:
            tracker.PrintItemFrequency();
            break;

        case 3:
            tracker.PrintHistogram();
            break;

        case 4:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please enter a number from 1 to 4.\n";
        }
    } while (choice != 4);

    return 0;
}



