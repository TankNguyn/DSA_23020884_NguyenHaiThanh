#include "LLStack.h"

LLStack::LLStack() {}

void LLStack::push(int data) {SLL.addFirst(data);}

int LLStack::pop(){return SLL.removeFirst();}

int LLStack::top(){return SLL.getNode(0);}

bool LLStack::isEmpty(){return SLL.isEmpty();}