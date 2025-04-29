#pragma once
#include <iostream>
#include <string>

class Wheels
{
protected:
	double radius;
	int count;
	std::string name;
public:
	Wheels(std::string name, double radius, int count)
	{
		this->name = name;
		this->radius = radius;
		this->count = count;
	};
	~Wheels() {};
	void print()
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Radius: " << radius << std::endl;
		std::cout << "Count: " << count << std::endl;
	}
};

class Car : public Wheels
{
private:
	double speed;
public:
	Car(std::string name, double radius, int count, double speed) : Wheels(name, radius, count)
	{
		this->speed = speed;
	};
	~Car() {};
	void print()
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Radius: " << radius << std::endl;
		std::cout << "Count: " << count << std::endl;
		std::cout << "Speed: " << speed << std::endl;
	}
};

class Bicycle : public Wheels
{
private:
	double speed;
public:
	Bicycle(std::string name, double radius, int count, double speed) : Wheels(name, radius, count)
	{
		this->speed = speed;
	};
	~Bicycle() {};
	void print()
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Radius: " << radius << std::endl;
		std::cout << "Count: " << count << std::endl;
		std::cout << "Speed: " << speed << std::endl;
	}
};