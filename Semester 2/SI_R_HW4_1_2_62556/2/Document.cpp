#include "Document.hpp"
#include <stdexcept>

Document::Document(const std::string& name, const std::string& location, const std::string& extension)
	:Object(name, location, extension) {}


void Document::write_line(const std::string& line)
{
	this->lines.push_back(line);
}

std::string Document::read_line()
{
	if (lineNumber >= int(this->lines.size()))
	{
		throw std::out_of_range("");
	}
	std::string line = this->lines[this->lineNumber];
	lineNumber++;
	return line;

}

std::string Document::read_line(const unsigned line)
{
	if (line > 0)
	{
		this->lineNumber = (int)(line - 1);
	}

	if (lineNumber >= (int)this->lines.size())
	{
		throw std::out_of_range("");
	}
	std::string result = this->lines[lineNumber];
	lineNumber++;
	return result;
}

bool Document::operator==(const Comparable* cmp) const
{

	const Document* document = dynamic_cast<const Document*>(cmp);

	if (document && document->lines.size() == this->lines.size())
	{

		for (int i = 0; i < (int)this->lines.size(); i++)
		{
			if (document->lines[i] != this->lines[i])
			{
				return false;
			}
		}
	}
	return true;
}
bool Document::operator!=(const Comparable* cmp) const
{
	const Document* document = dynamic_cast<const Document*>(cmp);

	if (document && document->lines.size() == this->lines.size())
	{

		for (int i = 0; i < (int)this->lines.size(); i++)
		{
			if (document->lines[i] == this->lines[i])
			{
				return false;
			}
		}
	}
	return true;
}

std::string Document::debug_print() const
{
	std::string result = "";
	for (size_t i = 0; i < this->lines.size(); i++)
	{
		std::string temp = "";
		temp =(i + 1) + ':';
		temp += lines[i] + '\n';
	}
	return result;
}

std::string Document::to_string() const
{
	std::string result = name + '\n' + location + '\n' + extension + '\n';

	for (size_t i = 0; i < this->lines.size(); i++)
	{
		result += this->lines[i] + '\n';
	}

	return result;

}

void Document::from_string(const std::string& document)
{
	int index = 0;
	std::string name = "";
	while (document[index] != '\n')
	{
		name += document[index];
		index++;
	}
	this->name = name;
	index++;
	std::string location = "";
	while (document[index] != '\n')
	{
		location += document[index];
		index++;
	}
	this->location = location;
	index++;
	std::string extension = "";
	while (document[index] != '\n')
	{
		extension += document[index];
		index++;
	}
	this->extension = extension;
	index++;
	std::string line = "";
	for (int i = index; i < (int)document.length(); i++)
	{
		if (document[i] != '\n')
		{
			line += document[i];
		}
		else if (document[i] == '\n')
		{
			this->lines.push_back(line);
			line = "";

		}
	}

}

Object* Document::clone() const
{
	return new Document(*this);
}
