#include <iostream>
using namespace std;
void reverse(string &word,int s,int e){
    //bc
    if(s>=e){
        return ;
    }
    //oc
    swap(word[s],word[e]);
    //cr
    reverse(word,s+1,e-1);
}
int main()
{
    string word = "abcdefg";
    reverse(word,0,word.size()-1);
    cout<<word;
    return 0;
}