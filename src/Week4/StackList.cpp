#include "LStack.h"

LStack::LStack(int size) : List(size) {}

int LStack::size(){return List.size();}

void LStack::push(int data) {List.addLast(data);}

int LStack::pop(){return List.eraseLast();}

int LStack::top(){return List.getNode(List.count-1);}

bool LStack::isEmpty(){return List.isEmpty();}



