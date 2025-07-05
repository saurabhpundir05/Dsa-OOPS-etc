//Heap Sort
#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int n,int i){
    int largest,l,r;
    largest=i;
    l=2*i+1;
    r=2*i+2;
    if(l<n && a[l]>a[largest]){
        largest=l;
    }
    if(r<n && a[r]>a[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}
void heapSort(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
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
    heapSort(a,n);
    cout<<"After Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
