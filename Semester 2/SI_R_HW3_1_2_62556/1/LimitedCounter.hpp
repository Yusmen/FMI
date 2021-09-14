#pragma once

#include "Counter.hpp"
#include<iostream>

class LimitedCounter :virtual public Counter
{
public:
	LimitedCounter(int);
	LimitedCounter(int, int);
	LimitedCounter(int, int, unsigned int);
	void increment();
	int getMax() const;


private:
	int max;

};

