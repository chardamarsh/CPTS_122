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
DietPlan::DietPlan(DietPlan& copyPlan)
{
	cCalories = copyPlan.getCalories();
	cName = copyPlan.getName();
	cDate = copyPlan.getDate();
}
DietPlan::~DietPlan()
{
	cout << "Diet Plan entry deleted." << endl;
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
	while (cout << "Day(DD):" << endl && !(cin >> y) || (y < 1))
	{
		cin.clear(); //clear bad input flag
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		cout << "Invalid input; please re-enter.\n" << endl;
	}

	date = m + '/' + d + '/' + y;
	this->setDate(date);
	cout << "Update Completed." << endl;
}

std::ifstream& operator>>(std::ifstream& lhs, DietPlan& rhs)
{
	string name, date, calories;
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
		std::getline(lhs, calories);
		std::getline(lhs, date);

		rhs.setCalories(atoi(calories.c_str()));
		rhs.setName(name);
		rhs.setDate(date);
	}

}
std::ostream& operator<<(std::ostream& lhs, const DietPlan& rhs);
