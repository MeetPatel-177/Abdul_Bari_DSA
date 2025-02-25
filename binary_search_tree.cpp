#include <bits/stdc++.h>
using namespace std;

class Node {
    public :
    Node* lchild;
    int data;
    Node* rchild;
    Node() {

    }
    Node(int x) {
        data = x;
        lchild = rchild = NULL;
    }
};

class BST {
    private : 
    Node* root;
    public : 
    BST() {
        root = NULL;
    }
    BST(int x) {
        root = new Node;
        root->data = x;
        root->lchild = root->rchild = NULL;
    }
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
        return height(root);
    }
    int height(Node *p);
    int count() {
        return count(root);
    }
    int count(Node* p);
    Node* search(int x) {
        return search(root,x);
    }
    Node* search(Node* p,int x);
    Node* Rsearch(int x) {
       return Rsearch(root,x);
    }
    Node* Rsearch(Node* p,int x);
    void insert(int x) {
        if(root == NULL) {
            root = new Node;
            root->data = x;
            root->lchild = root->rchild = NULL;
            return;
        }
        insert(root,x);
    }
    void insert(Node* p, int x);
    void Rinsert(int x) {
        root = Rinsert(root,x);
    }
    Node* Rinsert(Node* p, int x);
    void deleting(int x) {
        root = deleting(root,x);
    }
    Node* deleting(Node* p, int x);
    Node* InPre(Node* p) {
        while(p && p->rchild) {
            p = p->rchild;
        }
        return p;
    }
    Node* InSucc(Node* p) {
        while(p && p->lchild) {
            p = p->lchild;
        }
        return p;
    }
    void BST_Generate(vector<int>preorder);
};

void BST :: PreOrder(Node* p) {
    if(p) {
        cout << p->data << " ";
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

// void BST :: PreOrder(Node* p) {
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

void BST :: InOrder(Node* p) {
    if(p) {
        InOrder(p->lchild);
        cout << p->data << " ";
        InOrder(p->rchild);
    }
}

// void BST :: InOrder(Node* p) {
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

void BST :: PostOrder(Node* p) {
    if(p) {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout << p->data << " ";
    }
}

void BST :: LevelOrder() {
    queue<Node*>q;
    if(root) {
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
int BST :: height(Node* p) {
    int x,y;
    if(p) {
        x = height(p->lchild);
        y = height(p->rchild);
        return max(x,y) + 1;
    }
    return -1;
}

int BST :: count(Node* p) {
    int x,y;
    if(p) {
        x = count(p->lchild);
        y = count(p->rchild);
        return x+y+1;
    }
    return 0;
}

Node* BST :: search(Node* p, int x) {
    while(p) {
        if(p->data > x) {
            p = p->lchild;
        }else if(p->data < x) {
            p = p->rchild;
        }else {
            return p;
        }
    }
    return NULL;
}

Node* BST :: Rsearch(Node* p, int x) {
    if(p) {
        if(p->data < x) {
           return Rsearch(p->rchild,x);
        }else if(p->data > x) {
           return Rsearch(p->lchild,x);
        }else {
            return p;
        }
    }
    return NULL;
}

void BST :: insert(Node* p,int x) {
    Node* q = NULL;
    while(p) {
        q = p;
        if(p->data < x) {
            p = p->rchild;
        }else if(p->data > x) {
            p = p->lchild;
        }else {
            cout << "Element is already there" << endl;
            return;
        }
    }
    if(q->data < x) {
        Node* t = new Node;
        t->data = x;
        t->lchild = t->rchild = NULL;
        q->rchild = t;
    }else if(q->data > x) {
        Node* t = new Node;
        t->data = x;
        t->lchild = t->rchild = NULL;
        q->lchild = t;
    }
}

Node* BST :: Rinsert(Node* p,int x) {
    if(p == NULL) {
        Node* t = new Node;
        t->data = x;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(p->data < x) {
        p->rchild = Rinsert(p->rchild,x);
    }else if(p->data > x) {
        p->lchild = Rinsert(p->lchild,x);
    }else {
        cout << "Element is Already there" << endl;
        return p;
    }
}

Node* BST :: deleting(Node* p, int x) {
    if(p == NULL) {
        cout << "Element is Not there" << endl;
        return p;
    }else {
        if(p->data > x) {
            p->lchild = deleting(p->lchild,x);
        }else if(p->data < x) {
            p->rchild = deleting(p->rchild,x);
        }else {
            if(p->lchild == NULL && p->rchild == NULL) {
                delete p;
                return NULL;
            }
            if(height(p->lchild) > height(p->rchild)) {
                Node* q = InPre(p->lchild);
                p->data = q->data;
                p->lchild = deleting(p->lchild,q->data);
            }else {
                Node* q = InSucc(p->rchild);
                p->data = q->data;
                p->rchild = deleting(p->rchild,q->data);
            }
        }
        return p;
    }
}

void BST :: BST_Generate(vector<int>preorder) {
    int n = preorder.size();
    if(n == 0) return;
    int i=0;
    root = new Node(preorder[i++]);
    Node* p = root;
    stack<Node*>stk;
    while(i < n) {
        if(preorder[i] < p->data) {
            Node* t = new Node(preorder[i]);
            p->lchild = t;
            stk.push(p);
            p = t;
            i++;
        }else {
            if(stk.empty() ? 1 : stk.top()->data > preorder[i]) {
                Node* t = new Node(preorder[i]);
                p->rchild = t;
                p = t;
                i++;
            }else {
                p = stk.top();
                stk.pop();
            }
        }
    }
}
int main() {
    BST t;
    vector<int>preorder = {30,20,10,15,25,40,50,45};
    t.BST_Generate(preorder);
    t.InOrder();
    // t.Rinsert(30);
    // t.Rinsert(40);
    // t.Rinsert(20);
    // t.Rinsert(10);
    // t.Rinsert(50);
    // t.InOrder();
    // cout << endl;
    // t.LevelOrder();
    // cout << t.count() << " " << t.height();
    // t.deleting(20);
    // t.deleting(30);
    // t.deleting(20);
    // t.deleting(40);
    // t.deleting(10);
    // t.deleting(50);
    // t.deleting(20);
    // t.insert(20);
    // t.InOrder();
    // cout << endl;
    // cout << endl;
    // Node* p = t.search(38);
    // Node* q = t.Rsearch(38);
    // cout << p;

    // cout << q;
    // if(q)
    // cout << endl << q->data;
    // else 
    // cout << endl << "Not Found";
    // t.PreOrder();
    // cout << endl;
    // t.InOrder();
    // cout << endl;
    // t.PostOrder();
    // cout << endl;
    // t.LevelOrder();
    // cout << endl;
    // cout << t.height() <<  " " << t.count();
    return 0;
}