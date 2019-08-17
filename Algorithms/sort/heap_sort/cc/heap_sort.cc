#include "max_heap.h"

// using heap
template <typename T>
void heapSort1(T arr[], int n) {
  MaxHeap<T> max_heap(arr, n);
  for (int i = n; i > 0; --i) {
    arr[i - 1] = max_heap.top();
    max_heap.pop();
  }
}


template <typename T>
void __shiftDown(T arr[], int n, int k) {
  T e = arr[k];
  while (2 * k + 1 < n) {
    int j = 2 * k + 1;
    if (j + 1 < n && arr[j + 1] > arr[j]) {
      ++j;
    }
    if (arr[j] <= e) {
      break;
    }
    arr[k] = arr[j];
    k = j;
  }
  arr[k] = e;
}

// in place
template <typename T>
void heapSort(T arr[], int n) {
  for (int i = (n - 2) / 2; i >= 0; --i) {
    __shiftDown(arr, n, i);
  }
  for (int i = n - 1; i > 0; --i) {
    swap(arr[0], arr[i]);
    __shiftDown(arr, i, 0);
  }
}
