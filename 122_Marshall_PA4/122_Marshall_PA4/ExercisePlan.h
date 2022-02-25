#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

#include "DietPlan.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class ExercisePlan
{
public:
	ExercisePlan(int calories = 0, string name = "", string date = "");
	ExercisePlan(ExercisePlan& copyPlan);
	~ExercisePlan();

	int getSteps() const;
	string getName() const;
	string getDate() const;

	void setSteps(int newCalories);
	void setName(string newName);
	void setDate(string newDate);

	void editExerciseGoal(ExercisePlan dailygoal);

private:
	int cSteps;
	string cName;
	string cDate;
};