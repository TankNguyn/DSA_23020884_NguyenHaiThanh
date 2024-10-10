#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {};
};

typedef struct Node *point;

struct StackLL
{
    point head;

    StackLL() : head(NULL) {};

    // kiểm tra stack rỗng
    bool isEmpty()
    {
        if (head == NULL)
            return 1;
        return 0;
    } // độ phức tạp: O(1)

    // hàm trả về kích thước stack
    int size()
    {
        if (isEmpty())
            return 0;
        int i = 1;
        point r = head;
        while (r->next != NULL)
        {
            r = r->next;
            i++;
        }
        return i;
    } // độ phức tạp: O(n)

    // lấy phần tử trên cùng stack
    int top()
    {
        if (isEmpty())
            return -1;
        return head->data;
    } // độ phức tạp: O(1)

    // thêm phần tử vào stack
    void push(int n)
    {
        point p = new Node(n);
        if (isEmpty())
            head = p;
        else
        {
            p->next = head;
            head = p;
        }
    } // độ phức tạp: O(1)

    // xóa phần tử trên cùng stack
    int pop()
    {
        if (isEmpty())
            return -1;
        int res = head->data;
        head = head->next;
        return res;
    } // độ phức tạp: O(1)
};

int main()
{
    StackLL a;
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