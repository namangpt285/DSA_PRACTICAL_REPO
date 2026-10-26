#include <iostream>
using namespace std;

class Stack {
    int arr[10];
    int capacity;
    int top;

public:
    Stack() {
        capacity = 10;
        top = -1;
    }

    void push(int x) {
        if(top == capacity - 1) {
            cout << "Stack Overflow" << endl;
        }
        else {
            top++;
            arr[top] = x;
        }
    }

    void pop() {
        if(top == -1) {
            cout << "Stack Underflow" << endl;
        }
        else {
            top--;
        }
    }

    int peek() {
        if(top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else {
            return arr[top];
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    int size() {
        return top + 1;
    }

    void print() {
        if(top == -1) {
            cout << "Stack is empty" << endl;
        }
        else {
            for(int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    cout << "--- Stack (Array) ---" << endl;
    
    s.push(100);
    s.push(200);
    s.push(300);

    cout << "Stack Elements: ";
    s.print();

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    cout << "After one pop: ";
    s.print();

    cout << "New top element: " << s.peek() << endl;
    cout << "Stack size: " << s.size() << endl;
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (s.isFull() ? "Yes" : "No") << endl;

    return 0;
}