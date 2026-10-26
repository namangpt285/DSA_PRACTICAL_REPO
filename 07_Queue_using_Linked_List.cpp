#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        if (front == NULL) {
            return true;
        }
        else {
            return false;
        }
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        Node* temp = front;
        int ans = front->data;
        if (front == rear) {
            front = NULL;
            rear = NULL;
        }
        else {
            front = front->next;
        }
        delete temp;
        return ans;
    }

    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    void display() {
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    cout << "--- Queue (Linked List) ---" << endl;
    Queue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue elements: ";
    q.display();

    cout << "Removed element: " << q.dequeue() << endl;

    q.enqueue(40);
    q.enqueue(50);
    
    cout << "Queue after modifications: ";
    q.display();
    cout << "Front element currently is: " << q.frontElement() << endl;

    return 0;
}