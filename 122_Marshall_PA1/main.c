/*Programmer: Charles Marshall

  Class: CPTS 122; Lab section 13

  Programming Assignment: PA 1: Analyzing Fitbit Data

  Date: 1-23-2022

  Description:  This file utilizes the functions defined in functions.c to do the following:
		Open 'data.csv' for reading and 'results.csv' for writing;
		Determine the target patient from 'data.csv';
		check and clean the data for invalid targets, duplicates and null/invalid data entries;
		Copy the data from 'data.csv' to an array of structs representing the data for the 24-hour period;
		Analyze the data and determine the total calories, total distance, total floors, total steps, average heartrate,
			max steps in a minute, and the longest consecutive range of poor sleep;
		Print the statistics and the cleansed data to 'results.csv'.				

  */
#include "functions.h"

int main(void)
{
	FitbitData dailyData[1440];
	DailyStats Stats = { .total_cals = 0.0, .total_distance = 0.0, .total_floors = 0, .total_steps = 0,
		.avg_heartrate = 0, .max_steps_minute = 0, .poor_sleep_start = '\0', .poor_sleep_end = '\0' };
	
	FILE* infile;
	FILE* outfile;

	infile = fopen("data.csv", "r"); //I had to copy the data from 'FitbitData.csv' to a new file 'data.csv' because I was getting an error saying "No such file or directory".
	if (!infile)
	{
		perror("fopen");
	}
	outfile = fopen("results.csv", "w");
	if (infile != NULL)
	{
		char row[1000];
		char* target;
		char* temp;
		fgets(row, 1000, infile);
		temp = strtok(row, ","); //used to skip past first comma
		target = strtok(NULL, ","); //obtains target patient for following functions
		
		get_info(infile, dailyData, target);
		process_data(outfile, dailyData, Stats);

		fclose(infile);
		fclose(outfile);
	}
	

	return 0;
}