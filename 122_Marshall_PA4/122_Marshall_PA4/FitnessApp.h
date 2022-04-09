/* Programmer: Charles Marshall
*
Class : CPTS 122; Lab section 13

Programming Assignment : PA 4 : Fitness Application in C++

Date : 3 - 2 - 2022

Description : This file contains the class FitnessApp, necessary to do the following:

Load daily and weekly exercise and diet plans from a .txt file to a vector;
Store daily and weekly exercise and diet plans to a .txt file from a vector;
Display exercise and diet plans to the screen;
And edit individual diet and exercise plans contained in the Fitness App.

*/
#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>

#include "ExercisePlan.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class FitnessApp
{
public:
	//FitnessApp();
	//FitnessApp(int entries);
	~FitnessApp();


	void loadDailyPlan(std::ifstream& infile, DietPlan& diet);
	void loadDailyPlan(std::ifstream& infile, ExercisePlan& exercise);

	void loadWeeklyPlan(std::ifstream& infile, vector<DietPlan>& diet);
	void loadWeeklyPlan(std::ifstream& infile, vector<ExercisePlan>& diet);


	DietPlan getDiet(int day);
	ExercisePlan getExercise(int day);

	vector<DietPlan> getWeeklyDiet();
	vector<ExercisePlan> getWeeklyExercise();


	void storeDailyPlan(std::ofstream& outfile, DietPlan& diet);
	void storeDailyPlan(std::ofstream& outfile, ExercisePlan& exercise);

	void storeWeeklyPlan(std::ofstream& outfile, vector<DietPlan>& diet);
	void storeWeeklyPlan(std::ofstream& outfile, vector<ExercisePlan>& exercise);


	void displayDailyPlan(DietPlan& diet);
	void displayDailyPlan(ExercisePlan& exercise);

	void displayWeeklyPlan(vector<DietPlan>& diet);
	void displayWeeklyPlan(vector<ExercisePlan>& exercise);

	void editWeeklyPlan(vector<DietPlan>& diet);
	void editWeeklyPlan(vector<ExercisePlan>& exercise);


	void clearDiet();
	void clearExercise();

	int displayMenu();

	void runApp(std::ifstream& dietplan, std::ifstream& exerciseplan, std::ofstream& fitnessplan);



private:
	vector<DietPlan> weeklyDiet;
	vector<ExercisePlan> weeklyExercise;
};

