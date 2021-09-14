#pragma once
#ifndef TEAMLEAD_H
#define TEAMLEAD_H

#include<vector>

#include "Developer.hpp"

class TeamLead :public Developer
{
public:
	TeamLead(const std::string&, double);
	TeamLead();
	std::vector<Developer*>& getTeam();
	void addDeveloperToTeam(Developer* developer, double salary);
	void removeDeveloperFromTeam(const std::string& name);
	void increaseTeamSalariesBy(double amount);
	void decreaseTeamSalariesBy(double amount);
	void addLeavingRequest(const LeavingRequest& leavingRequest);
	void addPromotionRequest(const PromotionRequest& promotionRequest);
	void fulfillLeavingRequests();
	void fulfillPromotionRequests();
	void print();
	int findDeveloper(std::string);

private:
	
	
	std::vector<Developer*> team;
	std::vector<LeavingRequest> leavingRequests;
	std::vector<PromotionRequest> promotionRequests;
	

};
#endif

