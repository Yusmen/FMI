#pragma once
#pragma warning(disable : 4996)
#include<cstring>

class Drink {
public:
	Drink();
	~Drink();
	Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price);
	Drink(const Drink&);
	Drink& operator=(const Drink&);

	const char* get_name() const;
	int get_calories() const;
	double get_quantity() const;
	double get_price() const;

	void set_name(const char* new_name);

	// Add whatever you deem needed here
private:
	// Add whatever you deem needed here

	char* name;
	int calories;
	double quantity;
	double price;
	//void strcpy(char* first, const char* second);
	//int strlen(const char*);
	
	
};
