#include "Repository.hpp"



void Repository::add(Subscriber* subscriber)
{
	this->subscribers.push_back(subscriber);

}

Repository::Repository(const Repository& rhs)
{
	for (auto x : rhs.subscribers) {
		subscribers.push_back(x->clone());
	}

}

Repository& Repository::operator=(const Repository& rhs)
{
	if (this != &rhs)
	{
		for (auto x : subscribers)
		{
			if (x != nullptr)
			{
				delete x;
			}
			
		}
		subscribers.clear();

		for (auto x : rhs.subscribers)
		{
			subscribers.push_back(x->clone());
		}
	}
	return *this;

}

Subscriber* Repository::get(const std::string& id) const
{
	int index = 0;
	bool exists = false;
	for (int i = 0; i < (int)this->subscribers.size(); i++)
	{
		if (this->subscribers[i]->id == id)
		{
			exists = true;
			index = i;
			break;

		}
	}
	if (!exists)
	{
		return nullptr;
	}
	return this->subscribers[index];
}
