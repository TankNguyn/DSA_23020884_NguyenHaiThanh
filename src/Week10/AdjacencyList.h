#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include<bits/stdc++.h>

using namespace std;

struct Node
{
    char vertex;
    Node *next;

    Node(char v);
};

typedef struct Node *point;

class AdjacencyList{
private:
    point AL[1000];

    bool remove(point x, char m);

    void adjDFS(stack<char>& s, char u);

    void adjBFS(queue<char>& q, char u);
public:
    AdjacencyList();

    void addEdge(char u, char v);

    bool isEdge(char u, char v);

    void removeEdge(char u, char v);

    void adj(char u);

    void DFS(stack<char>& s, char u);

    void BFS(queue<char>& q, char u);
};

#endif
