#include <bits/stdc++.h>

using namespace std;

// cấu trúc node
struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {};
};

typedef struct Node *point;

// quản lí node
struct SLL
{
    point head;
    point tail;

    SLL() : head(NULL), tail(NULL) {};

    // truy xuất node ở vị trí i
    int GetNode(int i)
    {
        point r = head;
        for (int j = 0; j < i; j++)
        {
            r = r->next;
        }
        return r->data;
    } // độ phức tạp O(n)

    // chèn node vào đầu SLL
    void addFirst(int y)
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
    void addLast(int y)
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
    void addMid(int i, int y)
    {
        point p = new Node(y);
        if (head == NULL)
            head = tail = p;
        else
        {
            point r = head;
            for (int j = 0; j < i; j++)
            {
                r = r->next;
            }
            p->next = r->next;
            r->next = p;
        }
    } // độ phức tạp: O(n)

    // xóa node đầu của danh sách
    void removeFirst()
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
            head = head->next;
        }
    } // độ phức tạp: O(1)

    // xóa node cuối của danh sách
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
            point r = head;
            while ((r->next)->next != NULL)
            {
                r = r->next;
            }
            tail = r;
            free(r);
            tail->next = NULL;
        }
    } // độ phức tạp: O(n)

    // xóa node vị trí i
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
            p->next = NULL;
        }
    } // độ phức tạp: O(n)

    // duyệt xuôi
    void BrowseFw()
    {
        if (head == NULL)
            return;
        else{
            point r = head;
            while(r->next != NULL){
                cout << r->data <<" ";
                r = r->next;
            }
        }
    }//độ phức tạp: O(n)
};

int main(){
    SLL a;
    a.addFirst(1);
    a.addLast(2);
    a.addMid(1,3);
    a.GetNode(2);
    a.BrowseFw();
    a.removeMid(2);
    a.removeFirst();
    a.removeLast();
}