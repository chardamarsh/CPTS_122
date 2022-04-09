/* Programmer: Charles Marshall
   Class : CPTS 122; Lab section 13
   Programming Assignment : PA 5 : Grocery Store Simulator
   Date : 3-10-2022
   Description : This file compiles the Data, QueueNode, and queue classes and function to run a simulation of a grocery store line.
*/

#include "test.h"

int main()
{
	//test functions

	//testEnqueue1();
	//testEnqueue2();
	//testDequeue1();
	//testDequeue2();
	//daySimulation();

	//Simulation functions
	int option = 0;
	int minutes = 0;
	cout << "\t\tGROCERY STORE LINE SIMULATOR" << endl;
	for (;;) 
	{
		cout << "Enter 1 to select an express lane, or 2 for a regular lane: ";
		cin >> option;
		if (option == 1 || option ==2) 
		{
			break;
		}
		else 
		{
			cout << "Please enter an integer 1-2." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	for (;;) 
	{
		cout << "Please enter the simulation time in minutes: ";
		if(cin >> minutes) 
		{
			break;
		}
		else 
		{
			cout << "Please enter a valid integer" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	runSimulation(minutes, option);

	return 0;
}