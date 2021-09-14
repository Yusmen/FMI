#include "TeamLead.hpp"


TeamLead::TeamLead(const std::string& name, double salary)
{
	this->name = name;
	this->salary = salary;
	this->teamLead = this;

}

TeamLead::TeamLead()
{

}


std::vector<Developer*>& TeamLead::getTeam()
{
	return team;
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary)
{
	if (developer != nullptr)
	{
		developer->setInitialSalary(salary);
		developer->getTeamLead() = this;
		this->team.push_back(developer);

	}

}

void TeamLead::removeDeveloperFromTeam(const std::string& name)
{
	int index = -1;
	index = this->findDeveloper(name);


	if (index != -1)
	{
		team[index]->getTeamLead() = nullptr;
		team.erase(team.begin() + index);
	}

}

void TeamLead::increaseTeamSalariesBy(double amount)
{
	for (int i = 0; i < (int)team.size(); i++)
	{
		team[i]->getSalary() += amount;

	}
}

void TeamLead::decreaseTeamSalariesBy(double amount)
{
	for (int i = 0; i < (int)team.size(); i++)
	{
		team[i]->getSalary() -= amount;

	}
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest)
{
	int index = findDeveloper(leavingRequest.getSender());
	if (index != -1)
	{
		this->leavingRequests.push_back(leavingRequest);
	}

}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest)
{
	int index = findDeveloper(promotionRequest.getSender());
	if (index != -1)
	{
		this->promotionRequests.push_back(promotionRequest);
	}
	
}

void TeamLead::fulfillLeavingRequests()
{
	for (int i = 0; i < (int)this->leavingRequests.size(); i++)
	{
		this->removeDeveloperFromTeam(this->leavingRequests[i].getSender());

	}
	this->leavingRequests.clear();
}

void TeamLead::fulfillPromotionRequests()
{
	for (int i = 0; i < (int)this->promotionRequests.size(); i++)
	{
		int index = this->findDeveloper(this->promotionRequests[i].getSender());
		if (index != -1)
		{
			this->team[i]->getSalary() += this->promotionRequests[i].getAmount();

		}
	}
	this->promotionRequests.clear();
}
void TeamLead::print()
{

	for (int i = 0; i < (int)team.size(); i++)
	{
		team[i]->print();
	}
}
int TeamLead::findDeveloper(std::string name)
{
	int index = -1;
	for (int i = 0; i < (int)team.size(); i++)
	{
		if (team[i]->getName() == name)
		{
			index = i;
		}
	}
	return index;
}

