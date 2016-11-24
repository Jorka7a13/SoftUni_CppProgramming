#ifndef CHARACTER_H
#define CHARACTER_H
#pragma once

#include <string>

class Character
{
private:
	unsigned int id_;
	std::string name_;
	float mass_;
	unsigned short jumpSpeed_;

public:
	Character();
	Character(unsigned int id, std::string name, float mass, unsigned short jumpSpeed);

	unsigned int getId() const;
	std::string getName() const;
	float getMass() const;
	unsigned short getJumpSpeed() const;
};

#endif