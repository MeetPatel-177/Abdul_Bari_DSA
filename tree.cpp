#include <bits/stdc++.h>
using namespace std;

class Node {
    public :
    Node* lchild;
    int data;
    Node* rchild;
};

class tree {
    private : 
    Node* root;
    public : 
    tree() {
        root = NULL;
    }
    void create();
    void PreOrder() {
        PreOrder(root);
    }
    void PreOrder(Node *p);
    void InOrder() {
        InOrder(root);
    }
    void InOrder(Node* p);
    void PostOrder() {
        PostOrder(root);
    }
    void PostOrder(Node* p);
    void LevelOrder();
    int height() {
        height(root);
    }
    int height(Node *p);
    int count() {
        count(root);
    }
    int count(Node* p);
};

void tree :: create() {
    queue<Node*>q;
    int x;
    // cout << "Enter root's value : ";
    cin >> x;
    if(x != -1) {
        root = new Node;
        root->data = x;
        root->lchild = root->rchild = NULL;
        q.push(root);
    }
    Node* p, *t;
    while(!q.empty()) {
        p = q.front();
        q.pop();
        int lc;
        // cout << "Enter left child's value of " << p->data << " : ";
        cin >> lc;
        if(lc != -1) {
            t = new Node;
            t->data = lc;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }
        int rc;
        // cout << "Enter right child's value of " << p->data << " : ";
        cin >> rc;
        if(rc != -1) {
            t = new Node;
            t->data = rc;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.push(t);
        }
    }
}

void tree :: PreOrder(Node* p) {
    if(p) {
        cout << p->data << " ";
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

// void tree :: PreOrder(Node* p) {
//     stack<Node*>stk;
//     while(p || !stk.empty()) {
//         if(p) {
//             cout << p->data << " ";
//             stk.push(p);
//             p = p->lchild;
//         }else {
//             p = stk.top();
//             stk.pop();
//             p = p->rchild;
//         }
//     }
// }

void tree :: InOrder(Node* p) {
    if(p) {
        InOrder(p->lchild);
        cout << p->data << " ";
        InOrder(p->rchild);
    }
}

// void tree :: InOrder(Node* p) {
//     stack<Node*>stk;
//     while(p || !stk.empty()) {
//         if(p) {
//             stk.push(p);
//             p = p->lchild;
//         }else {
//             p = stk.top();
//             cout << p->data << " ";
//             stk.pop();
//             p = p->rchild;
//         }
//     }
// }

void tree :: PostOrder(Node* p) {
    if(p) {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout << p->data << " ";
    }
}

void tree :: LevelOrder() {
    queue<Node*>q;
    if(root->data != -1) {
        cout << root->data << " ";
        q.push(root);
    }
    Node *p, *t;
    while(!q.empty()) {
        p = q.front();
        q.pop();
        if(p->lchild) {
            t = p->lchild;
            cout << t->data << " ";
            q.push(t);
        }
        if(p->rchild) {
            t = p->rchild;
            cout << t->data << " ";
            q.push(t);
        }
    }
}
int tree :: height(Node* p) {
    int x,y;
    if(p) {
        x = height(p->lchild);
        y = height(p->rchild);
        return max(x,y) + 1;
    }
    return -1;
}

int tree :: count(Node* p) {
    int x,y;
    if(p) {
        x = count(p->lchild);
        y = count(p->rchild);
        return x+y+1;
    }
    return 0;
}
int main() {
    tree t;
    t.create();
    t.PreOrder();
    cout << endl;
    t.InOrder();
    cout << endl;
    t.PostOrder();
    cout << endl;
    t.LevelOrder();
    cout << endl;
    cout << t.height() <<  " " << t.count();
    return 0;
}