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