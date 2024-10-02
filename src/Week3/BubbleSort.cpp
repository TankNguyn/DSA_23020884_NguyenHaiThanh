#include <bits/stdc++.h>

using namespace std;

void BubbleSort(int a[], int n)
{
    bool swap = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (!swap)
            return;
        else
        {
            swap = false;
            for (int j = 0; j < n - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    int tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;
                    swap = true;
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[10000];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    BubbleSort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}