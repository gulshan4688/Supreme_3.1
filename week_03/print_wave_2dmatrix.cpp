#include <iostream>
using namespace std;
int main()
{
    int n=4;
    int m=4;
    int A[n][m] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13,14,15,16}
                  };
    int j = 0;
    int i = 0;
    int count = 0;
    int col=0;
    while (col<m)    /*count < m*n/4*/
    {
        if (i % 2 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                cout << A[i][j] << " ";
            }
        }
        else{
            for (int i = n-1; i >=0; i--)
            {
                cout << A[i][j] << " ";
            }
        }
        col++;
        j++;
        i++;
        count++;
    }

    return 0;
}