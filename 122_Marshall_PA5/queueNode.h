/* Programmer: Charles Marshall
   Class : CPTS 122; Lab section 13
   Programming Assignment : PA 5 : Grocery Store Simulator
   Date : 3-10-2022
   Description : This file contains the definition for the class QueueNode.
*/

#pragma once
#include <iostream>
#include <string>
#include <random>

#include "data.h"



class QueueNode

{

public: // Member functions

    QueueNode(Data* newData = nullptr, QueueNode* newNext = nullptr);

    QueueNode(Data* newData);

    void setData(Data* newData);

    void setNextPtr(QueueNode* nextPtr);

    Data* getData();

    QueueNode* getNextPtr();

    void printNode();

private:

    Data* pData;    // The memory for Data will need to be allocated on the heap as well!

    QueueNode* pNext;

};