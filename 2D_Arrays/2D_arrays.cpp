#include <iostream>
using namespace std;
void printArray(int arr[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void printSum(int arr[3][3], int row, int col)
{

    for (int i = 0; i < col; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; j++)
        {
            sum += arr[j][i];
        }
        cout << sum << " ";
    }
}
void transposeOfmatrix(int arr[3][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < col; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    printArray(arr, 3, 3);
}
void colWise(int arr[3][3], int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}

int main()
{

    // row wise accessing------------>
    int brr[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    // cout << "printing row wise:";
    // cout << endl;
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // //   coloumn wise accessing------------->
    // cout << endl;

    // cout << "printing col wise:"<<endl;
    // colWise(brr, 3, 3);
    // cout<<"------------------->"<<endl;
    // printSum(brr, 3, 3);
    // cout<<endl<<"------------------->"<<endl;
    transposeOfmatrix(brr, 3, 3);

    return 0;
}