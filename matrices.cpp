#include <bits/stdc++.h>
using namespace std;

void diagonal(vector<int>mat, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j) {
                cout << mat[i] << " ";
            }else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}
//By using row major mapping 
void lower_triangular1(vector<int>mat, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i<j) {
                cout << 0 << " ";
            }else {
                cout << mat[i*(i+1)/2 + j] << " ";
            }
        }
        cout << endl;
    }
}
//By using column major mapping 
void lower_triangular2(vector<int>mat, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i<j) {
                cout << 0 << " ";
            }else {
                cout << mat[n*(n+1)/2 - (n-j)*(n-j+1)/2 + i-j] << " ";
            }
        }
        cout << endl;
    }
}
//By using row major mapping 
void upper_triangular1(vector<int>mat, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i>j) {
                cout << 0 << " ";
            }else {
                cout << mat[n*(n+1)/2 - (n-i)*(n-i+1)/2 + j-i] << " ";
            }
        }
        cout << endl;
    }
}
//By using column major mapping 
void upper_triangular2(vector<int>mat, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i>j) {
                cout << 0 << " ";
            }else {
                cout << mat[j*(j+1)/2 + i] << " ";
            }
        }
        cout << endl;
    }
}
//by using lower triangular matrix
void symmetric1(vector<int>mat, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i<j) {
                cout << mat[j*(j+1)/2 + i] << " "; 
            }else {
            cout << mat[i*(i+1)/2 + j] << " ";
            }
        }
        cout << endl;
    }
}
//by using upper triangular matrix
void symmetric2(vector<int>mat, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i>j) {
                cout << mat[i*(i+1)/2 + j] << " "; 
            }else {
            cout << mat[j*(j+1)/2 + i] << " ";
            }
        }
        cout << endl;
    }
}
//by using row major mapping
//to use column major just change i to j and j to i
void tri_diagonal(vector<int>mat, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(abs(i-j) <= 1) {
                cout << mat[2*i + j] << " ";
            }else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}
//we only need to store one column and one row of elements 
void toeplitz(vector<int>mat, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i<=j) {
                cout << mat[j-i] << " ";
            }else {
                cout << mat[n+i-j-1] << " ";
            }
        }
        cout << endl;
    }
}
int main() {
    int n;
    cin >> n;
    //only n elements are non zero
    vector<int>mat_diagonal(n,4);
    diagonal(mat_diagonal,n);
    cout << endl;

    //1+2+3+4+...+n = n(n+1)/2 non zero elements
    vector<int>mat_lower(n*(n+1)/2,5);
    lower_triangular1(mat_lower,n);
    cout << endl;
    lower_triangular2(mat_lower,n);
    cout << endl;

    //n+n-1+n-2+...+1 = n(n+1)/2 non zero elements
    vector<int>mat_upper(n*(n+1)/2,6);
    upper_triangular1(mat_upper,n);
    cout << endl;
    upper_triangular2(mat_upper,n);
    cout << endl;
    
    return 0;
}