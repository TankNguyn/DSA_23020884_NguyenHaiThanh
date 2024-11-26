#include <bits/stdc++.h>

using namespace std;

struct Node
{
    string key;
    int value;

    Node(string k, int val) : key(k), value(val) {};
};

typedef Node *point;

class LinearProbling
{
private:
    point lp[10000];

    int HashCode(string k)
    {
        int s = 0;
        for (int i = 0; i < k.length(); i++)
        {
            s = s + k[i];
        }
        return s % 100;
    }

public:
    LinearProbling()
    {
        for (int i = 0; i < 10000; i++)
        {
            lp[i] = NULL;
        }
    }

    void put(string k, int val)
    {
        int tmp = HashCode(k);
        while (lp[tmp] != NULL)
        {
            if (lp[tmp]->key == "\0" || lp[tmp]->key == k)
                break;
            else
            {
                if (tmp == 99)
                    tmp = 0;
                else
                    tmp++;
            }
        }
        if (lp[tmp] == NULL)
            lp[tmp] = new Node(k, val);
        else
        {
            lp[tmp]->key = k;
            lp[tmp]->value = val;
        }
    }

    int get(string k)
    {
        int tmp = HashCode(k);
        while (lp[tmp] != NULL)
        {
            if (lp[tmp]->key == k)
                return lp[tmp]->value;
            if (tmp == 99)
                tmp = 0;
            else
                tmp++;
        }
        return -1;
    }

    void del(string k)
    {
        int tmp = HashCode(k);
        while (lp[tmp] != NULL)
        {
            if (lp[tmp]->key == k)
                break;
            else
            {
                if (tmp == 99)
                    tmp = 0;
                else
                    tmp++;
            }
        }
        if (lp[tmp] == NULL)
            return;
        lp[tmp]->key = "\0";
    }
};

int main()
{
    LinearProbling a;
    a.put("Lemon", 5);
    a.put("Banana", 6);
    a.put("nomeL", 5);
    a.put("Apple", 10);
    cout << a.get("Apple") << endl;
    a.del("Apple");
    cout << a.get("nomeL") << endl;
    a.del("nomeL");
    cout << a.get("Banana") << endl;
    a.del("Banana");
    cout << a.get("Lemon") << endl;
    a.del("Lemon");
    return 0;
}