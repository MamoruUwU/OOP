#pragma once
#include <iostream>
#include <string>

class Liquid
{
protected:
	std::string name;
	double density;

public:
	Liquid(std::string name, double density)
	{
		this->name = name;
		this->density = density;
	}
	~Liquid() {};

	void print()
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Density: " << density << std::endl;
	}
};

class Alcohol : public Liquid
{
private:
	double alcohol_strength;
public:
	Alcohol(std::string name, double density, double alcohol_strength) : Liquid(name, density)
	{
		this->alcohol_strength = alcohol_strength;
	};
	~Alcohol() {};

	void new_data(std::string name, double density)
	{
		this->name = name;
		this->density = density;
	}

	void print()
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Density: " << density << std::endl;
		std::cout << "Alcohol strength: " << alcohol_strength << std::endl;
	}
};