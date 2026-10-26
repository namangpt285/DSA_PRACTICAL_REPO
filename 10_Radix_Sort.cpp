#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > mx) {
            mx = arr[i];
        }
    }
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int *output = new int[n];
    int count[10] = {0};

    for(int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for(int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for(int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    delete [] output;
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);

    for(int exp = 1; m / exp > 0; exp = exp * 10) {
        countSort(arr, n, exp);
    }
}

int main() {
    cout << "--- Radix Sort ---" << endl;
    int arr[] = {253, 192, 3, 2, 10, 75, 478, 88};
    int n = 8;

    cout << "Original array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    radixSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}