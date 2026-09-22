#include <iostream>
using namespace std;
class Shape{
    public:
    virtual void draw(){
        cout<<"Generic Drawing..."<<endl;
    }
};
class Circle:public Shape{
    public:
    void draw(){
        cout<<"circle drawing..."<<endl;
    }
};
class Rectangle:public Shape{
    public:
    void draw(){
        cout<<"Rectangle drawing..."<<endl;
    }
};
class Triangle:public Shape{
    public:
    void draw(){
        cout<<"Triangle drawing..."<<endl;
    }
};
void shapeDrawing(Shape *s){
    s->draw();
}
int main()
{
    // Shape s;
    // Circle c;
    // Triangle *t=new Triangle();
    // shapeDrawing(t);
    // shapeDrawing(&s);
    // shapeDrawing(&c);
    Shape *s=new Shape();
    s->draw();
    // UpCasting
    Shape *s2=new Circle();
    s2->draw();
    Circle *c=new Circle();
    c->draw();
    //downCasting
    Shape *s3=new Shape();
    Circle *c2=(Circle *)s3;
    c2->draw(); 
    return 0;
}