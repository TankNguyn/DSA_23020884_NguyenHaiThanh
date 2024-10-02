#include <bits/stdc++.h>

using namespace std;

void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        bool ok = false;
        int temp = a[i];

        while ((j >= 0) && !ok)
        {
            cout << i << " " << j << " " << temp <<" "<<ok;
            if (a[j] > temp)
            {
                a[j + 1] = a[j];
                j--;
            }
            else
                ok = true;
        }
        a[j + 1] = temp;
    }
}

int main()
{
    int a[6] = {5, 1, 3, 4, 6, 2};
    InsertionSort(a, 6);
}