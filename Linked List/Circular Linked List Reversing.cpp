//Reverse Cicular Linked List
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
//Insert value at head of Circular Linked List
void insertAtHead(node* &head,int val){
    node* n=new node(val);
    node* temp=head;
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}
//Reverse Logic
void reverseLL(node* &head){
    if(head==NULL || head->next==head){
        return;
    }
    node* prev=NULL;
    node* curr=head;
    node* tail=head;
    node* forward=NULL;
    do{
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    while(curr!=head);
    tail->next=prev;
    head=prev;
}
//Circular Linked List Traversal
void display(node* &head){
    node* temp=head;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    while(temp!=head);
    cout<<"NULL"<<endl;
}
//Driver Code
int main(){
    node* head=NULL;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,5);
    display(head);
    reverseLL(head);
    display(head);
    return 0;
}
// Output
// 5->4->3->2->1->NULL
// 1->2->3->4->5->NULL