//Shell Sort
#include<bits/stdc++.h>
using namespace std;
void shellSort(int a[],int n){
    int gap;
    gap=n/2;
    while(gap>0){
        for(int i=gap;i<n;i++){
            int temp=a[i];
            int j=i;
            while(j>=gap && a[j-gap]>temp){
                a[j]=a[j-gap];
                j=j-gap;
            }
            a[j]=temp;
        }
        gap=gap/2;
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
    shellSort(a,n);
    cout<<"After Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
