#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(std::string id, size_t period) :Subscriber(id), period(period) {}


void PeriodicSampler::signal(Message message)
{
	this->datas.push_back(message);

	if (((int)datas.size() - 1) % this->period != 0 && (int)datas.size() != 1)
	{
		this->datas[(int)datas.size() - 1].isIgnored = true;

	}
	else
	{
		this->datas[(int)datas.size() - 1].isIgnored = false;
	}



}

int PeriodicSampler::read() const
{
	if ((int)this->datas.size() == 0)
	{
		return 0;
	}
	int index = 0;
	for (int i = (int)this->datas.size() - 1; i >= 0; i--)
	{
		if (this->datas[i].isIgnored == false)
		{
			index = i;
			break;


		}

	}
	return this->datas[index].getData();
}

Subscriber* PeriodicSampler::clone() const
{
	return new PeriodicSampler(*this);
}
