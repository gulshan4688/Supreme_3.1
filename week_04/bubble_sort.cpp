#include <iostream>
using namespace std;
void print(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
int main()
{
    int arr[10]={8,7,4,5,4,3,2,9};
    int n=8;
    for(int i=0 ; i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                j++;
            }
        }
    }
    print(arr,8);
    return 0;
}