#include <bits/stdc++.h>

using namespace std;

class symTabList
{
private:
    int *data;
    string *key;
    int count;

    int binarySearch(string IP, int left, int right)
    {
        if (left > right)
            return -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (IP == key[mid])
                return mid;
            if (IP < key[mid])
                return binarySearch(IP, left, mid - 1);
            if (IP > key[mid])
                return binarySearch(IP, mid + 1, right);
        }
        return -1;
    }

public:
    symTabList(int size) : data(new int[size]), key(new string[size]), count(0) {}

    void put(string IP, int value)
    {
        int pos = binarySearch(IP, 0, count - 1);
        if (pos != -1)
        {
            data[pos] = value;
            return;
        }
        else
        {
            int i;
            for (i = count - 1; (i >= 0 && key[i] > IP); --i)
            {
                data[i + 1] = data[i];
                key[i + 1] = key[i];
            }
            data[i + 1] = value;
            key[i + 1] = IP;
            ++count;
        }
    }

    void del(string IP)
    {
        int pos = binarySearch(IP, 0, count - 1);
        if (pos != -1)
        {
            for (int i = pos; i < count - 1; ++i)
            {
                data[i] = data[i + 1];
                key[i] = key[i + 1];
            }
            --count;
            cout << "Deleted successfully" << endl;
        }
        else
            cout << "Can't delete" << endl;
    }

    int get(string IP)
    {
        int pos = binarySearch(IP, 0, count - 1);
        if (pos != -1)
            return data[pos];
        cout << "Can't get value of IP" << endl;
        return -1;
    }

    bool contains(string IP)
    {
        return binarySearch(IP, 0, count - 1) != -1;
    }

    void iterable()
    {
        for (int i = 0; i < count; ++i)
            cout << key[i] << " ";
        cout << endl;
    }

    bool isEmpty() { return count == 0; }

    int size() { return count; }
};

int main()
{
    symTabList STL(100);

    STL.put("A", 12);
    STL.put("b", 17);
    STL.put("qui", 35);
    STL.put("8", 2);
    STL.put("iop", 67);
    STL.put("v", 57);
    STL.put("4", 7);
    STL.put("m", 4);

    string IP;
    cin >> IP;
    STL.del(IP);

    cout << STL.get("iop") << endl;

    if (STL.contains("4") == true)
        cout << "True" << endl;
    else
        cout << "false" << endl;

    cout << STL.isEmpty() << endl;
    cout << STL.size() << endl;

    STL.iterable();

    return 0;
}