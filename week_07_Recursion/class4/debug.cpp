#include <iostream>
using namespace std;

bool isPowerOfFour(int n) {
        if(n<=1){
           return false;
        }
        if(n%4==0){
           return true;
        }
       
        return isPowerOfFour(n/4);
    }
int main(){
    bool ans=isPowerOfFour(17);
    cout<<ans;
    return 0;
}