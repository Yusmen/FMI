#include "TwowayCounter.hpp"

TwowayCounter::TwowayCounter() :Counter(0, 1) {}

TwowayCounter::TwowayCounter(int initial) : Counter(initial) {}

TwowayCounter::TwowayCounter(int initial, unsigned int step) : Counter(initial, step) {}


void TwowayCounter::decrement()
{
	this->initial -= step;
}
