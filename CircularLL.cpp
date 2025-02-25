#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
}*head = NULL;

void createLL(vector<int>arr, int n) {
    head = new Node;
    head->data = arr[0];
    head->next = head;
    Node* prev = head;
    for(int i=1; i<n; i++) {
        Node* t = new Node;
        t->data = arr[i];
        t->next = prev->next;
        prev->next = t;
        prev = t;
    }
}
void displayCLL(Node* p) {
    do {
        cout << p->data << " -> ";
        p = p->next;
    }while(p != head);
}
int count(Node* p) {
    int count = 0;
    do {
        count++;
        p = p->next;
    }while(p!=head);
    return count;
}
void display_rec(Node* p) {
    static int flag = 0;
    if(p!=head || flag == 0) {
        flag = 1;
        cout << p->data << " -> ";
        display_rec(p->next);
    }
    flag = 0;
    //if we don't make it 0 again and we call it multiple time 
    //then we will get error after one time
    //because for whole program static int will remain same
}
void insert(Node* p, int x, int pos) {
    if(pos == 0) {
        Node* t = new Node;
        t->data = x;
        if(head == NULL) {
            head = t;
            head->next = head;
        }else {
        while(p->next != head) {
            p = p->next;
        }
        p->next = t;
        t->next = head;
        head = t;
        }
    }else {
        pos = pos%count(head);
        Node* t = new Node;
        t->data = x;
        for(int i=0; i<pos-1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t; 
    }
}
void deleting(Node *p, int pos) {
    if(head == NULL) return;
    if(pos == 0) {
        while(p->next!=head) {
            p = p->next;
        }
        if(p == head) {
            delete head;
            head = NULL;
        }else {
        p->next = head->next;
        Node* q = head;
        head = head->next;
        delete q;
        } 
    }else {
        for(int i=0; i<pos-2; i++) {
            p = p->next;
        }
        Node* q = p->next;
        p->next = q->next;
        delete q;
    }
}
int main() {
    vector<int>arr = {1,2,3,4,5};
    createLL(arr,5);
    // insert(head,7,9);
    // deleting(head,0);
    displayCLL(head);
    cout << endl;
    return 0;
}