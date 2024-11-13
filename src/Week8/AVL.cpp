#include <bits/stdc++.h>
#include "LLQueue.h"

using namespace std;

struct Node
{
    string key;
    int value;
    Node *left;
    Node *right;
    int height;

    Node(string k, int val) : left(NULL), right(NULL), key(k), value(val), height(1) {};
};

typedef struct Node *point;

class AVL
{
private:
    point root;

    int CompareTo(string x, string y)
    {
        if (x < y)
            return -1;
        if (x > y)
            return 1;
        return 0;
    }

    int getHeight(point x)
    {
        if (x == NULL)
            return 0;
        else
            return x->height;
    }

    int getBalance(point x)
    {
        if (x == NULL)
            return 0;
        else
            return getHeight(x->left) - getHeight(x->right);
    }

    point rightRotate(point x)
    {
        point y = x->left;
        point z = y->right;
        y->right = x;
        x->left = z;
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        return y;
    }

    point leftRotate(point x)
    {
        point y = x->right;
        point z = y->left;
        y->left = x;
        x->right = z;
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        return y;
    }

    point treeBalance(point x, int balance)
    {
        // Trái Trái
        if (balance > 1 && getBalance(x->left) >= 0)
            return rightRotate(x);
        // Trái Phải
        if (balance > 1 && getBalance(x->left) < 0)
        {
            x->left = leftRotate(x->left);
            return rightRotate(x->right);
        }
        // Phải Phải
        if (balance < -1 && getBalance(x->right) <= 0)
            return leftRotate(x);
        // Phải Trái
        if (balance < -1 && getBalance(x->right) > 0)
        {
            x->right = rightRotate(x->right);
            return leftRotate(x);
        }
        return x;
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
        // Cập nhật chỉ số cân bằng của cây
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        int bal = getBalance(x);
        /*
        //Trái Trái
        if(bal > 1 && getBalance(x->left) >= 0) return rightRotate(x);
        //Trái Phải
        if(bal > 1 && getBalance(x->left) < 0){
            x->left = leftRotate(x->left);
            return rightRotate(x->right);
        }
        //Phải Phải
        if(bal < -1 && getBalance(x->right) <=0) return leftRotate(x);
        //Phải Trái
        if(bal < -1 && getBalance(x->right) > 0){
            x->right = rightRotate(x->right);
            return leftRotate(x);
        }
        return x;
        */
        return treeBalance(x, bal);
    }

    point Min(point x)
    {
        point y = x;
        while (y->left != NULL)
        {
            y = y->left;
        }
        return y;
    }

    point delMin(point x)
    {
        point y = x;
        if (y->left == NULL)
            return y->right;
        y->left = delMin(y->left);
        return y;
    }

    point del(point x, string k)
    {
        if (x == NULL)
            return NULL;
        int cmp = CompareTo(k, x->key);
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
            // thay thế nút
            point a = x;
            x = Min(a->right); // nút mới tìm được
            x->right = delMin(a->right);
            x->left = a->left;
        }
        if (x == NULL)
            return NULL;
        // Cập nhật chỉ số cân bằng của cây
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        int bal = getBalance(x);
        return treeBalance(x, bal);
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
    AVL() : root(NULL) {};

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
    AVL a;
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