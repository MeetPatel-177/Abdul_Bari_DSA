#include <bits/stdc++.h>
using namespace std;

//TC -> O(n) & SC -> O(1)
void method1(vector<int>arr,int n) {
    int i=0;
    while(i<n) {
        int count = 1;
        while(arr[i] == arr[i+1]) {
            count++;
            i++;
        }
        cout << arr[i] << " -> " << count << endl;
        i++;
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
        if(hashh[i] >= 1) {
            cout << i << " -> " << hashh[i] << endl;
        }
    }
}
int main() {
    vector<int>arr = {1,1,2,2,3,4,5,6,7,7,7,8,9,10,11,11,11,11,14};
    int n = arr.size();
    method1(arr,n);
    cout << endl;
    method2(arr,n);
    return 0;
}
//For sorted array, hashhing is not preferable