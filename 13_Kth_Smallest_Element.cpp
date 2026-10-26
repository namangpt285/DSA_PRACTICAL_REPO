#include <iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    int pivot = arr[s];
    int count = 0;

    for(int i = s + 1; i <= e; i++) {
        if(arr[i] <= pivot) {
            count++;
        }
    }

    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    int i = s;
    int j = e;

    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

int kthSmallest(int arr[], int s, int e, int k) {
    int p = partition(arr, s, e);

    if(p == k) {
        return arr[p];
    }
    else if(p < k) {
        return kthSmallest(arr, p + 1, e, k);
    }
    else {
        return kthSmallest(arr, s, p - 1, k);
    }
}

int main() {
    cout << "--- Kth Smallest Element ---" << endl;
    int arr[] = {10, 4, 5, 8, 6, 11, 26};
    int n = 7;
    int k = 3; 

    cout << "Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int ans = kthSmallest(arr, 0, n - 1, k);
    cout << "Element at sorted index " << k << " is: " << ans << endl;

    return 0;
}