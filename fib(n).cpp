#include <bits/stdc++.h>
using namespace std;

//will take O(2^n) as it will make approximately 2^n calls for any n
int fibrecursive(int n) {
    if(n <= 1) {
        return n;
    }
    return fibrecursive(n-2) + fibrecursive(n-1);
}

//will take O(n) as only one for loop is running in this full function
int fibiterative(int n) {
    int t0 = 0, t1 = 1, s;
    if(n <= 1) {
        return n;
    }
    for(int i=2; i<=n; i++) {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}


int fib(int n, vector<int>& arr) {
    if(n <= 1) {
        arr[n] = n;
        return n;
    }
    if(arr[n-2] == -1) {
        arr[n-2] = fib(n-2,arr);
    }
    if(arr[n-1] == -1) {
        arr[n-1] = fib(n-1,arr);
    }
    return arr[n-2] + arr[n-1];
}

int main() {
    int n;
    cin >> n;
    vector<int>arr(n,-1);
    int a = fibrecursive(n);
    cout << a << endl;
    int b = fibiterative(n);
    cout << b << endl;
    int c = fib(n,arr);
    cout << c << endl;
    return 0;
}