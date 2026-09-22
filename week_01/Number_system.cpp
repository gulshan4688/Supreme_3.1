#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//------------>>>> using division method

// int dec_to_binary(int n){
//     vector<int> remain;
//         int bit=0;
//         int rem=0;
//         int i=0;
//     while(n>0){
//         bit=n%2;
//         rem=(bit*pow(10,i)+rem);
//         n=n/2;
//         i++;
//         // cout<<bit<<endl;
        
//     }
//     return rem;
// }

// ----------->>>>> using bitwise method 

// int dec_to_binary_bitwise_method(int n){
//     int rem=0;
//     int bit=0;
//     int i=0;
//     while(n>0){
//         bit=n&1;
//         rem=(bit*pow(10,i)+rem);
//         n=n>>1;
//         i++;
//     }
//     return rem;
// }

// --------------->>>>>> bianry to decimal conversion 

int binary_to_decimal(int n){
    int digit=0;
    int val=0;
    int i=0;
    while(n>0){
        digit=n%10;
        val=digit*pow(2,i)+val;
        n=n/10;
        i++;   

    }
    return val;

}
int main()
{
    int n ;
    cin>>n;
    // int binary=dec_to_binary(n);
    // int binary=dec_to_binary_bitwise_method(n);
    int binary=binary_to_decimal(n);
    cout<<binary;

    return 0;
}