#include "guestTeacher.h"

GuestTeacher::GuestTeacher(unsigned short id, std::string name, std::string currentCourse, float salaryForCourse)
	: SchoolMember(id, name, currentCourse),
	salaryForCourse_(salaryForCourse)
{}

GuestTeacher::~GuestTeacher()
{}

float GuestTeacher::getSalaryForCourse() const
{
	return this->salaryForCourse_;
}