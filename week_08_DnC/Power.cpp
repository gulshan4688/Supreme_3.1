#include <iostream>
using namespace std;
int power(int a,int b,int i,int ans){
    // base case 
    if(b==1){
        return a;
    }
    if(b==0){
        return 1;
    }
    if(i==b){
        return ans;
    }
    //processing
    ans=ans*a;
    i++;
    ans =power(a,b,i,ans);
    return ans;

}
int main()
{
    // cout<<"enter the number";
    // cin>>a>>b;
    // Power(a,b);
    // int ans=1;
    // for(int i=0;i<b;i++){
    //     ans=ans*a;
    // }
    // cout<<ans;
    int i=0;
    int ans=1;
    cout<<power(5,15,i,ans);
    return 0;
}