#include "student.h"

Student::Student(unsigned short id, std::string name, std::string currentCourse, unsigned char currentPoints, float averageEvaluationMark)
	: SchoolMember(id, name, currentCourse), 
	currentPoints_(currentPoints), 
	averageEvaluationMark_(averageEvaluationMark)
{}

Student::~Student()
{}

unsigned char Student::getCurrentPoints() const
{
	return this->currentPoints_;
}

float Student::getAverageEvaluationMark() const
{
	return this->averageEvaluationMark_;
}