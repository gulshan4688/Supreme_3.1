#include <iostream>
#include <vector>
using namespace std;
void print_util(vector<int> &num, int s, int e)
{
    // base case
    if (e>=num.size())
    {
        return;
    }
    // one case
    for(int i=s;i<=e;i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;
    // call case
    print_util(num, s, e + 1);
}
void print(vector<int> &num, int s, int e){
    for (int s = 0; s < num.size(); s++)
    {
        print_util(num,s,s);
    }
    
}
int main()
{
    vector<int> num{1,2,3,4,5,6,7};
    cout<<"the subarrays are:"<<endl;

    print(num, 0, 0);
    return 0;
}