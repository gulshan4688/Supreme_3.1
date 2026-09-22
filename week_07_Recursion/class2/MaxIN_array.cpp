#include <iostream>
using namespace std;
int maxInArray(int arr[], int n, int index, int &max)
{
    // base case
    if (index == n)
    {
        return max;
    }
    // processing
    if (max < arr[index])
    {
        max = arr[index];
    }
    // recursive call
    maxInArray(arr,n,index+1,max);
    return max;
}
int main()
{
    int arr[] = {1, 2, 30, 4, 5, 6};
    int index = 0;
    int max=INT16_MIN;
    cout<<maxInArray(arr,6,index,max);
    return 0;
}