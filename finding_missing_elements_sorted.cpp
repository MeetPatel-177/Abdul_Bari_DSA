#include <bits/stdc++.h>
using namespace std;
//use sum approach
void from_1_to_n(vector<int>arr) {
    int n = arr.size();
    int last = arr[n-1];
    int sum  = 0;
    //O(n)
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    cout << "Missing number is : ";
    cout << last*(last+1)/2 - sum << endl;
}
//play with indices
void randomsingle(vector<int>arr) {
    int diff = arr[0];
    int n = arr.size();
    cout << "Missing number is : ";
    for(int i=0; i<n; i++) {
        if(arr[i]-i != diff) {
            cout << i+diff << endl;
            break;
        }
    }
}
//if any two or more consecutive numbers are missing then we need
//a while loop
//the condition that above function has is already checked for while loop
void randommultiple(vector<int>arr) {
    int diff = arr[0];
    int n = arr.size();
    cout << "Missing numbers are : ";
    //O(n)
    for(int i=0; i<n; i++) {
        while(diff < arr[i]-i) {
            cout << i+diff << " ";
            diff++;
        }
    }
}

int main() {
    vector<int>arr1 = {1,2,3,4,5,6,8,9};
    vector<int>arr2 = {6,7,8,9,10,12,13,14};
    vector<int>arr3 = {10,11,12,13,14,16,17,20,22,23};
    from_1_to_n(arr1);
    randomsingle(arr2);
    randommultiple(arr3);
    return 0;
}
// TC -> O(n) we generally avoid while loop's time because it will
//take very less time in comparison with O(n)
// SC -> O(1)