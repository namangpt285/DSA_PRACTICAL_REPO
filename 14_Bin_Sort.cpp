#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

void binSort(int arr[], int n, int maxVal) {
    Node** bins = new Node*[maxVal + 1];

    for(int i = 0; i <= maxVal; i++) {
        bins[i] = NULL;
    }

    for(int i = 0; i < n; i++) {
        int val = arr[i];
        Node* newNode = new Node(val);
        newNode->next = bins[val];
        bins[val] = newNode;
    }

    int k = 0;
    for(int i = 0; i <= maxVal; i++) {
        Node* temp = bins[i];
        while(temp != NULL) {
            arr[k++] = temp->data;
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }

    delete [] bins;
}

int main() {
    cout << "--- Bin Sort ---" << endl;
    int arr[] = {4, 2, 0, 4, 1, 3, 2, 5};
    int n = 8;
    int maxVal = 5;

    cout << "Original array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    binSort(arr, n, maxVal);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}