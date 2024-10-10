#include <bits/stdc++.h>

using namespace std;

void SelectionSort(int a[], int n)
{
    if (n < 2)
        return;
    for (int i = 0; i < n - 1; i++)
    {
        int m = a[i];
        int vt = i;
        for (int j = i + 1; j < n; j++)
        {
            if (m > a[j])
            {
                m = a[j];
                vt = j;
            }
        }
        int tmp = a[i];
        a[i] = a[vt];
        a[vt] = tmp;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SelectionSort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}