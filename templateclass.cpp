#include <bits/stdc++.h>
using namespace std;

template<class T>
class Arithmatic {
    private :
    T a;
    T b;
    public :
    Arithmatic<T> (T a, T b) {
        this->a = a;
        this->b = b;
    }
    T add() {
        return a+b;
    }
    T sub() {
        return a-b;
    }
};

int main() {
    
    Arithmatic<float> ar(5.5,3.4);
    cout << ar.add() << endl;
    cout << ar.sub() << endl;
    return 0;
}