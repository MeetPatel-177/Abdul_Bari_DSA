#include <bits/stdc++.h>
using namespace std;

double pow(double x, int n) {
    if(n == 0) {
        return 1;
    }
    if(n%2==0) {
        return pow(x*x, n/2);
    }else {
        return x*pow(x*x,n/2);
    }
}
int main() {
    double x = -2;
    int n = 9;
    if(n<0) {
        x = 1/x;
    }
    cout << pow(x,n);
    return 0;
}