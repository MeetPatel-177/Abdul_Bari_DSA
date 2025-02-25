#include <bits/stdc++.h>
using namespace std;
//O(m+n) == O(2n) == O(n)
vector<int> merge(vector<int>a,vector<int>b) {
    int i=0,j=0,k=0;
    int n = a.size();
    int m = b.size();
    vector<int>c(m+n,0);
    while(i < n && j < m) {
        if(a[i] < b[j]) {
            c[k] = a[i];
            i++;
            k++;
        }else {
            c[k] = b[j];
            j++;
            k++;
        }
    }
    while(i < n) {
        c[k] = a[i];
        i++;
        k++;
    }
    while(j < m) {
        c[k] = b[j];
        k++;
        j++;
    }
    return c;
}
//O(m + m*n) == O(m*n) == O(n^2)
vector<int> unionn(vector<int>a,vector<int>b) {
    vector<int>c;
    for(int it : a) {
        c.push_back(it);
    }
    for(int it : b) {
        int found = 0;
        for(int it1 : a) {
            if(it == it1) {
                found = 1;
                break;
            }
        }
        if(!found) c.push_back(it);
    }
    return c;
}
//if we have two sorted arrays then
//O(m+n) == O(2n) == O(n)
vector<int> unionsorted(vector<int>a,vector<int>b) {
    int i=0,j=0;
    vector<int>c;
    int n = a.size(),m = b.size();
    while(i < n && j < m) {
        if(a[i] < b[j]) {
            c.push_back(a[i++]);
        }else if(a[i] > b[j]) {
            c.push_back(b[j++]);
        }else {
            c.push_back(a[i++]);
            j++;
        }
    }
    while(i < n) {
        c.push_back(a[i++]);
    }
    while(j < m) {
        c.push_back(b[j++]);
    }
    return c;
}
//O(m*n) == O(n*n) == O(n^2)
vector<int> intersection(vector<int>a, vector<int>b) {
    vector<int>c;
    for(int it : a) {
        for(int it1 : b) {
            if(it == it1) {
                c.push_back(it);
                break;
            }
        }
    }
    return c;
}
//O(m+n) == O(2n) == O(n)
vector<int> intersectionsorted(vector<int>a, vector<int>b) {
    int i=0,j=0;
    vector<int>c;
    int n = a.size(), m = b.size();
    while(i < n && j < m) {
        if(a[i] == b[j]) {
            c.push_back(a[i]);
            i++;
            j++;
        }else if(a[i] < b[j]) {
            i++;
        }else {
            j++;
        }
    }
    return c;
}
//O(m*n) == O(n^2)
vector<int> difference(vector<int>a, vector<int>b) {
    vector<int>c;
    for(int it : a) {
        int found = 0;
        for(int it1 : b) {
            if(it == it1) {
                found = 1;
                break;
            }
        }
        if(!found) c.push_back(it);
    }
    return c;
}
//O(m+n) == O(n)
vector<int> differencesorted(vector<int>a, vector<int>b) {
    int i=0,j=0;
    vector<int>c;
    int n = a.size(), m = b.size();
    while(i < n && j < m) {
        if(a[i] < b[j]) {
            c.push_back(a[i++]);
        }else if(a[i] > b[j]){
            j++;
        }else {
            i++;
            j++;
        }
    }
    while(i < n) {
        c.push_back(a[i++]);
    }
    return c;
    
}

int main() {
    vector<int>a = {1,4,6,8,9,12,14,16};
    vector<int>b = {2,4,6,8,10};

    vector<int>c = merge(a,b);
    vector<int>d = unionn(a,b);
    vector<int>e = unionsorted(a,b);
    vector<int>f = intersection(a,b);
    vector<int>g = intersectionsorted(a,b);
    vector<int>h = difference(a,b);
    vector<int>i = differencesorted(a,b);
    for(int it : a) {
        cout << it << " ";
    }
    cout << endl;
    for(int it : b) {
        cout << it << " ";
    }
    cout << endl;
    for(int it : i) {
        cout << it << " ";
    }
    return 0;
}