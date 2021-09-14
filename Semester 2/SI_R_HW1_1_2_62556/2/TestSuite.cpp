#include "TestSuite.hpp"

TestSuite::TestSuite(std::string name)
{
	this->name = name;
}

void TestSuite::add(const TestCase& new_test)
{
	this->testCases.push_back(new_test);
}

std::vector<TestCase> TestSuite::filterPassing() const
{
	std::vector<TestCase> passing;
	for (int i = 0; i < (int)this->testCases.size(); i++)
	{
		if (this->testCases[i].isPassing())
		{
			passing.push_back(this->testCases[i]);
		}

	}
	return passing;

}

std::vector<TestCase> TestSuite::filterFailing() const
{
	std::vector<TestCase> failedTests;
	for (int i = 0; i < this->testCases.size(); i++)
	{
		if (this->testCases[i].hasError())
		{
			failedTests.push_back(this->testCases[i]);
		}

	}
	return failedTests;
}

std::vector<TestCase> TestSuite::filterByErrorType(ErrorType errorType) const
{
	std::vector<TestCase> resultTests;
	for (int i = 0; i < this->testCases.size(); i++)
	{
		if (this->testCases[i].getErrorType() == errorType)
		{
			resultTests.push_back(this->testCases[i]);
		}

	}
	return resultTests;
}

void TestSuite::removeByErrorType(ErrorType errorType)
{

	for (int i = 0; i < this->testCases.size(); i++)
	{
		if (this->testCases[i].getErrorType() == errorType)
		{
			this->testCases.erase(testCases.begin() + i);
		}

	}

}

std::string TestSuite::getName() const
{
	return this->name;
}

void TestSuite::setName(const std::string& new_name)
{
	this->name = new_name;
}
