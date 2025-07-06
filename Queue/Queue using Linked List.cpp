//Queue Implementation using Linked List
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
class queue{
    private:
    node* front;
    node* rear;
    public:
    queue(){
        front=NULL;
        rear=NULL;
    }
void enqueue(int val){
    node* n=new node(val);
    if(rear==NULL){
        front=rear=n;
        return;
    }
    rear->next=n;
    rear=n;
}
void dequeue(){
    if(isEmpty()){
        cout<<"Queue underflow"<<endl;
        return;
    }
    node* temp=front;
    front=front->next;
    if(front==NULL){
        rear=NULL;
    }
    delete temp;
}
int peek(){
    if(isEmpty()){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    return front->data;
}
bool isEmpty(){
    return front==NULL;
}
};
//Driver Code
int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.dequeue();
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.isEmpty()<<endl;
    return 0;
}
// Output
// 2
// 1