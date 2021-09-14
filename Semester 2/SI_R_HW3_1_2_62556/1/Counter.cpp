#include "Counter.hpp"

Counter::Counter() :initial(0), step(1) {}

Counter::Counter(int initial) : step(1)
{
	this->initial = initial;
}

Counter::Counter(int initial, unsigned int step)
{
	this->initial = initial;
	this->step = step;
	
}

void Counter::increment()
{
	this->initial += step;
}

int Counter::getTotal() const
{
	return initial;
}

unsigned int Counter::getStep() const
{
	return this->step;
}
