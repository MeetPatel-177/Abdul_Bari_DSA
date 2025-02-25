#include <bits/stdc++.h>
using namespace std;

//always give declaration of each function that will be used in indirect
//recursion otherwise 1st can't access 2nd function and will not give any
//output and will not give any errors also
void f1(int n);
void f2(int n);

void f1(int n) {
    if(n > 0) {
        cout << n << " ";
        f2(n-1);
    }
}
void f2(int n) {
    if(n > 1) {
        cout << n << " ";
        f1(n/2);
    }
}
int main() {
    f1(20);
    return 0;
}