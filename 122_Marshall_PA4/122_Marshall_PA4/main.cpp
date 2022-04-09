#include "FitnessApp.h"

int main()
{
	FitnessApp fitnessapp;
	std::ifstream diet, exercise;
	std::ofstream fitness;
	diet.open("DietPlans.txt");
	exercise.open("ExercisePlans.txt");
	fitness.open("FitnessPlan.txt");

	fitnessapp.runApp(diet, exercise, fitness);

	exercise.close();
	diet.close();
	fitness.close();

	return 0;
}