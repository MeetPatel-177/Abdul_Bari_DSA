#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* prev;
    int data;
    Node* next;
}*first = NULL;

void display_forward(Node* p) {
    while(p) {
        cout << p->data << " -> ";
        p = p->next;
    }
}

void display_backward(Node* p) {
    while(p->next) {
        p = p->next;
    }
    while(p) {
        cout << p->data << " -> ";
        p = p->prev;
    }
}

int count(Node* p) {
    int count = 0;
    while(p) {
        count++;
        p = p->next;
    }
    return count;
}

void create(vector<int>arr, int n) {
    first = new Node;
    first->data = arr[0];
    first->prev = NULL;
    first->next = NULL;
    Node* last = first;
    for(int i=1; i<n; i++) {
        Node* t = new Node;
        t->data = arr[i];
        t->prev = last;
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void insert(Node* p, int x, int pos) {
    if(pos == 0) {
        Node* t = new Node;
        t->data = x;
        if(first == NULL) {
            first = t;
            first->next = NULL;
            first->prev = NULL;
        }else {
            t->next = first;
            t->prev = NULL;
            first->prev = t;
            first = t;
        }
    }else if(pos>0 && pos<=count(first)){
        Node* t = new Node;
        t->data = x;
        for(int i=0; i<pos-1; i++) {
            p = p->next;
        }
        Node* q = p->next;
        p->next = t;
        t->prev = p;
        t->next = q;
        if(q) q->prev = t;
    }
}

void deleting(Node* p, int pos) {
    if(first == NULL) return;
    if(pos == 1) {
        first = first->next;
        if(first) first->prev = NULL;
        delete p;
    }else if(pos>1 && pos<=count(first)) {
        Node* q = NULL;
        for(int i=0; i<pos-1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        if(p->next) p->next->prev = q;
        delete p;
    }
}

void reverse(Node* p) {
    while(p) {
        if(p->next == NULL) {
            first = p;
        }
        Node* temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
    }
}
int main() {
    vector<int>arr = {1,2,3,4,5};
    create(arr,5);
    // insert(first,8,0);
    // deleting(first,5);
    display_forward(first);
    cout << endl;
    // display_backward(first);  
    cout << endl;
    reverse(first);
    display_forward(first);
    cout << endl;
    display_backward(first);
    return 0;
}