#include <bits/stdc++.h>

using namespace std;

void merge(int x[], int l, int m, int r)
{
    int a[1000], b[1000], n1 = 0, n2 = 0;
    for (int i = 0; i < m - l + 1; i++)
    {
        a[i] = x[l + i];
        n1++;
    }
    for (int i = 0; i < r - m; i++)
    {
        b[i] = x[m + i + 1];
        n2++;
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            x[k] = a[i];
            i++;
        }
        else
        {
            x[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        x[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        x[k] = b[j];
        k++;
        j++;
    }
}

void mergesort(int x[], int d, int c)
{
    if (d >= c)
        return;
    int mid = (d + c) / 2;
    mergesort(x, d, mid);
    mergesort(x, mid + 1, c);
    merge(x, d, mid, c);
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
    mergesort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}