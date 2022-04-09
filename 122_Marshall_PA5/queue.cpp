/* Programmer: Charles Marshall
   Class : CPTS 122; Lab section 13
   Programming Assignment : PA 5 : Grocery Store Simulator
   Date : 3-10-2022
   Description : This file contains the member function definitions for the queue class, and runSimulation() which compiles all functions to simulate the queue over a set amount of time.
*/

#include "queue.h"

Queue::Queue(QueueNode* newpHead, QueueNode* newpTail, int t)
{
	this->pHead = newpHead;
	this->pTail = newpTail;
	this->type = t;
}
Queue::Queue(const Queue& copy)
{
	this->pHead = copy.pHead;
	this->pTail = copy.pTail;
	this->type = copy.type;
}
Queue::~Queue()
{
	this->clearQueue();
}

QueueNode* Queue::getpHead()
{
	return this->pHead;
}
QueueNode* Queue::getpTail()
{
	return this->pTail;
}

void Queue::setType(int t)
{
	this->type = t;
}

int Queue::getType()
{
	return this->type;
}

bool Queue::isEmpty()
{
	return (this->pHead == nullptr);
}

int Queue::queueLength()
{
	QueueNode* pMem = this->pHead;
	int count = 0;
	while (pMem != nullptr)
	{
		count++;
		pMem = pMem->getNextPtr();
	}
	return count;
}

void Queue::printQueue()
{
	QueueNode* pMem = this->pHead;
	
	if (pMem != nullptr)
	{
		while (pMem != nullptr)
		{
			pMem->printNode();
			pMem = pMem->getNextPtr();
		}
	}
	else
	{
		cout << "\nQueue is empty." << endl;
	}
}

bool Queue::enqueue()
{
	bool success = false;
	QueueNode* pMem = new QueueNode;
	Data* data = new Data;
	int t = this->type;

		if (isEmpty())
		{
			data->setNumber(1);
			data->setTime(t);
			data->setTotTime(data->getTime());
			pMem->setData(data);
			this->pHead = this->pTail = pMem;
			success = true;
		}
		else
		{
			data->setNumber(this->pTail->getData()->getNumber() + 1);
			data->setTime(t);
			data->setTotTime(this->pTail->getData()->getTotTime() + data->getTime());
			pMem->setData(data);
			this->pTail->setNextPtr(pMem);
			this->pTail = pMem;
			success = true;
		}
		return success;
}

Data* Queue::dequeue() // preconditions: queue must not be empty.
{
	{
		QueueNode* pTemp = this->pHead;

		if (this->pHead == this->pTail)
		{
			this->pHead = this->pTail = nullptr;
		}
		else
		{
			this->pHead = this->pHead->getNextPtr();
		}

		Data* data = pTemp->getData();
		delete pTemp;

		return data;
	}
}

void Queue::clearQueue()
{
	while (!isEmpty())
	{
		this->dequeue();
	}
}

void runSimulation(unsigned int time, int type)
{
	Queue line;
	string name;

	line.setType(type);

	int curTime = 1; //used to keep track of time
	int LineTime = 0; // used as check for arriving customers
	int lineLength = 0; // length of line
	int dequeueCounter = 0; // increments by 1 each minute, resets after 
	int enqueueCounter = 0; //increments by 1 each minute, resets after it reaches value of LineTime

	line.enqueue();

	random_device device;
	mt19937 generator(device());
	Data* tempData = new Data;
	uniform_int_distribution<int> distribution1(1, 5);
	uniform_int_distribution<int> distribution2(3, 8);
	//set line name
	if (type == 1)
	{	
		LineTime = distribution1(generator);
		name = "Express";
	}
	if (type == 2)
	{		
		LineTime = distribution2(generator);
		name = "Regular";
	}

	while (curTime != time)
	{	
		system("CLS");
		cout << "\t\tQueue Type: "<< name << endl;
		cout << "\t\tTotal Time: " << curTime << " Minutes" << endl;
		if (curTime % 10 != 0)
		{
			cout << "\t\tQueue Length: " << line.queueLength() << endl;
		}
		
		enqueueCounter++;
		dequeueCounter++;

		lineLength = line.queueLength();
		if (enqueueCounter == LineTime) //linetime
		{
			enqueueCounter = 0;
			if (tempData != nullptr && line.queueLength() == 0) 
				//if the line is empty, the data from the last available node is transferred to a temporary node to preserve customer number and total time
			{
				line.enqueue(); //temporary node
				line.getpHead()->setData(tempData); //add previous data
				line.getpTail()->setData(tempData);
				line.enqueue(); //add new node
				line.dequeue(); //remove temporary node

				dequeueCounter = 0;
			}
			else //regular enqueue
			{
				line.enqueue();
			}
			if (curTime % 10 != 0) //print new node to screen
			{
				line.getpTail()->printNode();
			}
			if (type == 1) //reset LineTime to a random interval
			{
				LineTime = distribution1(generator);
			}
			if (type == 2)
			{
				LineTime = distribution2(generator);
			}
		}
		if (line.getpHead() != nullptr) //only calls dequeue() if line is not empty
		{
			if (curTime > line.getpHead()->getData()->getTotTime()) //if current time is greater than total time/time of departure of the first person in line, they are dequeued.
			{
				tempData = line.dequeue();
				dequeueCounter = 0;
			}
		}
		if (curTime % 10 == 0)
		{
			cout << "\t\tQueue Length: " << line.queueLength() << endl;
		}
		if (curTime % 10 == 0 && curTime > 0) // print queue every 10 'minutes'
		{
			line.printQueue();
			system("pause");
		}
		curTime++;
		sleep_for(milliseconds(100)); //100 milliseconds = one simulated minute
	}
}