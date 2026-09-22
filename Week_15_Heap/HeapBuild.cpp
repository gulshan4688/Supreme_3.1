#include <bits/stdc++.h>
using namespace std;

class Heap {
public:
  int *arr;
  int capacity;
  int index;

  Heap(int capacity) {
    this->capacity = capacity;
    arr = new int[capacity];
    index = 0;
  }

  void printHeap() {
    for (int i = 1; i <= index; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  void insert(int val) {
    if (index == capacity) {
      cout << "Overflow" << endl;
      return;
    }
    index++;
    arr[index] = val;
    int i = index;

    while (i > 1) {
      int parentIdx = i / 2;
      if (arr[parentIdx] < arr[i]) {
        swap(arr[parentIdx], arr[i]);
        i = parentIdx; // because we have to also  exit the loop.

      } else
        break;
    }
  }
  void deleteFromHeap() {
    // step1 replacement((delection ka pehla rule tha ki 1 index wale ko last
    // index ke element se replace krso))
    swap(arr[1], arr[index]);
    // step2 decrease the size
    index--;
    // step3 Heapify
    // heapify(arr, index, 1);
  }
};
void heapify(int *arr, int n, int currIdx) {
  // n-> no. of element in the heap
  //   int i = currIdx;
  int leftIdx = 2 * currIdx;
  int rightIdx = 2 * currIdx + 1;
  // lets assume the that at i , there is the largest value
  int largestIdx = currIdx;
  // check for left
  if (leftIdx < n && arr[leftIdx] > arr[largestIdx]) {
    largestIdx = leftIdx;
  }
  if (rightIdx < n && arr[rightIdx] > arr[largestIdx]) {
    largestIdx = rightIdx;
  }
  // now we have index of lagest element till now
  // now the new case can be that largestIdx is still i
  if (largestIdx != currIdx) {
    swap(arr[largestIdx], arr[currIdx]);
    currIdx = largestIdx;
    heapify(arr, n, currIdx);
  }
}
void buildHeap(int *arr, int n) {
  for (int i = n / 2; i > 0; i--) {
    heapify(arr, n, i);
  }
}
void heapSort(int *arr, int n) {
  while (n != 1) {
    // replace elements
    swap(arr[1], arr[n - 1]);
    n--;
    // now heapify 1 index wala element
    heapify(arr, n , 1);
  }
}
int main() {
  // & we are given a array and we have to heapify it
  int arr[6] = {-1, 10, 12, 13, 14, 15};
  int n = 6;
  cout<<"After Build Heap"<<endl;
  buildHeap(arr, 6);
  for (int i = 1; i <= 5; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  heapSort(arr, n);
  // printing the heap inside the heap sort
  cout<<"After heap sort"<<endl;
  for (int k = 1; k < n; k++) {
    cout << arr[k] << " ";
  }
  cout << endl;
  return 0;
}
