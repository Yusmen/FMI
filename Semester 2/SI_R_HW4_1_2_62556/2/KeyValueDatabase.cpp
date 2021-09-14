#include "KeyValueDatabase.hpp"
#include <stdexcept>


KeyValueDatabase::KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension)
	:Object(name, location, extension) {}


void KeyValueDatabase::add_entry(const std::pair<std::string, int>& entry)
{
	for (size_t i = 0; i < this->entries.size(); i++)
	{
		if (this->entries[i].first == entry.first)
		{
			throw std::invalid_argument("");
		}
	}
	this->entries.push_back(entry);

}

int KeyValueDatabase::get_value(const std::string& key) const
{
	int result = 0;
	for (size_t i = 0; i < this->entries.size(); i++)
	{
		if (this->entries[i].first == key)
		{
			result = this->entries[i].second;
			break;
		}
	}
	if (result == 0)
	{
		throw std::invalid_argument("");
	}
	return result;
}

bool KeyValueDatabase::operator==(const Comparable* cmp) const
{
	const KeyValueDatabase* kvd = dynamic_cast<const KeyValueDatabase*>(cmp);

	if (kvd && kvd->entries.size() == this->entries.size())
	{
		for (size_t i = 0; i < this->entries.size(); i++)
		{
			if (this->entries[i].first != kvd->entries[i].first
				&& this->entries[i].second != kvd->entries[i].second)
			{
				return false;
			}
		}
	}

	return true;
}

bool KeyValueDatabase::operator!=(const Comparable* cmp) const
{

	const KeyValueDatabase* kvd = dynamic_cast<const KeyValueDatabase*>(cmp);

	if (kvd && kvd->entries.size() == this->entries.size())
	{
		for (size_t i = 0; i < this->entries.size(); i++)
		{
			if (this->entries[i].first == kvd->entries[i].first
				&& this->entries[i].second != kvd->entries[i].second)
			{
				return false;
			}
		}
	}

	return true;
}

std::string KeyValueDatabase::debug_print() const
{
	std::string result = "";
	for (size_t i = 0; i < this->entries.size(); i++)
	{
		std::string temp = "";
		
		temp = this->entries[i].first + ':';
		temp += (this->entries[i].second) + '\n';
		result += temp;
	}

	return result;
}

std::string KeyValueDatabase::to_string() const
{
	std::string result = name + '\n' + location + '\n' + extension + '\n';

	for (size_t i = 0; i < this->entries.size(); i++)
	{
		std::string temp = "";
		
		temp = this->entries[i].first + ':';
		temp += this->entries[i].second + '\n';
		result += temp;
	}

	return result;
}

void KeyValueDatabase::from_string(const std::string& kvd)
{
	int index = 0;
	std::string name = "";
	while (kvd[index] != '\n')
	{
		name += kvd[index];
		index++;
	}
	this->name = name;
	index++;
	std::string location = "";
	while (kvd[index] != '\n')
	{
		location += kvd[index];
		index++;
	}
	this->location = location;
	index++;
	std::string extension = "";
	while (kvd[index] != '\n')
	{
		extension += kvd[index];
		index++;
	}
	this->extension = extension;
	index++;
	std::string result = "";
	for (int i = index; i < (int)kvd.length(); i++)
	{
		std::pair<std::string, int> resultPair;
		
		if (kvd[i] != ':' && kvd[i] != '\n')
		{
			result += kvd[i];
		}
		else if (kvd[i] == ':')
		{
			resultPair.first = result;	
			result = "";

		}
		else if (kvd[i] == '\n')
		{	
			resultPair.second= stoi(result);
			result = "";
		}
		this->entries.push_back(resultPair);
	}


}

Object* KeyValueDatabase::clone() const
{
	return new KeyValueDatabase(*this);
}
