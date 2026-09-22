#include <iostream>
using namespace std;
int mySqrt(int x) {
        int s = 0;
        int e = x / 2;
        int mid = s + (e - s) / 2;
        int ans = -1;
        if (x == 1) {
            return 1;
        }
        while (s <= e) {
            int product = mid * mid;
            if (product == x) { 
                return mid;
            }
            if (product > x) {
                e = mid - 1;
            } else {
                ans = mid;
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }
int main(){
    
    return 0;
}