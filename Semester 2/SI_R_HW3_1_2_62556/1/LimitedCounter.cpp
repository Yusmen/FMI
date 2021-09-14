#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter(int max) :Counter(), max(max) {}

LimitedCounter::LimitedCounter(int max, int initial)
{
	this->max = max;
	this->initial = initial;
}

LimitedCounter::LimitedCounter(int max, int initial, unsigned int step)
{
	this->max = max;
	this->initial = initial;
	if (step >= 0)
	{
		this->step = step;
	}

}

void LimitedCounter::increment()
{
	if ((int)(initial + step) <= max)
	{
		initial += step;
	}

}

int LimitedCounter::getMax() const
{
	return this->max;
}

