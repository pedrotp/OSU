/*********************************************************************

** Program Filename: Queue.cpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Lab 6 - This is the implementation file for the Queue
class, which includes the source code for all the functions in the class.
A Queue is a first in first out (FIFO) data structure.

*********************************************************************/

#include "Queue.hpp"

/*********************************************************************

** Description: Queue()

** This is the constructor for the Queue class, which creates the
Queue and sets the head and tail pointers to 0

*********************************************************************/

Queue::Queue() {
  head = 0;
  tail = 0;
};

/*********************************************************************

** Description: Queue()

** This is the destructor for the Queue class, which deallocates all
the memory for each node when the Queue is destroyed

*********************************************************************/

Queue::~Queue() {

  QueueNode *queuePtr = head;
  while (queuePtr) {
    QueueNode *garbage = queuePtr;
    queuePtr = garbage->prev;
    delete garbage->value;
    delete garbage;
  }

};

/*********************************************************************

** Description: push()

** This function takes an integer value, adds it as the value of a
new node, and sets that node as the new tail node, updating all pointers
accordingly

*********************************************************************/

void Queue::push(Creature* val) {

  QueueNode *queuePtr = tail;
  tail = new QueueNode(val);
  if (queuePtr) {
    tail->next = queuePtr;
    queuePtr->prev = tail;
  } else {
    head = tail;
  }

};

/*********************************************************************

** Description: pop()

** This function removes the head node from the front of the stack,
sets the previous node as the new head node, returns the value of the
removed node, and updates all pointers accordingly

*********************************************************************/

Creature* Queue::pop() {

  Creature* result = 0;

  if (head) {

    QueueNode *queuePtr = head;
    result = queuePtr->value;
    head = queuePtr->prev;
    if (head) {
      head->next = 0;
    } else {
      tail = 0;
    }
    delete queuePtr;

  }

  return result;

};
