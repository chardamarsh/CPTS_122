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
ExercisePlan::ExercisePlan(ExercisePlan& copyPlan)
{
	cSteps = copyPlan.getSteps();
	cName = copyPlan.getName();
	cDate = copyPlan.getDate();
}
ExercisePlan::~ExercisePlan()
{
	cout << "Exercise Plan entry deleted." << endl;
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