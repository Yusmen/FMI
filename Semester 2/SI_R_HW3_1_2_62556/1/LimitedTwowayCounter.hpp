#pragma once

#include "LimitedCounter.hpp"
#include "TwowayCounter.hpp"

class LimitedTwowayCounter :public LimitedCounter, public TwowayCounter
{
public:
	LimitedTwowayCounter(int, int);
	LimitedTwowayCounter(int, int, int);
	LimitedTwowayCounter(int, int, int,unsigned int);
	void decrement();
	int getMin() const;

private:
	int min;

};


