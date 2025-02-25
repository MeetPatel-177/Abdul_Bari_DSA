#include <bits/stdc++.h>
using namespace std;

class Node {
    public : 
    int data;
    Node *next;
};

class stackk {
    private : 
    Node* top;
    public : 
    stackk() {
        top = NULL;
    }
    void push(int x);
    void pop();
    int stacktop();
    void display();
    int peek(int ind);
    int count();
};

void stackk :: push(int x) {
        Node* t = new Node;
        if(t != NULL) {
        t->data = x;
        t->next = top;
        top = t;
        }else {
            cout << "Stack Overflow" << endl;
        }
}

void stackk :: pop() {
    if(top == NULL) {
        cout << "Stack Underflow" << endl;
    }else {
        Node* t = top;
        top = top->next;
        delete t;
    }
}

int stackk :: stacktop() {
    if(top == NULL) {
        return -1;
    }else {
        return top->data;
    }
}

void stackk :: display() {
    Node* t = top;
    while(t) {
        cout << t->data << endl;
        t = t->next;
    }
}

int stackk :: count() {
    int count = 0;
    Node* t = top;
    while(t) {
        count++;
        t = t->next;
    }
    return count;
}

int stackk :: peek(int ind) {
    Node* t = top;
    if(ind < 1 || ind > count()) {
        return -1;
    }
    for(int i=0; i<ind-1; i++) {
        t = t->next;
    }
    return t->data;
}
int main() {
    stackk stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    // cout << stk.stacktop();
    // stk.display();
    cout << stk.peek(8);
    return 0;
}