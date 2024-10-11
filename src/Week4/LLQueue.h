#ifndef LLQUEUE_H
#define LLQUEUE_H

#include "SinglyLinkedList.h"

struct LLQueue
{
    SLL SLL;
    LLQueue();

    void enqueue(int data);

    int dequeue();

    int front();
    
    bool isEmpty();
};

#endif
