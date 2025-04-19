// Nick Williams
//4/15/2025
// SNHU
// CS 210
// Define class for Corner Grocer menu

#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <string>
#include <map>

class ItemTracker {
private:
    std::map<std::string, int> itemFrequency;

public:
    void LoadData(const std::string& filename);
    void SaveFrequencyData(const std::string& filename);
    int GetItemFrequency(const std::string& item);
    void PrintItemFrequency();
    void PrintHistogram();
};

#endif

