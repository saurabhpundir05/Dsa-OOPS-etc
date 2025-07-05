//Singly Linked List Implementation in cpp(Insertion, Deletion and Traversal)
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
//Inserting value at head position of singly linked list
void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}
//Inserting value at tail(end)
void insertAtTail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
//Inserting value at random position of singly linked list
void insertAtRandom(node* &head,int pos,int val){
    node* n=new node(val);
    node* temp=head;
    int size=0;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    if(pos<1 || pos>size+1){
        cout<<"Invalid Position"<<endl;
        delete n;
        return;
    }
    if(pos==1){
        insertAtHead(head,val);
        return;
    }
    temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
}
//deleting value from head of singly linked list
void deleteAtHead(node* &head){
    if(head==NULL){
        return;
    }
    node* del=head;
    head=head->next;
    delete del;
}
//deleting value from random position
void deleteAtRandom(node* &head,int val){
    node* temp=head;
    if(head==NULL){
        return;
    }
    if(head->data==val){
        deleteAtHead(head);
        return;
    }
    while(temp->next!=NULL && temp->next->data!=val){
        temp=temp->next;
    }
    if(temp->next==NULL){
        cout<<"Value not found"<<endl;
        return;
    }
    node* del=temp->next;
    temp->next=temp->next->next;
    delete del;
}
//searching in singly linked list
bool searching(node* head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
//traversal of singly linked list
void display(node* head){
    node* temp=head;
    if(head==NULL){
        cout<<"NULL"<<endl;
        return;
    }
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
//drivers code
int main(){
    node* head=NULL;
    insertAtHead(head,1);
    display(head);
    insertAtTail(head,2);
    display(head);
    insertAtRandom(head,1,3);
    display(head);
    deleteAtHead(head);
    display(head);
    deleteAtRandom(head,2);
    display(head);
    insertAtTail(head,55);
    insertAtTail(head,56);
    insertAtTail(head,57);
    insertAtTail(head,58);
    display(head);
    cout<<searching(head,58)<<endl;
    cout<<searching(head,59)<<endl;
    return 0;
}
