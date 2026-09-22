#include <iostream>
using namespace std;
int bs(int arr[] ,int s,int e,int x){
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]>x){
            e=mid-1;
        }
        else{
            s=mid+1; 
        }
        mid=s+(e-s)/2;
    }
    return -1;
}
int exponential_search(int arr[],int n,int x){
    int i=1;
    if(arr[0]==x){
            return 0;
        }
    while(i<n && arr[i]<x){
        i=i*2;

    }
    return bs(arr,i/2,min(i,n-1),x);
}
int main()
{
    int arr[10]={1,2,3,4,5,6,7,8};
    int n=8;
    int x=7;
    int ans=exponential_search(arr,8,7);
    cout<<ans;
    return 0;
}