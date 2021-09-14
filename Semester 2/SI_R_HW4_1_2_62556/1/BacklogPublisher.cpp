#include "BacklogPublisher.hpp"

void BacklogPublisher::subscribe(Subscriber* subscriber)
{
	for (int i = 0; i < (int)this->messages.size(); i++)
	{
		subscriber->signal(messages[i]);
	}
	this->subscribers.push_back(subscriber);
}

void BacklogPublisher::unsubscribe(Subscriber* subscriber)
{
	for (int i = 0; i < (int)this->subscribers.size(); i++)
	{
		if (subscriber->id == this->subscribers[i]->id)
		{
			this->subscribers.erase(subscribers.begin() + i);
		}
	}
}

void BacklogPublisher::signal(const Message& message)
{
	this->messages.push_back(message);
	for (int i = 0; i < (int)this->subscribers.size(); i++)
	{
		this->subscribers[i]->signal(message);
	}

}
