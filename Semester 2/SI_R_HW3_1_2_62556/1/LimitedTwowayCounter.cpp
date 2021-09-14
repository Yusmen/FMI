#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max) :LimitedCounter(max), min(min) {}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial) : LimitedCounter(max, initial), min(min) {}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial, unsigned int step) : LimitedCounter(max, initial, step), min(min) {}

void LimitedTwowayCounter::decrement()
{
	if ((int)(initial - step) >= min)
	{
		initial -= step;
	}
}

int LimitedTwowayCounter::getMin() const
{
	return this->min;
}

