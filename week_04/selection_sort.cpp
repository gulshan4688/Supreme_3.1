#include <iostream>
using namespace std;
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[10] = {44, 33, 55, 22, 11};
    int n = 5;
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            // find minimum
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        } 
            swap(arr[minIndex], arr[i]);
    }
    print(arr, 5);
    return 0;
}