#include <iostream>
#include <cmath>
using namespace std;
int convert_into_binary(int n){
    int bit;
    int binary_num=0;
    int i=0;
    int count=0;
    while(n>0){
        bit=n%2;
        // if(bit==1){
        //     count++;
        // }
        binary_num=bit*pow(10,i)+binary_num;
        n/=2;
        i++;
    }
    return binary_num;
}
int count_the_setBit(int binary_num){
    int count=0;
    while(binary_num>0){
        if(binary_num%2==1){
            count++;
        }
        binary_num=binary_num>>1;
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    int ans=count_the_setBit(n);
    // int binary=convert_into_binary(n);
    // cout<<binary;
    cout<<ans;
    return 0;
}