#ifndef GUEST_TEACHER_H
#define GUEST_TEACHER_H
#pragma once

#include "schoolMember.h"

class GuestTeacher : public SchoolMember
{
private:
	float salaryForCourse_;

public:
	GuestTeacher(unsigned short id, std::string name, std::string currentCourse, float salaryForCourse);
	~GuestTeacher();

	float getSalaryForCourse() const;

};

#endif