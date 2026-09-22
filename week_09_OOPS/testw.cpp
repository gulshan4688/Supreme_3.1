#include <iostream>
using namespace std;

class Parent {
private:
    int value;
public:
    Parent() { value = 10; cout << "Parent Constructor" << endl; }
    ~Parent() { cout << "Parent Destructor" << endl; }
    
    void setValue(int v) { value = v; }
    int getValue() { return value; }
};

class Child : public Parent {
private:
    int data;
public:
    Child() { data = 20; cout << "Child Constructor" << endl; }
    ~Child() { cout << "Child Destructor" << endl; }
    
    void setData(int d) { data = d; }
    int getData() { return data; }
};

int main() {
    Parent* p = new Child();
    delete p;
    return 0;
}