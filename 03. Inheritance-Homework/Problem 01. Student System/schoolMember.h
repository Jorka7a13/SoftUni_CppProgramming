#ifndef SCHOOL_MEMBER_H
#define SCHOOL_MEMBER_H
#pragma once

#include <string>

class SchoolMember
{
private:
	unsigned short id_;
	std::string name_;
	std::string currentCourse_;

protected:
	SchoolMember(unsigned short id, std::string name, std::string currentCourse); // Protected allows initialization only from the derived classes.

public:
	~SchoolMember();
	unsigned short getId() const;
	std::string getName() const;
	std::string getCurrentCourse() const;
};

#endif