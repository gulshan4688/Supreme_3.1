#include <iostream>
#include <string.h>
using namespace std;
bool checkPalindrome(string palin, int s, int e)
{
    // base case
    if (s >= e)
    {
        return true;
    }

    // one case
    if (palin[s] != palin[e])
    {
        return false;
    }
    // call case
    return checkPalindrome(palin, s + 1, e - 1);
}
int main()
{
    string palin = "poop";

    cout << checkPalindrome(palin, 0, palin.size()-1);
    return 0;
}