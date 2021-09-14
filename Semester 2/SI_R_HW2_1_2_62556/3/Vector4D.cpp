#include "Vector4D.hpp"

Vector4D::Vector4D(double number1, double number2, double number3, double number4)
{

	this->numbers[0] = number1;
	this->numbers[1] = number2;
	this->numbers[2] = number3;
	this->numbers[3] = number4;

}

Vector4D::Vector4D()
{
	numbers[0] = 0;
	numbers[1] = 0;
	numbers[2] = 0;
	numbers[3] = 0;

}


Vector4D& Vector4D::operator=(const Vector4D& rhs)
{
	this->numbers[0] = rhs.numbers[0];
	this->numbers[1] = rhs.numbers[1];
	this->numbers[2] = rhs.numbers[2];
	this->numbers[3] = rhs.numbers[3];

	return *this;
}

double& Vector4D::operator[](int index)
{
	return this->numbers[index];
}

void Vector4D::print() const
{
	std::cout << numbers[0] << std::endl;
	std::cout << numbers[1] << std::endl;
	std::cout << numbers[2] << std::endl;
	std::cout << numbers[3] << std::endl;
}

Vector4D Vector4D::operator+(const Vector4D& rhs) const
{
	Vector4D result;

	result.numbers[0] = this->numbers[0] + rhs.numbers[0];
	result.numbers[1] = this->numbers[1] + rhs.numbers[1];
	result.numbers[2] = this->numbers[2] + rhs.numbers[2];
	result.numbers[3] = this->numbers[3] + rhs.numbers[3];

	return result;
}

Vector4D Vector4D::operator-(const Vector4D& rhs) const
{
	Vector4D result;

	result.numbers[0] = this->numbers[0] - rhs.numbers[0];
	result.numbers[1] = this->numbers[1] - rhs.numbers[1];
	result.numbers[2] = this->numbers[2] - rhs.numbers[2];
	result.numbers[3] = this->numbers[3] - rhs.numbers[3];

	return result;
}

Vector4D Vector4D::operator*(const Vector4D& rhs) const
{
	Vector4D result;

	result.numbers[0] = this->numbers[0] * rhs.numbers[0];
	result.numbers[1] = this->numbers[1] * rhs.numbers[1];
	result.numbers[2] = this->numbers[2] * rhs.numbers[2];
	result.numbers[3] = this->numbers[3] * rhs.numbers[3];

	return result;
}

Vector4D Vector4D::operator/(const Vector4D& rhs) const
{
	Vector4D result;

	if (rhs.numbers[0] == 0 || rhs.numbers[1] == 0 || rhs.numbers[2] == 0 || rhs.numbers[3] == 0)
	{
		std::cout << "Cannot divide by zero!" << std::endl;
		return result;

	}


	result.numbers[0] = this->numbers[0] / rhs.numbers[0];
	result.numbers[1] = this->numbers[1] / rhs.numbers[1];
	result.numbers[2] = this->numbers[2] / rhs.numbers[2];
	result.numbers[3] = this->numbers[3] / rhs.numbers[3];

	return result;
}

Vector4D Vector4D::operator*(const double number) const
{
	Vector4D result;

	result.numbers[0] = this->numbers[0] * number;
	result.numbers[1] = this->numbers[1] * number;
	result.numbers[2] = this->numbers[2] * number;
	result.numbers[3] = this->numbers[3] * number;

	return result;
}

Vector4D& Vector4D::operator+=(const Vector4D& rhs) 
{
	this->numbers[0] += rhs.numbers[0];
	this->numbers[1] += rhs.numbers[1];
	this->numbers[2] += rhs.numbers[2];
	this->numbers[3] += rhs.numbers[3];

	return *this;

}

Vector4D& Vector4D::operator-=(const Vector4D& rhs)
{
	this->numbers[0] -= rhs.numbers[0];
	this->numbers[1] -= rhs.numbers[1];
	this->numbers[2] -= rhs.numbers[2];
	this->numbers[3] -= rhs.numbers[3];

	return *this;
}

Vector4D& Vector4D::operator*=(const Vector4D& rhs)
{
	this->numbers[0] *= rhs.numbers[0];
	this->numbers[1] *= rhs.numbers[1];
	this->numbers[2] *= rhs.numbers[2];
	this->numbers[3] *= rhs.numbers[3];

	return *this;
}

Vector4D& Vector4D::operator*=(const double number)
{
	this->numbers[0] *= number;
	this->numbers[1] *= number;
	this->numbers[2] *= number;
	this->numbers[3] *= number;
	return *this;
}

Vector4D& Vector4D::operator/=(const Vector4D& rhs)
{
	if (rhs.numbers[0] == 0 || rhs.numbers[1] == 0 || rhs.numbers[2] == 0 || rhs.numbers[3] == 0)
	{
		std::cout << "Cannot divide by zero!";

	}
	this->numbers[0] /= rhs.numbers[0];
	this->numbers[1] /= rhs.numbers[1];
	this->numbers[2] /= rhs.numbers[2];
	this->numbers[3] /= rhs.numbers[3];

	return *this;
}

Vector4D Vector4D::operator-()const
{
	Vector4D result;

	result.numbers[0] = (numbers[0] == 0) ? 0 : -numbers[0];
	result.numbers[1] = (numbers[1] == 0) ? 0 : -numbers[1];
	result.numbers[2] = (numbers[2] == 0) ? 0 : -numbers[2];
	result.numbers[3] = (numbers[3] == 0) ? 0 : -numbers[3];

	return result;
}



bool Vector4D::operator==(const Vector4D& rhs) const
{
	return (this->numbers[0] == rhs.numbers[0]
		&& this->numbers[1] == rhs.numbers[1]
		&& this->numbers[2] == rhs.numbers[2]
		&& this->numbers[3] == rhs.numbers[3]);
}

bool Vector4D::operator!=(const Vector4D& rhs) const 
{
	if (this->numbers[0] != rhs.numbers[0]
		|| this->numbers[1] != rhs.numbers[1]
		|| this->numbers[2] != rhs.numbers[2]
		|| this->numbers[3] != rhs.numbers[3])
	{
		return true;
	}
	return false;
}

bool Vector4D::operator<(const Vector4D& rhs) const
{
	bool flag = false;
	for (int i = 0; i < numbers_count; i++)
	{
		if (this->numbers[i] < rhs.numbers[i])
		{
			flag = true;
			break;
			
		}
		else if (this->numbers[i] != rhs.numbers[i])
		{
			flag = false;
			break;
			
		}
	}
	return flag;

}

bool Vector4D::operator>(const Vector4D& rhs) const 
{
	bool flag = false;
	for (int i = 0; i < numbers_count; i++)
	{
		if (this->numbers[i] > rhs.numbers[i])
		{
			flag = true;
		}
		else if (this->numbers[i] != rhs.numbers[i])
		{
			flag = false;
		}
	}
	return flag;
}

bool Vector4D::operator>=(const Vector4D& rhs) const
{
	bool flag = false;

	if (*this == rhs)
	{
		return true;
	}
	for (int i = 0; i < numbers_count; i++)
	{
		if (this->numbers[i] > rhs.numbers[i])
		{
			flag = true;
		}
		else if (this->numbers[i] != rhs.numbers[i])
		{
			flag = false;
		}
	}
	return flag;
}

bool Vector4D::operator<=(const Vector4D& rhs) const
{
	bool flag = false;
	if (*this == rhs)
	{
		return true;
	}
	for (int i = 0; i < numbers_count; i++)
	{
		if (this->numbers[i] < rhs.numbers[i])
		{
			flag = true;
		}
		else if (this->numbers[i] != rhs.numbers[i])
		{
			flag = false;
		}
	}

	return flag;
}

bool Vector4D::operator!() const
{
	if (numbers[0] == 0
		&& numbers[1] == 0
		&& numbers[2] == 0
		&& numbers[3] == 0)
	{
		return true;
	}
	return false;
}

