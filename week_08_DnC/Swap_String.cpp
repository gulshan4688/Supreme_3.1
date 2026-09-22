#include <iostream>
using namespace std;
void swap_str(string &name,int s,int e){
    if(s>=e){
        return ;
    }
    swap(name[s],name[e]);
    swap_str(name,s+1,e-1);
    // cout<<name;
}
int main()
{
    string name="mani";
    swap_str( name,0,name.size()-1);
    cout<<name;
    return 0;
}