#include <iostream>
using namespace std;
int main()
{
    cout<<"ghj";
    int arr[5]={1,0,1,0,0};
    for (int i = 0; i < 5; i++)
    {
        if (arr[i]==0){
            arr[i]=1;
        }
        else if(arr[i]==1){
            arr[i]=0;
        }
        
    }
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}