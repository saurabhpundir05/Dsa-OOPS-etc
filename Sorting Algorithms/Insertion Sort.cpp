//Insertion Sort
#include<iostream>
using namespace std;
void insertionSort(int a[],int n){
    for(int i=0;i<n;i++){
        int c=a[i];
        int j=i-1;
        while(a[j]>c && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=c;
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
    insertionSort(a,n);
    cout<<"After Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
