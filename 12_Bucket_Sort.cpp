#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(float arr[], int n) {
    vector<float> bucket[10];

    for(int i = 0; i < n; i++) {
        int index = n * arr[i];
        bucket[index].push_back(arr[i]);
    }

    for(int i = 0; i < n; i++) {
        sort(bucket[i].begin(), bucket[i].end());
    }

    int k = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < bucket[i].size(); j++) {
            arr[k++] = bucket[i][j];
        }
    }
}

int main() {
    cout << "--- Bucket Sort ---" << endl;
    float arr[] = {0.32, 0.67, 0.24, 0.75, 0.12, 0.88, 0.44};
    int n = 7;

    cout << "Original array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bucketSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}