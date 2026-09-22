#include <iostream>
#include <vector>
using namespace std;
void printsubsequences(string s, int i, string op ,vector<string> &ans)
{
    // base case
    if (i == s.length())
    {
        ans.push_back(op);
        return;
    }
    // 1 case solve
    char ch = s[i];
    // include ch
    // op.push_back(ch);
    printsubsequences(s, i + 1, op + ch,ans);
    // exclude ch
    printsubsequences(s, i + 1, op,ans);
    // call recursive
}
int main()
{
    string name = "xy";
    string op = "";
    vector<string> ans;
    cout<<"the Subsequences are:"<<endl;
    printsubsequences(name, 0, op,ans);
    for(auto i:ans){
        cout<<i<<endl;
    }
    return 0;
}