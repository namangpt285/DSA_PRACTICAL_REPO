#include <iostream>
using namespace std;

int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int count = 0;

    for(int i = s + 1; i <= e; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }

    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    int i = s;
    int j = e;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quicksort(int arr[], int s, int e){
    if(s >= e){
        return;
    }

    int p = partition(arr, s, e);

    quicksort(arr, s, p - 1);
    quicksort(arr, p + 1, e);
}

int main(){
    cout << "--- Quick Sort ---" << endl;
    int size = 9;
    int *arr = new int[size]{9, 3, 7, 5, 6, 2, 8, 4, 1};

    cout << "Original array: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, 0, size - 1);

    cout << "Sorted array: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    delete [] arr;
    return 0;
}