#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class DietPlan 
{
public:
	DietPlan(int calories = 0, string name = "", string date = "");
	DietPlan(DietPlan& copyPlan);
	~DietPlan();

	int getCalories() const;
	string getName() const;
	string getDate() const;

	void setCalories(int newCalories);
	void setName(string newName);
	void setDate(string newDate);

	void editDietGoal();

private:
	int cCalories;
	string cName;
	string cDate;
};

std::ifstream& operator>>(std::ifstream& lhs, DietPlan& rhs);
std::ostream& operator<<(std::ostream& lhs, const DietPlan& rhs);

//In the same file in which each class declaration exists, three nonmember functions must be declared.
//Note: an overloaded operator is considered an overloaded function. The overloaded stream insertion (<<) for both displaying a plan to the screen and for writing a plan to a file, and the extraction (>>) operator for reading a plan from a file.

 

