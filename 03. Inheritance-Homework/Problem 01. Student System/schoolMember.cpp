#include "schoolMember.h"

SchoolMember::SchoolMember(unsigned short id, std::string name, std::string currentCourse)
	: id_(id), 
	name_(name), 
	currentCourse_(currentCourse)
{}

SchoolMember::~SchoolMember()
{}

unsigned short SchoolMember::getId() const
{
	return this->id_;
}

std::string SchoolMember::getName() const
{
	return this->name_;
}

std::string SchoolMember::getCurrentCourse() const
{
	return this->currentCourse_;
}