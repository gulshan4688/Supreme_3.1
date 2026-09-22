#include <iostream>
using namespace std;
int main()
{
    // normally without recursion
    int n = 0;
    cout << "enter the number";
    cin >> n;
    int i = 0;
    int fn=0;
    int sn=1;
    int tn=0;
    tn=fn+sn; 
    cout<<0<<" "<<1<<" "<<1<<" ";
    while (i < n){
        tn=tn+sn;
        cout<<tn<<" " ;
        sn=tn-sn;
        i++;
    }

        return 0;
}