#pragma once


class Counter
{
public:
	Counter();
	Counter(int);
	Counter(int, unsigned int);
	void increment();
	int getTotal() const;
	unsigned int getStep() const;

protected:
	int initial;
	unsigned int step;

};


