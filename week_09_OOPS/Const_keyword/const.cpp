#include <iostream>
using namespace std;
class abc {
    int x;
    int *y;
    public:

    abc(){
        x=0;
        y=new int(0);
    }
    int getX(){
        return x;
    }
    int setX(int val){
        x=val;
    }
    int getY(){
        return *y;
    }
    int setY(int val){
        *y=val;
    }
    
};
int main(){
    abc c;
    cout<<c.getX()<<endl;
    cout<<c.getY()<<endl;
    return 0;
}
int main2()
{
    const int s=4;
    cout<<s<<endl;
    const int *p=new int(10);
    cout<<*p<<endl;
    int b=11;
    // *p=&b;   cant change the content of the  pointer but below pointer itself can ve re-assign 
    p=&b; 
    cout<<*p<<endl;
    return 0;
}