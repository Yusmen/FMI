#pragma once
#include <iostream>
#include<cstring>
#pragma warning(disable : 4996)


enum class ErrorType {
    None,
    BuildFailed,
    Warning,
    FailedAssertion,
};

/// Error represents a potential test error
/// It has a type and an optional message
class Error {
    /// Feel free to add additional private/public methods/fields
public:
    /// Check if the error has a message

    bool hasMessage() const;

    /// Retrieve the message of an error if such exists,
    /// otherwise return the only "safe" invalid pointer :)
    const char* getMessage() const;

    /// Retrieve the type of the error
    ErrorType getType() const;

    /// Create a new error of type None with no message
    /// We will be creating new Errors only via the 4 methods below
    static Error newNone();

    /// Create a new error of type BuildFailed with a message
    static Error newBuildFailed(const char* message);

    /// Create a new error of type Warning with a message
    static Error newWarning(const char* message);

    /// Create a new error of type FailedAssertion with a message
    static Error newFailedAssertion(const char* message);

private :
    char* message;
    ErrorType errorType;
};
