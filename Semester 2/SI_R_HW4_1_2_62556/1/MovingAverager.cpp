#include "MovingAverager.hpp"

MovingAverager::MovingAverager(std::string id, size_t windowSize) :Subscriber(id), windowSize(windowSize) {}

void MovingAverager::signal(Message message)
{
	this->datas.push_back(message);

}

int MovingAverager::read() const
{
	if ((int)this->datas.size() == 0)
	{
		return 0;
	}
	int sum = 0;
	int index = (int)this->datas.size() - 1;
	int average = 0;
	if (windowSize >= this->datas.size())
	{
		for (size_t i = 0; i < this->windowSize; i++)
		{
			sum += (int)this->datas[index].getData();
			index--;
		}
		average = sum / windowSize;
	}
	else
	{
		for (size_t i = 0; i < this->datas.size(); i++)
		{
			sum += (int)this->datas[index].getData();
			index--;
		}
		average = sum / (int)this->datas.size();
	}
	
	
	
	return average;
}

Subscriber* MovingAverager::clone() const
{
	return new MovingAverager(*this);
}
