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

void push(int d, Node* &top) {
    Node* newstack = new Node(d);
    newstack->next = top;
    top = newstack;
}

void pop(Node* &top) {
    if(top == NULL) {
        cout << "Stack Underflow" << endl;
    }
    else {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

int peek(Node* top) {
    if(top == NULL) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    else {
        return top->data;
    }
}

bool isEmpty(Node* top) {
    return top == NULL;
}

int size(Node* top) {
    int count = 0;
    Node* temp = top;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void print(Node* top) {
    if(top == NULL) {
        cout << "Stack is empty" << endl;
    }
    else {
        Node* temp = top;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    cout << "--- Stack (Linked List) ---" << endl;
    Node* top = NULL;
    push(10, top);
    push(20, top);
    push(30, top);

    cout << "Stack: ";
    print(top);

    cout << "Top element: " << peek(top) << endl;
    cout << "Stack size: " << size(top) << endl;

    pop(top);

    cout << "After pop: ";
    print(top);

    cout << "Top element: " << peek(top) << endl;
    cout << "Is stack empty? " << (isEmpty(top) ? "Yes" : "No") << endl;

    while(top != NULL) {
        pop(top);
    }

    return 0;
}