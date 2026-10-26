#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std ;

class Node{
    public :
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
    bool x;
    if (root == NULL) {
        Node* node1 = new Node(d);
        root = node1;
        root->left = NULL;
        root->right = NULL;
    }

    cout << "Does node " << root->data << " have left child? (1/0): ";
    cin >> x;

    if (x) {
        int leftData;
        cout << "Enter left child data: ";
        cin >> leftData;
        insert(root->left, leftData);
    }

    cout << "Does node " << root->data << " have right child? (1/0): ";
    cin >> x;

    if (x) {
        int rightData;
        cout << "Enter right child data: ";
        cin >> rightData;
        insert(root->right, rightData);
    }
}

void inorder(Node* root){
    if(root == NULL){
        return;
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

void Level_order(Node* root){
    if(root == NULL) return;
    queue<Node*> q ;
    q.push(root);
    while(q.size()>0){
        Node* curr = q.front();
        q.pop();
        cout<<curr->data<< " ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
    cout<<endl ;
}

bool search(Node* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    return search(root->left, key) || search(root->right, key);
}

int count_nodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int height_tree(Node* root){
    int height = 0 ;
    if(root == NULL){
        return 0 ;
    }
    else{
        height = 1 + max(height_tree(root->left), height_tree(root->right));
    }
    return height ;
}

int max_val(Node* root) {
    if (root == NULL) {
        return INT_MIN;
    }
    return max(root->data, max(max_val(root->left), max_val(root->right)));
}

void deleteDeepest(Node*& root, Node* deepest) {
    if (root == NULL) {
        return;
    }
    if (root == deepest) {
        delete root;
        root = NULL;
        return;
    }
    if (root->left == deepest) {
        delete root->left;
        root->left = NULL;
        return;
    }
    if (root->right == deepest) {
        delete root->right;
        root->right = NULL;
        return;
    }
    deleteDeepest(root->left, deepest);
    deleteDeepest(root->right, deepest);
}

void deleteNode(Node*& root, int key) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);

    Node* target = NULL;
    Node* deepest = NULL;

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->data == key) {
            target = temp;
        }
        deepest = temp;

        if (temp->left != NULL) {
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }

    if (target == NULL) {
        cout << "Value not found";
        return;
    }

    target->data = deepest->data;
    deleteDeepest(root, deepest);
}

// To run smoothly without waiting on interactive input in automated tests:
int main() {
    cout << "--- Binary Tree General ---" << endl;
    
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    
    cout << "Preorder traversal: "; preorder(root); cout << endl;
    cout << "Inorder traversal: "; inorder(root); cout << endl;
    cout << "Postorder traversal: "; postorder(root); cout << endl;
    
    cout << "Total nodes: " << count_nodes(root) << endl;
    cout << "Height: " << height_tree(root) << endl;
    cout << "Max value: " << max_val(root) << endl;
    
    cout << "Level order traversal: "; Level_order(root);
    
    cout << "Searching for 20: " << (search(root, 20) ? "Found" : "Not Found") << endl;
    
    cout << "Deleting 20..." << endl;
    deleteNode(root, 20);
    
    cout << "Level order after deletion: "; Level_order(root);
    
    return 0;
}