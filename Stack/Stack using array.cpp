//Stack Implementation using array
#include<iostream>
using namespace std;
#define n 100
class stack{
    int *arr;
    int top;
    public:
    stack(){
        arr=new int[n];
        top=-1;
    }
void push(int x){
    if(top==n-1){
        cout<<"Stack overflow"<<endl;
        return;
    }
    top++;
    arr[top]=x;
}
void pop(){
    if(top==-1){
        cout<<"Stack is empty"<<endl;
        return;
    }
    top--;
}
int peek(){
    if(top==-1){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    return arr[top];
}
bool isempty(){
    return top==-1;
}
};
int main(){  
    stack st;
    st.push(1);
    st.push(2);
    st.pop();
    st.push(3);
    st.push(7);
    cout<<st.peek()<<endl;
    cout<<st.isempty()<<endl;  
    return 0;
}
// Output
// 7
// 0
