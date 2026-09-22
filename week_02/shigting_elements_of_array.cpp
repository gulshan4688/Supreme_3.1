#include <iostream>
using namespace std;
void shifting(int array[], int t, int size)
{
    int temp[100];
    t = t % size;
    if (t == 0)
    {
        return;
    }

    // n elements copied in array temp
    int index = 0;
    for (int i = size -t; i < size; i++)
    {
        temp[index] = array[i];
        index++;
    }
    cout << temp[0] << " " << temp[1] << " " << array[2] << endl;
    // shifing every element by 2
    for (int i = size - 1; i >= 0; i--)
    {
        if ((i -t) >= 0)
        {
            array[i] = array[i -t];
        }
    }
    // again copying the temp elements in original array
    for (int i = 0; i < t; i++)
    {
        array[i] = temp[i];
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int array[6] = {1, 2, 3, 4, 5, 6};
    int n = 2;
    shifting(array, 19, 6);
    printArray(array, 6);
    return 0; 
}