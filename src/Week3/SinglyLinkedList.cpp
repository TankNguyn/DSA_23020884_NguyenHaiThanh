#include "SinglyLinkedList.h"

// cấu trúc node
Node::Node(int val) : data(val), next(NULL) {};

typedef struct Node *point;

// quản lí node

SLL::SLL() : head(NULL), tail(NULL) {};

// kiểm tra rỗng
bool SLL::isEmpty()
{
    if (head == NULL)
        return 1;
    return 0;
} // độ phức tạp: O(1)

// truy xuất node ở vị trí i
int SLL::getNode(int i)
{
    if (head == 0)
        return -1;
    point r = head;
    for (int j = 0; j < i; j++)
    {
        r = r->next;
        if (r == NULL & j != i - 1)
            return -1;
    }
    return r->data;
} // độ phức tạp O(n)

// chèn node vào đầu SLL
void SLL::addFirst(int y)
{
    point p = new Node(y);
    if (head == NULL)
        head = tail = p;
    else
    {
        p->next = head;
        head = p;
    }
} // độ phức tạp: O(1)

// chèn node vào cuối SLL
void SLL::addLast(int y)
{
    point p = new Node(y);
    if (head == NULL)
        head = tail = p;
    else
    {
        tail->next = p;
        tail = p;
    }
} // độ phức tạp: O(1)

// chèn node vào sau vị trí i
void SLL::addMid(int i, int y)
{
    if (i < 0)
        return;
    point p = new Node(y);
    if (head == NULL)
        head = tail = p;
    else
    {
        point r = head;
        for (int j = 0; j < i; j++)
        {
            r = r->next;
            if (r == NULL)
                return;
        }
        p->next = r->next;
        r->next = p;
    }
} // độ phức tạp: O(n)

// xóa node đầu của danh sách
int SLL::removeFirst()
{
    if (head == NULL)
        return -1;
    if (head->next == NULL)
    {
        point p = head;
        free(head);
        head = tail = NULL;
        return p->data;
    }
    else
    {
        point r = head;
        head = head->next;
        return r->data;
    }
} // độ phức tạp: O(1)

// xóa node cuối của danh sách
int SLL::removeLast()
{
    if (head == NULL)
        return -1;
    if (head->next == NULL)
    {
        point p = head;
        free(head);
        head = tail = NULL;
        return p->data;
    }
    else
    {
        point r = head;
        while ((r->next)->next != NULL)
        {
            r = r->next;
        }
        tail = r;
        tail->next = NULL;
        return r->data;
    }
} // độ phức tạp: O(n)

// xóa node vị trí i
int SLL::removeMid(int i)
{
    if (i < 0)
        return -1;
    if (head == NULL)
        return -1;
    if (head->next == NULL)
    {
        point p = head;
        free(head);
        head = tail = NULL;
        return p->data;
    }
    else
    {
        point r = head;
        point p = r->next;
        for (int j = 0; j < i - 1; j++)
        {
            r = p;
            p = p->next;
            if (p == NULL)
                return;
        }
        r->next = p->next;
        p->next = NULL;
        return p->data;
    }
} // độ phức tạp: O(n)

// duyệt xuôi
void SLL::BrowseFw()
{
    if (head == NULL)
        return;
    else
    {
        point r = head;
        while (r != NULL)
        {
            cout << r->data << " ";
            r = r->next;
        }
        cout << endl;
    }
} // độ phức tạp: O(n)

// duyệt ngược
void SLL::BrowseRv(point head)
{
    point tmp = head;
    if (tmp == NULL)
        return;
    BrowseRv(tmp->next);
    cout << tmp->data << " ";
}