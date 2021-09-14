#include "Error.hpp"


bool Error::hasMessage() const
{
	if (this->message == nullptr)
	{
		return false;
	}
	return true;
}

const char* Error::getMessage() const
{
	return this->message;
}

ErrorType Error::getType() const
{
	return this->errorType;
}

Error Error::newNone()
{
	Error error;
	error.errorType = ErrorType::None;
	error.message = nullptr;
	return error;
}

Error Error::newBuildFailed(const char* message)
{
	Error error;
	error.message = new char[strlen(message) + 1];
	strcpy(error.message, message);
	error.errorType = ErrorType::BuildFailed;
	return error;


}

Error Error::newWarning(const char* message)
{
	Error error;
	error.message = new char[strlen(message) + 1];
	strcpy(error.message, message);
	error.errorType = ErrorType::Warning;
	return error;
}

Error Error::newFailedAssertion(const char* message)
{
	Error error;
	error.message = new char[strlen(message) + 1];
	strcpy(error.message, message);
	error.errorType = ErrorType::FailedAssertion;
	return error;
}
