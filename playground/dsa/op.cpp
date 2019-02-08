#include <iostream>

using namespace std;

class Base {
    public:
        virtual void method1() = 0;
    };

void Base::method1() {
    cout<<"base";
}

class Derived : public Base {
    public:
        void method1() {
            cout<<"\nderived\n";
            Base::method1();
        }
};

int main() {
    Base *p = new Derived();
    p->method1();
    return 0;
}
