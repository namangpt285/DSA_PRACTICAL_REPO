#include <iostream>
using namespace std ;

class Node{
public:
    int data ;
    Node* next ;
    Node* prev ;

    Node(int data){
        this->data = data ;
        this->next = NULL ;
        this->prev = NULL ;
    }
};

void print(Node* head){
    Node* temp = head ;
    while(temp != NULL){
        cout<<temp->data<<" " ;
        temp = temp->next ;
    }
    cout<<endl ;
}

int getLength(Node* head){
    int Length = 0 ;
    Node* temp = head ;
    while(temp != NULL){
        Length++ ;
        temp = temp->next ;
    }
    return Length ;
}

void InsertAtHead(Node* &head,int d){
    Node* temp = new Node(d) ;
    if(head == NULL){
        head = temp ;
        return ;
    }
    head->prev = temp ;
    temp->next = head ;
    head = temp ;
}

void InsertAtTail(Node* &tail,int d){
    Node* temp = new Node(d) ;
    if(tail == NULL){
        tail = temp ;
        return ;
    }
    tail->next = temp ;
    temp->prev = tail ;
    tail = temp ;
}

void InsertAtMiddle(Node* &head,Node* &tail,int position,int d){
    if(position < 1){
        cout<<"Invalid position"<<endl ;
        return ;
    }
    if(position == 1){
        InsertAtHead(head,d) ;
        if(tail == NULL){
            tail = head ;
        }
        return ;
    }
    Node* temp = head ;
    int cnt = 1 ;
    while(cnt < position-1 && temp != NULL){
        temp = temp->next ;
        cnt++ ;
    }
    if(temp == NULL){
        cout<<"Invalid position"<<endl ;
        return ;
    }
    if(temp->next == NULL){
        InsertAtTail(tail,d) ;
        return ;
    }
    Node* nodeToInsert = new Node(d) ;
    nodeToInsert->next = temp->next ;
    nodeToInsert->prev = temp ;
    temp->next->prev = nodeToInsert ;
    temp->next = nodeToInsert ;
}

void DeleteNode(Node* &head, int position){
    if(position <= 0){
        cout<<"Invalid position"<<endl ;
        return ;
    }
    if(head == NULL){
        cout<<"List is empty"<<endl ;
        return ;
    }
    if(position == 1){
        Node* temp = head ;
        head = head->next ;
        if(head != NULL){
            head->prev = NULL ;
        }
        delete temp ;
        return ;
    }
    Node* temp = head ;
    int cnt = 1 ;
    while(cnt < position-1 && temp != NULL){
        temp = temp->next ;
        cnt++ ;
    }
    if(temp == NULL || temp->next == NULL){
        cout<<"Invalid position"<<endl ;
        return ;
    }
    Node* nodeToDelete = temp->next ;
    temp->next = nodeToDelete->next ;
    if(nodeToDelete->next != NULL){
        nodeToDelete->next->prev = temp ;
    }
    delete nodeToDelete ;
}

int main(){
    cout << "--- Doubly Linked List ---" << endl;
    Node* node1 = new Node(10) ;
    Node* head = node1 ;
    Node* tail = node1 ;

    cout<<"Initial List: "; print(head);
    
    InsertAtHead(head,12);
    InsertAtHead(head,13);
    cout<<"After Head Inserts: "; print(head);
    
    InsertAtTail(tail,23);
    cout<<"After Tail Insert: "; print(head);
    
    InsertAtMiddle(head,tail,4,523);
    cout<<"After Middle Insert: "; print(head);
    
    DeleteNode(head,3);
    cout<<"After Deleting pos 3: "; print(head);
    
    cout<<"Final Length: "<<getLength(head)<<endl ;

    return 0;
}