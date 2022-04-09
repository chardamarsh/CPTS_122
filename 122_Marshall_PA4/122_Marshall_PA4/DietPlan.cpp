/* Programmer: Charles Marshall
*
Class : CPTS 122; Lab section 13

Programming Assignment : PA 4 : Fitness Application in C++

Date : 3 - 2 - 2022

Description : This file contains the class functions for DietPlan, necessary to do the following:

Get, set, and destruct objects of class DietPlan;
edit individual diet plans;
and overloaded operators to read and write information contained in objects of class DietPlan to and from input and output files.

*/

#include "DietPlan.h"

DietPlan::DietPlan(int calories, string name, string date)
{
	if (calories < 0)
	{
		cCalories = 0;
	}
	else
	{
		cCalories = calories;
	}
	cName = name;
	cDate = date;
}
DietPlan::DietPlan(const DietPlan& copyPlan)
{
	setCalories(copyPlan.getCalories());
	setName(copyPlan.getName());
	setDate(copyPlan.getDate());
}
DietPlan::~DietPlan()
{
	//cout << "Diet Plan cleared." << endl;
}
int DietPlan::getCalories() const
{
	return cCalories;
}
string DietPlan::getName() const
{
	return cName;
}
string DietPlan::getDate() const
{
	return cDate;
}
void DietPlan::setCalories(int newCalories)
{
	cCalories = newCalories;
}
void DietPlan::setName(string newName)
{
	cName = newName;
}
void DietPlan::setDate(string newDate)
{
	cDate = newDate;
}

void DietPlan::editDietGoal() 
{
	int cals = 0;
	string name;
	string date;
	int m = 0, d = 0, y = 0;
	while (cout << "Enter a new steps value:" << endl && !(cin >> cals) || cals < 0)
	{
		cin.clear(); //clear bad input flag
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		cout << "Invalid input; please re-enter.\n" << endl;
	}
	this->setCalories(cals);
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
	while (cout << "Day(DD):" << endl && !(cin >> d) || ((d < 1) || (d > 31)))
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

std::ifstream& operator>> (std::ifstream& lhs, DietPlan& rhs)
{
	string name, date, calories;
	if (!lhs.is_open())
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
		std::getline(lhs, calories);
		std::getline(lhs, date);

		rhs.setCalories(atoi(calories.c_str()));
		rhs.setName(name);
		rhs.setDate(date);

		lhs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return lhs;

}
std::ostream& operator<< (std::ostream& lhs, const DietPlan& rhs)
{
	lhs << "\nDiet Name: " << rhs.getName() << "\nTarget Calories: " << rhs.getCalories() << "\nDate: " << rhs.getDate() << endl;
	return lhs;
}

std::ofstream& operator<< (std::ofstream& lhs, const DietPlan& rhs)
{
	lhs << rhs.getName() << '\n' << rhs.getCalories() << '\n' << rhs.getDate() << '\n' << endl;
	return lhs;
}
