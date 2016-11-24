#include "character.h"

Character::Character()
{}

Character::Character(unsigned int id, std::string name, float mass, unsigned short jumpSpeed)
	: id_(id),
	name_(name),
	mass_(mass),
	jumpSpeed_(jumpSpeed)
{}

unsigned int Character::getId() const
{
	return this->id_;
}

std::string Character::getName() const 
{
	return this->name_;
}

float Character::getMass() const
{
	return this->mass_;
}

unsigned short Character::getJumpSpeed() const
{
	return this->jumpSpeed_;
}