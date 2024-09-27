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
        
    }
};