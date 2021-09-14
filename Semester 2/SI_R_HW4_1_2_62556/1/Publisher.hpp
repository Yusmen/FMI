#pragma once
#include "Subscriber.hpp"
class Publisher
{
public:
	virtual void subscribe(Subscriber*) = 0;
	virtual void unsubscribe(Subscriber*) = 0;
	virtual void signal(const Message&) = 0;
	//~Publisher() = default;

protected:
	std::vector<Subscriber*> subscribers;
	std::vector<Message> messages;
	

};

