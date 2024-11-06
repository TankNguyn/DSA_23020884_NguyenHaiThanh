#include <bits/stdc++.h>

using namespace std;

struct Node
{
    string key;
    int value;
    Node *next;

    Node(string k, int val) : key(k), value(val), next(NULL) {}
};

typedef struct Node* point;

struct SymbolTable
{
    point head;

    SymbolTable() : head(NULL) {}

    void put(string k, int val)
    {
        point p = head;
        while (p->key != k || p->next != NULL)
        {
            p = p->next;
        }
        if (p->key == k)
        {
            p->value = val;
        }
        else
        {
            point r = new Node(k, val);
            p->next = r;
        }
    }

    int get(string k)
    {
        point p = head;
        while (p->key != k || p->next != NULL)
        {
            p = p->next;
        }
        if (p->key == k)
        {
            return p->value;
        }
        else
        {
            return -1;
        }
    }

    bool contains(string k)
    {
        point p = head;
        while (p->next != NULL)
        {
            if (p->key == k)
                return 1;
            else
                p = p->next;
        }
        return 0;
    }

    bool isEmpty()
    {
        if (head->next == NULL)
            return 1;
        else
            return 0;
    }

    int size()
    {
        point p = head;
        int count = 0;
        while (p->next != NULL)
        {
            count++;
            p = p->next;
        }
        return count;
    }

    void del(string k)
    {
        point p = head;
        point r = p;
        while (p->key != k || p->next != NULL)
        {
            p = p->next;
            if (r != head)
                r = r->next;
        }
        if (p->key == k)
        {
            r->next = p->next;
            p->next = NULL;
        }
        else
            return;
    }
};

int main()
{
    SymbolTable a;
    a.put("T",1);
    a.put("h",2);
    a.put("a",3);
    a.put("n",4);
    a.put("k",5);
    
}