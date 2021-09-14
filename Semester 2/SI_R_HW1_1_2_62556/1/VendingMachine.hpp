#pragma once
#include "Drink.hpp"


class VendingMachine {
    
public:
    VendingMachine();
    VendingMachine(const VendingMachine& from);
    VendingMachine& operator=(const VendingMachine& from);
    static const int drinks_size= 50;

    bool add_drink(const Drink& to_add);
    int buy_drink(const char* drink_name, const double money);

    double get_income() const;

    // Add whatever you deem needed here
private:
    // Add whatever you deem needed here

    Drink drinks[drinks_size];
    double income;
    //bool areEqual(const char*, const char*);
    
};
