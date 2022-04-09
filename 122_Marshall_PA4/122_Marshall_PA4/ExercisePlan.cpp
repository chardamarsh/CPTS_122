/* Programmer: Charles Marshall
*
Class : CPTS 122; Lab section 13

Programming Assignment : PA 4 : Fitness Application in C++

Date : 3 - 2 - 2022

Description : This file contains the class functions necessary to do the following:

Get, set, and destruct objects of class ExercisePlan;
edit individual exercise plans;
and overloaded operators to read and write information contained in objects of class ExercisePlan to and from input and output files.

*/

#include "ExercisePlan.h"

ExercisePlan::ExercisePlan(int calories, string name, string date)
{
	if (calories < 0)
	{
		cSteps = 0;
	}
	else
	{
		cSteps = calories;
	}
	cName = name;
	cDate = date;
}
ExercisePlan::ExercisePlan(const ExercisePlan& copyPlan)
{
	cSteps = copyPlan.getSteps();
	cName = copyPlan.getName();
	cDate = copyPlan.getDate();
}
ExercisePlan::~ExercisePlan()
{
	//cout << "Exercise Plan cleared." << endl;
}
int ExercisePlan::getSteps() const
{
	return cSteps;
}
string ExercisePlan::getName() const
{
	return cName;
}
string ExercisePlan::getDate() const
{
	return cDate;
}
void ExercisePlan::setSteps(int newSteps)
{
	cSteps = newSteps;
}
void ExercisePlan::setName(string newName)
{
	cName = newName;
}
void ExercisePlan::setDate(string newDate)
{
	cDate = newDate;
}

void ExercisePlan::editExerciseGoal()
{
	int steps = 0;
	string name;
	string date;
	int m = 0, d = 0, y = 0;
	while (cout << "Enter a new steps value:"<<endl && !(cin >> steps) || steps <0)
	{
		cin.clear(); //clear bad input flag
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		cout << "Invalid input; please re-enter.\n"<<endl;
	}
	this->setSteps(steps);
	while (cout << "Enter a new goal name:" << endl && !(cin >> name))
	{
		cin.clear(); //clear bad input flag
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		cout << "Invalid input; please re-enter.\n" << endl;
	}
	this->setName(name);
	cout << "Enter a new Date:" << endl;
	while (cout << "Month (MM):" << endl && !(cin >> m) || ((m < 1) || (m > 12)))
	{
		cin.clear(); //clear bad input flag
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		cout << "Invalid input; please re-enter.\n" << endl;
	}
	while (cout << "Day(DD):" << endl && !(std::cin >> d) || ((d < 1) || (d > 31)))
	{
		cin.clear(); //clear bad input flag
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		cout << "Invalid input; please re-enter.\n" << endl;
	}
	while (cout << "Year(YYYY):" << endl && !(cin >> y) || (y < 1))
	{
		cin.clear(); //clear bad input flag
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		cout << "Invalid input; please re-enter.\n" << endl;
	}

	if (m < 10)
	{
		date += '0';
	}
	date += std::to_string(m) + '/';
	if (d < 10)
	{
		date += '0';
	}
	date += std::to_string(d) + '/';

	date += std::to_string(y);

	this->setDate(date);
	cout << "Update Completed." << endl;
}

std::ifstream& operator>> (std::ifstream& lhs, ExercisePlan& rhs)
{
	string name, date, steps;
	if (!lhs)
	{
		cout << "File not found" << endl;
	}
	if (lhs.fail())
	{
		cout << "Error reading data" << endl;
	}
	else
	{
		std::getline(lhs, name);
		std::getline(lhs, steps);
		std::getline(lhs, date);

		rhs.setSteps(atoi(steps.c_str()));
		rhs.setName(name);
		rhs.setDate(date);
		lhs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return lhs;

}
std::ostream& operator<< (std::ostream& lhs, const ExercisePlan& rhs)
{
	lhs << "\nDiet Name: " << rhs.getName() << "\nTarget Calories: " << rhs.getSteps() << "\nDate: " << rhs.getDate() << endl;
	return lhs;
}

std::ofstream& operator<< (std::ofstream& lhs, const ExercisePlan& rhs)
{
	lhs << rhs.getName() << '\n' << rhs.getSteps() << '\n' << rhs.getDate() << '\n' << endl;
	return lhs;
}
