#include "student.h"
#include "teacher.h"
#include "guestTeacher.h"

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<Student> students;
vector<Teacher> teachers;
vector<GuestTeacher> guestTeachers;

Student getStudentById(unsigned short id)
{
	auto it = find_if(students.begin(), students.end(), [&id](const Student& obj) { return obj.getId() == id; });

	if (it != students.end())
	{
		return *it;
	}
}

Teacher getTeacherById(unsigned short id)
{
	auto it = find_if(teachers.begin(), teachers.end(), [&id](const Teacher& obj) { return obj.getId() == id; });

	if (it != teachers.end())
	{
		return *it;
	}
}

GuestTeacher getGuestTeacherById(unsigned short id)
{
	auto it = find_if(guestTeachers.begin(), guestTeachers.end(), [&id](const GuestTeacher& obj) { return obj.getId() == id; });

	if (it != guestTeachers.end())
	{
		return *it;
	}
}

void addStudent(Student student)
{
	students.push_back(student);
}

void addTeacher(Teacher teacher)
{
	teachers.push_back(teacher);
}

void addGuestTeacher(GuestTeacher guestTeacher)
{
	guestTeachers.push_back(guestTeacher);
}

void printStudentData(Student student)
{
	cout << "ID: " << student.getId() << endl;
	cout << "Name: " << student.getName() << endl;
	cout << "Current course: " << student.getCurrentCourse() << endl;
	cout << "Current points for the course: " << student.getCurrentPoints() << endl;
	cout << "Average evaluation mark: " << student.getAverageEvaluationMark() << endl;
	cout << endl;
}

void printTeacherData(Teacher teacher)
{
	cout << "ID: " << teacher.getId() << endl;
	cout << "Name: " << teacher.getName() << endl;
	cout << "Current course: " << teacher.getCurrentCourse() << endl;
	cout << "Monthly salary: " << teacher.getMonthlySalary() << endl;
	cout << "Joined " << teacher.getDaysPassed() << " days ago."<< endl;
	cout << endl;
}

void printGuestTeacherData(GuestTeacher guestTeacher)
{
	cout << "ID: " << guestTeacher.getId() << endl;
	cout << "Name: " << guestTeacher.getName() << endl;
	cout << "Current course: " << guestTeacher.getCurrentCourse() << endl;
	cout << "Salary for course: " << guestTeacher.getSalaryForCourse() << endl;
	cout << endl;
}

int main()
{
	int menuSelection;
	bool isRunning = true;

	while (isRunning)
	{
		cout << endl;
		cout << "Please choose an option: " << endl;
		cout << "1. Get data for student with ID" << endl;
		cout << "2. Get data for teacher with ID" << endl;
		cout << "3. Get data for gest teacher with ID" << endl;
		cout << "4. Add data for new student" << endl;
		cout << "5. Add data for new teacher" << endl;
		cout << "6. Add data for new guest teacher" << endl;
		cout << "0. Exit" << endl << endl;

		cout << "Option: ";
		cin >> menuSelection;
		cout << endl;

		if (menuSelection != 0 && (menuSelection < 1 || menuSelection > 6))
		{
			cerr << menuSelection << " is an invalid option!" << endl;
		}
		else if (menuSelection == 0)
		{
			isRunning = false;
		}
		else
		{
			switch (menuSelection)
			{
				case 1:
				{
					unsigned short currentId;

					cout << "Please enter an id: ";
					cin >> currentId;
					cout << endl;

					Student student = getStudentById(currentId);
					printStudentData(student);

					break;
				}
				case 2:
				{
					unsigned short currentId;

					cout << "Please enter an id: ";
					cin >> currentId;
					cout << endl;

					Teacher teacher = getTeacherById(currentId);
					printTeacherData(teacher);

					break;
				}
				case 3:
				{
					unsigned short currentId;

					cout << "Please enter an id: ";
					cin >> currentId;
					cout << endl;

					GuestTeacher guestTeacher = getGuestTeacherById(currentId);
					printGuestTeacherData(guestTeacher);

					break;
				}
				case 4:
				{
					unsigned short id;
					string name; 
					string currentCourse;
					unsigned char currentPoints;
					float averageEvaluationMark;

					cout << "Please enter an id: ";
					cin >> id;
					cout << "Please enter a name: ";
					cin >> name;
					cout << "Please enter a current course: ";
					cin >> currentCourse;
					cout << "Please enter current points for the course: ";
					cin >> currentPoints;
					cout << "Please enter average evaluation mark: ";
					cin >> averageEvaluationMark;

					addStudent(Student(id, name, currentCourse, currentPoints, averageEvaluationMark));
					break;
				}
				case 5:
				{
					unsigned short id;
					string name;
					string currentCourse;
					float monthlySalary;
					unsigned short daysPassed;

					cout << "Please enter an id: ";
					cin >> id;
					cout << "Please enter a name: ";
					cin >> name;
					cout << "Please enter a current course: ";
					cin >> currentCourse;
					cout << "Please enter a monthly salary: ";
					cin >> monthlySalary;
					cout << "Please enter how many days have passed since they joined: ";
					cin >> daysPassed;

					addTeacher(Teacher(id, name, currentCourse, monthlySalary, daysPassed));
					break;
				}
				case 6:
				{
					unsigned short id;
					string name;
					string currentCourse;
					float salary;

					cout << "Please enter an id: ";
					cin >> id;
					cout << "Please enter a name: ";
					cin >> name;
					cout << "Please enter a current course: ";
					cin >> currentCourse;
					cout << "Please enter a salary for course: ";
					cin >> salary;

					addGuestTeacher(GuestTeacher(id, name, currentCourse, salary));
					break;
				}
			}
		}
	}

	return 0;
}