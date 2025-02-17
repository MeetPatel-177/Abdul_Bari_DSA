#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void create1(vector<int> arr, int n)
{
    first = new Node;
    first->data = arr[0];
    first->next = NULL;
    Node *temp = NULL;
    Node *prev = first;
    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = arr[i];
        temp->next = NULL;
        prev->next = temp;
        prev = temp;
    }
}
void create2(vector<int> arr, int n)
{
    second = new Node;
    second->data = arr[0];
    second->next = NULL;
    Node *temp = NULL;
    Node *prev = second;
    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = arr[i];
        temp->next = NULL;
        prev->next = temp;
        prev = temp;
    }
}
void display(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
}
void concat(Node *p, Node *q)
{
    third = p;
    while (p->next)
    {
        p = p->next;
    }
    p->next = q;
}
void merge(Node *p, Node *q)
{
    Node *last = NULL;
    if (p->data < q->data)
    {
        last = third = p;
        p = p->next;
    }
    else
    {
        last = third = q;
        q = q->next;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
        }
    }
    if (p)
        last->next = p;
    else
        last->next = q;
}
bool checkingloop(Node *p)
{
    Node *q = p;
    while (q && q->next)
    {
        p = p->next;
        q = q->next->next;
        if (p == q)
            return true;
    }
    return false;
}
void createloop(vector<int> arr, int n)
{
    first = new Node;
    first->data = arr[0];
    first->next = NULL;
    Node *prev = first;
    for (int i = 0; i < n; i++)
    {
        Node *t = new Node;
        t->data = arr[i];
        t->next = NULL;
        prev->next = t;
        prev = t;
    }
    Node *temp = first->next->next;
    prev->next = temp;
}
int main()
{
    vector<int> arr1 = {1, 3, 5, 7, 9};
    vector<int> arr2 = {2, 4, 6, 8, 10};
    create1(arr1, 5);
    create2(arr2, 5);
    display(first);
    cout << endl;
    display(second);
    cout << endl;
    merge(first,second);
    display(third);
    return 0;
}