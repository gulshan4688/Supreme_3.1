#include <iostream>
using namespace std;
int minInArray(int arr[], int n, int index, int &max)
{
    // base case
    if (index == n)
    {
        return max;
    }
    // processing
    if (max > arr[index])
    {
        max = arr[index];
    }
    // recursive call
    minInArray(arr,n,index+1,max);
    return max;
}
int main()
{
    int arr[] = {0, 2, 30, 4, 5, 6};
    int index = 0;
    int max=INT16_MAX;
    cout<<minInArray(arr,6,index,max);
    return 0;
}