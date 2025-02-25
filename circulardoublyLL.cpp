#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* prev;
    int data;
    Node* next;
}*head = NULL;

void create(vector<int>arr,int n) {
    head = new Node;
    head->data = arr[0];
    head->next = head;
    head->prev = head;
    Node* last = head;
    for(int i=1; i<n; i++) {
        Node* t = new Node;
        t->data = arr[i];
        t->prev = last;
        t->next = last->next;
        last->next = t;
        last = t;
    }
    head->prev = last; 
}

void display_forward(Node* p) {
    do {
        cout << p->data << " -> ";
        p = p->next;
    }while(p != head);
}

void display_backward(Node* p) {
    do {
        p = p->prev;
        cout << p->data << " -> ";
    }while(p != head);
}
int main() {
    vector<int>arr = {1,2,3,4,5};
    create(arr,5);
    display_forward(head);
    cout << endl;
    display_backward(head);
    return 0;
}