#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int val) : data(val), next(NULL), prev(NULL) {};
};

typedef struct Node *point;
struct DLL
{
    point head;
    point tail;

    DLL() : head(NULL), tail(NULL) {};

    // Lấy phần tử thứ i trong danh sách
    int GetNode(int i)
    {
        if (head == NULL)
            return -1;
        point p = head;
        for (int j = 0; j < i; j++)
        {
            p = p->next;
        }
        return p->data;
    } // độ phức tạp: O(n)

    // Chèn node vào đầu danh sách
    void addFirst(int x)
    {
        point p = new Node(x);
        if (head == NULL)
            head = tail = p;
        else
        {
            p->next = head;
            head->prev = p;
            head = p;
        }
    } // độ phức tạp: O(1)

    // Chèn node vào cuối danh sách
    void addLast(int x)
    {
        point p = new Node(x);
        if (head == NULL)
            head = tail = p;
        else
        {
            p->prev = tail;
            tail->next = p;
            tail = p;
        }
    } // độ phức tạp: O(1)

    // Chèn node sau vị trí i
    void addMid(int i, int x)
    {
        point p = new Node(x);
        point r = head;
        if (head == NULL)
            head = tail = p;
        for (int j = 0; j < i; j++)
        {
            r = r->next;
            if (r->next == NULL)
                return;
        }
        p->next = r->next;
        p->prev = r;
        r->next = p;
    } // độ phức tạp: O(n)

    // Xóa node ở đầu danh sách
    void removeFirst()
    {
        if (head == NULL)
            return;
        if (head->next == NULL)
        {
            free(head);
            head = tail = NULL;
        }
        else{
            head = head->next;
            head->prev = NULL;
        }
    } // độ phức tạp: O(1)

    // Xóa node ở cuối danh sách
    void removeLast()
    {
        if (head == NULL)
            return;
        if (head->next == NULL)
        {
            free(head);
            head = tail = NULL;
        }
        else
        {
            tail = tail->prev;
            tail->next = NULL;
        }
    } // độ phức tạp: O(1)

    // Xóa node ở vị trí i
    void removeMid(int i)
    {
        if (head == NULL)
            return;
        if (head->next == NULL)
        {
            free(head);
            head = tail = NULL;
        }
        else
        {
            point r = head;
            point p = r->next;
            for (int j = 0; j < i - 1; j++)
            {
                r = p;
                p = p->next;
                if (p->next == NULL)
                    return;
            }
            r->next = p->next;
            (p->next)->prev = r;
            delete (p);
        }
    } // độ phức tạp: O(n)

    // duyệt xuôi
    void BrowseFw()
    {
        if (head == NULL)
            return;
        point p = head;
        while (p->next != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    } // độ phức tạp: O(n)

    // duyệt ngược
    void BrowseRv()
    {
        if (head == NULL)
            return;
        point p = tail;
        while (p->prev != NULL)
        {
            cout << p->data << " ";
            p = p->prev;
        }
        cout << endl;
    } // độ phức tạp: O(n)
};

int main()
{
    DLL a;
    a.addFirst(1);
    a.addLast(2);
    a.addMid(1, 3);
    cout << a.GetNode(2) << endl;
    a.BrowseFw();
    a.BrowseRv();
    a.removeMid(2);
    a.removeLast();
    a.removeFirst();
}