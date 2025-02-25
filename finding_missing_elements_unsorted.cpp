#include <bits/stdc++.h>
using namespace std;

void method1(vector<int>arr, int maxi, int n) {
    cout << "Missing numbers are : ";
    for(int i=1; i<maxi; i++) {
        int found = 0;
        for(int j=0; j<n; j++) {
            if(arr[j] == i) {
                found = 1;
                break;
            }
        }
        if(!found) {
            cout << i << " ";
        }
    }
}

void method2(vector<int>arr,int maxi, int n) {
    vector<int>hashh(maxi+1,0);
    //hashing take elements in O(1)
    //O(n) for traversing in arr and copying in hashh
    for(int it : arr) {
        hashh[it] = 1;
    }
    cout << "Missing numbers are : ";
    for(int i=1; i<maxi+1; i++) {
        if(hashh[i] == 0) {
            cout << i << " ";
        }
    }
}

int main() {
    vector<int>arr = {1,5,3,2,7,9,6,4,10,12,11,16,14,19,22,21};
    int n = arr.size();
    int maxi = arr[0];
    //O(n)
    for(int it : arr) {
        if(it > maxi) {
            maxi = it;
        }
    }
    method1(arr,maxi,n);
    cout << endl;
    method2(arr,maxi,n);
}
//method 1 - TC -> O(n^2) & SC -> O(1)
//method 2 - TC -> O(n) & SC ->O(maxi)
//In today's computers we are not much worried about space so we prefer
//to use hashhing method over O(n^2) method