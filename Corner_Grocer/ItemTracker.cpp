// Nick Williams
//4/15/2025
// SNHU
// CS 210
// Defines class members and functions for item tracker

#include "ItemTracker.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void ItemTracker::LoadData(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    string item;
    while (inputFile >> item) {
        item = ToLower(item); // Normalize to lowercase
        ++itemFrequency[item];
    }

    inputFile.close();
}


void ItemTracker::SaveFrequencyData(const string& filename) {
    ofstream outFile(filename);
    for (const auto& pair : itemFrequency) {
        outFile << pair.first << " " << pair.second << endl;
    }
    outFile.close();
}

int ItemTracker::GetItemFrequency(const string& item) {
    string normalizedItem = ToLower(item); // Convert input to lowercase
    if (itemFrequency.find(normalizedItem) != itemFrequency.end()) {
        return itemFrequency[normalizedItem];
    }
    return 0;
}

void ItemTracker::PrintItemFrequency() {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }
}

void ItemTracker::PrintHistogram() {
    for (const auto& pair : itemFrequency) {
        cout << setw(15) << left << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }

}

// Convert a string to lowercase
std::string ItemTracker::ToLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return lowerStr;
}

