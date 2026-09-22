#include <iostream>
using namespace std;
int sumN(int n,int i,int arr[]){
    if(i==n){
        return 0;
    }
    int ans=arr[i]+sumN(n,i+1,arr);
    return ans;
}
int main()
{
    int arr[]={1,1,1,1,1,1};
    cout<<sumN(6,0,arr);
    return 0;
}