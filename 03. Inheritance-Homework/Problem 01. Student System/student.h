#ifndef STUDENT_H
#define STUDENT_H
#pragma once

#include "schoolMember.h"

class Student : public SchoolMember
{
private:
	unsigned char currentPoints_;
	float averageEvaluationMark_;

public:
	Student(unsigned short id, std::string name, std::string currentCourse, unsigned char currentPoints, float averageEvaluationMark);
	~Student();

	unsigned char getCurrentPoints() const;
	float getAverageEvaluationMark() const;
};

#endif