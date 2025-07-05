//Reversing Doubly Linked List(Iterative & Recursive)
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
//Iterative reverse logic
void reverseLL(node* &head){
    if(head==NULL ||head->next==NULL){
        return;
    }
    node* temp=NULL;
    node* curr=head;
    while(curr!=NULL){
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
    if(temp!=NULL){
        head=temp->prev;
    }
}
//Recursive reverse logic
void recursiverevLL(node* &head,node* curr){
    if(curr==NULL){
        return;
    }
    node* temp=curr->next;
    curr->next=curr->prev;
    curr->prev=temp;
    if(curr->prev==NULL){
        head=curr;
        return;
    }
    recursiverevLL(head,curr->prev);
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
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,5);
    display(head);
    reverseLL(head);
    display(head);
    recursiverevLL(head,head);
    display(head);
    return 0;
}
// Output
// 5->4->3->2->1->NULL
// 1->2->3->4->5->NULL
// 5->4->3->2->1->NULL