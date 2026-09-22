#include <iostream>
using namespace std;
bool checkPrime(int n){
    for (int i = 2; i < n; i++)
    {
        if(n%i==0){
            return false;
        }
    }
    return true;
    
}
int main()
{
    int n;
    cout<<"enter the number";
    cin>>n;
    // while(i<n){
    //     if(n%i==0){
    //         cout<<"not a prime";
    //         break;
    //     }
    //     else{
    //         cout<<"prime no.";
    //         break;
    //     i++;
    //     }
    // }

    // ----------print all prime number between 1 to N--------   
    int i=2;
    while (i<=n)
    {
        if(checkPrime(i)){
            cout<<i<<" ";
        }
        i++;
    }
    

    return 0;
}