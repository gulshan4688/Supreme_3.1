#include <iostream>
using namespace std;
bool check(int arr[], int n, int target, int index)
{
    // base case
    if (index >= n)
    {
        return false;
    }
    // processing
    if (target == arr[index])
    {
        return true;
    }
    // call

    return check(arr, 6, target, index +1);
    
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int index = 0;
    if (check(arr, 6,7, 0))
    {
        cout << "target Found";
    }
    else
    {
        cout << "target not Found";
    }
    return 0;
}