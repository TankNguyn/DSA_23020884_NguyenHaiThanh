#include <bits/stdc++.h>

using namespace std;

void swap(int x, int y, int a[])
{
    int tmp = a[x];
    a[x] = a[y];
    a[y] = tmp;
} // O(1)

void sink(int a[], int n, int k)
{
    int x = k;
    if (x >= n || x * 2 > n)
        return;
    if (x * 2 + 1 <= n)
    {
        if (a[x * 2] < a[x * 2 + 1])
        {
            if (a[x] < a[x * 2 + 1])
            {
                swap(x, x * 2 + 1, a);
                sink(a, n, x * 2 + 1);
            }
            else
                return;
        }
        else
        {
            if (a[x] < a[x * 2])
            {
                swap(x, x * 2, a);
                sink(a, n, x * 2);
            }
            else
                return;
        }
    }
    else
    {
        if (a[x] < a[x * 2])
        {
            swap(x, x * 2, a);
            sink(a, n, x * 2);
        }
        else
            return;
    }
} // O(logn)

void Heap(int a[], int n)
{
    for (int i = n / 2; i >= 1; i--)
        sink(a, n, i);
}

int main()
{
    int n;
    cin >> n;
    int a[100000];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    Heap(a, n);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}