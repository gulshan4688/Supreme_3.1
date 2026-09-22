#include <iostream>
using namespace std;
int main()
{
   
    // cout<<"enter the number of rows"<<endl;
    // cin>>n;

    // ------->>>>>>> strainght pyramid--------- 
    // for (int i = 0; i < n; i++)
    // {
    //     // for spaces
    //     for (int j = 0; j<=n-i-1; j++)
    //     {
    //         cout<<" ";
    //     }

    //     // for stars

    //     for (int j = 0; j < i+1; j++)
    //     {
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    //// ------->>>>>>> downwards  pyramid--------- 

    // for (int i = n; i >=0; i--)
    // {
    //     // for spaces
    //     for (int j = 0; j<=n-i-1; j++)
    //     {
    //         cout<<" ";
    //     }

    //     // for stars

    //     for (int j = 0; j < i+1; j++)
    //     {
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }


    //-------------->>>>>>>>full diamond-----------

    // for (int i = 0; i < n; i++)
    // {
    //     // for spaces
    //     for (int j = 0; j<=n-i-1; j++)
    //     {
    //         cout<<" ";
    //     }

    //     // for stars

    //     for (int j = 0; j < i+1; j++)
    //     {
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }
    // for (int i = n; i >=0; i--)
    // {
    //     // for spaces
    //     for (int j = 0; j<=n-i-1; j++)
    //     {
    //         cout<<" ";
    //     }

    //     // for stars

    //     for (int j = 0; j < i+1; j++)
    //     {
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }


    // ---------------->>>>>>>>>>inverted hollow pyramid
 int n=5;
    for (int i = n-1; i >=0; i--)
    {
        // for spaces
        for (int j = 0; j<=n-i-1; j++)
        {
            cout<<" ";
        }

        // for stars

        for (int j = 0; j <n-i; j++)
        {
            if(i==0 || i==n-1 || j==0 || j==n-i-1){
                cout<<"* ";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

    
    return 0;
}