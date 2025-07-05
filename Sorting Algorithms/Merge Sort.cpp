//Merge Sort
#include<bits/stdc++.h>
using namespace std;
void merges(int a[],int lb,int mid,int ub){
    vector<int> temp;
    int left,right;
    left=lb;
    right=mid+1;
    while(left<=mid && right<=ub){
        if(a[left]<=a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(a[left]);
        left++;
    }
    while(right<=ub){
        temp.push_back(a[right]);
        right++;
    }
    for(int i=lb;i<=ub;i++){
        a[i]=temp[i-lb];
    }
}
void mergeSort(int a[],int lb,int ub){
    if(lb<ub){
        int mid=lb+(ub-lb)/2;
        mergeSort(a,lb,mid);
        mergeSort(a,mid+1,ub);
        merges(a,lb,mid,ub);
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
    mergeSort(a,0,n-1);
    cout<<"After Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
