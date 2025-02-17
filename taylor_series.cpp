#include <bits/stdc++.h>
using namespace std;
//will take O(n2) multiplications so hard to use
float taylorrecursive(int x, int n) {
    if(n == 0) {
        return 1;
    }
    static float p=1,f=1;
    float r = taylorrecursive(x,n-1);
    p *= x;
    f *= n;
    return r + p/f;
}
//will also use O(n2) multiplications so hard to use
float tayloriterative(int x, int n) {
    float s = 0;
    static float p=1,f=1;
    for(int i=1; i<=n; i++) {
        s = s + p/f;
        p *= x;
        f *= i;
    }    
    return s;
}
//will use only O(n) multiplications so easy in compare to above two
float horneriterative(int x, int n) {
    float s = 1;
    for(; n>0; n--) {
        s = 1 + s*x/n;
    }
    return s;
}
//will use only O(n) multiplications so easy in compare to above two
float hornerrecursive(int x, int n) {
    static float s = 1;
    if(n == 0) {
        return s;
    }
    s = 1 + s*x/n;
    return hornerrecursive(x,n-1);
}

int main() {
    
    float a = taylorrecursive(2,15);
    cout << a << endl;
    float b = tayloriterative(2,15);
    cout << b << endl;
    float c = horneriterative(2,15);
    cout << c << endl;
    float d = hornerrecursive(2,15);
    cout << d << endl;
    return 0;
}