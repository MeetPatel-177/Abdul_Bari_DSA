#include <bits/stdc++.h>
using namespace std;

void changing_case(string s) {
    for(int i=0; s[i]!='\0'; i++) {
        if(s[i]>='A'&&s[i]<='Z') {
            s[i] += 32;
        }
        else if(s[i]>='a' && s[i]<='z') {
            s[i] -= 32;
        }
    }
    cout << s << endl;
}

void vowel_and_consonents(string s) {
    int vowel = 0, conso = 0;
    for(auto it : s) {
        if(it=='a'||it=='e'||it=='i'||it=='o'||it=='u'||
           it=='A'||it=='E'||it=='I'||it=='O'||it=='U') vowel++;
           else if((it>=65 && it<=90) || (it>=97&&it<=122)) conso++;
    }
    cout << vowel << " " << conso << endl;
}

void words(string s) {
    int words = 1;
    for(int i=1; s[i] != '\0'; i++) {
        if(s[i]==' ' && s[i-1] != ' ') {
            words++;
        }
    }
    cout << words << endl;
}
//for checking passwords with only a given range
bool valid(string s) {
    for(int i=0; s[i]!='\0';i++) {
        if(!(s[i]>='A'&&s[i]<='Z') && !(s[i]>='a'&&s[i]<='z') && !(s[i]>=
        '0'&&s[i]<='9')) {
            return false;
        }
    }
    return true;
}
//with using extra string
void rev(string s) {
    string rev = "";
    for(int i=0; s[i]!='\0'; i++) {
        rev += s[s.size()-i-1];
    }
    cout << rev << endl;
}
//without using any extra string
void rev2(string s) {
    int n = s.size();
    for(int i=0,j=n-1; i<j; i++,j--) {
        swap(s[i],s[j]);
    }
    cout << s << endl;
}

void compare(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    for(int i=0; i<n && i<m; i++) {
        if(s1[i] != s2[i]) { 
            if(s1[i]>s2[i]) {
                cout << "s1 is greater than s2" << endl;
            }else {
                cout << "s1 is less than s2" << endl;
            }
            return;
        }
    }
    cout << "s1 ans s2 are equal" << endl;
    return;
}

void palindrome(string s) {
    string rev = "";
    for(int i=0; s[i]!='\0';i++) {
        rev += s[s.size()-i-1];
    }
    if(rev == s) {
        cout << "Palindrome" << endl;
    }else {
        cout << "Not Palindrome" << endl; 
    }
}

void duplicate(string s) {
    int h = 0, x=0;
    for(int i=0; s[i]!='\0'; i++) {
        x = 1;
        x = x << (s[i]-'a');
        if((h & x) > 0) {
            cout << s[i] << " is duplicated" << endl;
        }else {
            h = h|x;
        }
    }
}
//O(n^2)
void anagram(string s1,string s2) {
    if(s1.size() != s2.size()) {
        cout << "Not Anagram" << endl;
        return;
    }

    for(int i=0; s1[i]!='\0'; i++) {
        int found = 0;
        for(int j=0; s2[j]!='\0'; j++) {
            if(s1[i] == s2[j]) {
                s2[j] = '0';
                found = 1;
                break;
            }
        }
        if(!found) {
            cout << "Not Anagram" << endl;
            return;
        }
    }
    cout << "Anagram" << endl;

}
//O(n) & O(n)
void anagram2(string s1, string s2) {
    if(s1.size() != s2.size()) {
        cout << "Not Anagram" << endl;
        return;
    }
    vector<int>hashh(26,0);
    for(auto it : s1) {
        hashh[it-'a'] ++;
    }
    for(auto it : s2) {
        hashh[it-'a'] --;
    }
    for(int it : hashh) {
        if(it != 0) {
            cout << "Not Anagram" << endl;
            return;
        }
    }
    cout << "Anagram" << endl;
}
int main() {
    string s;
    getline(cin,s);
    string s1 = "medically";
    // string s2 = "Meev";
    // if(s == s2) {
    //     cout << "equal" << endl;
    // }else if(s > s2) {
    //     cout << "s1 is greater than s2" << endl;
    // }else {
    //     cout << "s1 is smaller than s2" << endl;
    // }
    // changing_case(s);
    // vowel_and_consonents(s);
    // words(s);
    // valid(s) ? cout << "Valid" : cout << "Invalid";
    // cout << endl;
    // rev(s);
    // rev2(s);
    // compare(s,s2);
    // palindrome(s);
    // duplicate(s);
    anagram2(s,s1);
    cout << s.size();
    return 0;
}