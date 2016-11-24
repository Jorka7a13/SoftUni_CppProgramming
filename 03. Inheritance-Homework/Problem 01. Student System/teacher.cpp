#include "teacher.h"

Teacher::Teacher(unsigned short id, std::string name, std::string currentCourse, float monthlySalary, unsigned short daysPassed)
	: SchoolMember(id, name, currentCourse), 
	monthlySalary_(monthlySalary), 
	daysPassed_(daysPassed)
{}

Teacher::~Teacher()
{}

float Teacher::getMonthlySalary() const
{
	return this->monthlySalary_;
}

unsigned short Teacher::getDaysPassed() const
{
	return this->daysPassed_;
}