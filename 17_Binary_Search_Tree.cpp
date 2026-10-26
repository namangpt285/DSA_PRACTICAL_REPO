#include <iostream>
using namespace std ;

class Node{
    public:
    int data ;
    Node* left ;
    Node* right ;
    Node(int d ){
        this->data = d ;
        this->left = NULL ;
        this->right = NULL ;
    }
};

void insert(Node*& root, int d) {
    if (root == NULL) {
        root = new Node(d);
        return;
    }
    if (d < root->data) {
        insert(root->left, d);
    }
    else if (d > root->data) {
        insert(root->right, d);
    }
    else {
        cout << "Duplicate value not allowed";
    }
}

void buildBST(Node*& root) {
    bool more = true;
    while (more) {
        int data;
        cout << "Enter data: ";
        cin >> data;
        insert(root, data);
        cout << "Do you want to enter another value? (1/0): ";
        cin >> more;
    }
}

void inorder(Node* root){
    if(root == NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" " ;
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" " ;
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" " ;
}

bool searchBST(Node* root,int key ){
    if(root == NULL){
        return 0 ;
    }
    if(root->data == key){
        return 1 ;
    }
    else if(key < root->data){
        return searchBST(root->left, key);
    }
    else {
        return searchBST(root->right, key);
    }
}

int findMin(Node* root){
    if(root == NULL){
        return 0 ;
    }
    while(root->left != NULL){
        root = root->left ;
    }
    return root->data ;
}

int findMax(Node* root){
    if(root == NULL){
        return 0 ;
    }
    while(root->right != NULL){
        root = root->right ;
    }
    return root->data ;
}

bool isBST(Node* root, long long low, long long high) {
    if (root == NULL) {
        return true;
    }
    if (root->data <= low || root->data >= high) {
        return false;
    }
    return isBST(root->left, low, root->data) &&
           isBST(root->right, root->data, high);
}

void deletionBST(Node*& root, int value) {
    if (root == NULL) {
        return;
    }

    if (value < root->data) {
        deletionBST(root->left, value);
    }
    else if (value > root->data) {
        deletionBST(root->right, value);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            int rightMin = findMin(root->right);
            root->data = rightMin;
            deletionBST(root->right, rightMin);
        }
    }
}

int main(){
    cout << "--- Binary Search Tree ---" << endl;
    Node* root = NULL ;
    
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);

    cout << "Initial Inorder traversal: "; inorder(root); cout << endl;
    cout << "Min Val: " << findMin(root) << " | Max Val: " << findMax(root) << endl;
    
    cout << "Is Valid BST? " << (isBST(root, -9999, 9999) ? "Yes" : "No") << endl;
    cout << "Search for 15: " << (searchBST(root, 15) ? "Found" : "Not Found") << endl;
    
    cout << "Deleting Node 10 (Root with two children)..." << endl;
    deletionBST(root, 10);
    
    cout << "After Deletion Inorder: "; inorder(root); cout << endl;
    
    return 0;
}