#include <bits/stdc++.h>
using namespace std;

class Rectangle {
    private :
    int length;
    int breadth;
    public : 
    Rectangle();
    Rectangle(int l, int b);
    int area();
    int peri();
    int getlength();
    int getbreadth();
    void setlength(int l) {
        length = l;
    };
    void setbreadth(int b) {
        breadth = b;
    };
    ~Rectangle() {

    }
};
Rectangle :: Rectangle() {
    length = breadth = 1;
}
Rectangle ::Rectangle(int l, int b) {
    length = l;
    breadth = b;
}
int Rectangle ::area() {
    return length*breadth;
}
int Rectangle::peri() {
    return 2*(length+breadth);
}
int Rectangle :: getbreadth() {
    return breadth;
}
int Rectangle::getlength() {
    return length;
}

int main() {
    Rectangle r(10,5);
    cout << "Area : " << r.area() << endl;
    cout << "Peri : " << r.peri() << endl;
    cout << "Length : " << r.getlength() << endl;
    cout << "Breadth : " << r.getbreadth() << endl;
    r.setlength(15);
    r.setbreadth(10);
    cout << "After Change : " << endl;
    cout << "Area : " << r.area() << endl;
    cout << "Peri : " << r.peri() << endl;
    cout << "Length : " << r.getlength() << endl;
    cout << "Breadth : " << r.getbreadth() << endl;
    return 0;
}