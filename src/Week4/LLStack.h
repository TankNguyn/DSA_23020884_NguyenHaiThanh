#ifndef LLSTACK_H
#define LLSTACK_H

#include "SinglyLinkedList.h"

struct LLStack
{
    SLL SLL;
    LLStack();

    void push(int data);

    int pop();

    int top();
    
    bool isEmpty();
};

#endif
