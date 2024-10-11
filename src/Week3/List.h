#ifndef LIST_H
#define LIST_H

#include <bits/stdc++.h>

using namespace std;

struct List
{
    int count = 0;
    int *arr;

    List(int size);

    int size();

    bool isEmpty();

    int getNode(int k);

    void addFirst(int k);

    void addLast(int k);

    void addMid(int i, int k);

    int eraseFirst();

    int eraseLast();

    int eraseMid(int i);

    void BrowseFw();

    void BrowseRv();
};

#endif