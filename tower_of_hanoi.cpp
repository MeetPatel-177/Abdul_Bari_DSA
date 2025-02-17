#include <bits/stdc++.h>
using namespace std;

//tower_of_hanoi 
//from a to c using b and n is the number of disks that we want to transfer
//will take 2^(n+1)-1 calls for any n so O(2^n) TC will be consumed
void toh(int n, int a, int b, int c) {
    if(n > 0) {
        toh(n-1,a,c,b);
        cout << "from " << a << " to " << c << endl;
        toh(n-1,b,a,c);
    }
}

int main() {
    int n;
    cin >> n;
    //it will print approx 2^n lines in output for any n
    
    toh(n,1,2,3);
    return 0;
}