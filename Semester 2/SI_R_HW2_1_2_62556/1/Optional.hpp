#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

template <typename T>

class Optional
{
public:
	Optional();
	Optional(const T& value);

	bool is_none() const;
	T get_value() const;
	Optional<T>& operator=(const Optional<T>& rhs);

private:

	T member;
};

template<typename T>
Optional<T>::Optional()
{
	this->member = T();
}

template<typename T>
Optional<T>::Optional(const T& value)
{
	this->member = value;
}

template<typename T>
bool Optional<T>::is_none() const
{
	return this->member == T();
}

template<typename T>
T Optional<T>::get_value() const
{
	return this->member;
}

template<typename T>
Optional<T>& Optional<T>::operator=(const Optional<T>& rhs)
{
	this->member = rhs.member;
	return *this;
}
