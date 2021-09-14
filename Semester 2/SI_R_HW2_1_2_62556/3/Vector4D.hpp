#pragma once
#include<vector>
#include<iostream>
class Vector4D
{

public:
	const static int numbers_count = 4;
	Vector4D(double, double, double, double);
	Vector4D();
	Vector4D& operator=(const Vector4D& rhs);
	double& operator[](int index);
	void print() const;

	Vector4D operator+(const Vector4D& rhs) const;
	Vector4D operator-(const Vector4D& rhs) const;
	Vector4D operator*(const Vector4D& rhs) const;
	Vector4D operator/(const Vector4D& rhs) const;

	Vector4D operator*(const double number) const;

	Vector4D& operator+=(const Vector4D& rhs);
	Vector4D& operator-=(const Vector4D& rhs);
	Vector4D& operator*=(const Vector4D& rhs);
	Vector4D& operator*=(const double number);
	Vector4D& operator/=(const Vector4D& rhs);
	Vector4D operator-() const;

	bool operator==(const Vector4D& rhs) const;
	bool operator!=(const Vector4D& rhs) const;
	bool operator<(const Vector4D& rhs) const;
	bool operator>(const Vector4D& rhs) const;
	bool operator>=(const Vector4D& rhs) const;
	bool operator<=(const Vector4D& rhs) const;
	bool operator!() const;
	
	
private:
	
	double numbers[numbers_count];
	

};