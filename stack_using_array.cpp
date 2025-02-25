#include <bits/stdc++.h>
using namespace std;

class stackk {
    private : 
    int size;
    int top;
    int *s;
    public :
    stackk() {
        size = 0;
        top = -1;
        s = NULL;
    }
    stackk(int sz) {
        size = sz;
        top = -1;
        s = new int[sz];
    }
    ~stackk() {
        delete []s;
        s = NULL;
    }
    void push(int x);
    void pop();
    int stacktop();
    int peek(int ind);
    void display();
};

void stackk :: push(int x) { 
    if(top != size-1) {
    top++;
    s[top] = x;
    cout << "element added " << endl;
    }else {
        cout << "Stack Overflow" << endl;
    }
}

void stackk :: pop() {
    if(top != -1) {
    top--;
    cout << "element deleted " << endl;
    }else {
        cout << "Stack Underflow" << endl;
    }
}

int stackk :: stacktop() {
    if(top != -1) return s[top];
    else return -1;
}

int stackk :: peek(int ind) {
    if(ind > top && top != -1) {
        return -1;
    }else {
        return s[top - ind];
    }
}

void stackk :: display() {
    for(int i=top; i>=0; i--) {
        cout << s[i] << endl;
    }
}

int main() {
    stackk stk(5);
    stk.push(5);
    stk.push(6);
    stk.push(7);
    stk.push(8);
    stk.push(9);
    stk.push(10);
    stk.pop();
    stk.push(10);
    stk.display();
    // stk.push(10);
    // cout << stk.stacktop();
    // stk.pop();
    // cout << stk.stacktop();
    // stk.pop();
    // stk.pop();
    // cout << stk.stacktop();
    // stk.display();
    // cout << stk.peek(0);


    return 0;
}