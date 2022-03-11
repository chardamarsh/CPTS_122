/* Programmer: Charles Marshall
   Class : CPTS 122; Lab section 13
   Programming Assignment : PA 5 : Grocery Store Simulator
   Date : 3-10-2022
   Description : This file contains the member function definitions for the class Data.
*/
#include "data.h"

Data::Data(int customer, int service, int totaltime)
{

	this->customerNumber = customer;
	this->serviceTime = service;
	this->totalTime = totaltime;
}

Data::Data(const Data& copy)
{
	this->customerNumber = copy.customerNumber;
	this->serviceTime = copy.serviceTime;
	this->totalTime = copy.totalTime;
}

Data::~Data()
{

}

int Data::getNumber()
{
	return this->customerNumber;
}

int Data::getTime()
{
	return this->serviceTime;
}

int Data::getTotTime()
{
	return this->totalTime;
}

void Data::setNumber(int num)
{
	this->customerNumber = num;
}

void Data::setTime(int option) // option 1: express lane. Option 2: regular lane.
{
	int time = 0;
	random_device device;
	mt19937 generator(device());
	if (option == 1) //express lane
	{
		uniform_int_distribution<int> distribution(1, 5);
		time = distribution(generator);
	}
	if (option == 2)//regular lane
	{
		uniform_int_distribution<int> distribution(3, 8);
		time = distribution(generator);
	}
	if(option != 1 && option != 2)
	{
		cout << "\nTime not set. Option 1 or 2 must be input." << endl;
	}
	
	this->serviceTime = time;
}

void Data::setTotTime(int total)
{
	this->totalTime = total;
}