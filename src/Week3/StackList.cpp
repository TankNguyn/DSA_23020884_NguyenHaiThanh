#include <bits/stdc++.h>

using namespace std;

struct StackList
{
    int count = 0;
    int *arr;

    StackList(int size) : arr(new int[size]) {}

    // kiểm tra stack rỗng
    bool isEmpty()
    {
        return !count;
    } // độ phức tạp: O(1)

    // hàm trả về kích thước stack
    int size()
    {
        return count;
    } // độ phức tạp: O(1)

    // lấy phần tử trên cùng của stack
    int top()
    {
        if (isEmpty())
            return -1;
        return arr[count - 1];
    } // độ phức tạp: O(1)

    // chèn phần tử vào stack
    void push(int n)
    {
        count++;
        arr[count - 1] = n;
    } // độ phức tạp: O(1)

    // Xoá phần tử trên cùng của stack
    int pop()
    {
        if (isEmpty())
            return -1;
        int res = arr[count - 1];
        count--;
        return res;
    } // Độ phức tạp: O(1)
};

int main()
{
    StackList a(100);
    cout << a.isEmpty() << endl;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    cout << a.size() << endl;
    while (!a.isEmpty())
    {
        cout << a.top() << " " << a.pop() << endl;
    }
    return 0;
}