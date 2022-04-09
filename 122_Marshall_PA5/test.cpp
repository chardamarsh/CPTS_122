/* Programmer: Charles Marshall
   Class : CPTS 122; Lab section 13
   Programming Assignment : PA 5 : Grocery Store Simulator
   Date : 3-10-2022
   Description : This file contains the function definitions for program test functions.
*/
#include "test.h"

void testEnqueue1()
{
	Queue test;
	test.setType(1);
	bool val = false;
	val = test.enqueue();
	if (val == true)
	{
		cout << "enqueue successful." << endl;
	}

}
void testEnqueue2()
{
	Queue test;
	bool val = false;
	test.setType(1);
	val = test.enqueue();
	val = test.enqueue();
	if (val == true)
	{
		cout << "enqueue successful." << endl;
	}

}
void testDequeue1()
{
	Queue test;
	bool val = false;
	test.setType(1);
	val = test.enqueue();
	val = test.dequeue();
	if (val == true)
	{
		cout << "dequeue successful." << endl;
	}
}
void testDequeue2()
{
	Queue test;
	bool val = false;
	test.setType(1);
	val = test.enqueue();
	val = test.enqueue();
	val = test.dequeue();
	if (val == true)
	{
		cout << "dequeue successful." << endl;
	}
}

void daySimulation()
{
	runSimulation(1440, 1); //express lane simulation
	runSimulation(1440, 2); // regular lane simulation
}