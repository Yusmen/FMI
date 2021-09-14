#pragma once

class Comparable
{
public:

	//virtual ~Comparable() = 0;
	virtual bool operator==(const Comparable* rhs) const = 0;
	virtual bool operator!=(const Comparable* rhs) const = 0;

};