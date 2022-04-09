/* Programmer: Charles Marshall
   Class : CPTS 122; Lab section 13
   Programming Assignment : PA 5 : Grocery Store Simulator
   Date : 3-10-2022
   Description : This file contains the class definition for the class Data.
*/

#pragma once

#include <iostream>
#include <random>

using namespace std;

class Data

{

public: // Member functions
    Data(int customer = 0, int service = 0, int totaltime = 0);
    Data(const Data& copy);

    ~Data();

    int getNumber();
    int getTime();
    int getTotTime();

    void setNumber(int num);
    void setTime(int option);
    void setTotTime(int total);


private:

    int customerNumber;

    int serviceTime;   // Random time; varies between express and normal lanes

    int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes

};

