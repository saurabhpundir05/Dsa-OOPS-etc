//Reverse a Singly Linked List (Iterative+Recursive)
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
//Reverse singly linked list using Iterative Approach
node* reverseLL(node* &head){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}
//Reverse singly linked list using Recursive Approach
node* recursiverevseLL(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newhead=recursiverevseLL(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
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
//Drivers code
int main(){
    node* head=NULL;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,5);
    display(head);
    node* newhead=reverseLL(head);
    display(newhead);
    node* recnewhead=recursiverevseLL(newhead);
    display(recnewhead);
    return 0;
}
