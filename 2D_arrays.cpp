#include <bits/stdc++.h>
using namespace std;

int main() {
    //direct approach all inside stack
    int A[3][4];
    for(int i=0; i<3; i++) {
        for(int j=0; j<4; j++) {
            A[i][j] = i*j;
        }
    }
    for(int i=0; i<3; i++) {
        for(int j=0; j<4; j++) {
           cout << A[i][j] << " ";
        }
        cout << endl;
    }
    //an array of pointers for all rows will be created
    //array of pointers will be created inside stack but for all 
    //columns arrays will be created inside heap
    int *B[3];
    // B[0] = new int[4];
    // B[1] = new int[4];
    // B[2] = new int[4];
    for(int i=0; i<3; i++) {
        B[i] = new int[4];
    }
    for(int i=0; i<3; i++) {
        for(int j=0; j<4; j++) {
            B[i][j] = i*j;
        }
    }
    for(int i=0; i<3; i++) {
        for(int j=0; j<4; j++) {
           cout << B[i][j] << " ";
        }
        cout << endl;
    }
    //only a double pointer is created inside stack and all other things
    //will be created inside heap 
    int **C;
    C = new int *[3];
    for(int i=0; i<3; i++) {
        C[i] = new int[4];
    }
    for(int i=0; i<3; i++) {
        for(int j=0; j<4; j++) {
            C[i][j] = i*j;
        }
    }
    for(int i=0; i<3; i++) {
        for(int j=0; j<4; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}