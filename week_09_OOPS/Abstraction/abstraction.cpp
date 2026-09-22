#include <iostream>
#include "bird.h"
using namespace std;
void birdDoes(Bird *&bird){
    // means jo bhi pararmeter isme pass hoga wo eat and fly ko call karega 
    bird->eat();
    bird->fly();
}
int main()
{
    Bird *baby=new eagle();
    birdDoes(baby);
    return 0;
}