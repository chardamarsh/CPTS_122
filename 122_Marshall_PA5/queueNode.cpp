/* Programmer: Charles Marshall
   Class : CPTS 122; Lab section 13
   Programming Assignment : PA 5 : Grocery Store Simulator
   Date : 3-10-2022
   Description : This file conatins the function definitions for the class queueNode.
*/

#include "queueNode.h"

QueueNode::QueueNode(Data* newData, QueueNode* newNext)
{
	this->pNext = newNext;
	this->pData = newData;
}

QueueNode::QueueNode(Data* newData)
{
	this->pData = newData;
	this->pNext = nullptr;
}

void QueueNode::setData(Data* newData)
{
	this->pData = newData;
}

void QueueNode::setNextPtr(QueueNode* nextPtr)
{
	this->pNext = nextPtr;
}

Data* QueueNode::getData()
{
	return this->pData;
}

QueueNode* QueueNode::getNextPtr()
{
	return this->pNext;
}

void QueueNode::printNode()//node must not be nullptr
{
	cout << "\nCustomer Number: " << this->getData()->getNumber() << "\nService Time: " << this->getData()->getTime() << "\nDeparture Time: " << this->getData()->getTotTime() 
		<< endl;
}