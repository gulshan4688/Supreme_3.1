
#include <iostream>
using namespace std;
void swap_str(string &name, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    swap(name[s], name[e]);
    swap_str(name, s + 1, e - 1);
    // cout<<name;
}
bool palindrome(string word,int s,int e){
    if(s>=e){
        return true;
    }
    if(word[s]!=word[e]){
        return false;
    }
    else{
        return palindrome(word,s+1,e-1);
    }
}
int main()
{
    string name = "mani";
    string word="poodfasp";
    // palindrome(word,0,word.size()-1) ? cout<<"true" : cout<<"false";
    if(!(palindrome(word,0,word.size()-1))){
        cout<<"false";
    }
    else{
        cout<<"true";
    }
    return 0;
}