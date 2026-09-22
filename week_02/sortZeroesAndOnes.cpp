#include <iostream>
using namespace std;
void sort0and1(int arr[],int n){
    int countzero=0;
    int countones=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==0){
            countzero++;
        }
        if (arr[i]==1)
        {
            countones++;
        }
        
    }
    // insertion 
    // i se start hoga aur pehle countzro tak jayenge fir countone se start krke
    // n tak jayenge aise krke 0 and 1 fill kr denge array mei aur sort kr denge
    // int i=0;
    // for (; i < countzero; i++){
    //     arr[i]=0;   
    // }
    // for (i=countzero; i < n; i++){
    //     arr[i]=1;
    // }

    // second method using prebuild funtion 
    fill(arr,arr+countzero,0);
    fill(arr+countzero,arr+n,1);
    
}
void printArray(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
int main()
{
    cout<<"ghj";
    int arr[5]={1,0,1,0,0};
    sort0and1(arr,5);
    printArray(arr,5);
    return 0;
}