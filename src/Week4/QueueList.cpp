#include <bits/stdc++.h>

using namespace std;

struct QueueList
{
    int count = 0;
    int *arr;

    QueueList(int size) : arr(new int[size]) {}

    // kiểm tra queue rỗng
    bool isEmpty()
    {
        return !count;
    } // độ phức tạp: O(1)

    // hàm trả về kích thước queue
    int size()
    {
        return count;
    } // độ phức tạp: O(1)

    // lấy phần tử đầu của queue
    int front()
    {
        if (isEmpty())
            return -1;
        return arr[0];
    } // độ phức tạp: O(1)

    // chèn phần tử vào queue
    void enqueue(int n)
    {
        count++;
        arr[count - 1] = n;
    } // độ phức tạp: O(1)

    // Xoá phần tử queue
    int dequeue()
    {
        if (isEmpty())
            return -1;
        int res = arr[0];
        for (int i = 1; i < count; i++)
        {
            arr[i - 1] = arr[i];
        }
        count--;
        return res;
    } // Độ phức tạp: O(n)
};

int main()
{
    QueueList a(100);
    cout << a.isEmpty() << endl;
    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    a.enqueue(4);
    cout << a.size() << endl;
    while (!a.isEmpty())
    {
        cout << a.front() << " " << a.dequeue() << endl;
    }
    return 0;
}