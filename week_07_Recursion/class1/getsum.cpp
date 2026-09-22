#include <iostream>
using namespace std;
int getSum(int n){
    // base case
    if(n==0){
        return 0;
    }
    // recursive call
    int ans=n+getSum(n-1);
    return ans;
}
int main()
{
    cout<<getSum(10);
    return 0;
}