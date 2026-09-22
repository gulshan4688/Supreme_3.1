#include <iostream>
using namespace std;
int PO2(int n)
{
    // base case
    if (n == 0)
    {
        return 1;
    }
    int small = PO2(n - 1);
    int big = small * 2;
    return big;
}

int main()
{
    int n = 4;
    cout << PO2(n);
    return 0;
}