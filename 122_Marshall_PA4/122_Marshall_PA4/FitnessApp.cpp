/* Programmer: Charles Marshall
*
Class : CPTS 122; Lab section 13

Programming Assignment : PA 4 : Fitness Application in C++

Date : 3 - 2 - 2022

Description : This file contains the class function definitions necessary to do the following:

Load daily and weekly exercise and diet plans from a .txt file to a vector;
Store daily and weekly exercise and diet plans to a .txt file from a vector;
Display exercise and diet plans to the screen;
And edit individual diet and exercise plans contained in the Fitness App.

*/
#include "FitnessApp.h"


FitnessApp::~FitnessApp()
{
	this->weeklyDiet.clear();
	this->weeklyExercise.clear();
	cout << "Fitness App cleared." << endl;
}

void FitnessApp::loadDailyPlan(std::ifstream& infile, DietPlan& diet)
{
	if (infile.is_open())
	{
		if (!infile.eof())
		{
			infile >> diet;
		}
	}
}
void FitnessApp::loadDailyPlan(std::ifstream& infile, ExercisePlan& exercise)
{
	if (infile.is_open())
	{
		if (!infile.eof())
		{
			infile >> exercise;
		}
	}
}

void FitnessApp::loadWeeklyPlan(std::ifstream& infile, vector<DietPlan>& diet)
{
	
	//loadDailyPlan(infile, daily);
	//diet.push_back(daily);
	if (infile.is_open())
	{
		int i = 0;
		DietPlan daily;
		while (!infile.eof())
		{
			loadDailyPlan(infile, daily);
			diet.push_back(daily);
			i++;
		}
		system("CLS");
		cout << i << " Daily Diet Plans loaded." << endl;
	}
}
void FitnessApp::loadWeeklyPlan(std::ifstream& infile, vector<ExercisePlan>& exercise)
{
	if (infile.is_open())
	{
		int i = 0;
		ExercisePlan daily;
		//loadDailyPlan(infile, daily);
		//diet.push_back(daily);
		while (!infile.eof())
		{
			loadDailyPlan(infile, daily);
			exercise.push_back(daily);
			i++;
		}
		system("CLS");
		cout << i << " Daily Exercise Plans loaded." << endl;

	}
}

DietPlan FitnessApp::getDiet(int day)
{
	return this->weeklyDiet[day - 1];
}
ExercisePlan FitnessApp::getExercise(int day)
{
	return this->weeklyExercise[day - 1];
}

vector<DietPlan> FitnessApp::getWeeklyDiet()
{
	return this->weeklyDiet;
}

vector<ExercisePlan> FitnessApp::getWeeklyExercise()
{
	return this->weeklyExercise;
}


void FitnessApp::storeDailyPlan(std::ofstream& outfile, DietPlan& diet)
{
	outfile << diet;
}
void FitnessApp::storeDailyPlan(std::ofstream& outfile, ExercisePlan& exercise)
{
	outfile << exercise;
}

void FitnessApp::storeWeeklyPlan(std::ofstream& outfile, vector<DietPlan>& diet)
{
	int a = 0;
	outfile << "\t\tWEEKLY DIET PLAN\n" << endl;
	for (int i = 0; i < diet.size(); i++)
	{
		outfile << diet[i];
		a = i;
	}
	system("CLS");
	if (a > 0)
	{
		cout << a + 1 << " Daily Diet Plans written to output file." << endl;
	}
	else
	{
		cout << "Diet Plan must be loaded before using this function." << endl;
	}
}
void FitnessApp::storeWeeklyPlan(std::ofstream& outfile, vector<ExercisePlan>& exercise)
{
	int a = 0;
	outfile << "\t\tWEEKLY EXERCISE PLAN\n" << endl;
	for (int i = 0; i < exercise.size(); i++)
	{
		outfile << exercise[i];
		a = i;
	}
	system("CLS");
	if (a > 0)
	{
		cout << a + 1 << " Daily Exercise Plans written to output file." << endl;
	}
	else
	{
		cout << "Exercise Plan must be loaded before using this function." << endl;
	}
}


void FitnessApp::displayDailyPlan(DietPlan& diet)
{
	cout << diet << endl;
}
void FitnessApp::displayDailyPlan(ExercisePlan& exercise)
{
	cout << exercise << endl;
}

void FitnessApp::displayWeeklyPlan(vector<DietPlan>& diet)
{
	int a = 0;
	system("CLS");
	for (int i = 0; i < diet.size(); i++)
	{
		cout << i+1 << ": " << diet[i];
		a = i;
	}
	if (a == 0)
	{
		cout << "Diet Plan must be loaded before using this function." << endl;
	}
	//system("PAUSE");
	//system("CLS");
}
void FitnessApp::displayWeeklyPlan(vector<ExercisePlan>& exercise)
{
	int a = 0;
	system("CLS");
	for (int i = 0; i < exercise.size(); i++)
	{
		cout << i+1 << ": " << exercise[i];
		a = i;
	}
	if (a == 0)
	{
		cout << "Exercise Plan must be loaded before using this function." << endl;
	}
	//system("PAUSE");
	//system("CLS");
}

void FitnessApp::editWeeklyPlan(vector<DietPlan>& diet)
{
	int option = 10;
	
	while (option != 0)
	{
		system("CLS");
		this->displayWeeklyPlan(this->weeklyDiet);
		cout << "\nSelect a day to edit by number, or enter 0 to exit:" << endl;
		while (!(cin >> option) || option < 0 || option > diet.size())
		{
			cin.clear(); //clear bad input flag
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
			cout << "Invalid input; please re-enter.\n" << endl;
		}
		if (option != 0)
		{
			diet[option - 1].editDietGoal();
		}
		system("CLS");
	}

}
void FitnessApp::editWeeklyPlan(vector<ExercisePlan>& exercise)
{
	int option = 10;

	while (option != 0)
	{
		system("CLS");
		this->displayWeeklyPlan(this->weeklyExercise);
		cout << "\nSelect a day to edit by number, or 0 to exit:" << endl;
		while (!(cin >> option) || option < 0 || option > exercise.size())
		{
			cin.clear(); //clear bad input flag
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
			cout << "Invalid input; please re-enter.\n" << endl;
		}
		if (option != 0)
		{
			exercise[option - 1].editExerciseGoal();
		}
	}
}

void FitnessApp::clearDiet()
{
	this->weeklyDiet.clear();
	cout << "Diet Plan Cleared." << endl;
}
void FitnessApp::clearExercise()
{
	this->weeklyExercise.clear();
	cout << "Exercise Plan Cleared." << endl;
}

int FitnessApp::displayMenu()
{
	int option = 0;
	//system("CLS");
	cout << "\n1. Load Weekly Diet Plan" << endl;
	cout << "2. Load Weekly Exercise Plan" << endl;
	cout << "3. Store Weekly Diet Plan" << endl;
	cout << "4. Store Weekly Exercise Plan" << endl;
	cout << "5. Display Weekly Diet Plan" << endl;
	cout << "6. Display Weekly Exercise Plan" << endl;
	cout << "7. Edit Weekly Diet Plan" << endl;
	cout << "8. Edit Weekly Exercise Plan" << endl;
	cout << "9. Exit Application" << endl;

	while (!(cin >> option) || option < 1 || option > 9)
	{
		cin.clear(); //clear bad input flag
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		cout << "Invalid input; please re-enter.\n" << endl;
	}
	//system("CLS");
	return option;
}

void FitnessApp::runApp(std::ifstream& dietplan, std::ifstream& exerciseplan, std::ofstream& fitnessplan)
{
	int option = 0;
	while (option != 9)
	{
		option = this->displayMenu();
		if (option == 1)
		{
			this->loadWeeklyPlan(dietplan, this->weeklyDiet);
		}
		if (option == 2)
		{
			this->loadWeeklyPlan(exerciseplan, this->weeklyExercise);
		}
		if (option == 3)
		{
			this->storeWeeklyPlan(fitnessplan, this->weeklyDiet);
		}
		if (option == 4)
		{
			this->storeWeeklyPlan(fitnessplan, this->weeklyExercise);
		}
		if (option == 5)
		{
			this->displayWeeklyPlan(this->weeklyDiet);
		}
		if (option == 6)
		{
			this->displayWeeklyPlan(this->weeklyExercise);
		}
		if (option == 7)
		{
			this->editWeeklyPlan(this->weeklyDiet);
		}
		if (option == 8)
		{
			this->editWeeklyPlan(this->weeklyExercise);
		}
	}
}