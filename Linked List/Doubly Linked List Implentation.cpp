//Doubly Linked List Implementation(Insertion, Deletion & Traversal)
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
//Insert value at head of Doubly Linked List
void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head=n;
}
//Insert value at tail(end) of Doubly Linked List
void insertAtTail(node* &head,int val){
    node* n=new node(val);
    node* temp=head;
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
//Insert value at random position of Doubly Linked List
void insertAtRandom(node* &head,int val,int pos){
    if(pos==1){
        insertAtHead(head,val);
        return;
    }
    node* n=new node(val);
    node* temp=head;
    int c=1;
    while(temp!=NULL && c!=pos-1){
        temp=temp->next;
        c++;
    }
    if(temp==NULL){
        cout<<"Position not found"<<endl;
        return;
    }
    n->next=temp->next;
    n->prev=temp;
    if(temp->next!=NULL){
        temp->next->prev=n;
    }
    temp->next=n;
}
//Delete head value of Doubly Linked List
void deleteAtHead(node* &head){
    node* temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;
}
//Delete random position value of Doubly Linked List
void deleteAtRandom(node* &head,int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    int c=1;
    while(temp!=NULL && c!=pos){
        temp=temp->next;
        c++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    delete temp;
}
//Doubly Linked List Traversal
void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
//Drivers Code
int main(){
    node* head=NULL;
    insertAtHead(head,1);
    display(head);
    insertAtTail(head,2);
    display(head);
    insertAtRandom(head,3,3);
    display(head);
    deleteAtHead(head);
    display(head);
    insertAtHead(head,6);
    insertAtHead(head,7);
    insertAtHead(head,8);
    display(head);
    deleteAtRandom(head,4);
    display(head);
    return 0;
}
// Output
// 1->NULL
// 1->2->NULL
// 1->2->3->NULL
// 2->3->NULL
// 8->7->6->2->3->NULL
// 8->7->6->3->NULL