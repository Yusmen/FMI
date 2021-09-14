#pragma once
#include<string>
#include<vector>
#include"Message.hpp"

class Subscriber
{
public:
	Subscriber(std::string id);

	std::string id;

	virtual void signal(Message) = 0;

	virtual int read() const = 0;

	virtual Subscriber* clone() const = 0;
	~Subscriber() = default;

protected:

	std::vector<Message> datas;

};


