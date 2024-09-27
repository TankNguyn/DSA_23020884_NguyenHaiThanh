#include <bits/stdc++.h>

using namespace std;
struct List
{
    int count = 0;
    int *arr;

    List(int size) : arr(new int[size]) {}

    // truy cập phần tử k
    int GetNode(int k)
    {
        if (k > count)
            return -1;
        return arr[k];
    } // độ phức tạp: O(1)

    // chèn phần tử vào đầu danh sách
    void addFirst(int k)
    {
        if (count == 0)
        {
            count++;
            arr[0] = k;
        }
        // đẩy list sang phải 1 ô
        for (int i = count; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        count++;
        arr[0] = k;
    } // độ phức tạp: O(n)

    // chèn phần tử vào cuối danh sách
    void addLast(int k)
    {
        if (count == 0)
        {
            count++;
            arr[0] = k;
        }
        count++;
        arr[count - 1] = k;
    } // độ phức tạp: O(1)

    // Chèn phần tử vào vị trí bất kì
    void addMid(int i, int k)
    {
        if (count == 0)
        {
            count++;
            arr[0] = k;
        }
        if (i > count)
            arr[i] = k;
        // đẩy list sang phải 1 ô từ vị trí i
        for (int j = count; j > i; j--)
        {
            arr[j] = arr[j - 1];
        }
        count++;
        arr[i - 1] = k;
    } // độ phức tạp: O(n)

    // Xóa phần tử đầu
    int eraseFirst()
    {
        if (count == 0)
            return -1;
        int res = arr[0];
        for (int i = 0; i < count - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        count--;
        return res;
    } // độ phức tạp: O(n)

    // Xoá phần tử cuối
    int eraseLast()
    {
        if (count == 0)
            return -1;
        int res = arr[count - 1];
        count--;
        return res;
    } // Độ phức tạp: O(1)

    // Xóa vị trí i
    int eraseMid(int i)
    {
        if (i > count || count == 0)
            return -1;
        int res = arr[i - 1];
        for (int j = i - 1; i < count - 1; i++)
        {
            arr[i] = arr[i - 1];
        }
        count--;
        return res;
    } // độ phức tạp: O(n)

    // duyệt xuôi
    void BrowseFw()
    {
        for (int i = 0; i < count; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    } // độ phức tạp O(n)

    // duyệt ngược
    void BrowseRv()
    {
        for (int i = count - 1; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    } // độ phức tạp: O(n)
};

int main()
{
    List a(5);
    cout << a.GetNode(3) << endl;
    a.addFirst(10);
    a.addLast(20);
    a.addMid(3, 30);
    cout << a.eraseFirst() << endl;
    cout << a.eraseLast() << endl;
    cout << a.eraseMid(3) << endl;
    a.BrowseFw();
    a.BrowseRv();
    return 0;
}