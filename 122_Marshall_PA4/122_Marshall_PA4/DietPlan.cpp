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