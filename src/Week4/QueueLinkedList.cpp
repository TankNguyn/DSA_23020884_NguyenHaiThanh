#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {};
};

typedef struct Node *point;

struct QueueLL
{
    point head;
    point tail;

    QueueLL() : head(NULL), tail(NULL) {};

    // kiểm tra queue rỗng
    bool isEmpty()
    {
        if (head == NULL)
            return 1;
        return 0;
    } // độ phức tạp: O(1)

    // hàm trả về kích thước queue
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

    // lấy phần tử đầu queue
    int front()
    {
        if (isEmpty())
            return -1;
        return head->data;
    } // độ phức tạp: O(1)

    // thêm phần tử vào queue
    void enqueue(int n)
    {
        point p = new Node(n);
        if (isEmpty())
            head = tail = p;
        else
        {
            tail->next = p;
            tail = p;
        }
    } // độ phức tạp: O(1)

    // xóa phần tử queue
    int dequeue()
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
    QueueLL a;
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