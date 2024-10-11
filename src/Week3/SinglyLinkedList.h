#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val);
};

typedef struct Node *point;

struct SLL
{
    point head;
    point tail;

    SLL();

    bool isEmpty();

    int getNode(int i);

    void addFirst(int y);

    void addLast(int y);

    void addMid(int i, int y);

    int removeFirst();

    int removeLast();

    int removeMid(int i);

    void BrowseFw();

    void BrowseRv(point head);
};

#endif