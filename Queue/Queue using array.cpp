//Queue Implementation using array
#include<iostream>
using namespace std;
#define n 10
class queue{
    int *arr;
    int front,rear;
    public:
    queue(){
        arr=new int[n];
        front=-1;
        rear=-1;
    }
void enqueue(int x){
    if(rear==n-1){
        cout<<"Queue is full"<<endl;
        return;
    }
    rear++;
    arr[rear]=x;
    if(front==-1){
        front++;
    }
}
void dequeue(){
    if(front==-1 || front>rear){
        cout<<"Queue is empty"<<endl;
        return;
    }
    for(int i=front;i<rear;i++){
        arr[i]=arr[i+1];
    }
    rear--;
}
int peek(){
    if(front==-1 || front>rear){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    return arr[front];
}
bool isempty(){
    return (front==-1 || front>rear);
}
};
int main(){  
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    cout<<q.isempty()<<endl;  
    return 0;
}
