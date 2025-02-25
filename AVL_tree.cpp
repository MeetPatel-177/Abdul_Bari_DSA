#include <bits/stdc++.h>
using namespace std;

class Node {
    public :
    Node* lchild;
    int data;
    int height;
    Node* rchild;
    Node(int x) {
        lchild = rchild = NULL;
        data = x;
        height = 1;
    }
};

class AVL {
    public :
    Node* root;
    AVL() {
        root = NULL;
    }
    void insert(int x) {
        root = insert(root,x);
    }
    Node* insert(Node* p, int x);
    int height(Node* p) {
        return p ? p->height : 0;
    }
    int BalanceFactor(Node* p) {
        return p ? (height(p->lchild) - height(p->rchild)) : 0;
    }
    void InOrder() {
        InOrder(root);
        cout << endl;
    }
    void InOrder(Node* p);
    Node* LLRotation(Node* p);
    Node* LRRotation(Node* p);
    Node* RRRotation(Node* p);
    Node* RLRotation(Node* p);
    Node* Delete(Node* p,int x);
    Node* InPre(Node* p);
    Node* InSucc(Node* p);
};

Node* AVL ::InPre(Node* p) {
    while(p && p->rchild) {
        p = p->rchild;
    }
    return p;
}

Node* AVL ::InSucc(Node* p) {
    while(p && p->lchild) {
        p = p->lchild;
    }
    return p;
}

void AVL :: InOrder(Node* p) {
    if(p) {
        InOrder(p->lchild);
        cout << p->data << " ";
        InOrder(p->rchild);
    }
}

Node* AVL ::LLRotation(Node* p) {
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = max(height(p->lchild),height(p->rchild)) + 1;
    pl->height = max(height(pl->lchild),height(pl->rchild)) + 1;

    if(p == root) {
        root = pl;
    }
    return pl;
}

Node* AVL ::LRRotation(Node* p) {
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    p->height = max(height(p->lchild),height(p->rchild)) + 1;
    pl->height = max(height(pl->lchild),height(pl->rchild)) + 1;
    plr->height = max(height(plr->lchild),height(plr->rchild)) + 1;
    if(p == root) {
        root = plr;
    }
    return plr;
}

Node* AVL ::RRRotation(Node* p) {
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = max(height(p->lchild),height(p->rchild)) + 1;
    pr->height = max(height(pr->lchild),height(pr->rchild)) + 1;

    if(p == root) {
        root = pr;
    }
    return pr;
}

Node* AVL ::RLRotation(Node* p) {
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;

    prl->lchild = p;
    prl->rchild = pr;

    p->height = max(height(p->lchild),height(p->rchild)) + 1;
    pr->height = max(height(pr->lchild),height(pr->rchild)) + 1;
    prl->height = max(height(prl->lchild),height(prl->rchild)) + 1;

    if(p == root) {
        root = prl;
    }
    return prl;
}

Node* AVL :: insert(Node* p, int x) {
    if(p == NULL) {
        Node* t = new Node(x);
        if(root == NULL) root = t;
        return t;
    }
    if(p->data > x) {
        p->lchild = insert(p->lchild,x);
    }else if(p->data < x) {
        p->rchild = insert(p->rchild,x);
    }else {
        cout << "element is already there" << endl;
        return p;
    }
    p->height = max(height(p->lchild),height(p->rchild)) + 1;
    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {
        return LLRotation(p);
    }
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1) {
        return LRRotation(p);
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1) {
        return RLRotation(p);
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1) {
        return RRRotation(p);
    }
    return p;
}

Node* AVL ::Delete(Node* p,int x) {
    if(p == NULL) {
        cout << "Element is Not There" << endl;
        return NULL;
    }
    if(p->lchild == NULL && p->rchild == NULL) {
        if(p == root) {
            root = NULL;
        }
        delete p;
        p = NULL;
        return NULL;
    }
    Node* q = NULL;
    if(p->data > x) {
        p->lchild = Delete(p->lchild,x);
    }else if(p->data < x) {
        p->rchild = Delete(p->rchild,x);
    }else {
        if(height(p->lchild) > height(p->rchild)) {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild,q->data);
        }else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild,q->data);
        }
        p->height = max(height(p->lchild),height(p->rchild)) + 1;
        if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {
            return LLRotation(p);
        }
        else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1) {
            return LRRotation(p);
        }
        else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1) {
            return RLRotation(p);
        }
        else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1) {
            return RRRotation(p);
        }
        return p;
    }
}

int main() {
    AVL t;
    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(25);
    t.insert(28);
    t.insert(27); 
    t.insert(5);
    t.Delete(t.root,17);
    t.Delete(t.root,10);
    t.Delete(t.root,15);
    t.Delete(t.root,20);
    t.Delete(t.root,40);
    t.Delete(t.root,30);
    t.Delete(t.root,25);
    // t.Delete(t.root,27);
    t.InOrder();
    cout << t.root->data;
    // t.insert(30);
    // t.insert(27);
    // t.insert(10);
    // t.insert(5);
    // t.insert(3);
    // t.insert(50);
    // t.insert(30);
    // t.insert(40);
    
    
    cout << " " << t.height(t.root);
    return 0;
}