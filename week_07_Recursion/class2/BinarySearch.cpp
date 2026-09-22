#include <iostream>
using namespace std;
int  recursive_BS(int arr[], int start, int end, int target)
{
    if (start >= end)
    {
        return -1;
    }
    int mid = (end + start) / 2;
    if (target == arr[mid])
    {
        return mid;
    }
    if (target > arr[mid])
    {
        return recursive_BS(arr, mid + 1, end, target);
    }
    else
    {
        return recursive_BS(arr, start, mid - 1, target);
    }
    // return false;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int start = 0;
    int end = size ;
    // int target = 8;
    // int start=0,end=size-1;
    int ans = recursive_BS(arr,start,end, 10);
    // if (recursive_BS(arr, start, end, 1))
    // {
    //     cout << "found";
    // }
    // else
    // {
    //     cout << "not found";
    // }
    cout << ans;
    return 0;
}