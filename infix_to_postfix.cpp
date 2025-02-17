#include <bits/stdc++.h>
using namespace std;

int isOperand(char x) {
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '('
       || x == ')' || x == '~') {
        return 0;
       }else {
        return 1;
       }
}

int out_stack_pre(char x) {
    if(x == '+' || x == '-') return 1;
    else if(x == '*' || x == '/') return 3;
    else if(x == '^') return 6;
    else if(x == '~') return 8;
    else if(x == '(') return 9;
    else if(x == ')') return 0;
    return 0;
}

int in_stack_pre(char x) {
    if(x == '+' || x == '-') return 2;
    else if(x == '*' || x == '/') return 4;
    else if(x == '^') return 5;
    else if(x == '~') return 7;
    else if(x == '(') return 0;
    return 0;
}

string infix_to_postfix(string s) {
    stack<char>stk;
    string ans = "";
    for(int i=0; s[i]!='\0'; i++) {
        if(isOperand(s[i])) {
            ans += s[i];
        }else {
            if(stk.empty()) stk.push(s[i]);
            else {
                if(s[i] == ')') {
                    while(!stk.empty() && stk.top() != '(') {
                        ans += stk.top();
                        stk.pop();
                    }
                    stk.pop();
                }
                if(out_stack_pre(s[i]) > in_stack_pre(stk.top())) {
                    stk.push(s[i]);
                }else {
                    while(!stk.empty() && 
                            out_stack_pre(s[i]) <= in_stack_pre(stk.top())) {
                        ans += stk.top();
                        stk.pop();
                    }
                    stk.push(s[i]);
                }
            }
        }
    }
    while(!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }
    return ans;
}
int main() {
    string s = "a+b*c-d^e^f";
    cout << infix_to_postfix(s);
    return 0;
}