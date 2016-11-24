#ifndef TEACHER_H
#define TEACHER_H
#pragma once

#include "schoolMember.h"

class Teacher : public SchoolMember
{
private:
	float monthlySalary_;
	unsigned short daysPassed_;

public:
	Teacher(unsigned short id, std::string name, std::string currentCourse, float monthlySalary, unsigned short daysPassed);
	~Teacher();

	float getMonthlySalary() const;
	unsigned short getDaysPassed() const;
};

#endif