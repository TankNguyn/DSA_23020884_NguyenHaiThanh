#include "AdjacencyList.h"

Node::Node(char v) : vertex(v), next(NULL) {};

bool AdjacencyList::remove(point x, char m)
{
    point y = x, z = x->next;
    while (z->vertex != m)
    {
        z = z->next;
        if (z == NULL)
            return 0;
        y = y->next;
    }
    y->next = z->next;
    z->next = NULL;
    return 1;
}

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
        x->next = AL[u];
        AL[u] = x;
    }
    if (AL[v] == NULL)
        AL[v] = new Node(u);
    else
    {
        point x = new Node(u);
        x->next = AL[v];
        AL[v] = x;
    }
}

bool AdjacencyList::isEdge(char u, char v)
{
    point x = AL[u];
    while (x != NULL)
    {
        if (x->vertex == v)
            return 1;
        else
            x = x->next;
    }
    return 0;
}

void AdjacencyList::removeEdge(char u, char v)
{
    if (AL[u] == NULL)
        return;
    if (AL[u]->next == NULL)
    {
        if (AL[u]->vertex == v)
            AL[u] = NULL;
        return;
    }
    bool tmp = remove(AL[u], v);
    if (!tmp)
        return;
    if (AL[v]->next == NULL)
    {
        AL[v] = NULL;
        return;
    }
    remove(AL[v], u);
}

void AdjacencyList::adj(char u)
{
    if (AL[u] == NULL)
        cout << "Không có đỉnh kề " << u;
    else
    {
        point x = AL[u];
        while (x != NULL)
        {
            cout << x->vertex << " ";
            x = x->next;
        }
    }
    cout << endl;
}

int main()
{
    AdjacencyList a;
    a.addEdge('A', 'B');
    a.addEdge('A', 'C');
    a.addEdge('A', 'F');
    a.addEdge('A', 'Z');
    a.addEdge('B', 'E');
    a.addEdge('D', 'F');
    a.addEdge('D', 'O');
    cout << a.isEdge('A', 'B') << " " << a.isEdge('C', 'F') << endl;
    a.adj('F');
    a.adj('B');
    a.adj('A');
    a.removeEdge('A', 'F');
    a.adj('A');
}