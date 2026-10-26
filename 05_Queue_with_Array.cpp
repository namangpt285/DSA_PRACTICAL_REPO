#include <iostream>
using namespace std;

class Queue {
public:
    int arr[5];
    int front;
    int rear;

    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        if (front == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isFull() {
        if (rear == 4) {
            return true;
        }
        else {
            return false;
        }
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = data;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int ans = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front++;
        }
        return ans;
    }

    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "--- Queue (Array) ---" << endl;
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue contents: ";
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Front element: " << q.frontElement() << endl;

    q.enqueue(40);
    q.enqueue(50);
    cout << "Queue contents after additions: ";
    q.display();

    return 0;
}