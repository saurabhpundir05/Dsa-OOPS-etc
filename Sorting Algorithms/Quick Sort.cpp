//Quick Sort
#include<iostream>
using namespace std;
int partition(int a[],int lb,int ub){
    int pivot,s,e;
    pivot=a[lb];
    s=lb;
    e=ub;
    while(s<e){
        while(a[s]<=pivot){
            s++;
        }
        while(a[e]>pivot){
            e--;
        }
        if(s<e){
            swap(a[s],a[e]);
        }
    }
    swap(a[lb],a[e]);
    return e;
}
void quickSort(int a[],int lb,int ub){
    if(lb<ub){
        int loc=partition(a,lb,ub);
        quickSort(a,lb,loc-1);
        quickSort(a,loc+1,ub);
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
    quickSort(a,0,n-1);
    cout<<"After Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
