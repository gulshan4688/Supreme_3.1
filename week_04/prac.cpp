#include <iostream>
using namespace std;
void sortArray(int nums[]) {
        int i = 0;
        while (i < n-1) {
            while(i<n-i-1)
            i=0;
            if (nums[i] > nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
                i++;
            }
            else{
                i++;
            }
        }
        return nums;
    }
int main()
{
    int arr[10]={5,4,3,2,1};
    int n=10;
    sortArray(arr);
    return 0;
}