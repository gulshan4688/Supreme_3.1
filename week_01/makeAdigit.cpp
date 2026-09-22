#include <iostream>
using namespace std;
int create_a_number(int n){
    
    // cin>>n;
    int digit;
    int num=0;
    while (n > 0)
    {
        cout<<"enter the digit"<<endl;
        cin >> digit;
        num=num*10+digit;
        n--;
    }
    return num;

}
int main()
{
    int n;
    cout<<"enter no. of times you want to enter the digits"<<endl;
    cin>>n;
    int ans=create_a_number(n);
    cout<<ans;
    
    return 0;
}