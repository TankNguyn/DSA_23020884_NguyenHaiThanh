#include <bits/stdc++.h>

using namespace std;

struct PQ
{
    int *arr;
    int count;

    PQ() : count(0)
    {
        arr = new int[1000000];
    };

    bool isEmpty()
    {
        return count;
    } // O(1)

    int size()
    {
        return count;
    } // O(1)

    void swap(int x, int y)
    {
        int tmp = arr[x];
        arr[x] = arr[y];
        arr[y] = tmp;
    } // O(1)

    void swim(int k)
    {
        int n = k;
        if (n <= 1)
            return;
        if (n % 2 != 0)
        {
            if (arr[n] > arr[n - 1])
            {
                swap(n, n - 1);
                n--;
            }
        }
        if (arr[n] > arr[n / 2])
        {
            swap(n, n / 2);
            swim(n / 2);
        }
        else
            return;
    } // O(logn)

    void sink(int k)
    {
        int n = k;
        if (n >= count || n * 2 > count)
            return;
        if (n * 2 + 1 <= count)
        {
            if (arr[n * 2] < arr[n * 2 + 1])
            {
                if (arr[n] < arr[n * 2 + 1])
                {
                    swap(n, n * 2 + 1);
                    sink(n * 2 + 1);
                }
                else
                    return;
            }
            else
            {
                if (arr[n] < arr[n * 2])
                {
                    swap(n, n * 2);
                    sink(n * 2);
                }
                else
                    return;
            }
        }
        else
        {
            if (arr[n] < arr[n * 2])
            {
                swap(n, n * 2);
                sink(n * 2);
            }
            else
                return;
        }
    } // O(logn)

    void insert(int x)
    {
        count++;
        arr[count] = x;
        swim(count);
    } // O(logn)

    int delMax()
    {
        swap(1, count);
        count--;
        sink(1);
        return arr[count + 1];
    } // O(logn)

    int getMax()
    {
        return arr[1];
    } // O(1)
};

int main()
{
    PQ a;
    a.insert(5);
    a.insert(10);
    a.insert(15);
    a.insert(2);
    a.insert(4);
    a.insert(6);
    a.insert(8);
    a.insert(0);
    a.insert(100);
    a.insert(20);
    while (a.isEmpty())
    {
        cout << a.getMax() << " " << a.delMax() << endl;
    }
    return 0;
}