#include "LQueue.h"

LQueue::LQueue(int size) : List(size) {}

int LQueue::size(){return List.size();}

void LQueue::enqueue(int data) {List.addLast(data);}

int LQueue::dequeue(){return List.eraseFirst();}

int LQueue::front(){return List.getNode(0);}

bool LQueue::isEmpty(){return List.isEmpty();}

