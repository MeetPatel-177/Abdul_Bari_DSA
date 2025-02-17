#include <bits/stdc++.h>
using namespace std;

int result(char ch, int first, int second) {
    if(ch == '+') {
        return first+second;
    }else if(ch == '-') {
        return first-second;
    }else if(ch == '*') {
        return first*second;
    }else if(ch == '/') {
        if(second != 0)
        return first/second;
        else return 0;
    }
    return 0;
}
int evaluation(string str) {
    stack<int>stk;
    for(int i=0; str[i] != '\0'; i++) {
        if(str[i]>='0' && str[i]<='9') {
            stk.push(str[i]-'0');
        }else {
            char ch = str[i];
            int second = stk.top();
            stk.pop();
            int first = stk.top();
            stk.pop();
            int res = result(ch,first,second);
            stk.push(res);
        }
    }
    return stk.top();
}
int main() {
    string str = "234*+82/-";
    cout << evaluation(str);
    return 0;
}