#include "LLQueue.h"

LLQueue::LLQueue() {}

void LLQueue::enqueue(int data) {SLL.addLast(data);}

int LLQueue::dequeue(){return SLL.removeFirst();}

int LLQueue::front(){return SLL.getNode(0);}

bool LLQueue::isEmpty(){return SLL.isEmpty();}