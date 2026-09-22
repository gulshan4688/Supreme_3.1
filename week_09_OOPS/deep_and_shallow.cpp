#include <iostream>
using namespace std;
class abc {
    public:
    int x;
    int *y;
    // initialisation 
    abc(int _x,int _y): x(_x),y(new int(_y)){};
    void print() const{
        cout<<"X: "<<x<<endl<<"Y: "<<y<<endl<<"*Y: "<<*y<<endl;
    }
    // c++ default shallow copy constructor
    abc(const abc &obj){
        x=obj.x;
        y=obj.y;
    }
    // but OUR SMART DEEP copy
    abc(const abc &obj){
        x=obj.x;
        y=new int (*obj.y);
    }
};
int main()
{
    
    abc c(1,2);
    c.print();
    abc b=c;
    // b=c;
    b.print();
    *b.y=20;
    b.print();
    // cout<<*b.y;
    return 0;
}