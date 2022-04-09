/* Programmer: Charles Marshall
*
Class : CPTS 122; Lab section 13

Programming Assignment : PA 4 : Fitness Application in C++

Date : 3 - 2 - 2022

Description : This file contains the class ExercisePlan, necessary to do the following:

Get, set, and destruct objects of class ExercisePlan;
edit individual exercise plans;
and overloaded operators to read and write information contained in objects of class ExercisePlan to and from input and output files.


*/
#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>

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
	ExercisePlan(const ExercisePlan& copyPlan);
	~ExercisePlan();

	int getSteps() const;
	string getName() const;
	string getDate() const;

	void setSteps(int newCalories);
	void setName(string newName);
	void setDate(string newDate);

	void editExerciseGoal();

private:
	int cSteps;
	string cName;
	string cDate;
};

std::ifstream& operator>> (std::ifstream& lhs, ExercisePlan& rhs);
std::ostream& operator<< (std::ostream& lhs, const ExercisePlan& rhs);
std::ofstream& operator<< (std::ofstream& lhs, const ExercisePlan& rhs);