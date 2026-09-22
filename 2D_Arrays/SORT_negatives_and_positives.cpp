#include <iostream>
using namespace std;
void sort(int arr[], int n)
{
    int index = 0;
    int j = 0;
    while (index < n)
    {
        if (arr[index] < 0)
        {
            swap(arr[index], arr[j]);
            j++;
        }
        else
            index++;
    }
}

int main()
{
    int arr[10] = {12, -7, -43, 90, -12, -7, -12};
    cout << "sorted arrays:" << endl;
    sort(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}