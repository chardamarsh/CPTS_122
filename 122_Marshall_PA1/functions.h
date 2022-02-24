/* Programmer: Charles Marshall
*
Class : CPTS 122; Lab section 13

Programming Assignment : PA 1 : Analyzing Fitbit Data

Date : 1 - 23 - 2022

Description : This file contains the structs definitions and function headers used to do the following :
Open 'data.csv' for reading and 'results.csv' for writing;
Determine the target patient from 'data.csv';
checkand clean the data for invalid targets, duplicatesand null / invalid data entries;
Copy the data from 'data.csv' to an array of structs representing the data for the 24 - hour period;
Analyze the dataand determine the total calories, total distance, total floors, total steps, average heartrate,
max steps in a minute, and the longest consecutive range of poor sleep;
Print the statistics and the cleansed data to 'results.csv'.

*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbitdata
{
    char patient[10];
    char minute[9];
    double calories;
    double distance;
    unsigned int floors;
    unsigned int heartRate;
    unsigned int steps;
    Sleep sleepLevel;
}FitbitData;

typedef struct dailystats
{
    double total_cals;
    double total_distance; //miles
    int total_floors;
    int total_steps;
    int avg_heartrate;
    int max_steps_minute;
    char poor_sleep_start[9];
    char poor_sleep_end[9];
}DailyStats;

/*************************************************************************************************************************************************************
  * Function:              get_info()                                                                                                                        *
  * Date Created:          1/23/2022                                                                                                                         *
  * Date Last Modified:    1/25/2022                                                                                                                         *
  * Description:		   Parses, cleanses, and copies comma-separated values from 'data.csv' to a struct array.                                            *
  * Input parameters:      infile(fitbit data .csv file), dailyData(array of structs to store 24-hours of fitbit data), target(target patient from infile)   *
  * Returns:               none                                                                                                                              *
  * Preconditions:         1. 'infile' must be opened for reading. 2. 'dailyData' struct array must be declared. 3. target must be determined from 'infile.' *
  * Postconditions:        The 'dailyData' array of structs will contain the cleansed fitbit data of the 24-hour period.                                     *
  ************************************************************************************************************************************************************/
void get_info(FILE* infile, FitbitData dailyData[], char* target);
/***********************************************************************************************************************************************************************
  * Function:              process_data()                                                                                                                              *
  * Date Created:          1/23/2022                                                                                                                                   *
  * Date Last Modified:    1/25/2022                                                                                                                                   *
  * Description:		   Calculates and writes statistics/cleansed data from dailyData to 'results.csv'.                                                             *
  * Input parameters:      outfile(results .csv file), dailyData(array of structs storing 24-hours of cleansed fitbit data),                                           *
                               stats(struct to store stats calculated from dailyData).                                                                                 *
  * Returns:               none                                                                                                                                        *
  * Preconditions:         1. 'outfile' must be opened for writing. 2. 'dailyData' struct array must contain cleansed data from input file.                            *
  * Postconditions:        1. 'stats' contain statistics calculated from 'dailyData.' 2.Data from 'stats' and 'dailyData' will be written to 'outfile' in .csv format. *
  **********************************************************************************************************************************************************************/
void process_data(FILE* outfile, FitbitData dailyData[], DailyStats stats);

#endif