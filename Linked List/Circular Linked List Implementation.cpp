//Cicular Linked List Implementation(Insertion,Deletion & Traversal)
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
//Insert value at Tail(end) of Circular Linked List
void insertAtTail(node* &head,int val){
    node* n=new node(val);
    node* temp=head;
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}
//Insert value at Random position of Circular Linked List
void insertAtRandom(node* &head,int val,int pos){
    if(pos==1){
        insertAtHead(head,val);
        return;
    }
    node* n=new node(val);
    node* temp=head;
    int c=1;
    while(c!=pos-1 && temp->next!=head){
        temp=temp->next;
        c++;
    }
    if(temp->next==head && c!=pos-1){
        insertAtTail(head,val);
        return;
    }
    n->next=temp->next;
    temp->next=n;
}
//Deletion of value at Head of Circular Linked List
void deleteAtHead(node* &head){
    if(head==NULL) return;
    if(head->next==head){
        delete head;
        head=NULL;
        return;
    }
    node* temp=head;
    node* last=head;
    while(last->next != head){
        last=last->next;
    }
    last->next=head->next;
    head=head->next;
    delete temp;
}
//Deletion of value at random position of Circular Linked List
void deleteAtRandom(node* &head,int pos){
    node* temp=head;
    int c=1;
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    while(c!=pos-1){
        temp=temp->next;
        c++;
    }
    node *del=temp->next;
    temp->next=temp->next->next;
    delete del;
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
    display(head);
    insertAtTail(head,3);
    display(head);
    insertAtRandom(head,55,2);
    display(head);
    insertAtHead(head,66);
    insertAtHead(head,67);
    insertAtHead(head,68);
    insertAtHead(head,69);
    display(head);
    deleteAtHead(head);
    display(head);
    deleteAtRandom(head,4);
    display(head);
    return 0;
}
// Output
// 2->1->NULL
// 2->1->3->NULL
// 2->55->1->3->NULL
// 69->68->67->66->2->55->1->3->NULL
// 68->67->66->2->55->1->3->NULL
// 68->67->66->55->1->3->NULL