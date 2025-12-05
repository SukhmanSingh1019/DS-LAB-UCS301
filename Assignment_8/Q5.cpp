#include <bits/stdc++.h>
using namespace std;

void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i ;
    int right = 2*i + 1;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void heapSortIncreasing(int arr[], int n) {
    for (int i = n; i > 1; i--) {
        swap(arr[0], arr[i]);  
        heapifyMax(arr, i, 0); 
    }
}

void heapSortDecreasing(int arr[], int n) {
      for (int i = n; i > 1; i--) {
        swap(arr[0], arr[i]);  
        heapifyMin(arr, i, 0); 
    }
}



