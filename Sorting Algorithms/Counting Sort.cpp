//Counting Sort
#include<bits/stdc++.h>
using namespace std;
void countingSort(int a[],int n){
    int max;
    max=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    int c[max+1]={0};
    for(int i=0;i<n;i++){
        c[a[i]]++;
    }
    for(int i=1;i<=max;i++){
        c[i]=c[i]+c[i-1];
    }
    int temp[n];
    for(int i=n-1;i>=0;i--){
        temp[c[a[i]]-1]=a[i];
        c[a[i]]--;
    }
    for(int i=0;i<n;i++){
        a[i]=temp[i];
    }
}
int main(){
    int n;
    cout<<"Enter Range"<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Before Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    countingSort(a,n);
    cout<<"After Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
