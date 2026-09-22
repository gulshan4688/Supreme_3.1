#include <iostream>
#include <vector>
using namespace std;

void ExIn(vector<int> arr,vector<int> op,vector<vector<int>> &ans,int index){
    if(index >=arr.size()){
        
        ans.push_back(op);
        return ;
    }
    //exclude
    ExIn(arr,op,ans,index+1);
    //include
    op.push_back(arr[index]);
    ExIn(arr,op,ans,index+1);

}
void printVector( vector<vector<int>>& ans) {
    for ( auto& vec : ans) { // Loop through each vector
        for (int num : vec) {    // Loop through each element in the vector
            cout << num << " ";  // Print the element
        }
        cout << endl;            // Print a newline after each inner vector
    }
}
int main()
{
    vector<int> arr ={1,2,3};
    vector<int> op;
    vector<vector<int>> ans;
    ExIn(arr,op,ans,0);
    // cout<<ans;
    printVector(ans);
    return 0;
}