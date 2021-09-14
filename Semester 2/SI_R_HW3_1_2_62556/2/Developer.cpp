#include "Developer.hpp"
#include "TeamLead.hpp"

Developer::Developer(const std::string& name)
{
	this->name = name;
	this->salary = 0;
	this->teamLead = nullptr;
}

Developer::Developer()
{

}

//Developer::~Developer()
//{
//	if (this->teamLead != nullptr)
//	{
//		delete this->teamLead;
//	}
//
//}


std::string Developer::getName() const
{
	return name;
}

double& Developer::getSalary()
{
	return salary;
}

TeamLead*& Developer::getTeamLead()
{
	return teamLead;
}

void Developer::setInitialSalary(double amount)
{
	if (salary == 0)
	{
		this->salary = amount;
	}
}

void Developer::sendLeavingRequest()
{
	LeavingRequest leavingRequest(this->name);

	if (this->teamLead != nullptr && this->teamLead->findDeveloper(this->name) != -1)
	{
		this->teamLead->addLeavingRequest(leavingRequest);
	}

}

void Developer::sendPromotionRequest(double amount)
{
	PromotionRequest promotionRequest(this->name, amount);

	if (this->teamLead != nullptr && this->teamLead->findDeveloper(this->name) != -1)
	{
		this->teamLead->addPromotionRequest(promotionRequest);
	}
}

void Developer::print()
{
	std::cout << this->name << " " << this->salary << "\n";
}

