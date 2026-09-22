#include <iostream>
using namespace std;
void printArr(int arr[],int n,int index){
    // base case
    if(index==n){
        return ;
    }
    // recursive call
    cout<<arr[index]<<" ";
    printArr(arr,n,index+1);
}
int main()
{
    int arr[]={1,2,3,4,5};
    int n=5;
    int index=0;
    printArr(arr,n,index);
    return 0;
}