#include <bits/stdc++.h>
#include "LLQueue.h"

using namespace std;

struct Node
{
    string key;
    int value;
    Node *left;
    Node *right;

    Node(string k, int val) : key(k), value(val), left(NULL), right(NULL) {};
};

typedef struct Node *point;

class BST
{
private:
    point root;

    // int size(point x){
    //     if(x == NULL) return 0;
    //     else return x->count;
    // }

    int CompareTo(string x, string y)
    {
        if (x < y)
            return -1;
        if (x == y)
            return 0;
        return 1;
    }

    point put(point x, string k, int val)
    {
        if (x == NULL)
            return new Node(k, val);
        int cmp = CompareTo(k, x->key);
        if (cmp < 0)
            x->left = put(x->left, k, val);
        else if (cmp > 0)
            x->right = put(x->right, k, val);
        else
            x->value = val;
        return x;
    }
    // hàm tìm nút có key nhỏ nhất
    point min(point x)
    {
        while (x->left != NULL)
            x = x->left;
        return x;
    }
    // hàm xóa nút có key nhỏ nhất
    point delMin(point x)
    {
        if (x->left == NULL)
            return x->right;
        x->left = delMin(x->left);
        return x;
    }

    point del(point x, string k)
    {
        if (x == NULL)
            return NULL;
        int cmp = CompareTo(k, x->key);
        // tìm key
        if (cmp < 0)
            x->left = del(x->left, k);
        else if (cmp > 0)
            x->right = del(x->right, k);
        else
        {
            if (x->right == NULL)
                return x->left; // không còn nút con phải
            if (x->left == NULL)
                return x->right; // không còn nút con trái
            // thay thế nốt
            point a = x;
            x = min(a->right); // nút mới tìm được
            x->right = delMin(a->right);
            x->left = a->left;
        }
        return x;
    }

    void inorder(point x, LLQueue y)
    {
        if (x == NULL)
            return;
        inorder(x->left, y);
        y.enqueue(x->value);
        inorder(x->right, y);
    }

    void preorder(point x, LLQueue y)
    {
        if (x == NULL)
            return;
        y.enqueue(x->value);
        preorder(x->left, y);
        preorder(x->right, y);
    }

    void postorder(point x, LLQueue y)
    {
        if (x == NULL)
            return;
        postorder(x->left, y);
        postorder(x->right, y);
        y.enqueue(x->value);
    }

public:
    BST() : root(NULL) {};

    bool isEmpty()
    {
        if (root == NULL)
            return 1;
        return 0;
    }

    int get(string k)
    {
        point x = root;
        while (x != NULL)
        {
            int cmp = CompareTo(k, x->key);
            if (cmp < 0)
                x = x->left;
            else if (cmp > 0)
                x = x->right;
            else
                return x->value;
        }
        return -1;
    }

    void put(string k, int val)
    {
        root = put(root, k, val);
    }

    void del(string k)
    {
        root = del(root, k);
    }
};

int main()
{
    BST a;
    a.put("T", 1);
    a.put("h", 2);
    a.put("a", 3);
    a.put("n", 4);
    a.put("k", 5);
    cout << a.get("T") << endl;
    a.del("T");
    cout << a.get("h") << endl;
    a.del("h");
    cout << a.get("a") << endl;
    a.del("a");
    cout << a.get("n") << endl;
    a.del("n");
    cout << a.get("k") << endl;
    a.del("k");
}