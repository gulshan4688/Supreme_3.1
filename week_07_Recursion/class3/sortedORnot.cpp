#include <iostream>
using namespace std;
bool sortedORnot(int arr[], int n, int i)
{
    // stop
    if (i == n - 1)
    {
        return true;
    }
    bool currAns=0;
    bool recurAns=0;
    // processing
    if (arr[i] < arr[i + 1])
    {
        currAns=true;
    }
    recurAns=sortedORnot(arr,n,i+1);

    return currAns && recurAns;
}
int main()
{
    int arr[] = {1, 19, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    bool ans = sortedORnot(arr, 10, 0);
    cout << ans;
    return 0;
}