#include <iostream>
using namespace std;
int paint(int n,int k){
    if(n==1){
        return k;
    }
    if(n==2){
        return k+ k*(k-1);
    }
    return (k-1) * (paint(n-1,k)+ paint(n-2,k));
}
int main()
{
    int n=4;
    int k=3;
    cout<<paint(n,k);
    return 0;
}