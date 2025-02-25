#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
}*first = NULL, *second=NULL, *third=NULL;//this first will be declared globally

void create(vector<int>arr, int n) {
    first = new Node;
    first->data = arr[0];
    first->next = NULL;
    Node *temp = NULL;
    Node *prev = first;
    for(int i=1; i<n; i++) {
        temp = new Node;
        temp->data = arr[i];
        temp->next = NULL;
        prev->next = temp;
        prev =  temp;
    }
}
//using loop O(n) TC and O(1) SC
void display1(Node* ptr) {
    while(ptr != NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
}
//using recursion O(n) TC and O(n) SC 
void display2(Node* ptr) {
    if(ptr == NULL) {
        return;
    }
    cout << ptr->data << " -> ";
    display2(ptr->next);
}
//will display in reverse order as it first calls and then prints
void reverse_display(Node* ptr) {
    if(ptr == NULL) {
        return;
    }
    reverse_display(ptr->next);
    cout << ptr->data << " -> ";
}

int count_node(Node* ptr) {
    int count = 0;
    while(ptr) {
        count++;
        ptr = ptr->next;
    }
    return count;
}
int count_node2(Node* ptr) {
    if(ptr == NULL) {
        return 0;
    }
    return count_node2(ptr->next) + 1;
}

int sum(Node* ptr) {
    int sum = 0;
    while(ptr) {
        sum += ptr->data;
        ptr = ptr->next;
    }
    return sum;
}

int sum_rec(Node* ptr) {
    if(ptr != NULL) {
        return ptr->data + sum_rec(ptr->next);
    }
    return 0;
}

int max(Node* ptr) {
    int max = ptr->data;
    while(ptr) {
        if(ptr->data > max) {
            max = ptr->data;
        }
        ptr = ptr->next;
    }
    return max;
}

int max_rec(Node* ptr) {
    int x = 0;
    if(ptr == NULL) {
        return INT_MIN;
    }
    x = max_rec(ptr->next);
    if(x > ptr->data) {
        return x;
    }else {
        return ptr->data;
    }
}

Node* search(Node* ptr, int target) {
    while(ptr) {
        if(ptr->data == target) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

Node* search_rec(Node* ptr, int target) {
    if(ptr == NULL) return NULL;
    if(ptr->data == target) return ptr;
    return search_rec(ptr->next,target);
}

Node* search_move_to_first(Node* p, int target) {
    Node* q = NULL; 
    while(p) {
        if(p->data == target) {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}
//will work for every condition so no need to check conditions all times
void insert(Node* p,int x, int pos) {
    Node* t;
    if(pos == 0) {
        t = new Node;
        t->data = x;
        t->next = first;
        first = t;
    }else if(pos>0 && pos<=count_node(p)) {
        for(int i=0; i<pos-1; i++) {
            p = p->next;
        }
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }else {
        cout << "Position is not valid" << endl;
    }
}
//if we want to create LL without arrays
void createLL(Node* p, int x) {
    Node* t = new Node;
    t->data = x;
    t->next = NULL;
    Node* last = p;
    if(first == NULL) {
        first = last = t;
    }else {
    last->next = t;
    last = t;
    }
}

void insertsorted(Node* p, int x) {
    Node* t = new Node;
    t->data = x;
    t->next = NULL;
    Node* q = NULL;
    if(first == NULL) {
        first = t;
    }else {
        while(p && p->data < x) {
            q = p;
            p = p->next;
        }
        if(p == first) {
            t->next = first;
            first = t;
        }else {
            t->next = q->next;
            q->next = t;
        }
    }
}

void deleting(Node* p, int pos) {
    if(pos == 1) {
        Node* t = first;
        first = first->next;
        delete t;   
    }else if(pos > 1 && pos <= count_node(first)) {
        Node *q = NULL;
        for(int i=0; i<pos-1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p;
    }
}

int issorted(Node* p) {
    int x = -1;
    while(p) {
        if(p->data < x) {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

void removedups(Node* p) {
    if(p == NULL) return;
    Node* q = p->next;
    while(q) {
        if(p->data != q->data) {
            p = q;
            q = q->next;
        }else {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void reversing_by_elements(Node* p) {
    vector<int>arr(count_node(first));
    int i=0;
    while(p) {
        arr[i++] = p->data;
        p = p->next;
    }
    p = first;
    i--;
    while(p) {
        p->data = arr[i--];
        p = p->next;
    }
}
void reversing_by_links(Node* p) {
    Node *q, *r;
    q = r = NULL;
    while(p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reversing_recursively(Node* p, Node* q) {
    if(p != NULL) {
        reversing_recursively(p->next,p);
        p->next = q;
    }else {
        first = q;
    }
}

int main() {
    
    // vector<int>arr = {1,2,3,4,18,6,7};
    // int n = arr.size();
    // create(arr,n);
    // display1(first);
    // cout << endl;
    // reverse_display(first);
    // cout << endl << count_node(first);
    // cout << endl << count_node2(first);
    // cout << endl << sum(first);
    // cout << endl << sum_rec(first);
    // cout << endl << max(first);
    // cout << endl << max_rec(first);
    // cout << endl << search(first,18);
    // cout << endl << search_rec(first,18);
    // cout << endl << search_move_to_first(first,18);
    // insert(first,32,2);
    // cout << endl;
    // display1(first);
    // cout << endl;
    // insert(first,4,10);
    // display1(first);
    // insertsorted(first,3);
    // insertsorted(first,5);
    // insertsorted(first,5);
    // insertsorted(first,8);
    // insertsorted(first,8);
    // insertsorted(first,8);
    
    // display1(first);
    // cout << endl;
    // reversing_recursively(first,NULL);
    // display1(first);

    
        
    return 0;
}