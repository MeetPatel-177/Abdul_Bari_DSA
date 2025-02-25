#include <bits/stdc++.h>
using namespace std;

class Node {
    public :
    int data;
    Node* next;
};

class queuee {
    private : 
    Node* front;
    Node* back;
    public :
    queuee() {
        front = back = NULL;
    }
    void push(int x);
    void pop();
    void display();
    int first();
    int last();
};

void queuee :: push(int x) {
    if(front == NULL) {
        front = new Node;
        front->data = x;
        front->next = NULL;
        back = front;
    }else {
        Node* t = new Node;
        if(t == NULL) {
            cout << "queue is full" << endl;
            return;
        }
        t->data = x;
        t->next = NULL;
        back->next = t;
        back = t;
    }
}

void queuee :: pop() {
    if(front == NULL) {
        cout << "queue is empty" << endl;
        return;
    }
    Node* t = front;
    front = front->next;
    delete t;
    if(front == NULL) {
        back = NULL;
    }
}

void queuee :: display() {
    Node* p = front;
    while(p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int queuee :: first() {
    if(front == NULL) {
        return -1;
    }
    return front->data;
}

int queuee :: last() {
    if(back == NULL) {
        return -1;
    }
    return back->data;
}

int main() {
    queuee q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    // q.push(8);
    // q.push(1);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.push(5);
    q.pop();
    // q.push(4);
    // q.push(5);
    // q.pop();
    // q.pop();
    q.display();
    cout << q.first() << " " << q.last();  
    return 0;
}