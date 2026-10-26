#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};

int getHeight(Node* root) {
    if(root == NULL) {
        return 0;
    }
    return root->height;
}

int getBalance(Node* root) {
    if(root == NULL) {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

Node* insert(Node* root, int key) {
    if(root == NULL) {
        return new Node(key);
    }

    if(key < root->data) {
        root->left = insert(root->left, key);
    }
    else if(key > root->data) {
        root->right = insert(root->right, key);
    }
    else {
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if(balance > 1 && key < root->left->data) {
        return rightRotate(root);
    }
    if(balance < -1 && key > root->right->data) {
        return leftRotate(root);
    }
    if(balance > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    cout << "--- AVL Tree Self-Balancing ---" << endl;
    Node* root = NULL;
    int arr[] = {12, 34, 26, 13, 54, 9, 21};

    cout << "Inserting sequence: 12, 34, 26, 13, 54, 9, 21" << endl;
    for(int i = 0; i < 7; i++) {
        root = insert(root, arr[i]);
    }

    cout << "Inorder traversal ensures sorted property: ";
    inorder(root);
    cout << "Tree root value is naturally balanced to: " << root->data << endl;
    cout << "Root Balance Factor: " << getBalance(root) << endl;

    return 0;
}