#ifndef LQUEUE_H
#define LQUEUE_H

#include "List.h"

struct LQueue
{
    List List;

    LQueue(int size);

    int size();

    void enqueue(int data);

    int dequeue();

    int front();
    
    bool isEmpty();
};

#endif