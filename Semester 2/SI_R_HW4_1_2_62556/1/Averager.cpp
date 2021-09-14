#include "Averager.hpp"

Averager::Averager(std::string id) :Subscriber(id) {}


void Averager::signal(Message message)
{
	this->datas.push_back(message);
}

int Averager::read() const
{
	if ((int)this->datas.size() == 0)
	{
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < (int)this->datas.size(); i++)
	{
		sum += (int)this->datas[i].getData();
	}
	int average = sum / (int)this->datas.size();
	return average;
}

Subscriber* Averager::clone() const
{
	return new Averager(*this);
}
