#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int new_num=0;
    while (n>0)
    {
        int digit=n%10;
        new_num=(new_num*10)+digit;
        n=n/10;
    }
    cout<<new_num;
    return 0;
}