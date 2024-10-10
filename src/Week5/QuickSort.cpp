#include <bits/stdc++.h>

using namespace std;

void qs(int x[], int d, int c)
{
    int pivot = (d + c) / 2;
    int l = d, r = c;
    do
    {
        while (x[l] < x[pivot])
            l++;
        while (x[r] > x[pivot])
            r--;
        if (l <= r)
        {
            int tmp = x[l];
            x[l] = x[r];
            x[r] = tmp;
            l++;
            r--;
        }
    } while (l < r);
    if (l < c)
        qs(x, l, c);
    if (d < r)
        qs(x, d, r);
}

int main()
{
    int n;
    cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++)
    {
         cin >> a[i];
    }
    qs(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}