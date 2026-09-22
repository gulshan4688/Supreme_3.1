#include <iostream>
using namespace std;
int main()
{

  // for (int i = 0; i <= n; i++)
  // {
  //     for (int j = 0; j <= i; j++)
  //     {
  //         if (i == 1 || i == n || j==0  || j==i)
  //         {
  //             cout << j+1 << " ";
  //         }
  //         else{
  //             cout<<"  ";
  //         }
  //     }
  //     cout << endl;
  // }
  // inverted pyramids of number

  // for (int i = 1; i < n; i++)
  // {
  //     for (int j = 0; j < n - i; j++)
  //     {
  //         if (i==n || i == 1 || j==0 || j==n-i-1)
  //         {

  //             cout << j+1 << "  ";
  //         }
  //         else{
  //             cout<<"   ";
  //         }
  //     }
  //     cout << endl<<endl;
  // }

  // -------------->>>>>>> Numeric palindrome equilateral traingle

  /*
                    1
                  1 2 1
                1 2 3 2 1
              1 2 3 4 3 2 1
            1 2 3 4 5 4 3 2 1
          1 2 3 4 5 6 5 4 3 2 1
  */

  // for (int i = 0; i <= n; i++)
  // {
  //     // spaces
  //     for (int k = 0; k < n - i; k++)
  //     {
  //         cout << "  ";
  //     }
  //     // couting
  //     for (int l = 0; l <= i; l++)
  //     {
  //         cout << l + 1 << " ";
  //     }
  //     for (int m = i; m > 0; m--)
  //     {
  //         cout << m << " ";
  //     }

  //     cout << endl;
  // }

  /*

                                *
                                * *
                                * * *
                                * * * *
                                * * * * *
                                * * * *
                                * * *
                                * *
                                *

  */
  // for (int i = 0; i < 2 * n - 1; i++)
  // {
  //     // forward traigle
  //     int cond = 0;

  //     if (i < n)
  //     {
  //         cond = i;
  //     }
  //     else
  //     {
  //         cond = n - (i % n) - 2;
  //     }
  //     for (int j = 0; j <= cond; j++)
  //     {
  //         cout << "*" << " ";
  //     }

  //     cout << endl;
  // }

  // -------------->>>>>>>>>> fancy patterns --#1

  /*
   * * * * * * * * 1 * * * * * * * *
   * * * * * * * 2 * 2 * * * * * * *
   * * * * * * 3 * 3 * 3 * * * * * *
   * * * * * 4 * 4 * 4 * 4 * * * * *
   * * * * 5 * 5 * 5 * 5 * 5 * * * *
   */

  // for (int i = 0; i < n; i++)
  // {
  //     int from_where_we_print = 8 - i;
  //     int print_num = i+1;
  //     int how_much_time = print_num;
  //     for (int j = 0; j < 17; j++)
  //     {
  //         if(from_where_we_print==j && how_much_time>0){
  //             cout<<print_num<<" ";
  //             from_where_we_print+=2;
  //             how_much_time--;

  //         }
  //         else{
  //             cout<<"* ";
  //         }
  //     }
  //     cout << endl;
  // }

  // -------------->>>>>>>>>>>facny pattern --#2
  /*
            1
            2 * 3
            4 * 5 * 6
            7 * 8 * 9 * 10
            7 * 8 * 9 * 10
            4 * 5 * 6
            2 * 3
            1
  */

  // int k = 1;

  // // growing phase
  // for (int i = 0; i < n; i++)
  // {
  //   // if ()
  //   // {
  //     for (int j = 0; j <=i; j++)
  //     {
  //       cout << k << " ";
  //       k++;
  //       if(j<i){
  //         cout<<"* ";
  //       }
  //     }
  //     cout << endl;
  //   // }
  // }

  // // shrinking phase

  // int start=k-n;
  // for (int i = 0; i < n; i++)
  // {
  //   int k=start;
  //   start=start-(n-i-1);
  //   for (int j = 0; j <=n-i-1;j++)
  //   {
  //     cout<<k<<" ";
  //     k++;
  //     if(j<n-i-1)  // becasue the limit is edge just the growing phase
  // in the for loop it j was less than i
  //     {
  //       cout<<"* ";
  //     }
  //   }
  //   cout<<endl;

  // }

  int n = 5;
  for (int i = 0; i < n; i++)
  {
    int cond=i<=n/2 ? 2*i : 0;
    for (int j = 0; j <=cond; j++)
    {
      if(j<=cond/2){
        cout<<j+1<<" ";
      }
      else{
        cout<<cond-j+1<<" ";
      }
    }
    cout<<endl;
    
  }
  

  return 0;
}