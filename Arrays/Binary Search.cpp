//Binary Search
#include<bits/stdc++.h>
using namespace std;
int binarySearch(int a[],int n,int key){
    int s,e;
    s=0;
    e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]<key){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter Range"<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cout<<"Enter element"<<endl;
    cin>>key;
    int loc=binarySearch(a,n,key);
    if(loc>=0){
        cout<<"Element found at "<<loc<<" index"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}
