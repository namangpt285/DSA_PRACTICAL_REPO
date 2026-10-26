#include <iostream>
using namespace std ;

class Node{
    public :
    int data ;
    Node* next ;
    Node(int data){
        this->data = data ;
        this->next = NULL ;
    }
};

void InsertAtHead(Node* &head,int d){
    Node* temp = new Node(d) ;
    temp->next = head ;
    head = temp ;
}

void Print(Node* &head){
    Node* temp = head ;
    while(temp!=NULL){
        cout<<temp->data<<" " ;
        temp = temp->next ;
    }
    cout<<endl ;
}

void InsetAtTail(Node* &tail,int d ){
    Node* temp = new Node(d) ;
    tail->next = temp ;
    tail = temp ;
}

void InsertAtMiddle(Node* &head,Node* &tail,int position,int d ){
    if(position==1){
        InsertAtHead(head,d) ;
        return ;
    }
    Node* temp = head ;
    int cnt = 1 ;
    while(cnt<position-1){
        temp = temp->next ;
        cnt++ ;
    }
    if(temp->next==NULL){
        InsetAtTail(tail,d) ;
        return ;
    }
    Node* nodeToInsert = new Node(d) ;
    nodeToInsert->next = temp->next ;
    temp->next = nodeToInsert ;
}

void deleteNode(Node* &head, int value){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    if(head->data == value){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* prev = head;
    Node* curr = head->next;
    while(curr != NULL && curr->data != value){
        prev = curr;
        curr = curr->next;
    }
    if(curr == NULL){
        cout<<"Value does not exist in list"<<endl;
        return;
    }
    prev->next = curr->next;
    delete curr;
}

void DeleteNode(Node* &head,int position){
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    if(position<=0){
        cout<<"Invalid position"<<endl ;
        return ;
    }
    Node* temp = head ;
    int cnt = 1 ;
    while(cnt < position-1 && temp!=NULL){
        temp = temp->next ;
        cnt++ ;
    }
    if(temp==NULL || temp->next==NULL){
        cout<<"Invalid position"<<endl ;
        return ;
    }
    Node* nodeToDelete = temp->next ;
    temp->next = temp->next->next ;
    delete nodeToDelete ;
}

int main(){
    cout << "--- Singly Linked List ---" << endl;
    Node* node1 = new Node(10) ;
    Node* head = node1 ;
    Node* tail = node1 ;
    Print(head) ;
    
    InsertAtHead(head,12) ;
    InsertAtHead(head,15) ;
    cout << "After Head Insertions: ";
    Print(head) ;
    
    InsetAtTail(tail,20) ;
    InsetAtTail(tail,25) ;
    cout << "After Tail Insertions: ";
    Print(head) ;
    
    InsertAtMiddle(head,tail,6,22) ;
    cout << "After Middle Insertion (pos 6): ";
    Print(head) ;
    
    DeleteNode(head,6) ;
    cout << "After Deleting pos 6: ";
    Print(head) ;
    
    deleteNode(head, 12);
    cout << "After Deleting value 12: ";
    Print(head);
    
    return 0 ;
}