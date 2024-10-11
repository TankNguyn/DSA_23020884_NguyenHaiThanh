#ifndef LSTACK_H
#define LSTACK_H

#include "List.h"

struct LStack
{
    List List;

    LStack(int size);

    int size();

    void push(int data);

    int pop();

    int top();
    
    bool isEmpty();
};

#endif