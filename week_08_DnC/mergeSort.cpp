#include <iostream>
#include <vector>
using namespace std;
void mergeSort(int arr[], int sizeArr, int brr[], int sizeBrr, vector<int> &ans)
{
    // we will first go with the 2 pointer approch
    int i = 0;
    int j = 0;
    while (i <= sizeArr && j <= sizeBrr)
    {
        if (arr[i] < brr[j])
        {
            ans.push_back(arr[i]);
            i++;
        }
        else
        {
            ans.push_back(brr[j]);
            j++;
        }
    }
    // if any of the conditons get false then we come outside the loop
    // it is only possible when one the loop reached its end one is still in the way to reach the end
    // now we have to just push the elements in the ans array from the array who has not reached its end.
    while (i < sizeArr)
    {
        ans.push_back(arr[i]);
        i++;
    }

    while (j < sizeBrr)
    {
        ans.push_back(brr[j]);
        j++;
    }
}
void merge(int arr[], int s, int e, int mid)
{
    // arrays length initialsed
    int leftLength = mid - s + 1;
    int rightLength = e - mid;
    // arrays created dynamically
    int *leftArr = new int[leftLength];
    int *rightArr = new int[rightLength];
    // fill the array by copying the values
    // copying in the left array in which left elements are there
    int index = s;

    for (int i = 0; i < leftLength; i++)
    {
        leftArr[i] = arr[index];
        index++;
    }
    // copying in rigth array in which right elements are there
    index = mid + 1;
    for (int i = 0; i < rightLength; i++)
    {
        rightArr[i] = arr[index];
        index++;
    }
    // after copying we need to merge the arrays
    // create every array indices
    int leftIdx = 0;
    int rightIdx = 0;
    int mainArrIdx = s;

    while (leftIdx < leftLength && rightIdx < rightLength)
    {
        if (leftArr[leftIdx] < rightArr[rightIdx])
        {
            arr[mainArrIdx] = leftArr[leftIdx];
            mainArrIdx++, leftIdx++;
        }
        else
        {
            arr[mainArrIdx] = rightArr[rightIdx];
            mainArrIdx++, rightIdx++;
        }
    }
    // now we have to handle the remaining elements in any of the arrays right or left
    while (leftIdx < leftLength)
    {
        arr[mainArrIdx] = leftArr[leftIdx];
        leftIdx++, mainArrIdx++;
    }
    while (rightIdx < rightLength)
    {
        arr[mainArrIdx] = rightArr[rightIdx];
        mainArrIdx++, rightIdx++;
    }
    // Deallocate dynamic arrays
    delete[] leftArr;
    delete[] rightArr;
}
void Rec_Merge(int arr[], int s, int e)
{
    // for single element both s and e will be on same postion and it is already sorted
    // base case
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;
    
    // left part recursion
    Rec_Merge(arr, s, mid);
    // right part recursion
    Rec_Merge(arr, mid + 1, e);
    // merge both parts
    merge(arr, s, e, mid);
}
void printArray(vector<int> ans)

{
    int size = ans.size();
    for (int i : ans)
    {
        cout << i << " ";
    }
}

int partition(int arr[], int s, int e)
{
    // base case
    int pivot = arr[s];
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= arr[s])
        {
            count++;
        }
    }
    // cout<<"count=="<<count<<endl;
    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);
    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}
void qucikSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(arr, s, e);

    // for left part
    qucikSort(arr, s, p - 1);
    // for right part
    qucikSort(arr, p + 1, e);
}
int main()
{
    // int arr[] = {1, 3, 5, 7, 9};
    // int sizeArr = 5;
    // int brr[] = {2, 4, 6};
    // int sizeBrr = 3;
    // cout << "step 1 " << endl;

    int crr[] = {6, 9, 2, 8, 3, 7, 4, 11, 5, 10};
    int s = 0;

    int size = 10;
    int e = size - 1;
    // int mid = (s + e) / 2;
    // vector<int> ans;
    // cout << "2 " << endl;
    // // mergeSort(arr, sizeArr, brr, sizeBrr, ans);
    Rec_Merge(crr, s, e);
    // cout << "3 " << endl;
    // // printArray(crr);
    // cout << "1 " << endl;
    // qucikSort(crr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << crr[i] << " ";
    }
    cout << endl;

    // cout << "4 " << endl;
    return 0;
}