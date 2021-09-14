#pragma once
#ifndef DEVELOPER_H
#define DEVELOPER_H


#include<string>
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"
#include<iostream>

class TeamLead;
class Developer
{
public:
	Developer(const std::string&);
	Developer();
	std::string getName() const;
	double& getSalary();
	TeamLead*& getTeamLead();
	void setInitialSalary(double);
	void sendLeavingRequest();
	void sendPromotionRequest(double);
	void print();

protected:
	std::string name;
	double salary;
	TeamLead* teamLead;
};
#endif