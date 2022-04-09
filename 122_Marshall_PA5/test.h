/* Programmer: Charles Marshall
   Class : CPTS 122; Lab section 13
   Programming Assignment : PA 5 : Grocery Store Simulator
   Date : 3-10-2022
   Description : This file contains the function headers for program test functions.
*/

#pragma once

#include <iostream>
#include <random>
#include "queue.h"

void testEnqueue1(); //tests enqueue function with an empty queue.
void testEnqueue2(); //tests equeue function with a queue containing one node.

void testDequeue1(); //tests dequeue with a queue containing one node.
void testDequeue2(); // tests dequeue with a queue containing two nodes.

void daySimulation(); // tests simulated grocery lines for 24 hours.