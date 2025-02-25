#include <bits/stdc++.h>
using namespace std;
//O(n^2)
void method1(vector<int>arr,int n,int k) {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] + arr[j] == k) {
                cout << arr[i] << " " << arr[j] << endl; 
            }
        }
    }
}
//O(n) & O(maxi)
void method2(vector<int>arr,int n, int k) {
    int maxi = arr[0];
    for(int it : arr) {
        if(it > maxi) maxi = it;
    }
    vector<int>hashh(maxi+1,0);
    for(int it : arr) {
        if(hashh[k-it] == 1) {
            cout << it << " " << k-it << endl;
        }
        hashh[it] = 1;
    }
}
//O(n)
void method_for_sorted(vector<int>arr,int n, int k) {
    int i=0,j=n-1;
    while(i<j) {
        if(arr[i]+arr[j] > k) {
            j--;
        }else if(arr[i]+arr[j]<k) {
            i++;
        }else {
            cout << arr[i] << " " << arr[j] << endl;
            i++;
            j--;
        }
    }
}

int main() {
    vector<int>arr = {1,2,5,7,8,9,11,15};
    int n = arr.size();
    int k = 16;
    method1(arr,n,k);
    cout << endl;
    method2(arr,n,k);
    cout << endl;
    method_for_sorted(arr,n,k);
    return 0;
}