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
    int arr[10] = {8, 7, 4, 5, 4, 3, 2, 9};
    int n = 8;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j])
        {

            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    print(arr, 8);
    return 0;
}