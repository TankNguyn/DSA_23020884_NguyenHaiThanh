#include<bits/stdc++.h>

using namespace std;

struct Node{
    string key;
    int value;
    Node *next;

    Node(string k, int val) : key(k), value(val), next(NULL) {};
};

typedef struct Node *point;

class HashTable{
private:
    point HT[1000];
    
    int HashCode(string k){
        int s=0;
        for(int i=0; i<k.length(); i++){
            s = s + k[i];
        }
        return s % 100;
    }
public:
    HashTable(){
        for(int i=0; i<100; i++){
            HT[i] = NULL;
        }
    }
    void put(string k, int val){
        int tmp = HashCode(k);
        point x = new Node(k,val);
        if(HT[tmp] == NULL){
            HT[tmp] = x;
            return;
        }
        point y = HT[tmp];
        while(y->next != NULL){
            if(y->key == k){
                y->value = val;
                return;
            }
            y = y->next;
        }
        y->next = x;
    }

    int get(string k){
        int tmp = HashCode(k);
        point x = HT[tmp];
        while(x != NULL){
            if(x->key == k) return x->value;
            x = x->next;
        }
        return -1;
    }

    void del(string k){
        int tmp = HashCode(k);
        if(HT[tmp] == NULL) return;
        if(HT[tmp]->next == NULL){
            if(HT[tmp]->key == k) HT[tmp] = NULL;
            return;
        }
        point x = HT[tmp], y = HT[tmp];
        while(y->key != k){
            if(y->next == NULL) return;
            y = y->next;
            if(x != HT[tmp]) x = x->next;
        }
        x->next = y->next;
        y->next = NULL;
    }
};

int main(){
    HashTable a;
    a.put("Lemon",5);
    a.put("Banana",6);
    a.put("nomeL",5);
    a.put("Apple",10);
    cout<<a.get("Apple")<<endl;
    a.del("Apple");
    cout<<a.get("nomeL")<<endl;
    a.del("nomeL");
    cout<<a.get("Banana")<<endl;
    a.del("Banana");
    cout<<a.get("Lemon")<<endl;
    a.del("Lemon");
    return 0;
}

