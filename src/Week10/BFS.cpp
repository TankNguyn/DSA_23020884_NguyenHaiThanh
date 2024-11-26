#include "AdjacencyList.h"

Node::Node(char v) : vertex(v), next(NULL) {};

AdjacencyList::AdjacencyList()
{
    for (int i = 'A'; i <= 'Z'; i++)
    {
        AL[i] = NULL;
    }
}

void AdjacencyList::addEdge(char u, char v)
{
    if (AL[u] == NULL)
        AL[u] = new Node(v);
    else
    {
        point x = new Node(v);
        if (AL[u]->next == NULL)
        {
            if (AL[u]->vertex > v)
            {
                x->next = AL[u];
                AL[u] = x;
            }
            else
                AL[u]->next = x;
        }
        else
        {
            point y = AL[u];
            while (1)
            {
                if (y->next == NULL)
                {
                    y->next = x;
                    break;
                }
                else if (y->next->vertex > v)
                {
                    x->next = y->next;
                    y->next = x;
                    break;
                }
                else
                    y = y->next;
            }
        }
    }

    if (AL[v] == NULL)
        AL[v] = new Node(u);
    else
    {
        point x = new Node(u);
        if (AL[v]->next == NULL)
        {
            if (AL[v]->vertex > u)
            {
                x->next = AL[v];
                AL[v] = x;
            }
            else
                AL[v]->next = x;
        }
        else
        {
            point y = AL[v];
            while (1)
            {
                if (y->next == NULL)
                {
                    y->next = x;
                    break;
                }
                else if (y->next->vertex > u)
                {
                    x->next = y->next;
                    y->next = x;
                    break;
                }
                else
                    y = y->next;
            }
        }
    }
   
}

void AdjacencyList::adjBFS(queue<char> &s, char v)
{
    if (AL[v] == NULL)
        return;
    point x = AL[v];
    while (x != NULL)
    {
        s.push(x->vertex);
        x = x->next;
    }
    AL[v] = NULL;
}

void AdjacencyList::BFS(queue<char> &s, char u)
{
    s.push(u);
    while (!s.empty())
    {
        char v = s.front();
        s.pop();
        if (AL[v] != NULL)
        {
            cout << v << " ";
            adjBFS(s, v);
        }
    }
}

int main(){
    AdjacencyList a;
    a.addEdge('A', 'B');
    a.addEdge('A', 'C');
    a.addEdge('A', 'F');
    a.addEdge('A', 'Z');
    a.addEdge('B', 'E');
    a.addEdge('D', 'F');
    a.addEdge('D', 'O');
    queue<char> s;
    char u;
    cout << "Nhập đỉnh bắt đầu: ";
    cin >> u;
    a.BFS(s, u);
}