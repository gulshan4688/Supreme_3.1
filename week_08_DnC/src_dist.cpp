#include <iostream>
using namespace std;
void walk(int src,int dest){
    if(src==dest){
        cout<<"reached";
        return ;
    }
    src++;
    walk(src,dest);
}
int main()
{
    int src=10;
    int dest=10;
    walk(src,dest);
    return 0;
}