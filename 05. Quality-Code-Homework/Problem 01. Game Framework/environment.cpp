#include "environment.h"

Environment::Environment()
{}

Environment::Environment(unsigned int id, std::string name, double gravity)
	: id_(id),
	name_(name),
	gravity_(gravity)
{}

unsigned int Environment::getId() const
{
	return this->id_;
}

std::string Environment::getName() const
{
	return this->name_;
}

double Environment::getGravity() const
{
	return this->gravity_;
}