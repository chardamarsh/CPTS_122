/* Programmer: Charles Marshall
*
Class : CPTS 122; Lab section 13

Programming Assignment : PA 4 : Fitness Application in C++

Date : 3 - 2 - 2022

Description : This file contains the class DietPlan, necessary to do the following:

Get, set, and destruct objects of class DietPlan;
edit individual diet plans;
and overloaded operators to read and write information contained in objects of class DietPlan to and from input and output files.

*/

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
	DietPlan(const DietPlan& copyPlan);
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

std::ifstream& operator>> (std::ifstream& lhs, DietPlan& rhs);
std::ostream& operator<< (std::ostream& lhs, const DietPlan& rhs);
std::ofstream& operator<< (std::ofstream& lhs, const DietPlan& rhs);