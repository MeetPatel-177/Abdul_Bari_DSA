#include <bits/stdc++.h>
using namespace std;

//TC -> O(n^2) & SC -> O(1)
void method1(vector<int>arr,int n) {
     for(int i=0; i<n; i++) {
        int count = 1;
        if(arr[i] != -1) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                arr[j] = -1;
            }
        }
    }
        if(count > 1) {
            cout << arr[i] << " -> " << count << endl;
        }
    }
}
//TC -> O(n) & SC -> O(maxi)
void method2(vector<int>arr,int n) {
    int maxi = arr[0];
    for(int it : arr) {
        if(it > maxi) {
            maxi = it;
        }
    }
    vector<int>hashh(maxi+1,0);
    for(int it : arr) {
        hashh[it] ++;
    }
    for(int i=0; i<maxi+1; i++) {
        if(hashh[i] > 1) {
            cout << i << " -> " << hashh[i] << endl;
        }
    }
}

int main() {
    vector<int>arr = {8,3,6,4,6,5,6,8,2,7};
    int n = arr.size();
    method1(arr,n);
    cout << endl;
    method2(arr,n);
    return 0;
}
//when the array is unsorted hashing is useful and preferable but 
//not when it is sorted