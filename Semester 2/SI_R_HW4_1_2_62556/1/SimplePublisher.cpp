#include "SimplePublisher.hpp"

void SimplePublisher::subscribe(Subscriber* subscriber)
{

	this->subscribers.push_back(subscriber);
}

void SimplePublisher::unsubscribe(Subscriber* subscriber)
{
	for (int i = 0; i < (int)this->subscribers.size(); i++)
	{
		if (subscriber->id == this->subscribers[i]->id)
		{
			this->subscribers.erase(subscribers.begin() + i);
		}
	}
}

void SimplePublisher::signal(const Message& message)
{
	this->messages.push_back(message);
	for (int i = 0; i < (int)this->subscribers.size(); i++)
	{
		this->subscribers[i]->signal(message);
	}

}

//Publisher* SimplePublisher::clone() const
//{
//	return new SimplePublisher(*this);
//}

