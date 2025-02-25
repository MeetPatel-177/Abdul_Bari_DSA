#include <bits/stdc++.h>
using namespace std;

class queuee {
    private :
    int cursize = 0;
    int size;
    int front;
    int back;
    int *q;
    public :
    queuee() {
        q = NULL;
        front = -1;
        back = -1;
        size = 0;
    }
    queuee(int sz) {
        size = sz;
        q = new int[sz];
        front = -1;
        back = -1;
    }
    ~queuee() {
        delete []q;
    }
    void push(int x);
    void pop();
    void display();
    int first();
    int last();
};

void queuee :: push(int x) {
    if(cursize <= size-1) {
    back++;
    q[back] = x;
    cursize++;
    cout << "element added" << endl;
    }else {
        cout << "queue is Full" << endl;
    }
}

void queuee :: pop() {
    if(front != back) {
        front++;
        cursize--;
        if(front == back) {
            back = front = -1;
        }
        cout << "element deleted" << endl;
    }else {
        cout << "queue is empty" << endl;
    }
}

void queuee :: display() {
    if(front == back) {
        cout << "q is empty" << endl;
        return;
    }
    int ptr = front;
    while(ptr != back) {
        ptr++;
        cout << q[ptr] << " ";
    }
    cout << endl;
}

int queuee :: first() {
    if(front != back) {
        int ptr = front;
        return q[++ptr];
    }else {
        return -1;
    }
}

int queuee :: last() {
    if(back != -1) {
        return q[back];
    }else {
        return -1;
    }
}
int main() {
    queuee q(5);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    // q.push(8);
    // q.push(1);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    // q.push(5);
    q.pop();
    q.push(4);
    // q.push(5);
    // q.pop();
    // q.pop();
    q.display();
    cout << q.first() << " " << q.last();
    return 0;
}