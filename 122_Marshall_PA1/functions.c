/* Programmer: Charles Marshall
*
Class : CPTS 122; Lab section 13

Programming Assignment : PA 1 : Analyzing Fitbit Data

Date : 1 - 23 - 2022

Description : This file contains the function definitions used to do the following :
Open 'data.csv' for reading and 'results.csv' for writing;
Determine the target patient from 'data.csv';
checkand clean the data for invalid targets, duplicatesand null / invalid data entries;
Copy the data from 'data.csv' to an array of structs representing the data for the 24 - hour period;
Analyze the dataand determine the total calories, total distance, total floors, total steps, average heartrate,
max steps in a minute, and the longest consecutive range of poor sleep;
Print the statistics and the cleansed data to 'results.csv'.

*/
#include "functions.h"

void get_info(FILE* infile, FitbitData dailyData[], char* target)
{
	
	char* temp_patient;
	char* minute;
	
	char row[1000];
	int i = 0;
	
	fgets(row, 1000, infile); //skips column name line
	while (!feof(infile))
	{
		int nullheart = 0, nullsteps = 0, nullsleep = 0;
		
		fgets(row, 1000, infile);
		int commas = 0;
		for (int index = 0; index < strlen(row); index++) //if statements used to determine if an entry is empty or null based on comma placement. //
		{
			if (row[index] == ',')
			{
				++commas;
			}
			if (commas == 5 &&row[index] == ',' && row[index + 1] == ',')
			{
				dailyData[i].heartRate = 9999;
				++nullheart;
			}
			if (commas == 6 && row[index] == ',' && row[index + 1] == ',')
			{
				dailyData[i].steps = 9999;
				++nullsteps;
			}
			if (row[index] == ',' && row[index + 1] == '\0')
			{
				dailyData[i].sleepLevel = 0;
				++nullsleep;
			}

		}
		
		temp_patient = strtok(row, ",");

		minute = strtok(NULL, ",");
		if (strcmp(minute, dailyData[i-1].minute) != 0 && strcmp(temp_patient, target) == 0) //checks for duplicates and/or invalid target
		{
			strcpy(dailyData[i].patient, temp_patient);
			
			strcpy(dailyData[i].minute, minute);
			//calories, distance, and floors do not contain any null/missing values. After the check for duplicates/invalid target, they are copied to the fitbitdata struct array.
			dailyData[i].calories = atof(strtok(NULL, ","));
			dailyData[i].distance = atof(strtok(NULL, ","));
			dailyData[i].floors = atoi(strtok(NULL, ","));
			//If heartrate/steps/sleeplevel do not contiain a null/missing value, they are copied into the fitbitdata struct array.
			if (nullheart == 0)
			{
				dailyData[i].heartRate = atoi(strtok(NULL, ","));
			}
			if (nullsteps == 0)
			{
				dailyData[i].steps = atoi(strtok(NULL, ","));
			}
			if (nullsleep == 0)
			{
				dailyData[i].sleepLevel = atoi(strtok(NULL, ","));
			}
			i++;
		}
	}

	return;
}

void process_data(FILE* outfile, FitbitData dailyData[], DailyStats stats)
{
	int sum_heartrate = 0;
	int valid_entries = 0;
	int sleep_range = 0;
	int sleep_range_start = 0;
	int sleep_range_end = 0;
	int max_steps = 0;

	for (int i = 0; i < 1440; i++)
	{
		stats.total_cals += dailyData[i].calories;
		stats.total_distance += dailyData[i].distance;
		stats.total_floors += dailyData[i].floors;
		if (dailyData[i].heartRate != 9999) //checks for invalidated data
		{
			sum_heartrate += dailyData[i].heartRate;
			valid_entries++;
		}
		if (dailyData[i].steps != 9999)
		{
			stats.total_steps += dailyData[i].steps;
		}
		if (dailyData[i].steps > max_steps && dailyData[i].steps != 9999)
		{
			max_steps = dailyData[i].steps;
		}
		if (dailyData[i].sleepLevel > 1 && i > sleep_range_start)
		{
			int j = i;
			int temp_range = 0;
			while (dailyData[j].sleepLevel > 1)
			{
				temp_range++;
				j++;
			}
			if (temp_range > sleep_range)
			{
				sleep_range = temp_range;
				sleep_range_start = j - sleep_range;
				sleep_range_end = j-1;
			}
		}
	}

	stats.max_steps_minute = max_steps;
	stats.avg_heartrate = (sum_heartrate / valid_entries);

	strcpy(stats.poor_sleep_start, dailyData[sleep_range_start].minute);
	strcpy(stats.poor_sleep_end, dailyData[sleep_range_end].minute);

	fprintf(outfile, "TotalCalories,TotalDistance,TotalFloors,TotalSteps,AvgHeartrate,MaxSteps,Sleep\n");
	fprintf(outfile, "%lf,%lf,%d,%d,%d,%d,%s:%s\n", stats.total_cals, stats.total_distance, stats.total_floors,
		stats.total_steps, stats.avg_heartrate, stats.max_steps_minute, stats.poor_sleep_start, stats.poor_sleep_end);
	for (int k = 0; k < 1440; k++)
	{
		fprintf(outfile, "%s,%s,%lf,%lf,%u,%u,%u,%d\n", dailyData[k].patient, dailyData[k].minute, dailyData[k].calories,
			dailyData[k].distance, dailyData[k].floors, dailyData[k].heartRate, dailyData[k].steps, dailyData[k].sleepLevel);
	}
}