#include <iostream>
using namespace std;
int main()
{
    // ----------------// hollow square and rectangle

    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //        if(i==0 || i==5-1){
    //         cout<<"*";
    //        }
    //        else{
    //         if(j==0 || j==5-1){
    //             cout<<"*";
    //         }
    //         else{
    //             cout<<" ";
    //         }
    //        }
    //     }
    //     cout<<endl;

    // }
    //-------->>>>>>>>>> RIght angle traingle

    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j <=i-1; j++)
    //     {
    //         cout<<"*"<<" ";
    //     }
    //     cout<<endl;

    // }

    //-------->>>>>>>>>> revrse RIght anle traingle
    // for (int i = 5; i >0; i--)
    // {
    //     for (int j = i; j >0; j--)
    //     {
    //         cout<<"*"<<" ";
    //     }
    //     cout<<endl;

    // }

    // ----------->>>>>>>>>>>>>> hollow traingle
    int n = 20;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i == 0 || i == n - 1)
            {
                cout << "*";
            }
            else
            {
                if (j == 0 || j == i - 1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

    //------>>>>>>>> hollow half inverted triangle
    // int n = 6;
    // for (int i = 0; i<n; i++)
    // {
    //     for (int j = 0; j<n-i; j++)
    //     {
    //          if (i == 0 || i == n - 1 || i+j==n-1 ||j==0)
    //         {
    //             cout << "*";
    //         }
    //         else
    //         {
    //             // if (j == 0 || j == i - 1)
    //             // {
    //             //     cout << "*";
    //             // }
    //             // else
    //             // {
    //                 cout <<" ";
    //             // }
    //         }
    //     }
    //     cout<<endl;

    // }

    // ---------------->>>>>>>>>>> Numeric half pyramid
    // int n=6;
    // for (int i = 1; i <=n; i++)
    // {
    //     for (int j = 1; j <=i-1; j++)
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;

    // }

    // ---------------->>>>>>>>>>>  -reverse -Numeric half pyramid

    // int n=20;
    // for (int i=0 ; i<n ; i++)
    // {
    //     for (int j = 1; j<=n-i; j++)
    //     {
    //         cout<<j<<"  ";
    //     }
    //     cout<<endl;

    // }

    return 0;
}