#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prep;

    Node(int val) : data(val), next(NULL), prep(NULL){};
};

typedef struct Node* point;
struct DLL{
    point head;
    point tail;

    DLL() : head(NULL) ,tail(NULL){};

    //Lấy phần tử thứ i trong danh sách
    int GetNode(int i){
        if(head == NULL) return -1;
        point p = head;
        for(int j=0; j<i; j++){
            p = p->next;
        }
        return p->data;
    }//độ phức tạp: O(n)

    //Chèn node vào đầu danh sách
    void addFirst(int x){
        point p = new Node(x);
        if(head == NULL) head = tail = p;    
        else{
            p->next = head;
            head->prep = p;
            head = p;
        }
    }//độ phức tạp: O(1)

    //Chèn node vào cuối danh sách
    void addLast(int x){
        point p = new Node(x);
        if(head == NULL) head = tail = p;
        else{
            p->prep = tail;
            tail->next = p;
            tail = p;
        }
    }//độ phức tạp: O(1)

    //Chèn node sau vị trí i
    void addMid(int i, int x){
        point p = new Node(x);
        point r = head;
        if(head == NULL) head = tail = p;
        for(int j=0; j<i; j++){
            r = r->next;
            if(r->next == NULL) return;
        }
        p->next = r->next;
        p->prep = r;
        r->next = p;
    }//độ phức tạp: O(n)

    //Xóa node ở đầu danh sách
    


};