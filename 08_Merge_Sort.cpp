#include <iostream>
using namespace std;

void merge(int arr[], int s, int e){
    int mid = s + (e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = s;
    for(int i=0; i<len1; i++){
        first[i] = arr[k++];
    }

    k = mid+1;
    for(int i=0; i<len2; i++){
        second[i] = arr[k++];
    }

    k = s;
    int index1 = 0;
    int index2 = 0;

    while(index1<len1 && index2<len2){
        if(first[index1] < second[index2]){
            arr[k++] = first[index1++];
        }
        else{
            arr[k++] = second[index2++];
        }
    }

    while(index1<len1){
        arr[k++] = first[index1++];
    }

    while(index2<len2){
        arr[k++] = second[index2++];
    }

    delete [] first;
    delete [] second;
}

void mergesort(int arr[], int size, int s, int end){
    if(s >= end){
        return;
    }

    int mid = s + (end-s)/2;

    mergesort(arr,size,s,mid);
    mergesort(arr,size,mid+1,end);

    merge(arr,s,end);
}

int main(){
    cout << "--- Merge Sort ---" << endl;
    int size = 7;
    int *arr = new int[size]{38, 27, 43, 3, 9, 82, 10};

    cout << "Original array: ";
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    mergesort(arr,size,0,size-1);

    cout << "SORTED ARRAY: ";
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    delete [] arr;
    return 0;
}