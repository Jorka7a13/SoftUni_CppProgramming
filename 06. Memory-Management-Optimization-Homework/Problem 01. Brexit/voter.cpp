#include "voter.h"
#include <iostream>

Voter::Voter()
{}

Voter::Voter(unsigned short age, std::string name, Gender gender, std::string city, std::string ethnos, Vote vote)
{
	setAge(age);
	setName(name);
	setGender(gender);
	setCity(city);
	setEthnos(ethnos);
	setVote(vote);
}

bool Voter::operator<(const Voter& voter) const
{
	return this->getName() < voter.getName();
}

void Voter::setAge(unsigned short age)
{
	if (age >= 18)
	{
		this->age_ = age;
	} 
	else 
	{
		std::cerr << "Age must be over 18 to vote!" << std::endl;
		this->age_ = 0;
	}
}

unsigned short Voter::getAge() const
{
	return this->age_;
}

void Voter::setName(std::string name)
{
	if (std::string::npos == name.find_first_of("0123456789!*/_=."))
	{
		this->name_ = name;
	}
	else 
	{
		std::cerr << "Name must contain only letters!" << std::endl;
		this->name_ = "";
	}
}

std::string Voter::getName() const 
{
	return this->name_;
}

void Voter::setGender(Gender gender)
{
	this->gender_ = gender;
}

Gender Voter::getGender() const
{
	return this->gender_;
}

void Voter::setCity(std::string city)
{
	if (std::string::npos == city.find_first_of("0123456789!*/_=."))
	{
		this->city_ = city;
	}
	else
	{
		std::cerr << "City name must contain only letters!" << std::endl;
		this->city_ = "";
	}
}

std::string Voter::getCity() const
{
	return this->city_;
}

void Voter::setEthnos(std::string ethnos)
{
	if (std::string::npos == ethnos.find_first_of("0123456789!*/_=."))
	{
		this->ethnos_ = ethnos;
	}
	else
	{
		std::cerr << "Ethnos name must contain only letters!" << std::endl;
		this->ethnos_ = "";
	}
}

std::string Voter::getEthnos() const
{
	return this->ethnos_;
}

void Voter::setVote(Vote vote)
{
	this->vote_ = vote;
}

Vote Voter::getVote() const
{
	return this->vote_;
}

bool Voter::isValid() const
{
	if (this->age_ >= 18 && this->name_ != "" && this->city_ != "" && this->ethnos_ != "")
	{
		return true;
	}

	return false;
}