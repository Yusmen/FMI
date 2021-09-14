#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

#include "Error.hpp"
#include "Optional.hpp"

template<typename T>

class Result {
public:
	Result();
	Result(const T& result);
	Result(const std::string& error_message);

	Optional<T> get_result() const;
	Optional<Error> get_error() const;

	
	bool operator==(const Error& rhs) const;
	bool operator==(const T& rhs) const;

private:
	Optional<T> result;
	Optional<Error> errorResult;
	bool isError = false;

};

template<typename T>
Result<T>::Result()
{
	result = T();
}

template<typename T>
Result<T>::Result(const T& result)
{
	Optional<T> optional(result);
	this->result = optional;
	isError = false;
}

template<typename T>
Result<T>::Result(const std::string& error_message)
{
	Error error(error_message);
	Optional<Error> optional(error);
	this->errorResult = optional;
	isError = true;

}

template<typename T>
Optional<T> Result<T>::get_result() const
{
	return this->result;
}

template<typename T>
Optional<Error> Result<T>::get_error() const
{
	return this->errorResult;
}

template<typename T>
bool Result<T>::operator==(const Error& rhs) const
{
	if (this->isError)
	{
		return true;
	}
	return false;
}

template<typename T>
 bool Result<T>::operator==(const T& rhs) const
{
	if (!this->isError)
	{
		return true;
	}
	return false;
}
