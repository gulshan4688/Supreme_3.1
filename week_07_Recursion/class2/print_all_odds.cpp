#include <iostream>
using namespace std;
void printOdds(int arr[], int size, int index)
{
    if (index == size){
        return ;
    }
    // for odd no.
    // if(arr[index]&1){
    //     cout<<arr[index]<<" ";
    // }
    // for even no.
    if(arr[index]%2==0){
        cout<<arr[index]<<" ";
    }

    printOdds(arr,size,index+1);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int index = 0;
    int size=6;
    printOdds(arr,size,index);
    return 0;
}