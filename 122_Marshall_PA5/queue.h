/* Programmer: Charles Marshall
   Class : CPTS 122; Lab section 13
   Programming Assignment : PA 5 : Grocery Store Simulator
   Date : 3-10-2022
   Description : This contains the Queue class definition, and the header for runSimulation().
*/

#pragma once
#include "data.h"
#include "queueNode.h"

#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <thread>

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;


class Queue

{
   
public:
    Queue(QueueNode* pHead = nullptr, QueueNode* pTail = nullptr, int t = 0);
    Queue(const Queue& copy);
    ~Queue();

    QueueNode* getpHead();
    QueueNode* getpTail();

    void setType(int t);

    int getType();

    bool isEmpty();

    int queueLength();

    void printQueue();

    bool enqueue();

    Data* dequeue();


private:

    QueueNode* pHead;

    QueueNode* pTail;

    int type; // express(1) or regular(2)

    void clearQueue();

};

void runSimulation(unsigned int time, int type); //time in minutes.