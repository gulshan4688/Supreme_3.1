#include <iostream>
using namespace std;
void count(int n)
{
    // stop condition
    if (n == 0)
    {
        return;
    }
    // recusion call
    count(n-1); 
    // processin part
    cout <<n<< " ";
}
int main()
{
    // int n;
    // cout << "enter the count num\n";
    // cin >> n;
    count(10);
    return 0;
}