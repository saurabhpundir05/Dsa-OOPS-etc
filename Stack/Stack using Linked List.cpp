//Stack Implementation using Linked List
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
class stack{
    private:
    node* head;
    public:
    stack(){
        head=NULL;
    }
void push(int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}
void pop(){
    if(isEmpty()){
        cout<<"Stack underflow"<<endl;
        return;
    }
    node* temp=head;
    head=head->next;
    cout<<temp->data<<" is Popped"<<endl;
    delete temp;
}
int peek(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    return head->data;
}
bool isEmpty(){
    return head==NULL;
}
};
//Driver Code
int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.isEmpty()<<endl;
    return 0;
}
// Output
// 2 is Popped
// 1
// 1 is Popped
// 1