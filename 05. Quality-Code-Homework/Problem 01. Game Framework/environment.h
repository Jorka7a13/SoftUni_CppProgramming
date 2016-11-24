#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#pragma once

#include <string>

class Environment
{
private:
	unsigned int id_;
	std::string name_;
	double gravity_;

public:
	Environment();
	Environment(unsigned int id, std::string name, double gravity);

	unsigned int getId() const;
	std::string getName() const;
	double getGravity() const;
};

#endif